# M5StickC-IDF: an ESP-IDF example for M5StickC

This is a M5StickC version of [M5Stack-IDF](https://github.com/m5stack/M5Stack-IDF).

## Install

* Download and install [esp-idf](https://github.com/espressif/esp-idf) of stable version and `idf.py`.
    * see [Get Started (CMake)](https://docs.espressif.com/projects/esp-idf/en/stable/get-started-cmake/index.html)
* Create template idf project

```
$ git clone --recursive https://github.com/yamanekko/M5StickC-IDF.git
```

## Build and Execution

```
## update config
$ idf.py menuconfig

## build
$ idf.py build

## transfer to flash
$ idf.py flash

## when you need to change port and baud:
$ idf.py -p /dev/tty.usbserial-9D527BF645A -b 115200 flash

## monitor
$ idf.py -p /dev/tty.usbserial-9D527BF645A -b 115200 monitor
```

## NOTE

* If you use macOS, you may need to fix `ulimit` value:

```
$ ulimit -n 2048
```

* When you got `error: 'mbedtls_ssl_conf_psk' was not declared in this scope`, fix config (https://github.com/espressif/arduino-esp32/issues/2154)
