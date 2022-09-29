//
// file: circle.c
// Created by hfwei on 2022/9/29.
//

#include <stdio.h>

int main() {
  /*
   * see PPT
   */
  const double PI = 3.14159;
  int radius = 10;

  /*
   * `*`: operator (运算符)
   * `2 * PI * radius`: expression
   * `circumference = 2 * PI * radius;`: assignment statement
   */
  double circumference = 2 * PI * radius;
  double area = PI * radius * radius;

  // radius = 10, circumference = 62.831800, area = 314.159000
  printf("radius = %d, circumference = %f, area = %f\n",
         radius, circumference, area);

  // radius = 10, circumference = 62.83, area = 314.16
  printf("radius = %d, circumference = %.2f, area = %.2f\n",
         radius, circumference, area);

  return 0;
}