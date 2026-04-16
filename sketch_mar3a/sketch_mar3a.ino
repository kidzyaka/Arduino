#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // Объект датчика

void setup() {
  Serial.begin(9600);
  
  // Инициализация датчика по адресу 0x76 или 0x77
  if (!bme.begin(0x76)) {
    Serial.println("Датчик не найден! Проверьте контакты.");
    while (1);
  }
}

void loop() {
  Serial.print("Температура: ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("Влажность: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Давление: ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.println("---");
  delay(2000);
}