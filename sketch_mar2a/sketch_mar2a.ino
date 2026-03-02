#include <NimBLEDevice.h>
#include <BleKeyboard.h>
#include <Keypad.h>

BleKeyboard bleKeyboard("ESP32deck", "kidz",100);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {20, 19, 18, 9};
byte colPins[COLS] = {21, 22, 23, 15};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  Serial.println("started");
}

void loop() {
  if(bleKeyboard.isConnected()) {
    char key = keypad.getKey();

    switch(key){
      case '1':
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_SHIFT);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_LEFT_GUI);
        bleKeyboard.press('s'); 
        delay(100);
        bleKeyboard.releaseAll();
        break;
      default:
        break;
    }
  }
}