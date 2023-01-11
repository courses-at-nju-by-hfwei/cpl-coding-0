//
// file: primes.c
// description: counting primes between 1 and max
// author: hfwei
// date: 2022/10/28.
//

// TODO:
// (1) [] the basic version
// (2) [] test the basic version
// (3) [] the `break` version
// (4) [] the `power` version
// (5) [] `if (is_prime == 1) vs. if (is_prime)`
// (6) [] `bool`: `true` and `false`
// (7) [] (optional) timing

#include <stdio.h>
#include <stdbool.h>

int main() {
  int max = 0;
  scanf("%d", &max);

  // adding code below
  int count = 0;
  for (int number = 2; number <= max; number++) {
    // check whether number is a prime number
    // >= C99: bool
    // C23: true/false may become keywords
    bool is_prime = true; // indicator variable
    // e.g., number = 15
    // e.g., number = 25
    for (int i = 2; i * i <= number; i++) {
      // check whether i is a factor of number
      if (number % i == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      count++;
      printf("%d ", number);
    }
  }

  printf("\ncount = %d\n", count);

  return 0;
}