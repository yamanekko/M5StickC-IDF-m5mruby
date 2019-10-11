#include "Arduino.h"
#include <stdio.h>
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <M5StickC.h>

void setup() {
    Serial.begin(115200);

    /* from Hello World Example */
    printf("Hello world!\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    // Initialize the M5StickC object
    M5.begin();

    // LCD display
    M5.Lcd.print("Hello World");
}

void loop() {
    Serial.println("loop");
    delay(1000);
}
