/**
 * file: josephus.h
 *
 * Created by hengxin on 12/19/21.
 */

#include <stdio.h>
#include <stdlib.h>
#include "llist/llist.h"

void SitInCircle(int num);
void KillUntilOne(void);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: josephus num\n");
    return 0;
  }

  int num = strtol(argv[1], NULL, 10);
//  SitInCircle(num);
//  KillUntilOne();
//  printf("%d: %d\n", num, Head());

  for (int i = 1; i <= num; i++) {
    Init();
    SitInCircle(i);
    KillUntilOne();
    printf("%d: %d\n", i, Head());
  }

  Free();

  return 0;
}

void SitInCircle(int num) {
  for (int i = num; i > 0; i--) {
    Push(i);
  }
}

void KillUntilOne() {
  Node *node = head;

  while (! IsSingleton()) {
    Delete(node);
    node = node ->next;
  }
}