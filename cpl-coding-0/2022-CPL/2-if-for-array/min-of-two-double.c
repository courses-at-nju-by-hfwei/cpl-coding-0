// Created by hfwei on 2022/10/6.
//

#include <stdio.h>
int main() {
  double a = 0.0;
  double b = 0.0;

  scanf("%lf%lf", &a, &b);

  double min;

  // do not use >= for doubles
  if (a >= b) {
    min = b;
  } else {
    min = a;
  }

  printf("min{%.20f, %.20f} = %.20f\n", a, b, min);

  return 0;
}
