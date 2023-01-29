/**
 * file: gcd.c
 *
 * Iteratively computing the greatest common divisor of two integers.
 *
 * Euclidean algorithm:
 * gcd(a, b) = gcd(b, a % b)
 *
 * Created by hengxin on 11/01/22.
 */

#include <stdio.h>

int GCD(int a, int b);

int main() {
  int a = 130;
  int b = 124;

  printf("gcd(%d, %d) = %d\n", a, b, GCD(a, b));

  return 0;
}

int GCD(int a, int b) {
  int tmp;
  while (b != 0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }

  return a;
}