#include "DHT.h"

#define DHTPIN 2
#define SENSORLEDPIN 3
#define OKLEDPIN 5
#define NOTOKLEDPIN 4

#define DHTTYPE DHT11



DHT dht(DHTPIN, DHTTYPE);



void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(SENSORLEDPIN, OUTPUT);
  pinMode(OKLEDPIN, OUTPUT);
  pinMode(NOTOKLEDPIN, OUTPUT);
  analogWrite(OKLEDPIN,5);
}

void loop() {

  
  delay(2500);
  
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  digitalWrite(SENSORLEDPIN,HIGH);
  delay(100);
  digitalWrite(SENSORLEDPIN, LOW);
  delay(100);

  if (t > 22 || t < 18){
    digitalWrite(NOTOKLEDPIN, HIGH);
    digitalWrite(OKLEDPIN,LOW);
  } else {
    digitalWrite(NOTOKLEDPIN, LOW);
    analogWrite(OKLEDPIN, 5);
  }


  Serial.print("Температура: ");
  Serial.print(t);
  Serial.print("\nВлажность:");
  Serial.print(h);
  Serial.print("\n");
}
