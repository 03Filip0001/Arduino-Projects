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
    if(millis() - time1 > 1000)
    {
      time1 = millis();
      number += i;
      if(number == 10) number = 0;
      else if(number == -1) number = 9;
    }
  }
  else if(value2)
  {
    if(i == 1) i = -1;
    else i = 1;
  }

  Serial.print(time1);
  Serial.print("  ");
  Serial.print(millis());
  Serial.print("  ");
  Serial.println(number);

  digitalWrite(lock_pin, LOW);

  shiftOut(data_pin, clock_pin, MSBFIRST, numbers[number][1]);

  digitalWrite(lock_pin, HIGH);
  
}
