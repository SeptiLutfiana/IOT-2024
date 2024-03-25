#define ledRed  D5
#define ledGreen  D6
#define ledBlue  D7

void setup() {
  // Mengatur pin LED sebagai output
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600); // Memulai komunikasi serial dengan kecepatan 9600 bps
}

void loop() {
  // Mengirim kode SOS menggunakan LED merah
  blinkSOS(ledRed, 1000); // Menggunakan fungsi blinkSOS() untuk mengirim kode SOS

  // Mengirim kode SOS menggunakan LED hijau (RGB)
  blinkSOS_RGB(ledGreen, 500); // Menggunakan fungsi blinkSOS_RGB() untuk mengirim kode SOS

  // Mengirim kode SOS menggunakan LED biru
  blinkSOS(ledBlue, 1000); // Menggunakan fungsi blinkSOS() untuk mengirim kode SOS
}

void blinkSOS(int pin, int delayTime) {
  // Mengirim kode SOS menggunakan LED dengan penundaan waktu tertentu
  for (int i = 0; i < 3; i++) {
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
  delay(delayTime * 2);
}

void blinkSOS_RGB(int pin, int delayTime) {
  // Mengirim kode SOS menggunakan LED RGB dengan penundaan waktu tertentu
  for (int i = 0; i < 3; i++) {
    analogWrite(pin, 255); // Mengaktifkan LED hijau (analogWrite digunakan karena menggunakan LED RGB)
    delay(delayTime);
    analogWrite(pin, 0); // Mematikan LED hijau
    delay(delayTime);
  }
  delay(delayTime * 2);
}