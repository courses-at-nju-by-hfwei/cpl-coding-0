/**
 * file: josephus-ll.c
 *
 * Created by hengxin on 12/19/21.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ll/ll.h"

void SitInCircle(LinkedList *list, int num);
void KillUntilOne(LinkedList *list);
int GetSurvivor(const LinkedList *list);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: josephus num\n");
    return 0;
  }
  int num = strtol(argv[1], NULL, 10);

  LinkedList list;
  for (int i = 1; i <= num; i++) {
    Init(&list);
    SitInCircle(&list, i);
    KillUntilOne(&list);
    printf("%d: %d\n", i, GetSurvivor(&list));
  }

  Free(&list);

  return 0;
}

void SitInCircle(LinkedList *list, int num) {
  for (int i = 1; i <= num; i++) {
    Append(list, i);
  }
}

void KillUntilOne(LinkedList *list) {
  Node *node = list->head;

  while (! IsSingleton(list)) {
    Delete(list, node);
    node = node ->next;
  }
}

int GetSurvivor(const LinkedList *list) {
  assert(IsSingleton(list));

  return Head(list);
}