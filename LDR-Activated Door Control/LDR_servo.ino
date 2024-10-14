#include <Servo.h>

Servo door;               // Create a servo object
const int doorSpeed = 5;  // Speed of door movement
int doorAngle = 0;        // Current angle of the door
const int ldrPin = A0;    // Pin for the LDR
int ldrRead;              // Variable to store LDR readings

void setup() {
    Serial.begin(9600);   // Initialize serial communication
    door.attach(9);       // Attach the servo on pin 9
    door.write(doorAngle); // Set initial angle to 0
    pinMode(ldrPin, INPUT); // Set LDR pin as input
}

void loop() {
    ldrRead = analogRead(ldrPin); // Read LDR value

    if (ldrRead <= 50) {
        openDoor(); // Open the door if LDR reading is low
    } else {
        closeDoor(); // Close the door if LDR reading is high
    }

    monitor(); // Print LDR and door angle readings
    delay(10); // Short delay for stability
}

void openDoor() {
    while (doorAngle < 180) { // Open door until fully open
        doorAngle += doorSpeed; // Increment the angle
        door.write(doorAngle); // Update servo position
        monitor(); // Monitor during opening
        delay(10); // Short delay for smooth movement
    }
    delay(3000); // Wait for 3 seconds after fully opened
}

void closeDoor() {
    if (doorAngle > 0) { // Only close if the door is open
        doorAngle -= doorSpeed; // Decrement the angle
        door.write(doorAngle); // Update servo position
    }
}

void monitor() {
    Serial.print("LDR = ");
    Serial.print(ldrRead);
    Serial.print(" Angle = ");
    Serial.println(doorAngle); // Print current values
}
