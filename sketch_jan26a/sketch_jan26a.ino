#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 2
#define SENSORLEDPIN 3
#define DHTERRORLEDPIN 9

#define DHTTYPE DHT11



DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(SENSORLEDPIN, OUTPUT);
  pinMode(DHTERRORLEDPIN, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
}

void loop() {

  
  delay(2500);
  
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  lcd.setCursor(12,0);
  lcd.print("    ");
  lcd.setCursor(12,0);
  lcd.print(t);

  lcd.setCursor(12,1);
  lcd.print("    ");
  lcd.setCursor(12,1);
  lcd.print(h);

  digitalWrite(SENSORLEDPIN,HIGH);
  delay(100);
  digitalWrite(SENSORLEDPIN, LOW);
  delay(100);


  if (isnan(h) || isnan(t)) {
    digitalWrite(DHTERRORLEDPIN, HIGH);
    delay(30);
    digitalWrite(DHTERRORLEDPIN, LOW);
  }


  Serial.print("Температура: ");
  Serial.print(t);
  Serial.print("\nВлажность:");
  Serial.print(h);
  Serial.print("\n");
}
