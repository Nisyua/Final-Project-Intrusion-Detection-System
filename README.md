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
- Pergi ke **Tools > Board > Boards Manager** , ketik *esp822*
- Klik Install

**Uploading the Sketch**
- Pergi ke **Tools > Board > Generic ESP822 Module**
- Pilih **Port:COM 7**

**Setting Telegram Bot**
- Install Telegram / pergi ke https://web.telegram.org
- Pada kolom **Search**, ketik **BotFather**
- Klik **/start > /newbot > (isi nama bot) **
- Jika bot berhasil dibuat, maka akan menerima pesan dengan tautan untuk mengakses bot dan token bot. Simpan token bot karena Anda akan membutuhkannya agar ESP8266 dapat berinteraksi dengan bot.
