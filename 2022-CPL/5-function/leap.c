// Created by hfwei on 2022/10/6.
//

#include <stdio.h>
int main() {
  int year = 0;
  scanf("%d", &year);

  int leap = 0;

  // test: year = 25
  // test: year = 80
  // test: year = 100
  // test: year = 400
  if ((year % 4 == 0 && year % 100 != 0) ||
      (year % 400 == 0)) {
    leap = 1;
  }

//  if (leap == 0) {
//    printf("The year %d is a common year.\n", year);
//  } else {
//    printf("The year %d is a leap year.\n", year);
//  }

  printf("The year %d is a %s year.\n", year, leap? "leap" : "common");

  return 0;
}
