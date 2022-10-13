// Created by hfwei on 2022/10/13.
//

#include <stdio.h>
#include <math.h>

int main() {
  int max = 0;
  scanf("%d", &max);

  for (int number = 2; number <= max; number++) {
    // why 1? why not 0?
    int is_prime = 1;

    for (int i = 2; i < ceil(sqrt(number)); i++) {
      if (number % i == 0) {
        is_prime = 0;
        break;
      }
    }

    if (is_prime) {
      printf("%d ", number);
    }
  }

  return 0;
}