#include <Ambient.h>

//Copy to scketch example "DumpInfo"
#include<SPI.h>
#include<MFRC522.h>

#define RST_PIN         5          // Configurable, see typical pin layout above
#define SS_PIN          15         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

//Copyend

#define SSID Buffalo-G-79EA
#define PASSWORD takeuchilab2110

void setup() {
  //RC522 Copy to scketch example "DumpInfo"
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  //Copy END

  //ESP8266
  WiFi.begin(SSID, PASSWORD);//WiFiの初期化

  while (WiFi.status() != WL_CONNECTED) {  //  Wi-Fiアクセスポイントへの接続待ち
    delay(500);

    ambient.begin(8881, bbd5365367c05048, &client);  //  チャネルIDとライトキーを指定してAmbientの初期化
    }

    
  //ESP8266 END
}

void loop() {
  //RC522 Copy to scketch example "DumpInfo"
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  //Copy END

  //ESP8266
  //ESP8266 END
}
