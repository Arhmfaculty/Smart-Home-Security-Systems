# Smart-Home-Security-Systems

## Overview
This project implements a **Smart Home Security System** designed to enhance home security through **biometric authentication**, **motion detection**, and **automated access control**. The system ensures that only **authorized users** can access the house while detecting and alerting unauthorized activities.

## Features
- **Biometric Authentication:** Uses fingerprint sensors for identity verification to restrict access to authorized users.
- **Motion Detection:** Infrared sensors detect movement and trigger alarms for intrusions.
- **Automated Locking System:** Electronic locks are activated or deactivated based on biometric verification.
- **Remote Monitoring and Alerts:** Sends notifications and logs activities to an online server for real-time monitoring.
- **Logging and Analytics:** All access attempts and alerts are recorded for later review and decision-making.

## System Components
- **Microcontroller:** ESP8266 with Wi-Fi connectivity for data transmission.
- **Fingerprint Sensor:** Adafruit fingerprint sensor for biometric authentication.
- **Motion Detector:** Passive Infrared (PIR) sensor for motion detection.
- **Buzzer and LED Indicators:** Provide immediate audible and visual alerts.
- **Online Server Integration:** Logs activities and access attempts for security tracking.

## Schematic Diagram
**Circuit Design:**
![image](https://github.com/user-attachments/assets/f0baff35-7aeb-452d-8d00-e5beb92b4f10)


## Software Requirements
- Arduino IDE
- ESP8266 Wi-Fi Library
- Adafruit Fingerprint Sensor Library
- Blynk App for mobile alerts (optional)

## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/username/smart-home-security.git
   ```
2. Open the project in Arduino IDE.
3. Install required libraries:
   - ESP8266WiFi
   - Adafruit Fingerprint Sensor
4. Flash the code to the ESP8266 microcontroller.
5. Connect the hardware components as per the schematic provided.

## Usage
- Register authorized fingerprints using the setup module.
- Activate the system by powering on the microcontroller.
- Test motion detection and alerts.
- Monitor logs and activity records through the online server.

## Future Enhancements
- Integrate voice recognition for multi-factor authentication.
- Implement GSM module for SMS alerts in case of Wi-Fi failure.
- Add facial recognition as an additional authentication layer.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request.


