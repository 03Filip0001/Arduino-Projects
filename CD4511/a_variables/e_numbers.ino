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

//int hundreds, tithes, singular;
