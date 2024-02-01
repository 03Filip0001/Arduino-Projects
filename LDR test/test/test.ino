#include <LDR.h>

LDR displej(2, 3, 4, 5, 6, 7, 8);

long unsigned int time1;

int next = 0;

int pins[7] = {2,3,4,5,6,7,8};

void setup() {
  displej.Setup();
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);

  time1 = millis();
}

void loop() {

  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);

  displej.showNumber(0);

  delay(10000);

  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);

  for(int i = 0; i < 7; i++){
      digitalWrite(pins[i], 0 & (1 << i));
  }

  delay(10000);



  
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);

  displej.showNumber(1);

  delay(10000);

  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);

  for(int i = 0; i < 7; i++){
      digitalWrite(pins[i], 0 & (1 << i));
  }

  delay(10000);
}
