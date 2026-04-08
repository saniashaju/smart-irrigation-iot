#define BLYNK_TEMPLATE_ID "TMPL3XBZjoscx"
#define BLYNK_TEMPLATE_NAME "Soil Moisture Monitor"
#define BLYNK_AUTH_TOKEN "k1QWGceZpIi2XOW5Ve2a3kgxcMmPw0ZQ"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Kerala Vision";   // WiFi name
char pass[] = "babu@3164";       // WiFi password

#define SOIL_PIN 34   // AO of soil sensor → GPIO34 on ESP32
#define RELAY_PIN 26  // IN pin of relay → GPIO26 (you can change if needed)

BlynkTimer timer;

void sendSensor()
{
  int soilValue = analogRead(SOIL_PIN);         
  int percent = map(soilValue, 0, 4095, 100, 0); // 100 = dry, 0 = wet

  Serial.print("Soil raw: ");
  Serial.print(soilValue);
  Serial.print(" | Soil %: ");
  Serial.println(percent);

  // Send soil percentage to Blynk
  Blynk.virtualWrite(V0, percent);

  // Automatic irrigation logic
  if (percent > 60)  // If soil is dry (>60%)
  {
    digitalWrite(RELAY_PIN, LOW);   // Relay ON (pump starts)
    Serial.println("Soil dry → Pump ON");
  }
  else  // Soil is wet
  {
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF (pump stops)
    Serial.println("Soil wet → Pump OFF");
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // keep pump OFF initially

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Read and send soil data every 1 second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
