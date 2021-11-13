/**
 * file: sum.c
 *
 * Recursively computing the sum of an array of integers
 *
 * Created by hengxin on 11/13/21.
 */

#include <stdio.h>

int Sum(const int numbers[], int len);

int main() {
  int numbers[5] = {1, 2, 3, 4, 5};
  printf("sum = %d\n", Sum(numbers, 5));

  return 0;
}

int Sum(const int numbers[], int len) {
  if (len == 0) {
    return 0;
  }

  return numbers[len - 1] + Sum(numbers, len - 1);
}