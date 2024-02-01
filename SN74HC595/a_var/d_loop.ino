void loop() {
  btn1.update();
  btn2.update();

  if(btn1.fell())
  {
    value1 = !value1;
  }
  if(btn2.fell())
  {
    value2 = !value2;
  }

  if(value1)
  {
    if(value2)
    {
      if(i == 1) i = -1;
      else i = 1;
      value2 = !value2;
    }
    else {
      if(millis() - time1 > 100)
    {
      time1 = millis();
      number += i;
      if(number == 1000) number = 0;
      else if(number == -1) number = 999;
      }
    }
  }
  else if(value2)
  {
    if(i == 1) i = -1;
    else i = 1;
  }

  if(number < 10)
  {
    showNumberLess10(number);
  }
  else if(number < 100)
  {
    showNumber_10_to_100(number);
  }
  else
  {
    showNumberHigher100(number);
  } 
}
