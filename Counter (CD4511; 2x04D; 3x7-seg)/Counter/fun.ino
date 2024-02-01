void display_num()
{
  separate_num();

  digitalWrite(DIS_1, LOW);
  digitalWrite(DIS_2, LOW);
  digitalWrite(DIS_3, LOW);

  digitalWrite(A, hundreds & (1 << 0));
  digitalWrite(B, hundreds & (1 << 1));
  digitalWrite(C, hundreds & (1 << 2));
  digitalWrite(D, hundreds & (1 << 3));

  digitalWrite(DIS_1, HIGH);

  delay(1);

  digitalWrite(DIS_1, LOW);
  digitalWrite(DIS_2, LOW);
  digitalWrite(DIS_3, LOW);

  digitalWrite(A, tithes & (1 << 0));
  digitalWrite(B, tithes & (1 << 1));
  digitalWrite(C, tithes & (1 << 2));
  digitalWrite(D, tithes & (1 << 3));

  digitalWrite(DIS_2, HIGH);
  
  delay(1);

  digitalWrite(DIS_1, LOW);
  digitalWrite(DIS_2, LOW);
  digitalWrite(DIS_3, LOW);

  digitalWrite(A, singular & (1 << 0));
  digitalWrite(B, singular & (1 << 1));
  digitalWrite(C, singular & (1 << 2));
  digitalWrite(D, singular & (1 << 3));

  digitalWrite(DIS_3, HIGH);

  delay(1);
  
}

void separate_num()
{
  if(number < 10)
  {
    hundreds = 0;
    tithes = 0;
    singular = number;
  }
  else if(number < 100)
  {
    hundreds = 0;
    tithes = (number / 10) % 10;
    singular = number % 10;
  }
  else
  {
    hundreds = (number / 100) % 10;
    tithes = (number / 10) % 10;
    singular = number % 10;
  }
}
