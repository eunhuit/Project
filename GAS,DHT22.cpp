#include "DHT.h"

int GasPin = A0;
int Gas = 0;
DHT dht(2, DHT22);

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
  Serial.println(Gas);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C ");
  delay(1000);  
}
