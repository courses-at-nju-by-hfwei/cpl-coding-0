/**
 * file: ll.c
 *
 * Created by hengxin on 12/19/21.
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "ll.h"

void Init(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

bool IsEmpty(const LinkedList *list) {
  return (list->head == NULL);
}

bool IsSingleton(const LinkedList *list) {
  return (! IsEmpty(list)) &&
         (list->head == list->tail);
}

int Head(const LinkedList *list) {
  return list->head->val;
}

Node *Search(const LinkedList *list, int val) {
  if (IsEmpty(list)) {
    return NULL;
  }

  Node *iter = list->head;
  do {
    if (iter->val == val) {
      return iter;
    }
    iter = iter->next;
  } while (iter != list->head);

  return NULL;
}

void Append(LinkedList *list, int val) {
  Node *node = malloc(sizeof *node);
  if (node == NULL) {
    printf("Error: malloc failed in Append()\n");
    return;
  }
  node->val = val;

  if (list->tail == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }

  list->tail = node;
  node->next = list->head;
}

void Insert(LinkedList *list, Node *prev, int val) {
  Node *node = malloc(sizeof *node);
  if (node == NULL) {
    printf("Error: malloc failed in Insert()\n");
    return;
  }
  node->val = val;

  node->next = prev->next;
  prev->next = node;

  if (prev == list->tail) {
    list->tail = node;
  }
}

void Delete(LinkedList *list, Node *prev) {
  Node *cur = prev->next;
  Node *next = cur->next;
  prev->next = next;

  if (cur == prev) {
    list->head = NULL;
    list->tail = NULL;
    free(cur);
    return;
  }

  if (cur == list->head) {
    list->head = next;
  }

  if (cur == list->tail) {
    list->tail = prev;
  }

  free(cur);
}

void Print(const LinkedList *list) {
  if (IsEmpty(list)) {
    return;
  }

  Node *iter = list->head;
  do {
    printf("%d\t", iter->val);
    iter = iter->next;
  } while (iter != list->head);
}

void Free(LinkedList *list) {
  while (! IsEmpty(list)) {
    Delete(list, list->head);
  }
}