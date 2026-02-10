#include <BleGamepad.h>

BleGamepad bleGamepad;

#define XPIN 4
#define YPIN 5
#define SW 6

void setup() {
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(115200);
  bleGamepad.begin();
}

void loop() {
  if (bleGamepad.isConnected()) {
    int xValue = analogRead(XPIN);
    int yValue = analogRead(YPIN);

    int mappedX = map(xValue, 0, 4095, -32767, 32767);
    int mappedY = map(yValue, 0, 4095, -32767, 32767);

    if (digitalRead(SW) == LOW) {
      bleGamepad.press(BUTTON_1);
    } else {
      bleGamepad.release(BUTTON_1);
    }

    bleGamepad.setX(mappedX);
    bleGamepad.setY(mappedY);
  }
  delay(10);

}
