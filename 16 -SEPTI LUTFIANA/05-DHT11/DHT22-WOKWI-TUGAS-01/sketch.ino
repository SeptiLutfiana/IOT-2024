#include <DHT.h>

#define BLYNK_TEMPLATE_ID "TMPL6_qNu-toC"
#define BLYNK_TEMPLATE_NAME "SENSOR SUHU DAN KELEMBABAN"
#define BLYNK_AUTH_TOKEN "534nY8f6DLJtrVok9NLDrjKlBNjrk-Uo2"

#define DHTPIN 18
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int lampu = 12; // Pin connected to the lamp
float hum;
float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(lampu, OUTPUT); // Set lampPin as output
}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  ");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C  ");

  // Konversi ke Kelvin
  float tempKelvin = temp + 273.15;
  Serial.print("Temperature (Kelvin): ");
  Serial.print(tempKelvin);
  Serial.print("K  ");

  // Konversi ke Reaumur
  float tempReaumur = temp * 0.8;
  Serial.print("Temperature (Reaumur): ");
  Serial.print(tempReaumur);
  Serial.print("°Ré  ");
  
  if (temp > 30) {
    digitalWrite(lampu, HIGH); // Turn on the lamp
  } else {
    digitalWrite(lampu, LOW); // Turn off the lamp
  }

  Serial.println();
  delay(2000);
}
