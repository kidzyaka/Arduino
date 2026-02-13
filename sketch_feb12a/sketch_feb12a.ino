#include <Servo.h>
int angle = 0;
Servo servo;

void setup() {
  servo.attach(2);

}

void loop() {
  for (angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    delay(10);
  }

  for (angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    delay(10);
  }
}
