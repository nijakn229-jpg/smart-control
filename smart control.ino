#define BLYNK_TEMPLATE_ID "TMPL34oZpjpx1"
#define BLYNK_TEMPLATE_NAME "4 relay"
#define BLYNK_AUTH_TOKEN "4nMQh8Z2AIv_AGYAWg-GTagcKz-IgZIN"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi Credentials
char ssid[] = "Airtel_LPoint";
char pass[] = "techkatj7Z1";

// Relay control pins
#define RELAY_LED1    5    // GPIO5 (D1) -> IN1 (LED 1)
#define RELAY_BUZZER 14    // GPIO14 (D5) -> IN2 (Buzzer)
#define RELAY_FAN    12    // GPIO12 (D6) -> IN3 (Fan)
#define RELAY_LED2    4    // GPIO4 (D2) -> IN4 (LED 2)

// Blynk virtual pin handlers
BLYNK_WRITE(V0) {
  digitalWrite(RELAY_FAN, param.asInt() ? LOW : HIGH);   // active LOW
}

BLYNK_WRITE(V1) {
  digitalWrite(RELAY_LED1, param.asInt() ? LOW : HIGH);  // active LOW
}

BLYNK_WRITE(V2) {
  digitalWrite(RELAY_LED2, param.asInt() ? LOW : HIGH);  // active LOW
}

BLYNK_WRITE(V3) {
  digitalWrite(RELAY_BUZZER, param.asInt() ? LOW : HIGH); // active LOW
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set pin modes
  pinMode(RELAY_LED1, OUTPUT);
  pinMode(RELAY_BUZZER, OUTPUT);
  pinMode(RELAY_FAN, OUTPUT);
  pinMode(RELAY_LED2, OUTPUT);

  // Set all relays OFF initially
  digitalWrite(RELAY_LED1, HIGH);
  digitalWrite(RELAY_BUZZER, HIGH);
  digitalWrite(RELAY_FAN, HIGH);
  digitalWrite(RELAY_LED2, HIGH);

  // Sync states from Blynk app
  Blynk.syncVirtual(V0, V1, V2, V3);
}

void loop() {
  Blynk.run();
}
