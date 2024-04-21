const int LED_PIN = 13; // Pin digital Arduino yang terhubung ke LED

void setup() {
  pinMode(LED_PIN, OUTPUT); // Mengatur pin sebagai OUTPUT
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Menyalakan LED
  delay(1000); // Menunda selama 1 detik
  digitalWrite(LED_PIN, LOW); // Mematikan LED
  delay(1000); // Menunda selama 1 detik
}