// Created by hfwei on 2022/10/6.
//

#include <stdio.h>
int main() {
  int a;
  int b;
  int c;

  scanf("%d%d%d", &a, &b, &c);

  int min;
  if (a > b) {
    if (b > c) { // a > b > c
      min = c;
    } else { // a > b and b <= c
      min = b;
    }
  } else { // a <= b
    if (a > c) { // c < a <= b
      min = c;
    } else { // a <= b and a <= c
      min = a;
    }
  }

  printf("min{%d, %d, %d} = %d\n", a, b, c, min);

  return 0;
}
