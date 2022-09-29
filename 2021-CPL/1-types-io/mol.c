//
// 6 克氧气的物质的量是多少?
//
// Created by hengxin on 10/10/21.
//

#include <stdio.h>

int main() {
  const double MOL = 6.02e23;
  const int GRAM_PER_MOL = 32;
  int mass = 6;

  double quantity = (mass * 1.0) / MOL_PER_GRAM * MOL;

  /**
   * Basic output
   * quantity = 112875000000000003407872.000000
   */
  printf("quantity = %f\n", quantity);

  /**
   * Basic output
   * quantity = 1.128750e+23
   * quantity = 1.12875e+23
   */
  printf("quantity = %e\nquantity = %g\n", quantity, quantity);

  /**
   * Expected output
   * quantity = 1.129e+23
   * quantity = 1.1288e+23
   */
  printf("quantity = %.3e\nquantity = %.5g\n", quantity, quantity);

  return 0;
}