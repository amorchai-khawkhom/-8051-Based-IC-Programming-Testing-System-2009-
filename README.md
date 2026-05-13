## Features

- AT89C51ED2 (8051 family) based controller
- LCD text display interface
- Matrix keypad user input
- Multiple ZIF sockets
- Standalone operation
- Serial communication via DB9
- Custom PCB design
- Embedded firmware written in C
- Power regulation onboard

## Firmware Architecture

The firmware was written in Embedded C for the 8051 architecture.

Main modules:
- LCD driver
- keypad scanning
- IC test logic
- UART communication
- sound/buzzer control
- test routines

## Hardware Architecture

Main Components:
- AT89C51ED2 microcontroller
- 16x4 LCD module
- Matrix keypad
- ZIF programming sockets
- MAX232 serial interface
- Power supply regulation circuit
- Custom mainboard and interface board

## Development Environment

- Year: ~2009
- MCU: AT89C51ED2
- Architecture: 8051
- IDE: Keil uVision
- PCB Software: Protel 99SE / Altium
- Language: Embedded C

## Project Photos

### Main Unit

<img width="3648" height="2048" alt="IMG_0410" src="https://github.com/user-attachments/assets/4d463251-c0b8-461f-a943-6e17add074c4" />
<img width="3648" height="2048" alt="IMG_0411" src="https://github.com/user-attachments/assets/a80f0473-5936-481f-ac69-aadf478f0e91" />
<img width="3648" height="2048" alt="IMG_0412" src="https://github.com/user-attachments/assets/3bd66ba2-b838-4ed4-abf3-554b9945a412" />
<img width="3648" height="2048" alt="IMG_0413" src="https://github.com/user-attachments/assets/a1583a8c-7c52-4975-abbf-e3ea8b89e0b5" />

### Internal Hardware
<img width="3648" height="2048" alt="IMG_0416" src="https://github.com/user-attachments/assets/b143de27-4755-47e4-9eca-2b164a8c2420" />
<img width="3648" height="2048" alt="IMG_0415" src="https://github.com/user-attachments/assets/9f028c8d-dc20-497c-9e4f-257ea3608bbc" />
<img width="3648" height="2048" alt="IMG_0414" src="https://github.com/user-attachments/assets/7e457946-7647-4ec8-a0b6-cb0e09a2d407" />


### Mainboard
<img width="3648" height="2048" alt="IMG_0417" src="https://github.com/user-attachments/assets/4da30587-bd18-45d3-af95-d0b590b491c6" />

## Schematics

### Main Controller Schematic

<img width="1275" height="810" alt="Screenshot 2026-05-13 100952" src="https://github.com/user-attachments/assets/df964efb-d753-4296-8225-14639d32ccc4" />


### Interface Board Schematic
<img width="1359" height="861" alt="Screenshot 2026-05-13 101010" src="https://github.com/user-attachments/assets/766491cf-0c0d-4135-84e0-522577489068" />



## PCB Layout

### PCB Upper Layer

<img width="288" height="552" alt="Screenshot 2026-05-13 100419" src="https://github.com/user-attachments/assets/0228ee95-a43b-4613-9db4-084e0fe3bdab" />


### PCB Bottom Layer

<img width="288" height="549" alt="Screenshot 2026-05-13 100440" src="https://github.com/user-attachments/assets/7fc17cf7-4170-43d6-ba1a-6a5603a8f233" />


### PCB Component Overlay

<img width="309" height="597" alt="Screenshot 2026-05-13 100403" src="https://github.com/user-attachments/assets/32d0e466-06d3-46e3-a264-0a9571b1ba03" />



## Signal Debugging and Validation

Logic analyzer was used to validate:
- digital interface timing of sound
- embedded firmware operation

### Example Capture

<img width="817" height="555" alt="image" src="https://github.com/user-attachments/assets/5bf1c63a-1ba3-4400-aed6-2aa4e77004d5" />

<img width="817" height="555" alt="image" src="https://github.com/user-attachments/assets/b84403f3-0daa-4b76-930c-c2f430785e33" />

<img width="817" height="555" alt="image" src="https://github.com/user-attachments/assets/e38ca05c-b805-4e60-b961-c7e4e93edafa" />

<img width="817" height="555" alt="image" src="https://github.com/user-attachments/assets/6648f4bc-e376-4849-b4b3-8fa143cb4277" />

<img width="817" height="555" alt="image" src="https://github.com/user-attachments/assets/5dd5ca1c-54c8-4309-9ac2-9962a1c503e7" />



## Engineering Notes

This project was developed before modern low-cost development platforms became common.

The system was fully designed from discrete hardware blocks including:
- PCB routing
- power regulation
- LCD interface
- keypad scanning
- serial communication
- firmware architecture

The project reflects early experience in embedded system integration and hardware/software co-design.

## Historical Context

This project was originally developed around 2009.
Some source files and original CAD documents may be incomplete due to hardware migration and archival limitations.

## Lessons Learned

- Embedded hardware/software integration
- PCB debugging
- Signal routing
- User interface implementation on resource-limited systems
- Low-level serial communication
- Mechanical integration and enclosure assembly
