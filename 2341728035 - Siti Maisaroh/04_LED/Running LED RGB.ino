#include <Arduino.h>
#define RED_LED 25 //led warna merah
#define GREEN_LED 26 //led warna hijau
#define BLUE_LED 27 //led warnah biru

void setup() {
 Serial.begin(115200);
 pinMode(RED_LED,OUTPUT);//atur pin-pin digital sebagai output
 pinMode(GREEN_LED,OUTPUT);
 pinMode(BLUE_LED,OUTPUT);
 Serial.println("Contoh Program LED RGB");
}

void rgbLED(){
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
 delay(2000);
}

void loop() {
 rgbLED();
}
