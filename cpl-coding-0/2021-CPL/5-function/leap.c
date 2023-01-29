//
// Created by hengxin on 10/16/21.
//

#include <stdio.h>

int IsLeapYear(int year);

int main() {
  int year;
  scanf("%d", &year);

  printf("The year %d is%s a leap year.\n",
         year,
         IsLeapYear(year) ? "" : " not");

  return 0;
}

int IsLeapYear(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}