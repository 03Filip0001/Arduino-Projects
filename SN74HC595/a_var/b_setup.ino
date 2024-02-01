void setup() {
  pinMode(BTN_1 ,INPUT_PULLUP);
  btn1.attach(BTN_1);
  btn1.interval(5);
  
  pinMode(BTN_2 ,INPUT_PULLUP);
  btn2.attach(BTN_2);
  btn2.interval(5);
  
  pinMode(lock_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);  
  pinMode(clock_pin, OUTPUT);

  pinMode(DIS_1, OUTPUT);
  pinMode(DIS_2, OUTPUT);
  pinMode(DIS_3, OUTPUT);

  Serial.begin(9600);
}
