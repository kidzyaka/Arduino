#include <Arduino.h>

#define XPIN 4
#define YPIN 5

void setup() {
  Serial.begin(115200);
}

void loop() {
  int xValue = analogRead(XPIN);
  int yValue = analogRead(YPIN);
  
  
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print("Y: ");
  Serial.println(yValue);
  
  delay(500);
}
