#include <Servo.h>

const int ldrAnalogPin = 7;    // Connect the LDR analog output pin to analog pin A0
const int servoPin = 9;         // Connect the servo signal pin to digital pin 9

Servo myServo;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrAnalogPin);

  // Map LDR value to servo angle
  int servoAngle = map(ldrValue, 0, 1023, 0, 180);

  // Limit servo angle to prevent damage
  servoAngle = constrain(servoAngle, 0, 180);

  // Move the servo to the calculated angle
  myServo.write(servoAngle);

  // Print LDR value and servo angle to Serial Monitor
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print("\t Servo Angle: ");
  Serial.println(servoAngle);

  delay(100);  // Adjust the delay as needed
}
