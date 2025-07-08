# Software Requirements Specification (SRS)

**Project Title:** Arduino UNO R4 WiFi PIR Security System  
**Version:** 1.3  
**Date:** 2025-07-08  
**Prepared by:** Alexander Arvedson

---

## 1. Introduction

### 1.1 Purpose
This document defines the software requirements for a security system implemented on the Arduino UNO R4 WiFi. The system detects motion using a PIR sensor, sounds an alarm, logs events over Serial and/or Wi-Fi, and includes password-based arming/disarming via a keypad. A status LCD provides real-time user feedback.

### 1.2 Scope
The Arduino UNO R4 WiFi security system includes:
- PIR sensor to detect motion
- Buzzer to sound an alarm
- I2C LCD for user communication
- Keypad for password entry
- Event logging over Serial and Wi-Fi (via built-in connectivity)
- LED indicators for system status
- Optional real-time clock (RTC) for timestamps

### 1.3 Intended Audience
This SRS is for developers, testers, and students designing or expanding the Arduino-based security system using the UNO R4 WiFi board.

---

## 2. Overall Description

### 2.1 Product Perspective
This is a self-contained system running on the Arduino UNO R4 WiFi, which features built-in Wi-Fi and advanced capabilities. It interacts with:
- PIR motion sensor (input)
- Keypad (input)
- I2C LCD display (output)
- Buzzer and LEDs (output)
- Serial and Wi-Fi (output to host system or server)

### 2.2 Product Functions
- Detect motion and trigger an alarm
- Arm/disarm the system via keypad with password entry
- Display system status and prompts on I2C LCD
- Send real-time log data over Serial and Wi-Fi
- Indicate armed/disarmed status via LEDs

### 2.3 User Classes

| User Class | Description |
|------------|-------------|
| Developer | Uploads code and monitors logs |
| End User  | Interacts with system via keypad, LCD, and LEDs |

---

## 3. Specific Requirements

### 3.1 Functional Requirements

| ID | Requirement | Description |
|----|-------------|-------------|
| FR1 | Motion Detection | Detect motion using PIR sensor |
| FR2 | Alarm Trigger | Sound buzzer for 5 seconds on detection |
| FR3 | Password Arming | Arm/disarm system using 4-digit password via keypad |
| FR4 | LCD Feedback | Display prompts, status, and feedback using I2C LCD |
| FR5 | Log Event Serial | Send alarm trigger events over USB Serial to host |
| FR6 | Log Event Wi-Fi | Send alarm event (with optional timestamp) to a remote system via HTTP POST or MQTT |
| FR7 | LED Status | Use LEDs to show armed (ON) / disarmed (OFF) |
| FR8 | Lockout | Lock system after 3 failed password attempts (optional timeout) |
| FR9 | Time Logging | Use RTC or millis-based uptime counter for timestamps |

### 3.2 Non-Functional Requirements

| ID | Requirement | Description |
|----|-------------|-------------|
| NFR1 | Reliability | System must detect and log all motion events |
| NFR2 | Real-Time Logging | Logging must occur within 1 second of motion |
| NFR3 | Connectivity | Wi-Fi settings are hardcoded or configured via code |
| NFR4 | Usability | LCD and keypad must provide responsive, intuitive feedback |
| NFR5 | Maintainability | Modular C++ classes used for alarm, sensor, keypad, LCD, and logging |

---

## 4. System Architecture

### 4.1 Hardware Components

| Component | Details |
|----------|---------|
| **Arduino UNO R4 WiFi** | Main controller with built-in Wi-Fi |
| **PIR Sensor** | HC-SR501, connected to digital input pin |
| **Buzzer** | Active buzzer, digital output |
| **I2C LCD** | 16x2 or 20x4 display using I2C backpack |
| **Keypad** | 4x3 or 4x4 matrix keypad connected via GPIO |
| **Two LEDs** | Status LEDs connected to digital output |
| **RTC Module (Optional)** | DS3231 via I2C if real-time logging is required |

### 4.2 Software Modules

- `main.ino`: System initialization and main control loop
- `PIRSensor.cpp/h`: Handles motion detection
- `Alarm.cpp/h`: Manages buzzer and alert control
- `KeypadManager.cpp/h`: Handles password input, validation, and lockout
- `LCDDisplay.cpp/h`: Manages text output and screen updates
- `Logger.cpp/h`: Serial and Wi-Fi logging
- `RTC.cpp/h`: Optional timestamp generation
- `WiFiClient.cpp/h`: Handles network communication (HTTP/MQTT)

---

## 5. Assumptions and Constraints

- Wi-Fi credentials are hardcoded or manually updated in source code
- Password is stored in flash memory (code), not EEPROM
- LCD uses standard I2C address (0x27 or 0x3F depending on module)
- Logging over Wi-Fi requires a reachable HTTP/MQTT endpoint
- Power source is stable USB or external 5V regulated supply

---

## 6. Future Enhancements

- Wi-Fi captive portal for configuring network and system password
- Web interface to monitor logs and system state
- LCD menu for system configuration
- Mobile notifications (via Blynk, Telegram, or MQTT push)
- Battery backup and tamper-proof casing

---

## 7. Glossary

| Term | Definition |
|------|------------|
| PIR | Passive Infrared sensor |
| RTC | Real-Time Clock module |
| MQTT | Lightweight messaging protocol for IoT |
| HTTP POST | Web protocol for sending data to server |
| I2C | Inter-Integrated Circuit, 2-wire communication bus |
| Wi-Fi | Wireless communication via UNO R4 WiFi module |
| LCD | Liquid Crystal Display used for textual feedback |
