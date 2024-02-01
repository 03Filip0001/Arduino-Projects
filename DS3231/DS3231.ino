#include <DS3231.h>
#include <TM1637.h>

#include <Bounce2.h>

#define CLK 3
#define DIO 2

#define BTN 9

unsigned long int time, time1;

int hour = 0, min = 0, sec = 0, number;
String num, h, m, s;

int Day, Month, Year, date;
String Date, d, mo, y;

bool clock = true;
bool colon = false;

TM1637 tm1637(CLK, DIO);
DS3231 rtc(SDA, SCL);
Bounce btn = Bounce();

void setup() {
  tm1637.init();
  tm1637.setBrightness(5);
  rtc.begin();

  //rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(15, 19, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 11, 2019);   // Set the date to January 1st, 2014

  pinMode(CLK, OUTPUT);
  pinMode(DIO, OUTPUT);

  pinMode(BTN, INPUT_PULLUP);

  btn.attach(BTN);
  btn.interval(5);

  time = millis();
  time1 = millis();
}

void loop() {

  btn.update();

  if (btn.fell()) clock = !clock;

  //Serial.print(rtc.getDOWStr());

  //Serial.print(rtc.getDateStr());

  //Serial.print(h);

  //Serial.print("  ");

  //Serial.println(rtc.getDateStr());

  if (clock) {
    num = rtc.getTimeStr();

    h = num[0];
    h += num[1];

    m = num[3];
    m += num[4];

    s = num[6];
    s += num[7];

    hour = h.toInt();
    min = m.toInt();
    sec = s.toInt();

    if (millis() - time1 > 1000)
    {
      tm1637.switchColon();
      colon = !colon;
      time1 = millis();
    }
    number = hour * 100 + min;
    tm1637.dispNumber(number);
  }
  else if(!clock){
    Date = rtc.getDateStr();

    d = Date[0];
    d += Date[1];

    mo = Date[3];
    mo += Date[4];

    y = Date[6];
    y += Date[7];
    y += Date[8];
    y += Date[9];

    Day = d.toInt();
    Month = mo.toInt();
    Year = y.toInt();

    if(!colon) tm1637.switchColon();

    date = Day * 100 + Month;
    tm1637.dispNumber(date);
    }
}
