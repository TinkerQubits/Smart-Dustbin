#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo lidServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address 0x27 or 0x3F

#define trigPin1 9   // Hand detection sensor
#define echoPin1 10
#define trigPin2 6   // Bin fullness sensor
#define echoPin2 7

long duration;
int distance1, distance2;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Smart Dustbin");
  delay(1500);
  lcd.clear();

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  lidServo.attach(3);
  lidServo.write(0);   // Lid initially closed
}

void loop() {

  distance1 = getDistance(trigPin1, echoPin1); // Hand sensor
  distance2 = getDistance(trigPin2, echoPin2); // Bin full sensor

  Serial.print("Hand: ");
  Serial.print(distance1);
  Serial.print("  Bin: ");
  Serial.println(distance2);

  // ---------------- FULL BIN CONDITION ----------------
  if (distance2 < 15) {     // FIXED: Now works properly
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bin is FULL!");
    lidServo.write(0);      // Keep lid closed
  }
  else {

    // ---------------- HAND DETECTION ----------------
    if (distance1 < 10) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Lid Opening...");
      lidServo.write(180);  // Lid open
      delay(3000);
      
      lidServo.write(0);    // Close lid
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Lid Closed");
    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ready to Use");
    }
  }

  delay(500);
}

// -----------------------------------------------------
//  Function to measure distance of ultrasonic sensor
// -----------------------------------------------------
int getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;  // Convert to cm
}
