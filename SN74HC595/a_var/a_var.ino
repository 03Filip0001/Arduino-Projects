#include "Bounce2.h"

#define BTN_1 2
#define BTN_2 3

#define clock_pin 3
#define data_pin 4
#define lock_pin 2

#define DIS_1 7
#define DIS_2 8
#define DIS_3 9

Bounce btn1 = Bounce();
Bounce btn2 = Bounce();

int wait = 5; // za delay

bool count = false;
int i = 1;
int number = 0;
long unsigned int time1 = 0;

int value1 = false;
int value2;

int hundreds, tithes, singular;

int numbers[10][2] = 
{
  {0, 252},
  {1, 96},
  {2, 218},
  {3, 242},
  {4, 102},
  {5, 182},
  {6, 190},
  {7, 224},
  {8, 254},
  {9, 246}
};
/*
  {0,0,1,1,1,1,1,1}, 11111100 // 0
  {0,0,0,0,0,1,1,0}, 01100000 // 1
  {0,1,0,1,1,0,1,1}, 11011010 // 2
  {0,1,0,0,1,1,1,1}, 11110010 // 3
  {0,1,1,0,0,1,1,0}, 01100110 // 4
  {0,1,1,0,1,1,0,1}, 10110110 // 5
  {0,1,1,1,1,1,0,1}, 10111110 // 6
  {0,0,0,0,0,1,1,1}, 11100000 // 7
  {0,1,1,1,1,1,1,1}, 11111110 // 8
  {0,1,1,0,1,1,1,1}  11110110 // 9
*/
