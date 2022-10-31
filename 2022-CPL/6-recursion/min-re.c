/**
 * file: min.c
 *
 * Recursively find the minimum of an array of integers
 *
 * Created by hengxin on 11/13/21.
 */

#include <stdio.h>

#define NUM 5
int numbers[NUM] = {0};

int Min(const int nums[], int len);
int MinOfTwo(int a , int b);

int main() {
  for (int i = 0; i < NUM; i++) {
    scanf("%d", &numbers[i]);
  }

  printf("min = %d\n", Min(numbers, NUM));

  return 0;
}

int Min(const int nums[], int len) {
  if (len == 1) {
    return nums[0];
  }

  return MinOfTwo(nums[len - 1], Min(nums, len - 1));
}

int MinOfTwo(int a, int b) {
  return a > b ? b : a;
}