#include <SoftwareSerial.h>
#define LED 8

SoftwareSerial master(10,11); // RX, TX

unsigned long int time;

bool ON = false;

char ch;

void setup() {
  Serial.begin(9600);
  master.begin(115200);

  pinMode(LED, OUTPUT);

  time = millis();
}

void loop() {
  if (millis() - time > 1000)
  {
    time = millis();

    if (ON)  master.print('1');
    else if (!ON) master.print('0');
    //Serial.flush();
    ON = !ON;
  }

  if (master.available())
    {
      ch = master.read();

      if (ch == '1') digitalWrite(LED, HIGH);
      else if (ch == '0') digitalWrite(LED, LOW);
    }
}
