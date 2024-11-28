#include "DHT.h"
#include <LiquidCrystal_I2C.h>

int GasPin = A0;
int Gas = 0;
DHT dht(2, DHT22);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(GasPin, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float hic = dht.computeHeatIndex(t, h, false);
  Gas = analogRead(GasPin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.setCursor(5, 0);
  lcd.print(Gas);
  lcd.setCursor(0, 1);
  lcd.print("H: ");
  lcd.setCursor(2, 1);
  lcd.print(h);
  lcd.setCursor(6, 1);
  lcd.print("%");
  lcd.setCursor(7, 1);
  lcd.print("T: ");
  lcd.setCursor(9, 1);
  lcd.print(t);
  lcd.setCursor(14, 1);
  lcd.print("*C");
  delay(1000);
}
