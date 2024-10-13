// Pin definitions
const int trig = 9;       // Trigger pin
const int echo = 10;      // Echo pin
const int buzzPin = 11;   // Buzzer pin
const int ledPin = 12;    // LED pin

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Start serial communication at 9600 baud
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Read the echo pulse
  long timetaken = pulseIn(echo, HIGH);
  
  // Calculate distance in cm
  float distance = timetaken * 0.0343 / 2;

  // Control logic based on distance
  if (distance >= 51 && distance <= 100) {
    // Blink LED when object is between 51 and 100 cm
    digitalWrite(buzzPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
  } else if (distance >= 5 && distance <= 50) {
    // Turn on LED and buzzer when object is between 5 and 50 cm
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzPin, HIGH);
  } else {
    // Turn off both LED and buzzer
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, LOW);
  }

  // Print the distance to the Serial Monitor
  Serial.print("Distance = ");
  Serial.println(distance);
  
  delay(10);  // Short delay before next reading
}


