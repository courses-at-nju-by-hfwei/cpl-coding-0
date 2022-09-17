//
// Given a radius (10) of a circle,
// to compute its circumference and area.
//
// Created by hengxin on 10/10/21.
//

#include <stdio.h>

int main() {
  const double PI = 3.14159;
  int radius = 10;

  double circumference = 2 * PI * radius;
  double area = PI * radius * radius;

  /**
   * Basic output
   * circumference = 62.831800, area = 314.159000
   */
  printf("circumference = %f, area = %f\n", circumference, area);

  /**
   * Expected output
   * circumference = 62.83, area = 314.16
   */
  printf("circumference = %.2f, area = %.2f\n", circumference, area);

  return 0;
}