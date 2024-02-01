int rel = 2;
int Received = 0;
bool Rel = false;

void setup() {
  Serial.begin(9600);
  pinMode(rel, OUTPUT);
  digitalWrite(rel, HIGH);
}

void loop() {
  if(Serial.available())
  {
    Received = Serial.read();
    (Received == '1') ? toogleRel() : delay(1);
  }
}

void toogleRel()
{
  if(Rel)
  {
    Rel = false;
    digitalWrite(rel, HIGH);
  }
  else
  {
    Rel = true;
    digitalWrite(rel, LOW);
  }
}
