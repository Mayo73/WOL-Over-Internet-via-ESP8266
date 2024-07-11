#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Netzwerkinformationen
const char* ssid = "Netzwerkname";
const char* password = "WLAN Passwort";

// MAC-Adresse des Zielgeräts
byte mac[] = {0x1C, 0x2B, 0x30, 0x42, 0x5D, 0xF3}; //Beispiel

void setup() {
  // Verbindung zum WLAN herstellen
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Verbindung zum WLAN...");
  }

  // WOL Magic Packet erstellen
  byte magicPacket[102];
  for (int i = 0; i < 6; i++) {
    magicPacket[i] = 0xFF;
  }
  for (int i = 1; i <= 16; i++) {
    for (int j = 0; j < 6; j++) {
      magicPacket[i * 6 + j] = mac[j];
    }
  }

  // WOL Magic Packet senden
  WiFiUDP udp;
  udp.beginPacketMulticast(IPAddress(255, 255, 255, 255), 9, WiFi.localIP());
  udp.write(magicPacket, 102);
  udp.endPacket();
}

void loop() {
  // Nichts zu tun
}