//
// Created by hengxin on 10/9/21.
//

#include <stdio.h>

int main() {
  /**
   * (see scanf-input-1.md):
   * input
   * 1
   * -20    .3
   *    -4.0e3
   * From "C: Modern Approach"
   */
//  int i;
//  int j;
//  double x;
//  double y;
//  scanf("%d%d%lf%lf", &i, &j, &x, &y);

  /**
   * input: 56789 0123 56a72
   * From "The Standard C Library" (P243)
   */
//  int i;
//  float x;
//  char name[50];
//
//  scanf("%2d%f%*d %[0123456789]", &i, &x, name);

//  char thx[4];
//  int b;
//  int c;
//  sscanf("thx 1138", "%s%2o%d", thx, &b, &c);
//  printf("%s\t%d\t%d\n", thx, b, c);

//  int a;
//  scanf("%d", &a);
//  printf("a = %d\n", a);

  // NO: char name[3] = "Luo";
  char name[4] = "Luo";
  printf("%s\n", name);

  return 0;
}