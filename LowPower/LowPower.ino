// **** INCLUDES *****
#include "LowPower.h"
#include <Wire.h>
#include "RTClib.h"

// Install Pin change interrupt for a pin, can be called multiple times
void pciSetup(byte pin)
{
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}


ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
{
}

#define ALARM_PIN A3
RTC_MCP79401 RTC;     // Instantiate the RTC module as a MCP79401

void setup()
{
  //RTC alarm pin triggers wake-up
  pinMode(ALARM_PIN, INPUT);
  pciSetup(ALARM_PIN);

  //RTC setup
  Wire.begin();                                  // Starts the I2C bus
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__, 5));   // Initializes RTC time with computer time and day of the week (1-7)
  
  wake_up();
}

void go_to_sleep()
{
  //disable serial port
  Serial.println("Zzzzzzzzz...");
  delay(100);
  Serial.end();

  //disable I2C
  Wire.end();

  // Enter power down state with ADC and BOD module disabled.
  // Wake up on pin change interrupt
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void wake_up()
{
  //start serial port
  Serial.begin(9600);
  Serial.println("Rise and shine! :)");

  //enable I2C
  Wire.end();
}

void printDateTime(DateTime dt)
{
  switch (dt.weekday()) {
    case 1: Serial.print ("Mon "); break;
    case 2: Serial.print ("Tue "); break;
    case 3: Serial.print ("Wed "); break;
    case 4: Serial.print ("Thu "); break;
    case 5: Serial.print ("Fri "); break;
    case 6: Serial.print ("Sat "); break;
    case 7: Serial.print ("Sun "); break;
  }
  Serial.print(dt.year(), DEC);
  Serial.print('.');
  if (dt.month() < 10) Serial.print("0");
  Serial.print(dt.month(), DEC);
  Serial.print('.');
  if (dt.day() < 10) Serial.print("0");
  Serial.print(dt.day(), DEC);
  Serial.print(' ');
  if (dt.hour() < 10) Serial.print("0");
  Serial.print(dt.hour(), DEC);
  Serial.print(':');
  if (dt.minute() < 10) Serial.print("0");
  Serial.print(dt.minute(), DEC);
  Serial.print(':');
  if (dt.second() < 10) Serial.print("0");
  Serial.print(dt.second(), DEC);
  Serial.println();
}

void loop()
{
  DateTime now = RTC.now();                    // Read current time
  DateTime alarm = DateTime (now.year() - 2000, now.month(), now.day(), now.weekday(), now.hour(), now.minute(), (now.second() + 5) % 60);

  //  setAlarmX accepts as 2nd parameter 'S' 'M' 'H' 'D' 'd' 'T'
  // S: the alarm goes off at the desired Seconds mark (eg: xxHxxM30S)
  // M: the alarm goes off at the desired Minute mark  (eg: xxH45MxxS)
  // H: the alarm goes off at the desired Hour mark    (eg: 10HxxMxxS)
  // D: the alarm goes off at the desired Weekday mark (eg: Monday)
  // d: the alarm goes off at the desired day mark     (eg: 1st of the month)
  // T: the alarm goes off at the desired Time mark    (at the defined Year, Month, Date, Weekday, Hour, Minute, Second)
  // T is the default option if the parameter is not recognized

  // The 3rd parameter is the MFP pin alarm state
  // 1 ==> idle LOW, alarm HIGH
  // 0 ==> idle HIGH, alarm LOW
  // It prioritizes the alarm0 setting
  RTC.unflagAlarm0();
  RTC.setAlarm0(alarm, 'S', 0);

  while (1)
  {
    Serial.print("Alarm!!! ");
    printDateTime(RTC.now());

    go_to_sleep();
    wake_up();

/*
    //rise and shine!
    Serial.print("Sending packet: ");
    Serial.println(counter);

    // send packet
    LoRa.beginPacket();
    LoRa.print("Take me to your leader! msg#");
    LoRa.print(counter++);
    LoRa.endPacket();
*/
    RTC.unflagAlarm0();
  }
}
