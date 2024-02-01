#define RS485 2
#define LED 3

char ch;

void setup() {
  Serial.begin(9600);

  pinMode(RS485, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  delay(1);
  
  digitalWrite(RS485, LOW);

  //while(!Serial.available()) {}

  if (Serial.available())
  {
    ch = Serial.read();

    if (ch == '1') digitalWrite(LED, HIGH);
    else if (ch == '0') digitalWrite(LED, LOW);


    digitalWrite(RS485, HIGH);

    delay(100);

    if (ch == '1') {
      Serial.print('0');
      Serial.flush();
    }
    else if (ch == '0') {
      Serial.print('1');
      Serial.flush();
    }
  }
}
