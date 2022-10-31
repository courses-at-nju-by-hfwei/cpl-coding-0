#include <stdio.h>
/**
 * file: fib-iter.c
 *
 * Iteratively computing the first n Fibonacci numbers
 *
 * Created by hengxin on 11/13/21.
*/

int main() {
  int n;
  scanf("%d", &n);

  long long fib1 = 0;
  long long fib2 = 1;
  printf("%lld %lld ", fib1, fib2);

  long long fib3;
  for (int i = 3; i < n; i++) {
    fib3 = fib1 + fib2;
    printf("%lld ", fib3);

    fib1 = fib2;
    fib2 = fib3;
  }

  return 0;
}