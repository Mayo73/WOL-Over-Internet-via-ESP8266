#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>

// Ersetzen Sie diese mit Ihren eigenen Netzwerkinformationen
const char* ssid = "Netzwerkname";
const char* password = "WLAN Passwort";

// MAC-Adresse des Zielgeräts
byte mac[] = {0x1C, 0x2B, 0x30, 0x42, 0x5D, 0xF3}; //BEISPIEL

ESP8266WebServer server(80);  // Server auf Port 80

void handleRoot() {
  String html = "<html>\
    <body>\
      <button onclick='window.location.href=\"/button\"'>PC Starten</button>\
    </body>\
  </html>";
  server.send(200, "text/html", html);
}

void handleButton() {
// Führen Sie hier Ihre serverseitige Aktion aus

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

  server.send(200, "text/plain", "Anfrage gesendet!");
}

void setup() {
  Serial.begin(115200);
  delay(10);

  // Verbinden Sie mit WiFi-Netzwerk
  Serial.println();
  Serial.println();
  Serial.print("Verbindung zu ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi verbunden");

  // Starten Sie den Server
  server.begin();
  Serial.println("Server gestartet");

  // Drucken Sie die IP-Adresse
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/button", handleButton);

}
  

void loop() {
  server.handleClient();
}

