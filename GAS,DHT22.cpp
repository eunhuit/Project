#include "DHT.h"
#include <PMS.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>


int GasPin = A0;
int Gas = 0;
DHT dht(2, DHT22);
SoftwareSerial nockanda(9,10);

PMS pms(nockanda);
PMS::DATA data;

void setup()
{
  Serial.begin(115200); 
  nockanda.begin(9600);
  pinMode(GasPin, INPUT);
  dht.begin();
}

void loop()
{
  if (pms.read(data))
  {
    Serial.print("1");
    delay(1000);
    Serial.print("0");
    delay(1000); 
    float mesei = data.PM_AE_UG_10_0;
    float chomesei = data.PM_AE_UG_2_5;
    float gukchomesei = data.PM_AE_UG_1_0;
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Gas = analogRead(GasPin);
    Serial.print("온도:");
    Serial.println(h);
    Serial.print("습도:");
    Serial.println(t);
    Serial.print("가스농도:");
    Serial.println(Gas);    
    Serial.print("미세먼지:");
    Serial.println(mesei);
    Serial.print("초미세먼지:");
    Serial.println(chomesei);
    Serial.print("극초미세먼지:");
    Serial.println(gukchomesei);

    Serial.println();
  }else{
    //Serial.print("FUCK");
  }

}
