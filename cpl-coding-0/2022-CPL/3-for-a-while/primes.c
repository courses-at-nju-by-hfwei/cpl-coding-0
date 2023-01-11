// Created by hfwei on 2022/10/13.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main() {
  int max = 0;
  scanf("%d", &max);

  int count = 0;
  clock_t start = clock();
  for (int number = 2; number <= max; number++) {
    // why 1? why not 0?
//    int is_prime = 1;
    // since C99
    bool is_prime = true;

    for (int i = 2; i * i <= number; i++) {
      if (number % i == 0) {
//        is_prime = 0;
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      count++;
      printf("%d ", number);
    }
  }
  clock_t end = clock();

  printf("\ncount = %d in %f seconds\n",
         count, (double) (end - start) / CLOCKS_PER_SEC);

  return 0;
}