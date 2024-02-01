#include <LedControl.h>

LedControl LED=LedControl(A2,A3,9,4);

void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B11111000,
B00100000,
B00100010,
B00100000,
B00100010,
B00100000,
B00000000};

  /* now display them one by one with a small delay */
  LED.setRow(3,0,a[0]);
  LED.setRow(3,1,a[1]);
  LED.setRow(3,2,a[2]);
  LED.setRow(3,3,a[3]);
  LED.setRow(3,4,a[4]);
  LED.setRow(3,5,a[5]);
  LED.setRow(3,6,a[6]);
  LED.setRow(3,7,a[7]);
}

void writeArduinoOnMatrix0() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00011110,
B00010010,
B00010010,
B00010010,
B00010010,
B00010010,
B00011110};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix1() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00000010,
B00000110,
B00001010,
B00000010,
B00000010,
B00000010,
B00000010};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix2() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00001100,
B00010010,
B00000010,
B00000010,
B00000100,
B00001000,
B00011110};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix3() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00011110,
B00000010,
B00000010,
B00011110,
B00000010,
B00000010,
B00011110};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix4() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00010010,
B00010010,
B00010010,
B00011110,
B00000010,
B00000010,
B00000010};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix5() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00011110,
B00010000,
B00010000,
B00011110,
B00000010,
B00000010,
B00011110};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix6() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00011110,
B00010000,
B00010000,
B00011110,
B00010010,
B00010010,
B00011110};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix7() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00011110,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix8() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00011110,
B00010010,
B00010010,
B00011110,
B00010010,
B00010010,
B00011110};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void writeArduinoOnMatrix9() {
  /* here is the data for the characters */
  byte a[8]= {B00000000,
B00011110,
B00010010,
B00010010,
B00011110,
B00000010,
B00000010,
B00011110};

  /* now display them one by one with a small delay */
  LED.setRow(2,0,a[0]);
  LED.setRow(2,1,a[1]);
  LED.setRow(2,2,a[2]);
  LED.setRow(2,3,a[3]);
  LED.setRow(2,4,a[4]);
  LED.setRow(2,5,a[5]);
  LED.setRow(2,6,a[6]);
  LED.setRow(2,7,a[7]);
}

void setup() {
  Serial.begin(115200);
  LED.shutdown(3, false);
  LED.setIntensity(3,8);
  LED.clearDisplay(3);

  LED.shutdown(2, false);
  LED.setIntensity(2,8);
  LED.clearDisplay(2);

  writeArduinoOnMatrix();
}

void loop() {
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix0();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix1();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix2();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix3();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix4();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix5();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix6();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix7();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix8();
  delay(10);
  LED.clearDisplay(2);
  writeArduinoOnMatrix9();
  Serial.println(0 / 8);
}
