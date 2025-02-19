Eine einfache Weboberfläche mit einem Button, gehostet auf einem ESP, um einen PC auch außerhalb des eigenen Netzwerkes zu starten.

MagicPacket.ino Template - erzeugt ein Magic Packet zum Starten eines PC's innerhalb eines Netzwerkes (benötigt wird Netzwerkname (SSID), Passwort und die MAC Adresse des zu startenden PC's)

SimpleWebServer.ino Template - stellt eine sehr simple Weboberfläche mit einem Button zur Verfügung, welche über jeden Browser nach eingabe der IP des ESP's erreicht werden kann. (benötigt wird Netzwerkname (SSID) und Passwort)

CompleteCode.ino - fertiger Code, welcher aus MagicPacket.ino und SimpleWebServer.ino passend zusammengestellt wurde - (benötigt wird Netzwerkname (SSID), Passwort und die MAC Adresse des zu startenden PC's)

Benögigt wird:
ESP8266 (Im Projekt wurde ein LONIN(WEMOS) D1 mini Pro verwendet),
Arduino Entwicklungsumgung,
USB Datenkabel
