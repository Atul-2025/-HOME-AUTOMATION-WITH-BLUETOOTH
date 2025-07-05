#define BLYNK_TEMPLATE_ID "TMPL3sBj1Zbsp"
#define BLYNK_TEMPLATE_NAME "Home automation"
#define BLYNK_AUTH_TOKEN "4m0ffdE4XAeOVlLhmHWMftniTONpLj7Q"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "4m0ffdE4XAeOVlLhmHWMftniTONpLj7Q";
char ssid[] = "Redmi 9A";//Enter your WIFI name
char pass[] = "123456abc";//En

const int relayPins[] = {D0, D1, D2, D3};

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Blynk.begin(auth, ssid, pass);
  for (int i = 0; i < 4; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH); // Initialize relays as OFF
  }
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(D0, !value);
  Serial.println(value ? "Relay 1 ON" : "Relay 1 OFF");
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(D1, !value);
  Serial.println(value ? "Relay 2 ON" : "Relay 2 OFF");
}

BLYNK_WRITE(V3) {
  int value = param.asInt();
  digitalWrite(D2, !value);
  Serial.println(value ? "Relay 3 ON" : "Relay 3 OFF");
}

BLYNK_WRITE(V4) {
  int value = param.asInt();
  digitalWrite(D3, !value);
  Serial.println(value ? "Relay 4 ON" : "Relay 4 OFF");
}

void loop() {
  Blynk.run();
}
