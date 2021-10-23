//
// Created by hengxin on 10/16/21.
//

#include <stdio.h>

int main() {
  int dogs;
  printf("How many\n");
  scanf("%d", &dogs);
  printf("So %d\n", dogs);

  int a;
  int b;

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
