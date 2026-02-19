#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>



#define SDA_PIN 21

#define SCL_PIN 22



#define SCREEN_WIDTH 128

#define SCREEN_HEIGHT 64



int i;



Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



void setup() {

Serial.begin(115200);



if (!Wire.begin(SDA_PIN, SCL_PIN)) {

Serial.println("Failed to initialize I2C");

while(1);

  }



if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 

Serial.println(F("SSD1306 allocation failed"));

for(;;);

  }



  display.clearDisplay();

  display.display();

}



void loop() {



  i++;



  display.clearDisplay();



  display.setCursor(0, 0);

  display.println(i);

  display.display(); 

  delay(1000);

}