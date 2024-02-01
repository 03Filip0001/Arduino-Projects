#include <Bounce2.h>

#define BTN_1 6
#define BTN_2 7
#define BTN_3 8
#define BTN_4 9

#define DIS_1 10
#define DIS_2 11
#define DIS_3 12

#define A 2
#define B 3
#define C 4
#define D 5

Bounce btn1 = Bounce();
Bounce btn2 = Bounce();
Bounce btn3 = Bounce();
Bounce btn4 = Bounce();

bool start = true;
long unsigned int time1;
int number = 0, x = 1;
int time2 = 1000;
int hundreds, tithes, singular;
bool positive = true;

void setup() {
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);

  pinMode(DIS_1, OUTPUT);
  pinMode(DIS_2, OUTPUT);
  pinMode(DIS_3, OUTPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  btn1.attach(BTN_1);
  btn1.interval(10);

  btn2.attach(BTN_2);
  btn2.interval(10);

  btn3.attach(BTN_3);
  btn3.interval(10);

  btn4.attach(BTN_4);
  btn4.interval(10);

  time1 = millis();
}

void loop() {
  btn1.update();
  btn2.update();
  btn3.update();
  btn4.update();

  if (btn2.fell())
  {
    start = true;
  }

  if (start)
  {
    if (btn1.fell())
    {
      start = false;
    }

    if (btn3.fell())
    {
      if (time2 > 50) time2 -= 50;
      else if (time2 == 50) time2 = 3;
    }

    if (btn4.fell())
    {
      if (time2 < 1000 && time2 != 3) time2 += 50;
      else if (time2 == 3) time2 = 50;
    }

    if (millis() - time1 > time2)
    {
      number += x;
      time1 = millis();
    }

    if (number == 256) number = 0;

    display_num();
  }
  else
  {
    digitalWrite(DIS_1, LOW);
    digitalWrite(DIS_2, LOW);
    digitalWrite(DIS_3, LOW);
    //digitalWrite(D, LOW);
  }

  /*else
    {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    }*/
}
