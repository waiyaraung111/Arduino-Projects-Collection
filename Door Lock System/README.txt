# Door Lock System with Keypad and LCD

## Overview

This project is a Door Lock System that uses a keypad for user input and an LCD to display messages. The system allows users to unlock the door using a predefined password, change the password, and lock the door using a relay. The password is stored in EEPROM, allowing it to persist even when the device is powered off.

## Components Required

- **Arduino Board** (e.g., Arduino Uno)
- **4x4 Keypad**
- **Liquid Crystal Display (LCD) with I2C interface**
- **Relay Module**
- **Breadboard and Jumper Wires**
- **Resistor (optional, for the keypad if needed)**

## Circuit Diagram

[Include a circuit diagram or schematic image here.]

## Libraries Used

- **Keypad**: For managing input from the keypad.
- **LiquidCrystal_I2C**: For controlling the LCD display.
- **EEPROM**: For storing the password.

## Installation

1. **Install Arduino IDE**: Make sure you have the latest version of the Arduino IDE installed on your computer.
   
2. **Install Required Libraries**: 
   - Open the Arduino IDE.
   - Go to `Sketch > Include Library > Manage Libraries`.
   - Search for and install the following libraries:
     - **Keypad** by Mark Stanley and Alexander Brevig.
     - **LiquidCrystal I2C** by Frank de Brabander.

3. **Clone or Download the Repository**: 
   - Clone the repository using:
     ```bash
     git clone https://github.com/your-username/your-repository.git
     ```
   - Alternatively, download the ZIP file and extract it.

4. **Open the Project**: Open `DoorLockSystem.ino` in the Arduino IDE.

5. **Upload the Code**: Connect your Arduino board and upload the code.

## Usage

1. **Initial Setup**: 
   - The system will display a welcome message. The default password is `1234`. You can change it after the first run.

2. **Unlocking the Door**:
   - Press `*` to enter the password.
   - Enter the password using the keypad. If correct, the door will unlock for 3 seconds.

3. **Changing the Password**:
   - Press `#` to change the password.
   - Enter the old password, followed by the new password twice to confirm.

4. **Locking the Door**:
   - Press `B` to lock the door.

## Code Explanation

- The main code structure includes functions for entering the password, opening the door, changing the password, and confirming the new password.
- The password is stored in an array and is managed using the EEPROM library to retain the value even after power loss.
  
### Code Functions:

- `EnterPassword()`: Prompts the user to enter the password.
- `OpenDoor()`: Unlocks the door for 3 seconds.
- `ChangePassword()`: Allows the user to change the password.
- `GetNewPassword1()`: Collects the new password input from the user.
- `GetNewPassword2()`: Confirms the new password input.

## Troubleshooting

- If the system doesn't compile, ensure that all required libraries are correctly installed.
- Check the wiring connections if the LCD or keypad is not responding.
- If the relay doesn't activate, verify the relay module connections and ensure it is powered correctly.

## Conclusion

This Door Lock System project provides a practical implementation of security using Arduino. It demonstrates the use of keypads and LCDs, along with EEPROM for data storage.

---

### **License**

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

