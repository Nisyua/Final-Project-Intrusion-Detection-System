# Final-Project-Intrusion-Detection-System
## High Temperature Sensing using DHT11 and Telegram Bot Notification
*Anis Saidatur Rochma - 05311840000002 - Teknologi Informasi*

Requirement :
- Arduino Uno
- DHT11
- Nodemcu
- Breadboard
- Jumper wire (male to male)

Langkah-langkah :
- Install Arduino IDE

**(Install ESP8266 Add-On di Arduino IDE) :**
- Buka Arduino IDE , pergi ke **File > Preferences**
- Masukkan  http://arduino.esp8266.com/stable/package_esp8266com_index.json ke dalam "Additional Boards Manager URLs" , lalu klik OK
![](https://github.com/Nisyua/Final-Project-Intrusion-Detection-System/blob/main/img/add%20json.png)
- Pergi ke **Tools > Board > Boards Manager** , ketik *esp822* , klik Install

**Install DHT11 add-on**
- Pergi ke **Tools > Board > Boards Manager** , ketik *dht11* 
- Pilih **DHT sensor library by Adafruit** , klik install
![](https://github.com/Nisyua/Final-Project-Intrusion-Detection-System/blob/main/img/dht11.png)

**Install Arduino Telegram Bot Library**
- Download https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot/archive/master.zip
- Pergi ke **Sketch > Include Library > Add. Zip library**

**Uploading the Sketch**
- Pergi ke **Tools > Board > Generic ESP822 Module**
![](https://github.com/Nisyua/Final-Project-Intrusion-Detection-System/blob/main/img/board.png)
- Pilih **Port:COM 7**
![](https://github.com/Nisyua/Final-Project-Intrusion-Detection-System/blob/main/img/portcom7.png)

**Setting Telegram Bot**
- Install Telegram / pergi ke https://web.telegram.org
- Pada kolom **Search**, ketik **BotFather**
- Klik **/start > /newbot > (isi nama bot)**
- Jika bot berhasil dibuat, maka akan menerima pesan dengan tautan untuk mengakses bot dan token bot. Simpan token bot karena Anda akan membutuhkannya agar ESP8266 dapat berinteraksi dengan bot.
![](https://github.com/Nisyua/Final-Project-Intrusion-Detection-System/blob/main/img/bot.png)

## Hasil

```
/temp
```
Digunakan untuk melihat temperature saat ini

![](https://github.com/Nisyua/Final-Project-Intrusion-Detection-System/blob/main/img/temp.jpg)

```
/tau
```
Digunakan untuk memberikan respon dari pengguna apabila telah mengetahui adanya Suhu tinggi yang dikirimkan oleh sistem.

![](https://github.com/Nisyua/Final-Project-Intrusion-Detection-System/blob/main/img/tau.jpg)
