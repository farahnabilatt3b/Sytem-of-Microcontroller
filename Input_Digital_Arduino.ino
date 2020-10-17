#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int GAS_SENSOR_LOW=3;
int BLUE_LED=4;
int YELLOW_LED=5; 

void setup() {
  // put your setup code here, to run once:
pinMode(GAS_SENSOR_LOW, INPUT_PULLUP);
pinMode(YELLOW_LED, OUTPUT);
pinMode(BLUE_LED, OUTPUT);
lcd.begin(20,4);
lcd.setCursor(0,0);
lcd.print("SISTEM PENDETEKSI");
lcd.setCursor(0,1);
lcd.print("ALCOHOL");
lcd.setCursor(0,2);
lcd.print("TELEKOMUNIKASI PNJ");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
int GAS_SENSOR_LOW_READ = digitalRead(GAS_SENSOR_LOW);
if (GAS_SENSOR_LOW_READ == LOW)
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("ALCOHOL DETECTED");
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  delay(10);
}
else
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("MOTION NOT DETECTED");
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  delay(10);
  }
}
