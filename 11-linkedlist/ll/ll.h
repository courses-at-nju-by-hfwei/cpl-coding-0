/**
 * file: ll.h
 *
 * Created by hengxin on 12/19/21.
 */

#include <stdbool.h>

#ifndef C_PL_CODING_0_11_LINKEDLIST_LL_LL_H_
#define C_PL_CODING_0_11_LINKEDLIST_LL_LL_H_

typedef struct node {
  int val;  // void *val;
  struct node *next;
} Node;

typedef struct ll {
  Node *head;
  Node *tail;
} LinkedList;

void Init(LinkedList *list);

bool IsEmpty(const LinkedList *list);
bool IsSingleton(const LinkedList *list);

int Head(const LinkedList *list);
Node *Search(const LinkedList *list, int val);

void Append(LinkedList *list, int val);
/**
 * The caller is responsible for ensuring that
 * *prev is a pointer to a node in the list.
 *
 * @param list
 * @param prev
 * @param val
 */
void Insert(LinkedList *list, Node *prev, int val);
void Delete(LinkedList *list, Node *prev);

void Free(LinkedList *list);
void Print(const LinkedList *list);

#endif //C_PL_CODING_0_11_LINKEDLIST_LL_LL_H_