//
// Created by hengxin on 10/16/21.
//

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }

  printf("%d\n", sum);

  return 0;
}