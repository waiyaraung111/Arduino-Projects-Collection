#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>   

Servo myservo;         
const int servoPin = 9;
const int ledPin = 3;
MPU6050 sensor;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int angle, absAngle;

void setup() { 
  myservo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
  
  Wire.begin();
  Serial.begin(9600);
  
  sensor.initialize();  // Initialize MPU6050
  delay(2);
}

void loop() { 
  sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  angle = atan2(ay, az) * (180 / PI);  // Calculate angle in degrees
  absAngle = abs(angle);
  
  Serial.print("Angle = ");
  Serial.println(absAngle);
  
  myservo.write(absAngle);  // Move servo based on absolute angle
  
  // Control LED based on angle range
  if (absAngle >= 170 && absAngle <= 180) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
