#include <SoftwareSerial.h>
SoftwareSerial atmega(2, 3);

void setup() {
  Serial.begin(9600);
  atmega.begin(9600);
}

void loop() {
  if(atmega.available()) {
    Serial.write(atmega.read());
  }
}
