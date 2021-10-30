/**
 * Test whether two arrays A and B have an element in common
 *
 * Created by hengxin on 10/30/21.
 */

#include <stdio.h>
#define LEN_A 5
#define LEN_B 5

int a[LEN_A] = {1, 3, 5, 7, 9};
int b[LEN_B] = {2, 4};

int main() {
//  int found = 0;

  /**
   * "break" version
   */
//  for (int i = 0; i < LEN_A && (! found); i++) {
//    for (int j = 0; j < LEN_B; j++) {
//      if (a[i] == b[j]) {
//        found = 1;
//        break;
//      }
//    }
//  }
//
//  if (found) {
//    printf("Yes.\n");
//  } else {
//    printf("No.\n");
//  }

  /**
   * "goto" version
   */
  for (int i = 0; i < LEN_A; i++) {
    for (int j = 0; j < LEN_B; j++) {
      if (a[i] == b[j]) {
        printf("Yes.\n");
        goto found;
      }
    }
  }
  printf("No.\n");

found:

  return 0;
}
