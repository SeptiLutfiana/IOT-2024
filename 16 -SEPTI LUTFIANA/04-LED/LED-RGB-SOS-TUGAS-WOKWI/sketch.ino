#include <Arduino.h>

#define RED_LED_PIN 6    // Pin LED merah
#define GREEN_LED_PIN 5  // Pin LED RGB (hijau)
#define BLUE_LED_PIN 4   // Pin LED biru (ESP32)

void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED_PIN, OUTPUT);    // Atur pin digital sebagai output
  pinMode(GREEN_LED_PIN, OUTPUT);  // Atur pin digital sebagai output
  pinMode(BLUE_LED_PIN, OUTPUT);   // Atur pin digital sebagai output

  Serial.println("Contoh Program LED SOS");
}

void loop()
{
  // 3 dits (3 titik atau huruf S) pada LED merah
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED_PIN, HIGH);    // LED merah nyala
    delay(150);                         // Delay selama 150ms
    digitalWrite(RED_LED_PIN, LOW);     // LED merah mati
    delay(100);                         // Delay selama 100ms
  }
  delay(100);

  // 3 dahs (3 garis atau huruf O) pada LED merah
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED_PIN, HIGH);    // LED merah nyala
    delay(400);                         // Delay selama 400ms
    digitalWrite(RED_LED_PIN, LOW);     // LED merah mati
    delay(100);                         // Delay selama 100ms
  }

  // 100ms delay untuk memberikan jarak antar huruf
  delay(100);

  // 3 dits lagi (3 titik atau huruf S) pada LED merah
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED_PIN, HIGH);    // LED merah nyala
    delay(150);                         // Delay selama 150ms
    digitalWrite(RED_LED_PIN, LOW);     // LED merah mati
    delay(100);                         // Delay selama 100ms
  }

  // Mengontrol LED RGB (hijau)
  digitalWrite(GREEN_LED_PIN, HIGH);    // Hidupkan LED hijau
  delay(1500);                          // Delay selama 1.5 detik
  digitalWrite(GREEN_LED_PIN, LOW);     // Matikan LED hijau

  // Mengontrol LED biru pada ESP32
  digitalWrite(BLUE_LED_PIN, HIGH);     // Hidupkan LED biru
  delay(1500);                          // Delay selama 1.5 detik
  digitalWrite(BLUE_LED_PIN, LOW);      // Matikan LED biru

  // Tunggu 5 detik sebelum mengulangi sinyal SOS
  delay(5000);
}