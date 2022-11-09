//
// Created by hfwei on 2022/11/9.
//

#include <stdio.h>
#include <float.h>

int main() {
  // 3.40282 * 10^38
  printf("FLT_MAX = %f\n", FLT_MAX);
  // TODO:
  printf("FLT_MIN = %f\n", FLT_MIN);
  printf("FLT_TRUE_MIN = %f\n", FLT_TRUE_MIN);
  // TODO:
  printf("FLT_EPSILON = %f\n\n", FLT_EPSILON);

  // %lf for scanf; %lf for printf since C99
  // 1.79769 * 10^308
  printf("DBL_MAX = %f\n", DBL_MAX);
  // TODO:
  printf("DBL_MIN = %f\n\n", DBL_MIN);

  // TODO:
  printf("LDBL_MAX = %Lf\n", LDBL_MAX);

  return 0;
}