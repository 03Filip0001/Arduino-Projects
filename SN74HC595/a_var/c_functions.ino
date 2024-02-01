void separateNumber(int number)
{
  if(number < 100)
  {
  singular = number % 10;
  tithes = (number / 10) % 10;
  }
  else
  {
  singular = number % 10;
  tithes = (number / 10) % 10;
  hundreds = (number / 100) % 10;
  }
}

void showNumberLess10(int number)
{
  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[0][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_1, LOW);
  delay(wait);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[0][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_2, LOW);
  delay(wait);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[number][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_3, LOW);
  delay(wait);
}

void showNumber_10_to_100(int number)
{
  separateNumber(number);
  
  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[0][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_1, LOW);
  delay(wait);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[tithes][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_2, LOW);
  delay(wait);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[singular][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_3, LOW);
  delay(wait);
}

void showNumberHigher100(int number)
{
  separateNumber(number);
  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[hundreds][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_1, LOW);
  delay(wait);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[tithes][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_2, LOW);
  delay(wait);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  
  digitalWrite(lock_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[singular][1]);
  digitalWrite(lock_pin, HIGH);
  digitalWrite(DIS_3, LOW);
  delay(wait);
}
