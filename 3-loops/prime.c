//
// Created by hengxin on 10/23/21.
//

#include <stdio.h>

int main() {
  int number = 0;
  scanf("%d", &number);

  int is_prime = 1;
  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      is_prime = 0;
      break;
    }
  }

  if (is_prime) {
    printf("%d is a prime number.\n", number);
  } else {
    printf("%d is not a prime number.\n", number);
  }

  return 0;
}