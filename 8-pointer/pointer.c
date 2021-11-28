/**
 * file: pointer.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <stdio.h>

int main() {
  int radius = 10;

  printf("radius = %d\n", radius);
  printf("&radius = %p\n", &radius);

  double circumference = 2 * 3.14 * radius;
  radius = 20;
  printf("radius = %d; circumference = %f\n", radius, circumference);
  printf("&radius = %p\n", &radius);

  int *ptr_radius = &radius;
  circumference = 2 * 3.14 * (*ptr_radius);
  *ptr_radius = 30;

  printf("radius = %d; circumference = %f\n", *ptr_radius, circumference);
  printf("&radius = %p\n", &radius);

  int radius_2 = 100;
  int *ptr_radius_2 = &radius_2;

  ptr_radius = ptr_radius_2;
  printf("radius = %d\n", *ptr_radius);

  *ptr_radius_2 = 200;
  printf("radius = %d\n", *ptr_radius);

  /**
   * Unfortunately, the compiler only complains about this!!!
   */
  const int radius_3 = 1000;
  ptr_radius = &radius_3;
  *ptr_radius = 2000;
  printf("radius = %d\n", *ptr_radius);
  printf("radius = %d\n", radius_3);

  return 0;
}