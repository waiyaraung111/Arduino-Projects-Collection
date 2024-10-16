### Project Title:
**IMU-Based Tilt Angle Control for Servo and LED**

---

### README File:

# IMU-Based Tilt Angle Control for Servo and LED

## Overview
This project showcases how to control a servo motor and an LED based on the tilt angle measured by an MPU6050 Inertial Measurement Unit (IMU). The angle is calculated from the IMU's acceleration data, and the servo motor is moved according to the angle. Additionally, the LED is switched on or off when the tilt falls within a specific range. This system could be used in motion-controlled devices, robotics, or interactive systems.

## Features
- **Tilt Angle Calculation**: Uses the MPU6050 sensor to calculate the tilt angle of the device in real-time.
- **Servo Motor Control**: The servo motor adjusts its position based on the calculated angle.
- **LED Indicator**: The LED turns on when the tilt angle is between 170° and 180°, serving as an indicator of extreme tilt.
- **Real-Time Data Display**: Angle data is displayed via the Serial Monitor for debugging or monitoring purposes.

## How It Works
1. The MPU6050 IMU sensor measures acceleration and gyroscope data.
2. The system calculates the tilt angle using the acceleration data on the Y and Z axes.
3. The calculated angle is used to control the position of a servo motor.
4. When the tilt angle is between 170° and 180°, the LED connected to the system is turned on. If the angle moves out of this range, the LED is turned off.
5. Real-time tilt angle data is printed to the Serial Monitor for visualization.

## Hardware Requirements
- **MPU6050 IMU Sensor**: To measure tilt angle (connected via I2C).
- **Servo Motor**: Controlled by the tilt angle, connected to pin 9.
- **LED**: To indicate when the tilt angle is within a certain range, connected to pin 3.
- **Microcontroller**: Arduino, ESP8266, or ESP32.
- **Jumper Wires** and **Breadboard** for connections.

## Pin Connections
- **MPU6050**: Connect to the I2C pins (SDA, SCL) of your microcontroller.
- **Servo Motor**: Connected to pin 9 of the microcontroller.
- **LED**: Connected to pin 3 of the microcontroller.

## Software Requirements
- **Arduino IDE**: To write and upload the code.
- **MPU6050 and Servo Libraries**: Make sure to install these in the Arduino IDE.

## Project Files
- **IMU_Sensor.ino**: The Arduino sketch that handles IMU data collection, tilt angle calculation, and servo/LED control.

## How to Run
1. Set up the hardware as per the connections mentioned.
2. Open the `IMU_Sensor.ino` file in the Arduino IDE.
3. Upload the sketch to your microcontroller.
4. Open the Serial Monitor to see the tilt angle in real-time.
5. Observe the servo motor moving based on the tilt angle, and the LED lighting up when the angle is between 170° and 180°.

