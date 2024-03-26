# Inter-Core Communication on ESP32 using FreeRTOS

This repository contains code for demonstrating inter-core communication between core 0 and core 1 on an ESP32 microcontroller using FreeRTOS.

## Overview

The provided code implements three tasks:
1. **Core 0 Incremental Data**: Generates incremental data and sends it to a shared queue.
2. **Core 1 Fixed Data**: Sends fixed data (999) to the shared queue.
3. **Core 1 Receiver**: Receives data from the shared queue and prints it to the serial monitor.

## Serial Output

The Serial Monitor will display the following output:

Received data:     1    2    3    4    5    6    7    8    9    10    999

Received data:     999

Received data:     999

Received data:     999

Received data:     999

Received data:     11    12    13    14    15    16    17    18    19    20    999

Received data:     999

....



## Usage

1. Install the ESP32 board support in the Arduino IDE.
2. Include the FreeRTOS library in your Arduino project.
3. Copy the provided code into your Arduino IDE.
4. If necessary, adjust the queue size by modifying `#define QUEUE_SIZE 20`.
5. Verify and upload the code to your ESP32 board.
6. Open the Serial Monitor in the Arduino IDE (baud rate: 115200).
7. You should observe data being sent and received between core 0 and core 1.

## Customization

- Modify the task functions to perform different operations if needed.
- Adjust the queue size according to your requirements.

## Contributing

Contributions are welcome! Please feel free to open issues or submit pull requests.

## Refrence
https://www.freertos.org/Documentation/RTOS_book.html

https://github.com/FreeRTOS/FreeRTOS-Kernel-Book/blob/main/ch05.md#523-blocking-on-queue-reads

