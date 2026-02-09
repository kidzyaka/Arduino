#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);

const char* ssid = "ESP";
const char* password = "12wdff7n4";

void setup() {
  pixel.setBrightness(20);
  pixel.begin();
  pixel.clear();
  pixel.show();
  Serial.begin(115200);
  pixel.setPixelColor(0,251,255,0);
  pixel.show();
  Serial.println("Запуск AP...");
  pixel.setPixelColor(0,255,166,0);
  pixel.show();
  bool APstatus = WiFi.softAP(ssid, password);
  
  if(APstatus) {
    pixel.setPixelColor(0,30,255,0);
    pixel.show();
    Serial.println("AP запущена:");
    Serial.println(ssid);
    Serial.println(password);
    Serial.println("Адресс AP:");
    Serial.println(WiFi.softAPIP());
  } else {
    pixel.setPixelColor(0,255,0,0);
    pixel.show();
    Serial.println("Что-то сломалось");
  }
}

void loop() {
  for (int brightness = 0; brightness <= 150; brightness++) {
    pixel.setPixelColor(0, 0, 0, brightness);
    pixel.show();
    delay(10);
  }

  for (int brightness = 150; brightness >= 0; brightness--) {
    pixel.setPixelColor(0, 0, 0, brightness);
    pixel.show();
    delay(10);
  }
}
