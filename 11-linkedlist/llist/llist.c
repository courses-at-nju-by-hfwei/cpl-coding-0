/**
 * file: llist.c
 *
 * Created by hengxin on 12/19/21.
 */

#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

Node *head = NULL;
Node *tail = NULL;

void Init() {
  head = tail = NULL;
}

int IsEmpty() {
  return (head == NULL);
}

int IsSingleton() {
  return (head == tail) && (head != NULL);
}

int Head() {
  return head->val;
}

void Push(int val) {
  Node *node = malloc(sizeof(*node));
  if (node == NULL) {
    printf("Error: malloc failed in Push()\n");
    exit(EXIT_FAILURE);
  }
  node->val = val;

  node->next = head;
  head = node;

  if (tail == NULL) {
    tail = head;
  }
  tail->next = head;
}

void Delete(Node *prev) {
  Node *cur = prev->next;
  Node *next = cur->next;
  prev->next = next;

  if (cur == prev) {
    head = tail = NULL;
    free(cur);
    return;
  }

  if (cur == head) {
    head = next;
  }

  if (cur == tail) {
    tail = prev;
  }

  free(cur);
}

void Print() {
  if (IsEmpty()) {
    return;
  }

  Node *iter = head;
  do {
    printf("%d\t", iter->val);
    iter = iter->next;
  } while (iter != head);
}

void Free() {
  // TODO:
}