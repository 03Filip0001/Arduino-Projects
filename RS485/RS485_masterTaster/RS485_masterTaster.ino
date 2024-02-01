#include <Bounce2.h>

#define BTN 10
#define LED 9
#define RS485 8

Bounce btn = Bounce();

bool ON = false;

char ch;

void setup() {
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  pinMode(RS485, OUTPUT);

  pinMode(BTN, INPUT_PULLUP);

  btn.attach(BTN);
  btn.interval(5);

  digitalWrite(RS485, LOW);
}

void loop() {
  btn.update();

  if(btn.fell())
  {
    ON = !ON;

    digitalWrite(RS485, HIGH);
    delay(1);

    if(ON) Serial.print('1');
    else Serial.print('0');
    delay(5);

    digitalWrite(LED, LOW);
    digitalWrite(RS485, LOW);
  }

  if(Serial.available())
  {
    ch = Serial.read();

    if(ch == '1') digitalWrite(LED, HIGH);
    else if(ch == '0') digitalWrite(LED, LOW);
  }
}
