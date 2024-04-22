#include <Arduino.h>

#define RED_LED 6 // Led warna merah
#define GREEN_LED 5 // Led warna hijau
#define BLUE_LED 2 // Led warna biru

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT); // Atur pin-pin digital sebagai output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.println("Contoh Program LED RGB");
}

void rgbLED() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  Serial.println("LED Merah nyala");
  delay(1000);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  Serial.println("LED Hijau nyala");
  delay(1000);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  Serial.println("LED Biru nyala");
  delay(1000);
}

void loop() {
  rgbLED();
}
