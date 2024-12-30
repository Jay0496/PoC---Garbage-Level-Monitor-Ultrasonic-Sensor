#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Ultrasonic sensor pins
const int trigPin = 7;
const int echoPin = 6;

// LED pin
const int ledPin = 13;

// Voltage reading pin
const int voltagePin = A0;

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Battery thresholds
const float maxVoltage = 5.0;   // Full battery voltage
const float minVoltage = 3.3;  // Minimum operating voltage

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Read battery voltage
  int voltageReading = analogRead(voltagePin);
  float batteryVoltage = voltageReading * (5.0 / 1023.0) * 2; // *2 for voltage divider

  // Calculate battery life percentage
  float batteryLife = ((batteryVoltage - minVoltage) / (maxVoltage - minVoltage)) * 100;
  if (batteryLife > 100) {
    batteryLife = 100; // Clamp to 100%
  } else if (batteryLife < 0) {
    batteryLife = 0; // Clamp to 0%
  }

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm");

  lcd.setCursor(0, 1);
  lcd.print("Batt: ");
  lcd.print(batteryLife, 0); // Display as whole number
  lcd.print("%");

  // LED logic
  if (distance < 10) { // If distance < 10 cm, turn on LED
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // Update every second
}
