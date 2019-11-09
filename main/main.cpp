#include "Arduino.h"
#include <stdio.h>
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <M5StickC.h>
#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/string.h"

#include "app_ruby.h"

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

void setup()
{
    Serial.begin(115200);

    // Initialize the M5StickC object
    M5.begin();

    // LCD display
    M5.Lcd.print("Hello World");
    delay(1000);
    M5.Lcd.fillScreen(ST7735_WHITE);
    delay(1000);
}

void loop()
{
    mrb_state *mrb = mrb_open();
    mrb_value ret;

    try {
        ret = mrb_load_irep(mrb, ruby_code);
    } catch (...) {
        printf("load_irep error!!\n");
    }
    printf("load irep end\n");

    if (mrb->exc) {
        if (!mrb_undef_p(ret)) {
            mrb_value s = mrb_funcall(mrb, mrb_obj_value(mrb->exc), "inspect", 0);
            if (mrb_string_p(s)) {
                printf(RSTRING_PTR(s));
            } else {
                printf("error unknown\n");
            }
        }
    }

    mrb_close(mrb);
    printf("mrb close OK!\n");
    delay(10000);
}

// The arduino task
void loopTask(void *pvParameters)
{
    setup();
    for (;;) {
        loop();
    }
}

extern "C" void app_main()
{
    initArduino();
    xTaskCreatePinnedToCore(loopTask, "loopTask", 1024*12, NULL, 1, NULL, ARDUINO_RUNNING_CORE);
}
