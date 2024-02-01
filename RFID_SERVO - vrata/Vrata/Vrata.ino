#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN  10

#define SERVO 2

MFRC522 mfrc522(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

Servo servo;

double time;

byte dataBlock[]    = {
    0x01, 0x02, 0x03, 0x04, //  1,  2,   3,  4,
    0x05, 0x06, 0x07, 0x08, //  5,  6,   7,  8,
    0x09, 0x0a, 0xff, 0x0b, //  9, 10, 255, 11,
    0x0c, 0x0d, 0x0e, 0x0f  // 12, 13, 14, 15
  };

void setup() {
  Serial.begin(9600);
  //while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();

  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
  }

  servo.attach(SERVO);
  servo.write(10);
  time = millis();
}

void loop() {

  if(millis() - time > 3000)
  {
    servo.write(10);
  }
  
  if (! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  if (! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);

  if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    //Serial.println(F("This sample only works with MIFARE Classic cards."));
    return;
  }

  byte sector         = 1;
  byte blockAddr      = 4;
  
  byte trailerBlock   = 7;
  MFRC522::StatusCode status;
  byte buffer[18];
  byte size = sizeof(buffer);
  status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    //Serial.print(F("PCD_Authenticate() failed: "));
    //Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  //Serial.print(F("Reading data from block ")); Serial.print(blockAddr);
  //Serial.println(F(" ..."));
  status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    //Serial.print(F("MIFARE_Read() failed: "));
    //Serial.println(mfrc522.GetStatusCodeName(status));
  }
  //Serial.print(F("Data in block ")); Serial.print(blockAddr); Serial.println(F(":"));
  dump_byte_array(buffer, 16); //Serial.println();
  //Serial.println();

  //Serial.println(F("Checking result..."));
  
  /*
  //Serial.print(F("Number of bytes that match = ")); Serial.println(count);
  if (count == 16) {
    //Serial.println(F("Success :-)"));
  } else {
    //Serial.println(F("Failure, no match :-("));
    //Serial.println(F("  perhaps the write didn't work properly..."));
  }*/
  //Serial.println();
  // Halt PICC
  mfrc522.PICC_HaltA();
  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();

  //delay(4000);
}

void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        //Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i]);
    }
    Serial.println();

    byte count = 0;
  for (byte i = 0; i < 16; i++) {
    // Compare buffer (= what we've read) with dataBlock (= what we've written)
    if (buffer[i] == dataBlock[i])
      count++;
  }
  
  Serial.println(count);

  if(count == 7){
    servo.write(80);
    time = millis();
  }
  else{
    servo.write(10);
  }
}
