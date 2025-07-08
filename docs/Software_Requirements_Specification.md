# Software Requirements Specification (SRS)

**Project Title:** Arduino UNO R4 WiFi PIR Security System  
**Version:** 1.2  
**Date:** 2025-07-08  
**Prepared by:** Alexander Arvedson

---

## 1. Introduction

### 1.1 Purpose
This document defines the software requirements for a security system implemented on the Arduino UNO R4 WiFi. The system detects motion using a PIR sensor, sounds an alarm, logs events over Serial and/or Wi-Fi, and includes password-based arming/disarming via a keypad.

### 1.2 Scope
The Arduino UNO R4 WiFi security system includes:
- PIR sensor to detect motion
- Buzzer to sound an alarm
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
- Buzzer (output)
- Keypad (input)
- Serial interface (output)
- Wi-Fi (output to server or MQTT broker)

### 2.2 Product Functions
- Detect motion and trigger an alarm
- Arm/disarm the system via password entry
- Send real-time log data over Serial and Wi-Fi
- Indicate armed/disarmed status via LED

### 2.3 User Classes

| User Class | Description |
|------------|-------------|
| Developer | Uploads code and monitors logs |
| End User  | Interacts with system via keypad and observes output/alarm |

---

## 3. Specific Requirements

### 3.1 Functional Requirements

| ID | Requirement | Description |
|----|-------------|-------------|
| FR1 | Motion Detection | Detect motion using PIR sensor |
| FR2 | Alarm Trigger | Sound buzzer for 5 seconds on detection |
| FR3 | Password Arming | Arm/disarm system using 4-digit password via keypad |
| FR4 | Log Event Serial | Send alarm trigger events over USB Serial to host |
| FR5 | Log Event Wi-Fi | Send alarm event (with optional timestamp) to a remote system via HTTP POST or MQTT |
| FR6 | LED Status | Use LED to show armed (ON) / disarmed (OFF) |
| FR7 | Lockout | Lock system after 3 failed password attempts (optional timeout) |
| FR8 | Time Logging | Use RTC or millis-based uptime counter for timestamps |

### 3.2 Non-Functional Requirements

| ID | Requirement | Description |
|----|-------------|-------------|
| NFR1 | Reliability | System must detect and log all motion events |
| NFR2 | Real-Time Logging | Logging must occur within 1 second of motion |
| NFR3 | Connectivity | Wi-Fi settings are hardcoded or configured via code |
| NFR4 | Usability | Keypad input must provide feedback via Serial or LED blink |
| NFR5 | Maintainability | Modular C++ classes used for alarm, sensor, keypad, and logging |

---

## 4. System Architecture

### 4.1 Hardware Components

| Component | Details |
|----------|---------|
| **Arduino UNO R4 WiFi** | Main controller with built-in Wi-Fi |
| **PIR Sensor** | HC-SR501, connected to digital input pin |
| **Buzzer** | Active buzzer, digital output |
| **Keypad** | 4x3 or 4x4 matrix keypad connected via GPIO |
| **LED** | Status LED connected to digital output |
| **RTC Module (Optional)** | DS3231 via I2C if real-time logging is required |

### 4.2 Software Modules

- `main.ino`: Initialization, main loop
- `PIRSensor.cpp/h`: Handles motion detection
- `Alarm.cpp/h`: Manages buzzer
- `KeypadManager.cpp/h`: Handles password input, validation, lockout
- `Logger.cpp/h`: Serial + Wi-Fi logging
- `RTC.cpp/h`: Optional, for timestamp management
- `WiFiClient.cpp/h`: Handles network communication (HTTP or MQTT)

---

## 5. Assumptions and Constraints

- Wi-Fi credentials are hardcoded or manually updated
- Password is stored in code memory (not EEPROM)
- Network logging requires external endpoint (e.g., logging server, MQTT broker)
- System is powered via USB or regulated external supply

---

## 6. Future Enhancements

- Wi-Fi captive portal for password/Wi-Fi config
- Web interface to view logs
- LCD or OLED screen for display
- Integration with mobile app or push notifications
- Battery backup and tamper detection

---

## 7. Glossary

| Term | Definition |
|------|------------|
| PIR | Passive Infrared sensor |
| RTC | Real-Time Clock module |
| MQTT | Lightweight messaging protocol for IoT |
| HTTP POST | Web protocol for sending data to server |
| Wi-Fi | Wireless communication via UNO R4 WiFi module |
