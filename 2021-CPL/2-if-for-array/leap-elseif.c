//
// Created by hengxin on 10/16/21.
//

#include <stdio.h>

int main() {
  int year;
  scanf("%d", &year);

  if (year % 4 != 0) {
    printf("The year %d is a common year.\n", year);
  } else if (year % 100 != 0) {
      printf("The year %d is a leap year.\n", year);
  } else if (year % 400 != 0) {
    printf("The year %d is a common year.\n", year);
  } else {
    printf("The year %d is a leap year.\n", year);
  }

  return 0;
}