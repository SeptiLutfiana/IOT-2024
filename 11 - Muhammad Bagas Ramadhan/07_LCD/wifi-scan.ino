#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Inisialisasi pin untuk LED
const int blueLedPin = 26;
const int greenLedPin = 25;
const int redLedPin = 27;

// Inisialisasi pin data untuk sensor DHT22
const int dhtPin = 21;

// Inisialisasi alamat I2C untuk LCD
const int i2cAddr = 0x27;
const int lcdCols = 16;
const int lcdRows = 2;

// Inisialisasi objek LCD
LiquidCrystal_I2C lcd(i2cAddr, lcdCols, lcdRows);

// Inisialisasi objek sensor DHT22
DHT dht(dhtPin, DHT22);

void setup() {
  // Set pin-mode LED
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Setup LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Temperature:");

  // Inisialisasi sensor DHT22
  dht.begin();
}

void loop() {
  // Baca data suhu dari sensor DHT22
  float temperature = dht.readTemperature();

  // Tampilkan suhu di LCD
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print(" C   ");

  // Kontrol LED sesuai dengan suhu
  if (temperature < 17) {
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  } else if (temperature >= 17 && temperature <= 27) {
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  } else {
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  }

  delay(1000);
}
