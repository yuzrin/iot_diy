
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
// You  get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "mXKfE7UMfuzhhNAJVxL7P6x3qH-kcRua";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TP-LINK_B0FF54";
char pass[] = "79959070";

#define DHTTYPE DHT11
#define DHTPIN 14

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  timer.run();
}
