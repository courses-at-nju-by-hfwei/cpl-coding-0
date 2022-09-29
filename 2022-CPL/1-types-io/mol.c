//
// Created by hengxin on 9/29/22.
//

#include <stdio.h>
int main() {
  const double MOL = 6.02e23;
  const int GRAM_PER_MOL = 32;
  int mass = 6;

  double quantity = (mass * 1.0) / GRAM_PER_MOL * MOL;

  printf("quantity = %f\n", quantity);

  printf("quantity = %e\nquantity = %g\n",
         quantity, quantity);

  printf("quantity = %.3e\nquantity = %.5g",
         quantity, quantity);

  return 0;
}