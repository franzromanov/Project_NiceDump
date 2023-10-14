//include library
#include "CTBot.h";
//variabel untuk bot telegram
CTBot mybot ;
//konfigurasi koneksi
String ssid = "ITK-A.X";
String pass = "K@mpusM3rdeka!";
String token = "6534366391:AAEChuzFeeRAAA9ajA7Jcy0tY_JY7HFCQHI"   ;
const int id = 1137066585 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Memulai Telegram Bot. Koneksi ke Wifi");

  //koneksi ke wifi
  mybot.wifiConnect(ssid,pass);
  //set token telegram
  mybot.setTelegramToken(token);

  //cek koneksi
  if(mybot.testConnection())
    Serial.println("Koneksi Berhasil");
  else
    Serial.println("Koneksi Gagal");

}

void loop() {
  // put your main code here, to run repeatedly:
  //baca pesan masuk dari telegram
  TBMessage msg ;
  if (mybot.getNewMessage(msg))
  {
    //tampilkan
    Serial.println("Pesan Masuk : " + msg.text);

    
  }

}
