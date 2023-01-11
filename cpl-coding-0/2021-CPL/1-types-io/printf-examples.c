//
// Created by hengxin on 10/9/21.
//

#include <stdio.h>
#include <limits.h>

int main() {
  printf("INT_MIN = %d \t INT_MAX = %d\n", INT_MIN, INT_MAX);

  /*
   * Test: precision when printing an integer
   */
  printf("INT_MAX = %.20d\n", INT_MAX);
  int zero = 0;
  printf("zero = %.0d\n", zero);

  printf("%c\n", 0x97);

  /**
   * To print a date and time in the form "Monday, October 11, 09:20"
   * followed by PI to five decimal places.
   *
   * From "The Standard C Library" (Page 240)
   */
//   char weekday[] = "Monday";
//   char month[] = "October";
//   int day = 11;
//   int hour = 9;
//   int minute = 0;
//
//   printf("\n");
//   printf("\n");

  return 0;
}