# M5StickC-IDF: an ESP-IDF example for M5StickC with m5mruby

This is a M5StickC version of [M5Stack-IDF](https://github.com/m5stack/M5Stack-IDF) with [m5mruby](https://github.com/yamanekko/m5mruby).

## Install

* Download and install [esp-idf](https://github.com/espressif/esp-idf) of stable version and `idf.py`.
    * see [Get Started (CMake)](https://docs.espressif.com/projects/esp-idf/en/stable/get-started-cmake/index.html)
* Create template idf project

```
$ git clone https://github.com/yamanekko/M5StickC-IDF-m5mruby.git
$ cd M5StickC-IDF-m5mruby
$ git submodule update --init --recursive --recommend-shallow --depth 5
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

* If you got an error:

```
E (515) esp_image: Image length 1065616 doesn't fit in partition length 1048576
E (521) boot: Factory app partition is not bootable
E (526) boot: No bootable app partitions in the partition table
```

It's partitions issue. Use partitions.bin in this repo.

```
## flash partition table
$ idf.py -b 115200 partition_table-flash

## then flash and monitor
$ idf.py -b 115200 flash monitor
```
