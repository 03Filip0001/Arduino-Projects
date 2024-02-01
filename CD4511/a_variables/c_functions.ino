void showNumberLess10(int number)
{
  digitalWrite(DIS_1, LOW);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  digitalWrite(A, bin_numbers[0][0]);
  digitalWrite(B, bin_numbers[0][1]);
  digitalWrite(C, bin_numbers[0][2]);
  digitalWrite(D, bin_numbers[0][3]);
  delay(5);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, LOW);
  digitalWrite(DIS_3, HIGH);
  digitalWrite(A, bin_numbers[0][0]);
  digitalWrite(B, bin_numbers[0][1]);
  digitalWrite(C, bin_numbers[0][2]);
  digitalWrite(D, bin_numbers[0][3]);
  delay(5);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, LOW);
  digitalWrite(A, bin_numbers[number][0]);
  digitalWrite(B, bin_numbers[number][1]);
  digitalWrite(C, bin_numbers[number][2]);
  digitalWrite(D, bin_numbers[number][3]);
  delay(5);
}

void showNumber_10_to_100(int number)
{
  separateNumber(number);
  
  digitalWrite(DIS_1, LOW);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  digitalWrite(A, bin_numbers[0][0]);
  digitalWrite(B, bin_numbers[0][1]);
  digitalWrite(C, bin_numbers[0][2]);
  digitalWrite(D, bin_numbers[0][3]);
  delay(5);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, LOW);
  digitalWrite(DIS_3, HIGH);
  digitalWrite(A, bin_numbers[tithes][0]);
  digitalWrite(B, bin_numbers[tithes][1]);
  digitalWrite(C, bin_numbers[tithes][2]);
  digitalWrite(D, bin_numbers[tithes][3]);
  delay(5);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, LOW);
  digitalWrite(A, bin_numbers[singular][0]);
  digitalWrite(B, bin_numbers[singular][1]);
  digitalWrite(C, bin_numbers[singular][2]);
  digitalWrite(D, bin_numbers[singular][3]);
  delay(5);
}

void showNumberHigher100(int number)
{
  separateNumber(number);
  digitalWrite(DIS_1, LOW);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, HIGH);
  digitalWrite(A, bin_numbers[hundreds][0]);
  digitalWrite(B, bin_numbers[hundreds][1]);
  digitalWrite(C, bin_numbers[hundreds][2]);
  digitalWrite(D, bin_numbers[hundreds][3]);
  delay(5);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, LOW);
  digitalWrite(DIS_3, HIGH);
  digitalWrite(A, bin_numbers[tithes][0]);
  digitalWrite(B, bin_numbers[tithes][1]);
  digitalWrite(C, bin_numbers[tithes][2]);
  digitalWrite(D, bin_numbers[tithes][3]);
  delay(5);

  digitalWrite(DIS_1, HIGH);
  digitalWrite(DIS_2, HIGH);
  digitalWrite(DIS_3, LOW);
  digitalWrite(A, bin_numbers[singular][0]);
  digitalWrite(B, bin_numbers[singular][1]);
  digitalWrite(C, bin_numbers[singular][2]);
  digitalWrite(D, bin_numbers[singular][3]);
  delay(5);
}
