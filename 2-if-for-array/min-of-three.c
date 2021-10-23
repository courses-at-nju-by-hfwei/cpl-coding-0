//
// Created by hengxin on 10/16/21.
//

#include <stdio.h>

int main() {
  int a;
  int b;
  int c;

  scanf("%d%d%d", &a, &b, &c);

  int min;
  if (a > b) {
    if (b > c) {
      min = c;
    } else {
      min = b;
    }
  } else {
    if (a > c) {
      min = c;
    } else {
      min = a;
    }
  }

//  int min_of_a_b;
//  if (a >= b) {
//    min_of_a_b = b;
//  } else {
//    min_of_a_b = a;
//  }
//
//  int min;
//  if (min_of_a_b >= c) {
//    min = c;
//  } else {
//    min = min_of_a_b;
//  }

  printf("min{%d, %d, %d} = %d\n", a, b, c, min);

  return 0;
}

