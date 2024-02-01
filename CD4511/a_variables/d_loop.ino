void loop() {
  
  if(number <= 9)
  {
    //for(int j = 0; j < 10;j++)
    //{
      showNumberLess10(number);
    //}
  }
  if(number >= 10 && number < 100)
    /*for(int j = 0; j < 10; j++)
    {*/
      showNumber_10_to_100(number);
    //}
  if(number >= 100)
  //for(int j = 0; j < 10; j++)
  //{
    showNumberHigher100(number);
  //}
  
  if(number == 0)
    x = 1;
  else if(number == 999)
    x = -1;
 
  number = number + x;
}
