void sort(int num) {
  Put = false;
  for (i = 0; i < 5; i++) {
    if (row[i] == -1 && Put == false) {
      row[i] = num;
      Put = true;
      break;
    }
  }
  bubbleSort();
}
void Move() {
  row[0] = row[1];
  row[1] = row[2];
  row[2] = row[3];
  row[3] = row[4];
  row[4] = -1;
}

void Move(int num)
{
  for(int j = num; j < 4;j++)
  {
    row[j] = row[j + 1];
  }
  row[4] = -1;
}

void ledsOn(){
  for(i = 0; i< 5;i++){
    if(clicked[i]){
      digitalWrite(LEDS[i], HIGH);
    }
    else if(!clicked[i]){
      digitalWrite(LEDS[i], LOW);
    }
  }
}

void bubbleSort()
{
  int k;
  bool zameni = true;

  while(zameni)
  {
    zameni = false;
    for(k = 0; k < 4;k++)
    {
      if(row[k] < row[k + 1]) // 1 3
      {
        int pom = row[k]; // 1 3
        row[k] = row[k + 1]; // 3 3
        row[k + 1] = pom; // 3 1
        zameni = true;
      }
    }
  }
}
