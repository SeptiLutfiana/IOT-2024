#include <DHT.h>


#define BLYNK_TEMPLATE_ID "TMPL6_qNu-toC"
#define BLYNK_TEMPLATE_NAME "SENSOR SUHU DAN KELEMBABAN"
#define BLYNK_AUTH_TOKEN "534nY8f6DLJtrVok9NLDrjKlBNjrk-Uo2"


#define DHTPIN 18
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Menggunakan DHT11");
}

void loop() {
  delay(2000);
float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);

if (isnan(h) || isnan(t) || isnan(f))
{
  Serial.println("Failed to read from DHT sensor!");
  return;
}

float hif = dht.computeHeatIndex(f, h);
float hic = dht.computeHeatIndex(t, h, false);

Serial.print(F("Humidity: "));
Serial.print(h);
Serial.print(F("%  Temperature: "));
Serial.print(t);
Serial.print(F("°C "));
Serial.print(f);
Serial.print(F("°F  Heat index: "));
Serial.print(hic);
Serial.print(F("°C "));
Serial.print(hif);
Serial.println(F("°F"));
}