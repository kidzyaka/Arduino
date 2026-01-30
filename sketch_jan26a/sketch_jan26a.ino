#include "DHT.h"

#define DHTPIN 2
#define SENSORLEDPIN 3
#define OKLEDPIN 5
#define NOTOKLEDPIN 4
#define DHTERRORLEDPIN 9

#define DHTTYPE DHT11



DHT dht(DHTPIN, DHTTYPE);



void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(SENSORLEDPIN, OUTPUT);
  pinMode(OKLEDPIN, OUTPUT);
  pinMode(NOTOKLEDPIN, OUTPUT);
  pinMode(DHTERRORLEDPIN, OUTPUT);
  analogWrite(OKLEDPIN,5);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  setColor(170, 0, 255);
  setColor(255, 0, 0);
}

void loop() {

  
  delay(2500);
  
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)){
    for (int i = 0; i <= 3; i++){
      digitalWrite(DHTERRORLEDPIN, HIGH);
      delay(50);
      digitalWrite(DHTERRORLEDPIN, LOW);
      delay(50);
    }
  }

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

  if (h < 30){
    setColor(255, 200, 0);
  } else if (h > 65) {
    setColor(0, 200, 255);
  } else {
    setColor(170, 0, 255);
  }



  Serial.print("Температура: ");
  Serial.print(t);
  Serial.print("\nВлажность:");
  Serial.print(h);
  Serial.print("\n");
}

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(6, redValue); 
  analogWrite(7,  greenValue); 
  analogWrite(8, blueValue);
}
