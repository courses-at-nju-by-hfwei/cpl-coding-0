/**
 * file: pointer.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <stdio.h>

int main() {
  /********** About radius **********/
  int radius = 10;

  printf("radius = %d\n", radius);

  // every variable has an address
  // &: address-of operator ("取地址"运算符)
  printf("The address of radius is %p\n", &radius);
  // we have already used the address of a variable before
  // scanf("%d", &radius);

  // radius as a left value; refer to its address (the storage space)
  radius = 20;
  // radius as a right value; refer to its value
  double circumference = 2 * 3.14 * radius;
  printf("radius = %d; circumference = %f\n", radius, circumference);
  /********** About radius **********/

  /********** About ptr_radius **********/
  // ptr_radius is a variable of type "pointer to int"
  int *ptr_radius = &radius;
  // ptr_radius is a variable: has its value
  printf("ptr_radius = %p\n", ptr_radius);
  // ptr_radius is a variable: has its address
  printf("The address of ptr_radius is %p\n", &ptr_radius);
  /********** About ptr_radius **********/

  /********** About *ptr_radius **********/

  // IMPORTANT:
  // *ptr_radius: behaves just like radius
  // type: int; value: the value of radius; address: the address of radius
  // *: indirection operator ("间接寻址"/"解引用"运算符)
  printf("radius = %d\n", *ptr_radius);
  // *ptr_radius as a right value
  circumference = 2 * 3.14 * (*ptr_radius);
  // take the address of *ptr_radius
  // &*ptr_radius is the same as ptr_radius
  printf("The address of *ptr_radius is %p\n", &*ptr_radius);
  // *ptr_radius as a left value
  *ptr_radius = 30;
  printf("radius = %d\n", *ptr_radius);
  /********** About *ptr_radius **********/

  /********** About ptr_radius again **********/
  // ptr_radius as a left value
  int radius2 = 100;
  int *ptr_radius2 = &radius2;

  ptr_radius = ptr_radius2;
  printf("radius = %d\n", *ptr_radius);

  // ptr_radius as a right value
  /********** About ptr_radius again **********/

  /********** About const **********/

  /********** About const **********/
}