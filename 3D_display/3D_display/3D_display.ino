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
unsigned long time1;

int modul[] = {A, B, C, D, E, F, G};

int numbers[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int number = 0;

int which = 0;
bool inverse = false;

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
  
    digitalWrite(NPN1, LOW);
    digitalWrite(NPN2, LOW);
    digitalWrite(PNP1, HIGH);
    digitalWrite(PNP2, HIGH);
  
  time = millis();
  time1 = millis();
}

void loop() {
  if(millis() - time > 1000)
  {
    number++;
    if(number == 10) number = 0;
    time = millis();
  }

  Display();

  if(millis() - time1 > 25){
    which++;
    if(which == 8) which = 0;
    time1 = millis();
    Show(0);
  }
}

void Display() {
  if(numbers[number][which] == 0) inverse = true;
  else inverse = false;

  if(inverse) Current(1);
  else Current(0);

  Show(1);
}

void Current(int current){
  if(current == 1){
    digitalWrite(NPN1, HIGH);
    digitalWrite(NPN2, LOW);
    digitalWrite(PNP1, LOW);
    digitalWrite(PNP2, HIGH);
  }
  else if(current == 0){
    digitalWrite(NPN1, LOW);
    digitalWrite(NPN2, HIGH);
    digitalWrite(PNP1, HIGH);
    digitalWrite(PNP2, LOW);
  }
}

void Show(int light){
  if(light == 1)  digitalWrite(modul[which], HIGH);
  else {
    int x = which - 1;
    if(x == -1) x = 7;
    digitalWrite(modul[x], LOW);
  }
}
