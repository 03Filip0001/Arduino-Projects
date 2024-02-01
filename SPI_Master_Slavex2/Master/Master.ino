#include <Bounce2.h>
#include<SPI.h>

#define BTN_1 7
#define BTN_2 6

#define SLAVE_1 9
#define SLAVE_2 8

bool slave1 = false;
bool slave2 = false;

Bounce btn1 =  Bounce();
Bounce btn2 =  Bounce();

void setup() {
  Serial.begin(115200);

  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);

  pinMode(SLAVE_1, OUTPUT);
  pinMode(SLAVE_2, OUTPUT);
  digitalWrite(SLAVE_1, HIGH);
  digitalWrite(SLAVE_2, HIGH);

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH); // OVO OBAVEZNO MORA

  btn1.attach(BTN_1);
  btn1.interval(5);

  btn2.attach(BTN_2);
  btn2.interval(5);

}

void loop() {
  btn1.update();
  btn2.update();

  if(btn1.fell())
  {
    slave1 = !slave1;
  }

  if(btn2.fell())
  {
    slave2 = !slave2;
  }

  digitalWrite(SLAVE_1, LOW);
  SPI.transfer(slave1);
  digitalWrite(SLAVE_1, HIGH);

  digitalWrite(SLAVE_2, LOW);
  SPI.transfer(slave2);
  digitalWrite(SLAVE_2, HIGH);

}
