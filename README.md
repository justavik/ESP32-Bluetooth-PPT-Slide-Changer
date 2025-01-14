# ESP32-Bluetooth-PPT-Slide-Changer
A minimalist Bluetooth Low Energy presentation remote built with ESP32. This project transforms an ESP32 board and two buttons into a wireless presentation controller that emulates keyboard arrow keys for navigating slides.
## Overview
This controller connects to your computer as a standard Bluetooth keyboard, sending UP and DOWN arrow key events when the corresponding buttons are pressed. Perfect for presentations, document browsing, or any application that responds to arrow key inputs.
## Features
- Bluetooth Low Energy (BLE) connectivity
- Hardware button debouncing for reliable operation
- Low latency key event transmission
- Cross-platform compatibility (works with any device that supports BLE keyboards)
## Components
- 1x ESP32 DevKitC based on ESP32-WROOM-32E
- 2x 4-Pin Tactile Push Buttons
- 1x Breadboard (I used 830 Pin)
- 4x Male-to-Male Jumper Wires
- Data cable (Micro-USB to Type-A to connect board to PC)
- Optional: Power source like 3.7V Lithium Battery with protection circuit or a PowerBank (only for demonstration / portability convinience; data + charging cable both transfers data and powers esp32).
## Hardware Configuration
- 3V3 to 5V end of ESP32 placed on breadboard (j row)
- 2 Tactile 4-pin push buttons positioned spanning across midline.
- GPIO 12 connected to bottom right pin of one button.
- GPIO 13 connected to bottom right pin of other button.
- 3V3 connected to both upper right pins of both buttons.
## Code
- Found at esp32_bt_ppt_slide_changer.ino
## Upload Instructions
- Connect Data Transfer Cable from Micro-USB port of ESP32 to PC.
- Open Arduino IDE (downloaded from https://arduino.cc/en/software), create new sketch and paste esp32_bt_ppt_slide_changer.ino code.
- Add ESP32 support by going to File/Preferences and paste "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json" in "Additional Boards Manager URLs".
- Install ESP32 board by Espressif Systems from Tools/Board/Boards Manager.
- Install ESP32-BLE-Keyboard library by downloading the ZIP (under green code button) from GitHub (https://github.com/T-vK/ESP32-BLE-Keyboard) and then Selecting the ZIP file from Sketch/Include Library/Add .ZIP Library... in the IDE.
- Find and connect port from Tools/Port (CMO in Windows or /dev/ttyUSB0 in Linux).
- Set upload speed to 115200 from Tools/Upload Speed.
- Start Upload (click -> in IDE). The code first compiles. Press and hold the esp32 boot button for a few seconds while the board connects if necessary and wait for Upload to be Finished.
- Open BlueTooth Settings in PC and Connect to "Slide Controller" (make sure your PC is discoverable as a bluetooth device).
- Test button functionality.
