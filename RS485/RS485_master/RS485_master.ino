#define RS485 7
#define LED 8

unsigned long int time;

bool on = true;

char ch;

void setup() {
  Serial.begin(9600);

  pinMode(RS485, OUTPUT);
  pinMode(LED, OUTPUT);
  time = millis();
}

void loop() {
  if (millis() - time > 1000)
  {
    time = millis();

    digitalWrite(RS485, HIGH);
    delay(1);

    if (on)
    {
      Serial.print('1');
      Serial.flush();
    }
    else if (!on)
    {
      Serial.print('0');
      Serial.flush();
    }
    on = !on;

    delay(1);

    digitalWrite(RS485, LOW);
    delay(1);

    while (!Serial.available()) {}
    ch = Serial.read();

    if (ch == '1') digitalWrite(LED, HIGH);
    else if (ch == '0')  digitalWrite(LED, LOW);
    
  }
  /*
  if(Serial.available())
  {
    ch = Serial.read();

    if (ch == '1') digitalWrite(LED, HIGH);
    else if (ch == '0')  digitalWrite(LED, LOW);
  }
  */
}
