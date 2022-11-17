/**
 * file: pointer.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  /********** On radius **********/
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
  /********** On radius **********/

  /********** On ptr_radius **********/
  // ptr_radius is a variable of type "pointer to int"
  int *ptr_radius = &radius;
  // ptr_radius is a variable: has its value
  printf("ptr_radius = %p\n", ptr_radius);
  // ptr_radius is a variable: has its address
  printf("The address of ptr_radius is %p\n", &ptr_radius);
  /********** On ptr_radius **********/

  /********** On *ptr_radius **********/

  // IMPORTANT:
  // *ptr_radius: behaves just like radius
  // type: int; value: the value of radius; address: the address of radius
  // *: indirection/dereference operator ("间接寻址"/"解引用"运算符)
  printf("radius = %d\n", *ptr_radius);
  // *ptr_radius as a right value
  circumference = 2 * 3.14 * (*ptr_radius);
  // take the address of *ptr_radius
  // &*ptr_radius is the same as ptr_radius
  printf("The address of *ptr_radius is %p\n", &*ptr_radius);
  // *ptr_radius as a left value
  *ptr_radius = 30;
  printf("radius = %d\n", *ptr_radius);
  /********** On *ptr_radius **********/

  /********** On ptr_radius again **********/
  // ptr_radius as a left value
  int radius2 = 100;
  int *ptr_radius2 = &radius2;

  ptr_radius = ptr_radius2;
  printf("radius = %d\n", *ptr_radius);

  // ptr_radius as a right value
  /********** On ptr_radius again **********/


  /********** On array names **********/
  int numbers[5] = {0};
  // vs. numbers[2] = {2};
  // numbers++;
  // numbers = &radius;
  int *ptr_array = numbers;
  ptr_array++;
  /********** On array names **********/

  /********** On malloc/free **********/
  // undefined behavior
  // free(numbers);
  /********** On malloc/free **********/

  /********** On const **********/
  const int *ptr_radius3 = &radius;
  // *ptr_radius3 = 50;
  radius = 50;
  int *ptr_radius4 = ptr_radius3;
  *ptr_radius4 = 100;
  printf("radius = %d\n", radius);
  /********** On const **********/
}