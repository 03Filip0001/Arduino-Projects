#include <SoftwareSerial.h>
#define LED 8

SoftwareSerial slave(10,11);

char ch;

void setup() {
  Serial.begin(9600);

  slave.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  if (slave.available())
  {
    ch = slave.read();

    if (ch == '1') digitalWrite(LED, HIGH);
    else if (ch == '0') digitalWrite(LED, LOW);

    if (ch == '1') slave.print('0');
    else if (ch == '0') slave.print('1');
    //Serial.flush();
  }
}
