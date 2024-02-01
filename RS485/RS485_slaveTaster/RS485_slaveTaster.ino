#define LED 9
#define RS485 8

char ch;

void setup() {
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  pinMode(RS485, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(RS485, LOW);
}

void loop() {
  if(Serial.available())
  {
    digitalWrite(LED, HIGH);
    ch = Serial.read();

    delay(5);
    digitalWrite(RS485, HIGH);
    delay(5);

    if(ch == '1') 
    {      
      Serial.print('0');
      digitalWrite(LED, HIGH);
    }
    else if (ch == '0')
    {
      Serial.print('1');
      digitalWrite(LED, LOW);
    }
    delay(5);
    digitalWrite(RS485, LOW);
    delay(1);
  }
}
