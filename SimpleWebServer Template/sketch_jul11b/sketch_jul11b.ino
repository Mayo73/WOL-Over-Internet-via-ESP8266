#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Ersetzen Sie diese mit Ihren eigenen Netzwerkinformationen
const char* ssid = "Netzwerkname";
const char* password = "WLAN Passwort";

ESP8266WebServer server(80);  // Server auf Port 80

void handleRoot() {
  String html = "<html>\
    <body>\
      <button onclick='window.location.href=\"/button\"'>Klicken Sie mich</button>\
    </body>\
  </html>";
  server.send(200, "text/html", html);
}

void handleButton() {
  // Führen Sie hier Ihre serverseitige Aktion aus
  server.send(200, "text/plain", "Der Button wurde geklickt!");
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

  //server.on("/",  {
  //  server.send(200, "text/html", "Hallo Welt! Dies ist mein ESP8266 Webserver.")});
}
  

void loop() {
  server.handleClient();
}

