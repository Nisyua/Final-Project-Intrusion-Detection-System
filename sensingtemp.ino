#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "DHT.h" //library sensor yang telah diimportkan

const char* ssid = "syalala"; //nama wifi
const char* password = "T0p1_54y@_bund4r"; //passw wifi

#define BOTtoken "XXXXXXXXXXX"
#define CHAT_ID "XXXXXXX" 

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

#define DHTPIN 15 //Pin apa yang digunakan //D8 No GPIO (general propose input output) 
#define DHTTYPE DHT11   // DHT 11 

int botRequestDelay = 1000; //NODEMCU memberikan delay agar tidak terjadi spam
unsigned long lastTimeBotRan; //pendukung delay

const int ledPin  = 2; 
bool ledState     = LOW; //ketika program diup -> led masi keadaan mati

DHT dht(DHTPIN, DHTTYPE); //
void setup() { 
  Serial.begin(9600); //bandwith komunikasi serial
  Serial.println("Pengujian DHT11!"); //penulisan di serial monitor
  dht.begin();
  
  #ifdef ESP8266
    client.setInsecure();
  #endif
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { // ketika tidak terkoneksi, akan ulang terus
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP()); // konek -> ip keluar
  
  bot.sendMessage(CHAT_ID, "Bot IntrusionDetector aktif ..", ""); //setup udah jalan, mulai kirim bot
}

void loop() { //dijalankan berulang kali
  //Pembacaan untuk data kelembaban
  float humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
  float celcius_1 = dht.readTemperature();
  //mengecek pembacaan apakah terjadi kegagalan atau tidak
  if (isnan(humidity_1) || isnan(celcius_1)) {
    Serial.println("Pembacaan data dari module sensor gagal!");
    delay(1000);
    return;
  }
  //pembacaan nilai pembacaan data kelembaban
  Serial.print("Kelembaban: ");
  Serial.print(humidity_1);
  Serial.print(" %\t");
  
  //pembacaan nilai pembacaan data suhu
  Serial.print("Suhu : ");
  Serial.print(celcius_1); //format derajat celcius
  Serial.print("°"); //simbol derajat
  Serial.println("C / ");
  delay(1000);

  bool warningMessage = false; 
  String chat_id2 = String(bot.messages[0].chat_id);
  String text2 = bot.messages[0].text;
  
  if(millis() > lastTimeBotRan + botRequestDelay){ //millis-> return akumulasi dalam 1milisecond sampe true
    if(warningMessage == false){
      if(celcius_1 >= 40 ){
        if (text2 == "/tau") {
          bot.sendMessage(chat_id2, "Stay safe, Anis!", "");
          warningMessage = true;
        }
        else{
          bot.sendMessage(chat_id2, "Peringatan!! Suhu tinggi diatas 40 derajat celcius!", "");
          delay(1000);
        }
      }
  }
  else if(celcius_1 < 40){
    warningMessage = false;
  }
    
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  while(numNewMessages){ 
    Serial.println("got response");
    Serial.println(String(numNewMessages));
    for (int i=0; i<numNewMessages; i++) {
      String chat_id = String(bot.messages[i].chat_id);
      if (chat_id != CHAT_ID){
        bot.sendMessage(chat_id, "Unauthorized user", "");
        continue;
      }
      
      String text = bot.messages[i].text;
      Serial.println(text);
      
      String from_name = bot.messages[i].from_name;
  
      String suhu = "Temp : ";
      suhu += celcius_1;
      suhu += " °C\n";
  
      String hum = "Hum : ";
      hum += humidity_1;
      hum += " %\n";
      
      if (text == "/led_on") {
        bot.sendMessage(chat_id, "LED state set to ON", "");
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
      }
      if (text == "/led_off") {
        bot.sendMessage(chat_id, "LED state set to OFF", "");
        ledState = LOW;
        digitalWrite(ledPin, ledState);
      }
      if (text == "/temp") {
        bot.sendMessage(chat_id, suhu, "");
      }
      if (text == "/state") {
        if (digitalRead(ledPin)){
          bot.sendMessage(chat_id, "LED is ON", "");
        }
        else{
          bot.sendMessage(chat_id, "LED is OFF", "");
        }
      }
    }
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
  lastTimeBotRan = millis(); 
}
}
