#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  WiFi.STA.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(40,0);
  display.println(F("WiFi Scan"));
  display.drawLine(4,10, 124, 10, SSD1306_WHITE);
  display.display();
  display.setCursor(0, 18);

}

void loop() {
  int n = WiFi.scanNetworks();

  for (int i = 0; i < n; ++i) {

    String line = WiFi.SSID(i) + " | " + String(WiFi.RSSI(i)) + " dBm | " + "Ch: " + String(WiFi.channel(i));
    display.println(line);
    display.display();
    Serial.println(line);
    delay(10);
  }

  delay(10000);
}