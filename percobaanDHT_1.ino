#include <LiquidCrystal.h>
#include "DHT.h"  //Memasukan Library DHT ke Program

#define DHTTYPE DHT11 //memilih tipe DHT11, bisa diubah menjadi DHT22, DHT21
LiquidCrystal lcd(12,11,5,4,3,2);
int ledmerah= 8;



void setup() {
Serial.begin(9600);  //komunikasi Serial dengan komputer
dht.begin(); //Komunikasi DHT dengan Arduino
pinMode (ledmerah,OUTPUT);
lcd.begin(16,2);
   
}

void loop() {
 lcd.setCursor(0,0);
float kelembaban = dht.readHumidity();
 float suhu = dht.readTemperature();
 lcd.print("SUHU:");
 lcd.print(suhu);
  lcd.setCursor (0,1);
  lcd.print("kelembaban:");
  lcd.print (kelembaban);
  Serial.print(" Kelembaban: "); //menampilkan tulisan Kelembaban di Serial Monitor
  Serial.print(kelembaban); //menampilkan nilai kelembaban
  Serial.print(" Suhu: "); //menampilkan tulisan suhu
  Serial.println(suhu); //menampilkan nilai suhu
  
  delay(500); //memberi jeda waktu baca selama 500 mili detik

  if (suhu >30.00){
    digitalWrite (ledmerah,HIGH);
  }
  
  else if(suhu < 31.00){
    digitalWrite (ledmerah,LOW);
     }

  
} 
