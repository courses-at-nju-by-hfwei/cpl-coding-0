//
// file: sphere.c
// Created by hfwei on 2022/9/29.
//

#include <stdio.h>
#include <math.h>

int main() {
  const double PI = 3.14159;
  int radius = 100;

  double surface_area = 4 * PI * radius * radius;
  double volume = 3.0 / 4 * PI * pow(radius, 3.0);

  printf("%.4f : surface_area \n%.4f : volume\n",
         surface_area, volume);

  printf("%-15.4f : surface_area \n%-15.4f : volume\n",
         surface_area, volume);

  return 0;
}
