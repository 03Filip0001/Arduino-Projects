#include <Bounce2.h>

#define BTN 9

#define A1 2
#define A2 3
#define A3 4
#define A4 5

#define K1 6
#define K2 7
#define K3 8

Bounce btn = Bounce();

int anode[] = {A1, A2, A3, A4};
int katode[] = {K1, K2, K3};

int wait = 250;
unsigned long int time;

int i;

int red = 0, kolona = 0;

bool go = true;

int ran1, ran2;

void setup() {
  Serial.begin(9600);

  pinMode(BTN, INPUT_PULLUP);
  btn.attach(BTN);
  btn.interval(5);

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);

  pinMode(K1, OUTPUT);
  pinMode(K2, OUTPUT);
  pinMode(K3, OUTPUT);


  for (i = 0; i < 4; i++)
  {
    digitalWrite(anode[i], LOW);
  }

  for (i = 0; i < 3; i++)
  {
    digitalWrite(katode[i], HIGH);
  }

  time = millis();
}

void loop() {
  Serial.println(go);

  btn.update();

  if (btn.fell())
  {
    go = !go;
    for (i = 0; i < 4; i++)
  {
    digitalWrite(anode[i], LOW);
  }

  for (i = 0; i < 3; i++)
  {
    digitalWrite(katode[i], HIGH);
  }
  }

  if (go)
  {
    upali_diodu(red, kolona);
  }
  else
  {
    upali_diodu(ran1, ran2);
  }
}

void upali_diodu(int a, int b)
{
  if (millis() - time < wait)
  {
    digitalWrite(katode[a], LOW);
    digitalWrite(anode[b], HIGH);
  }

  if (millis() - time > wait)
  {
    digitalWrite(katode[a], HIGH);
    digitalWrite(anode[b], LOW);
    time = millis();

    ran1 = random(3);
    ran2 = random(4);
    kolona++;
    if (kolona == 4)
    {
      red++;
      kolona = 0;
    }
    if (red == 3)
    {
      kolona = 0;
      red = 0;
    }
  }
}

/*
   kolona++;
    if (kolona == 4)
    {
      red++;
      kolona = 0;
    }
    if (red == 3)
    {
      kolona = 0;
      red = 0;
    }
*/
