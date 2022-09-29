//
// Given a radius (100) of a sphere,
// to compute its surface area and volume.
//
// Created by hengxin on 10/10/21.
//
// Terminal: gcc sphere.c -o sphere -lm
// CMake: target_link_libraries(sphere m)
//

#include <math.h>
#include <stdio.h>

int main() {
  const double PI = 3.14159;
  int radius = 100;

  double surface_area = 4 * PI * radius * radius;
  double volume = 3.0 / 4 * PI * pow(radius, 3);

  /**
   * Basic output
   * 125663.600000 : surface_area
   * 2356192.500000 : volume
   */
  printf("%f : surface_area \n%f : volume\n", surface_area, volume);

  /**
   * Expected output:
   * 125663.6000     : surface_area
   * 2356192.5000    : volume
   */
  printf("%-15.4f : surface_area \n%-15.4f : volume\n", surface_area, volume);

  return 0;
}