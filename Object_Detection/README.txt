# Ultrasonic Distance Sensor with Buzzer and LED

This Arduino project uses an ultrasonic sensor to measure the distance of an object and triggers an LED and a buzzer based on the distance detected. The project is ideal for simple proximity detection systems like obstacle avoidance or distance alarms.

## Features
- Measures distance using an ultrasonic sensor (HC-SR04 or similar).
- Turns on an LED and buzzer when an object is detected within a certain range.
- Blinks the LED for objects detected at medium range.
- Displays the distance on the Serial Monitor for debugging and visualization.

## Components Used
- Arduino Uno (or compatible board)
- Ultrasonic Sensor (HC-SR04)
- Buzzer
- LED
- Jumper wires
- Breadboard

## Pin Configuration
- **Trigger Pin (Trig):** Pin 9
- **Echo Pin (Echo):** Pin 10
- **Buzzer Pin:** Pin 11
- **LED Pin:** Pin 12

## Working Principle
The ultrasonic sensor sends out a sound wave from the **trigger pin**, and the **echo pin** measures how long it takes for the sound to return after bouncing off an object. This time is used to calculate the distance of the object.

Based on the measured distance:
- If the object is between **51 cm and 100 cm**, the LED blinks, and the buzzer stays off.
- If the object is between **5 cm and 50 cm**, the LED and the buzzer are turned on.
- If the object is out of this range, both the LED and buzzer are turned off.

## Circuit Diagram
(Include a link or image of the circuit diagram here if possible)

## Setup Instructions

1. **Hardware Setup:**
    - Connect the **Trig pin** of the ultrasonic sensor to pin 9 on the Arduino.
    - Connect the **Echo pin** of the ultrasonic sensor to pin 10 on the Arduino.
    - Connect the **Buzzer** to pin 11.
    - Connect the **LED** to pin 12.
    - Power the sensor and other components using the 5V and GND pins on the Arduino.

2. **Software Setup:**
    - Install the Arduino IDE from the official [Arduino website](https://www.arduino.cc/en/software).
    - Connect your Arduino to your computer using a USB cable.
    - Upload the provided code from `distance_sensor.ino` to your Arduino.

3. **Testing:**
    - Open the Serial Monitor in the Arduino IDE (Ctrl + Shift + M) to see the distance readings.
    - Place objects at varying distances from the sensor to see how the LED and buzzer react.

## Code Explanation

- The **trigger pin** is used to send a pulse from the ultrasonic sensor.
- The **echo pin** listens for the pulse to return and measures the time taken.
- The **distance** is calculated using the formula:
  ```
  distance = timetaken * 0.0343 / 2;
  ```
  Where 0.0343 cm/μs is the speed of sound in air.

- Based on the distance, the LED and buzzer are turned on or off:
  - **5 cm ≤ distance ≤ 50 cm:** LED and buzzer both ON.
  - **51 cm ≤ distance ≤ 100 cm:** LED blinks, buzzer OFF.
  - **distance > 100 cm or < 5 cm:** LED and buzzer both OFF.

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/ultrasonic-sensor-project.git
   ```

2. Open the `.ino` file in the Arduino IDE.

3. Upload the code to your Arduino.

4. Observe the LED and buzzer react to objects placed in front of the ultrasonic sensor. You can monitor the distance readings through the Serial Monitor.

## License
This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

## Contributing
Feel free to fork this repository and contribute by submitting pull requests. For major changes, please open an issue first to discuss what you would like to change.

## Acknowledgments
- Inspired by various Arduino ultrasonic sensor tutorials.
- Special thanks to the Arduino community for providing excellent resources and support.

