#include <LiquidCrystal.h>

#define BTN 14
#define RS 8
#define EN 9
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7

LiquidCrystal lcd(RS, EN, pin4, pin5, pin6, pin7);

int i = 0;
int j = 0;

int sifra[4] = {1, 2, 3, 4};
int hoi[4] = {0, 0, 0, 0};

int koji;

bool correct = false;
bool newPass = false;

void setup() {
  Serial.begin(9600);

  pinMode(BTN, INPUT);

  lcd.begin(16, 2);

  lcd.print("Unesite sifru");
}

int button(int val)
{
  if (val < 50)
  {
    return 4;
  }
  else if (val < 200)
  {
    return 2;
  }
  else if (val < 350)
  {
    return 3;
  }
  else if (val < 550)
  {
    return 1;
  }
  else if (val < 750)
  {
    return 5;
  }
  else
  {
    return 0;
  }
}

void PrintPass()
{
  lcd.clear();
  lcd.setCursor(0, 1);
  for (j = 0; j < 4; j++)
  {
    lcd.print(hoi[j]);
    lcd.print(" ");
  }
}

void PrintNewPass()
{
  lcd.print(sifra[i]);
  lcd.print(" ");
}

void newPassword()
{
  i = 0;
  lcd.setCursor(0,1);
  do {
    do {
      koji = button(analogRead(BTN));
    } while (!koji);

    if (koji != 5) {
      sifra[i] = koji;
      PrintNewPass();
      i++;
    }
    delay(500);
  } while (i < 4);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Promenjeno");
  newPass = false;
  delay(2000);
  lcd.clear();
  i = 0;
  lcd.print("Unesite sifru");
}

void loop() {
  do {
    koji = button(analogRead(BTN));
  } while (!koji);

  if (koji != 5)
  {
    hoi[i] = koji;
    i++;

    PrintPass();
    if (i == 4)
    {
      correct = true;
      for (j = 0; j < 4; j++)
      {
        if (!(sifra[j] == hoi[j])) correct = false;
        hoi[j] = 0;
      }
      i = 0;
      if (correct) {
        if (newPass) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tacno");
          delay(2000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Nova sifra:");
          newPassword();
        }
        else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tacno");
          delay(2000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Unesite sifru");
        }
      }
      else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Netacno, ponovi");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Unesite sifru");
      }
    }
  }
  else {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Unesite sifru:");
    newPass = true;
  }
  delay (500);
}
