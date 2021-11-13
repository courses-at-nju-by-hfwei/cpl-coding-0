/**
 * file: fib-iter.c
 *
 * Iteratively computing the first n Fibonacci numbers
 *
 * Created by hengxin on 11/13/21.
 */

#include <stdio.h>
#include <limits.h>

#define MAX 93
long long fibs[MAX] = {0, 1};

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 2; i < n; i++) {
    fibs[i] = fibs[i - 1] + fibs[i - 2];
  }

  for (int i = 0; i < n; i++) {
    printf("%lld ", fibs[i]);
  }

  printf("\n%lld\n", LLONG_MAX);

  return 0;
}