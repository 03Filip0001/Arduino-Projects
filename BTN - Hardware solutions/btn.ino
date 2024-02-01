int d1 = 12;
int d2 = 11;
int d3 = 10;

int cap = A0;
int btn = A1;
int trg = A2;

bool read_btn = true;
bool d1_state = false;
bool btn_state = true;

bool read_cap = true;
bool d2_state = false;
bool cap_state = true;

void setup() {
  Serial.begin(9600);

  pinMode(btn, INPUT);
  pinMode(cap, INPUT);
  pinMode(trg, INPUT);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);

}

void loop() {   
  if(read_btn){
    if(analogRead(btn) > 1000){
      read_btn = false;
      d1_state = !d1_state;
      digitalWrite(d1, d1_state);
    }
  }
  analogRead(btn) > 1000 ? btn_state = true : btn_state = false;
  if(!read_btn && !btn_state){
    if(analogRead(btn) < 50){
      read_btn = true;
    }
  }


  if(read_cap){
    if(analogRead(cap) > 1000){
      read_cap = false;
      d2_state = !d2_state;
      digitalWrite(d2, d2_state);
      Serial.println(analogRead(cap));
    }
  }
  analogRead(cap) > 1000 ? cap_state = true : cap_state = false;
  if(!read_cap && !cap_state){
    if(analogRead(cap) < 50){
      read_cap = true;
    }
  }
}
