// Created by hfwei on 2022/10/6.
//

#include <stdio.h>
#include <stdbool.h>

// function declaration: function definition without the function body
bool IsLeapYear(int year);

int main() {
  // `year`: is a local variable in the main function
  // (1) storage duration: exist with the main function
  // (2) scope (life time): from its definition to the end of the main function
  int year = 0;
  scanf("%d", &year);

  // IsLeapYear(year): call by value
  printf("The year %d is a %s year.\n", year,
         IsLeapYear(year) ? "leap" : "common");

  return 0;
}

// function definition
// year is a formal parameter (形式参数) of the function IsLeapYear
// (1) storage duration
// (2) scope
bool IsLeapYear(int year) {
  return ((year % 4 == 0 && year % 100 != 0) ||
      (year % 400 == 0));
}