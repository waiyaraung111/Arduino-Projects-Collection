# LDR-Activated Door Control

## Overview

The **Smart Door Opener** is an innovative door control system that utilizes a Light Dependent Resistor (LDR) to detect light levels and automatically open or close a servo-operated door based on the surrounding light conditions. This project is ideal for automating access to rooms or spaces based on the presence of light, enhancing convenience and energy efficiency.

## Features

- **Automatic Door Operation**: Opens the door when the light level is low (indicating the presence of an object or person) and closes it when the light level is high.
- **Real-time Monitoring**: Displays current LDR readings and door angle on the serial monitor for debugging and monitoring purposes.
- **Smooth Servo Control**: Gradual door movement for a gentle opening and closing experience.
- **Customizable Threshold**: Adjustable LDR threshold for sensitivity based on your needs.

## Components Required

- Arduino board (e.g., Arduino Uno)
- Servo motor
- Light Dependent Resistor (LDR)
- Resistor (10kΩ recommended for voltage divider)
- Jumper wires
- Breadboard (optional)

## Wiring Diagram

1. Connect the LDR in series with the resistor to create a voltage divider:
   - One end of the LDR to 5V.
   - The other end of the LDR to one end of the resistor and to the analog input pin (A0).
   - Connect the other end of the resistor to GND.
   
2. Connect the servo motor:
   - The servo signal wire to digital pin 9.
   - The power wire to 5V.
   - The ground wire to GND.

## Setup Instructions

1. Install the Arduino IDE on your computer if you haven't already.
2. Open the IDE and create a new sketch.
3. Copy and paste the provided code into the sketch.
4. Connect your Arduino board to the computer using a USB cable.
5. Select the appropriate board and port in the Arduino IDE.
6. Upload the code to the Arduino.

## Usage

1. Once the code is uploaded, open the Serial Monitor in the Arduino IDE.
2. Adjust the light conditions around the LDR to test the door's response:
   - Cover the LDR to simulate low light and trigger the door opening.
   - Remove the cover to simulate high light and trigger the door closing.
3. Observe the real-time readings of the LDR and the door angle in the Serial Monitor.

## Customization

- **Threshold Adjustment**: You can modify the `if (ldrRead <= 50)` line in the `loop()` function to change the sensitivity of the light detection.
- **Door Speed**: Adjust the `doorSpeed` variable to change how quickly the door opens or closes.

## Conclusion

The **Smart Door Opener** project is a fun and practical application of Arduino and servo control technology. You can expand its functionality by integrating additional sensors or creating a more sophisticated control logic based on your needs.


