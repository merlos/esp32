# Playing with ESP32 microcontroller

These are toy microprojects for testing the use of a ESP32 microcontroller.
Nothing you cannot find in any example library.

They work with the Arduino IDE.

The libraries/ folder are external libraries. They are external libraries managed by the IDE, I have included them just for MY convenience. 

I have used two microcontrollers:
* ESP32
* ESP32S3-WROOM1

Note that they're not fully documented. 

## Install arudino-cli in MacOS

```bash
brew install arduino-cli
```

Create this arduino-cli.json
```
board_manager:
  additional_urls:
    - https://dl.espressif.com/dl/package_esp32_index.json
```
Then run:
```
arduino-cli core update-index --config-file arduino-cli.yaml
arduino-cli config set network.connection_timeout 600s
arduino-cli core install esp32:esp32
```

## License

MIT
