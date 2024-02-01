#define A 2
#define B 3
#define C 4
#define D 5
#define DIS_1 10
#define DIS_2 11
#define DIS_3 12

int bin_numbers[10][4] = 
{
  {0,0,0,0}, // 0
  {1,0,0,0}, // 1
  {0,1,0,0}, // 2
  {1,1,0,0}, // 3
  {0,0,1,0}, // 4
  {1,0,1,0}, // 5
  {0,1,1,0}, // 6
  {1,1,1,0}, // 7
  {0,0,0,1}, // 8
  {1,0,0,1}  // 9
  };

int number = 0, x = 1;
int hundreds, tithes, singular;
