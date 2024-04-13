
# IoT Flame Sensor with ESP8266 and Arduino Nano

This repository contains the firmware for an IoT device that detects flame levels and communicates the status over HTTP to a server. The device uses a NodeMCU8266 with an old bootloader, a CH340 Arduino Nano, and a flame sensor module.

## Components

- NodeMCU8266 (Old Bootloader)
- CH340 Arduino Nano
- Flame Sensor Module
- Jumper Wires
- Breadboard

## Setup

### Flame Sensor Firmware

The firmware for the flame sensor is written for the Arduino Nano. It reads the analog value from the flame sensor and sends the status over serial to the NodeMCU.

### WiFi Communication Firmware

The NodeMCU8266 is programmed to read the status from the Arduino Nano over serial and send it to a server using HTTP POST requests.

## Configuration

Replace the `ssid` and `password` variables with your own WiFi credentials.

```c++
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
```

## Server Endpoint

Make sure to have a server running to receive the POST requests. The server should expose the following endpoint:

```
http://your_server/flame-status
```

This endpoint will receive the flame status as a JSON object with a `status` key.

## Usage

After powering up the device, it will start sending the flame status to the server every second.

## Contributing

If you'd like to contribute to this project, please fork the repository and issue a pull request with your changes.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments
- Papa
- Navratri
- Moti❤️