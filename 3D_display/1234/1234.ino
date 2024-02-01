#define NPN1 2
#define NPN2 3
#define PNP1 4
#define PNP2 5
  
#define A 6
#define B 7
#define C 8
#define D 9
#define E 10
#define F 11
#define G 12

unsigned long time;

void setup() {
  pinMode(NPN1, OUTPUT);
  pinMode(NPN2, OUTPUT);
  pinMode(PNP1, OUTPUT);
  pinMode(PNP2, OUTPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  for (int i = A; i <= G; i++)
  {
    digitalWrite(i, LOW);
  }

  digitalWrite(NPN1, HIGH);
    digitalWrite(NPN2, LOW);
    digitalWrite(PNP1, LOW);
    digitalWrite(PNP2, HIGH);
  
}

void loop() {
  for (int i = A; i <= G; i++)
  {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }

    digitalWrite(NPN2, HIGH);
    digitalWrite(NPN1, LOW);
    digitalWrite(PNP2, LOW);
    digitalWrite(PNP1, HIGH);

  for (int i = A; i <= G; i++)
  {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }

    digitalWrite(NPN1, HIGH);
    digitalWrite(NPN2, LOW);
    digitalWrite(PNP1, LOW);
    digitalWrite(PNP2, HIGH);
}
