//Komunikacije
#include <Wire.h>
#include <SPI.h>

//Biblioteka za RFID citac kartica
#include <MFRC522.h>

//Biblioteka za LCD displej
#include <LiquidCrystal_I2C.h>

//Biblioteka za barometar
#include <SFE_BMP180.h>

//Biblioteka za led matrix
#include <LedControl.h>

//Konfiguracija za RFID citac kartica
#define RST_PIN_RFID  7
#define SS_PIN_RFID   8

MFRC522 RFID(SS_PIN_RFID, RST_PIN_RFID);
MFRC522::MIFARE_Key key;
//Sifra u heksadecimalnom zapisu koja ce se smatrati tacnom
byte password[7] = {
  0x01, 0x02, 0x03, 0x04, //  1, 2, 3, 4,
  0x05, 0x06, 0x07      //  5, 6, 7
};

//Konfiguracija za LCD displej
#define LCD_ADDR  0x27 //Adresa za LEDd displej
//Velicina displeja (20 x 4)
#define COLONS     20
#define ROWS       4
LiquidCrystal_I2C LCD(LCD_ADDR, COLONS, ROWS);

//Konfiguracija za DS3231
#define DS3231_ADDR 0x68
#define DS3231_REG  0X00
uint8_t dataTime[7];
uint8_t Time[7];
String Time_STR;

//Konfiguracija za barometar
#define ALTITUDE 76 //Nadmorska visina (u metrima)
SFE_BMP180 pressure;
double baseline;
double Pressure;
double Temperature;

//Konfiguracija za diode i dugme
#define GREEN 4
#define RED   5

//Konfiguracija za led matrix
#define NUM_OF_DISPLAY 4
#define DATA_PIN_LED A2
#define CLK_PIN_LED A3
#define SS_PIN_LED 9
LedControl LED = LedControl(DATA_PIN_LED, CLK_PIN_LED, SS_PIN_LED, NUM_OF_DISPLAY);

//Karakteri za LED matrix displej 0-9, i karakter "T:"
byte chars[11][8] = {
  {
    B00000000,
    B00000000,
    B00000000,
    B01111111,
    B01000001,
    B01000001,
    B01111111,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00010000,
    B00100000,
    B01111111,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B00100001,
    B01000011,
    B01000101,
    B00111001,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B01001001,
    B01001001,
    B01001001,
    B00111110,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B01111000,
    B00001000,
    B00001000,
    B01111111,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B01111001,
    B01001001,
    B01001001,
    B01001111,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B01111111,
    B01001001,
    B01001001,
    B01001111,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B01000000,
    B01000000,
    B01000000,
    B01111111,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B01111111,
    B01001001,
    B01001001,
    B01111111,
    B00000000
  },

  {
    B00000000,
    B00000000,
    B00000000,
    B01111001,
    B01001001,
    B01001001,
    B01111111,
    B00000000
  },

  {
    B01000000,
    B01000000,
    B01111110,
    B01000000,
    B01000000,
    B00010100,
    B00000000
  }
};

//Ostale promenljive
int i, j;
unsigned long Timee;

void key_init()
{
  //Pravljenje kljuca kako bismo mogli da procitamo karticu na RFID-u
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
  }
}

void getTime()
{
  //Citanje vremena sa DS3231
  Wire.begin();
  Wire.beginTransmission(DS3231_ADDR);
  Wire.write(DS3231_REG);
  Wire.endTransmission();

  Wire.requestFrom(DS3231_ADDR, 7);
  i = 0;
  while (Wire.available())
  {
    dataTime[i] = Wire.read();
    i++;
  }

  for (i = 0; i < 7; i++)
  {
    Time[i] = dataTime[i] - 6 * (dataTime[i] >> 4);
  }

  i = 0;
  getTime_STR();
}

void getTime_STR()
{
  //Pravljenje kako da nam izgleda vreme prilikom prikaza
  //Dekoracija
  Time_STR = "";
  if (Time[2] >= 10)  Time_STR += Time[2];
  else {
    Time_STR += "0";
    Time_STR += Time[2];
  }
  Time_STR += ":";
  if (Time[1] >= 10)  Time_STR += Time[1];
  else {
    Time_STR += "0";
    Time_STR += Time[1];
  }
  Time_STR += ":";
  if (Time[0] >= 10)  Time_STR += Time[0];
  else {
    Time_STR += "0";
    Time_STR += Time[0];
  }
}

void writeTime()
{
  LCD.setCursor(0, 0);
  LCD.print("Time:");
  LCD.setCursor(7, 0);
  LCD.print(Time_STR);
}

void Read_pressure()
{
  char status;

  //Da bismo dobili pritisak prvo moramo procitati temperaturu
  status = pressure.startTemperature();
  delay(status);
  status = pressure.getTemperature(Temperature);
  status = pressure.startPressure(3);
  delay(status);
  status = pressure.getPressure(Pressure, Temperature);

  Pressure = pressure.sealevel(Pressure, ALTITUDE);
}

void writePressure()
{
  LCD.setCursor(0, 2);
  LCD.print("Pressure:");
  LCD.setCursor(10, 2);
  LCD.print(String(Pressure, 2));
  LCD.print("mb");
  Wire.end();
}

void writeTemperature() {
  int a, b, c, d;
  //Rastavljanje temperature na 4 cifre
  if (Temperature < 10)
  {
    a = 0;
    b = (int)Temperature;
    c = (int)(Temperature * 10) % 10;
    d = (int)(Temperature * 100) % 10;
  }
  else if (Temperature < 100)
  {
    a = (int)(Temperature / 10) % 10;
    b = (int)Temperature % 10;
    c = (int)(Temperature * 10) % 10;
    d = (int)(Temperature * 100) % 10;
  }
  else {
    a = b = c = d = 0;
  }
  writeDigits(a, b, c, d);
}

void writeDigits(int x, int y, int z, int d) {
  int onDisplay[] = {d, z, y, x, 10};
  int i = 0;
  int j = 0;
  int n = 0;
  int k = 0;
  
  for (i = 0; i < 8; i++) {
    LED.setColumn(3, i, chars[onDisplay[4]][i]);
  }

  n = 2;
  
  for (i = 3; i >= 0; i--) {
    if (i == 1) {
      LED.setColumn(n, k, 0x01);
      if (++k >= 8) {
        n--;
        k = 0;
      }
    }
    for (j = 0; j < 6; j++) {
      LED.setColumn(n, k, chars[onDisplay[i]][j + 2]);
      if (++k >= 8) {
        n--;
        k = 0;
      }
    }
  }
}

void ReadRFID()
{ 
  //Provera da li imamo bilo kakvu karticu koju bismo mogli da procitamo
  if (! RFID.PICC_IsNewCardPresent())
  {
    return;
  }

  if (! RFID.PICC_ReadCardSerial())
  {
    return;
  }

  //Provera da li mi ovu karticu mozemo da citamo
  MFRC522::PICC_Type piccType = RFID.PICC_GetType(RFID.uid.sak);
  if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    return;
  }

  //Potrebne promenljive kako bismo procitali karticu
  byte sector         = 1;
  byte blockAddr      = 4;
  byte trailerBlock   = 7;
  MFRC522::StatusCode status;
  byte buffer[18];
  byte size = sizeof(buffer);
  
  //Provere da li komunikacija sa karticom dobra
  status = (MFRC522::StatusCode) RFID.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(RFID.uid));
  if (status != MFRC522::STATUS_OK) {
    return;
  }
  status = (MFRC522::StatusCode) RFID.MIFARE_Read(blockAddr, buffer, &size);

  byte count = 0;
  for (byte i = 0; i < 7; i++) {
    if (buffer[i] == password[i])
      count++;
  }

  if(count == 7)
  {
    digitalWrite(GREEN, HIGH);
    Timee = millis();
  }
  else{
    digitalWrite(RED, HIGH);
    Timee = millis();
  }

  //Prekid komunikacije sa karticom nakon sto smo procitali sta je na njoj
  RFID.PICC_HaltA();
  RFID.PCD_StopCrypto1();

  /*
  //Prikaz onoga sto RFID cita to jest sta se nalazi na kartici
  for(i = 0; i < 7; i++)
  {
    Serial.print(buffer[i]);
    Serial.print(" ");
  }
  Serial.println();
  */
}

void setup() {
  Serial.begin(115200);

  SPI.begin();
  RFID.PCD_Init();
  key_init();
  SPI.end();

  LED.shutdown(0, false);
  LED.setIntensity(0, 8);
  LED.clearDisplay(0);

  LED.shutdown(1, false);
  LED.setIntensity(1, 8);
  LED.clearDisplay(1);

  LED.shutdown(2, false);
  LED.setIntensity(2, 8);
  LED.clearDisplay(2);

  LED.shutdown(3, false);
  LED.setIntensity(3, 8);
  LED.clearDisplay(3);

  Wire.begin();
  LCD.begin();
  LCD.backlight();
  pressure.begin();
  Wire.end();

  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);
  delay(500);

  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);

  Timee = millis();
}

void loop() {
  getTime();
  writeTime();
  Read_pressure();
  writePressure();
  writeTemperature();

  SPI.begin();
  ReadRFID();
  SPI.end();

  if(millis() - Timee > 2500)
  {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
  }
}
