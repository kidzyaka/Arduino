#include <Servo.h>
int angle = 0;
const int trigPin = 9;
const int echoPin = 10;

Servo servo;

void setup() {
  servo.attach(2);
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for (angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    int distance = duration * 0.0343 / 2;

    Serial.print(distance);
    Serial.println(" см");
    //delay(10);
  }

  for (angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    int distance = duration * 0.0343 / 2;

    Serial.print(distance);
    Serial.println(" см");
    //delay(10);
  }

  
}
