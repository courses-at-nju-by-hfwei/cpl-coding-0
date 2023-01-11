#include <stdio.h>

/**
 * file: fib.c
 *
 * Recursively computing the n-th Fibonacci number
 *
 * Created by hengxin on 11/13/21.
 */

int Fib(int n);

int main() {
  int n;
  scanf("%d", &n);

  printf("%d\n", Fib(n));
}

int Fib(int n) {
  if (n == 1) {
    return 0;
  }

  if (n == 2) {
    return 1;
  }

  return Fib(n - 1) + Fib(n - 2);
}