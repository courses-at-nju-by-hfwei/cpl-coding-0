/**
 * file: min-max.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <stdio.h>
#define LEN 20
int numbers[LEN] = {0};

void MinMax(const int nums[], int len, int *min, int *max);

int main() {
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);

  int min = 0;
  int max = 0;
  MinMax(numbers, len, &min, &max);

  printf("min = %d, max = %d\n", min, max);

  return 0;
}

void MinMax(const int nums[], int len, int *min, int *max) {
  *min = nums[0];
  *max = nums[0];

  for (int i = 1; i < len; i++) {
    if (nums[i] < *min) {
      *min = nums[i];
    }

    if (nums[i] > *max) {
      *max = nums[i];
    }
  }
}
