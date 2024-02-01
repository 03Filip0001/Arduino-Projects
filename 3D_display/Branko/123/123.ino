#define NPN1 12
#define PNP1 10
#define NPN2 11
#define PNP2 9

void setup() {
  pinMode(NPN1, OUTPUT);
  pinMode(PNP1, OUTPUT);
  pinMode(NPN2, OUTPUT);
  pinMode(PNP2, OUTPUT);

}

void loop() {
  ugasi();
  upali_1();
  delay(1000);
  
  ugasi();
  upali_2();
  delay(1000);
}

void upali_1()
{
  digitalWrite(NPN1, HIGH);
  digitalWrite(PNP2, LOW);
}

void upali_2()
{
  digitalWrite(NPN2, HIGH);
  digitalWrite(PNP1, LOW);
}

void ugasi()
{
  digitalWrite(NPN1, LOW);
  digitalWrite(NPN2, LOW);
  digitalWrite(PNP1, HIGH);
  digitalWrite(PNP2, HIGH);
  delay(1);
}
