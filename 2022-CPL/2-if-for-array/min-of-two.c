// Created by hfwei on 2022/10/6.
//

#include <stdio.h>

int main() {
  int a = 0;
  int b = 0;

  scanf("%d%d", &a, &b);

  int min;
  if (a >= b) {
    min = b;
  } else {
    min = a;
  }

  printf("min{%d, %d} = %d\n", a, b, min);

  return 0;
}