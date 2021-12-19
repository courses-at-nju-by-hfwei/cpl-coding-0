/**
 * file: llist.h
 *
 * Created by hengxin on 12/19/21.
 */

#ifndef C_PL_CODING_0_11_LINKEDLIST_LLIST_H_
#define C_PL_CODING_0_11_LINKEDLIST_LLIST_H_

#include <stddef.h>

// recursive declaration
typedef struct node {
  int val;
  struct node *next;
} Node;

extern Node *head;
extern Node *tail;

void Init(void);
int IsEmpty(void);
int IsSingleton(void);
int Head(void);
void Push(int val);
Node* Pop(void);
void Search(int val);
void Insert(Node *node, int val);

/**
 * Delete the node *after* this NODE.
 * The caller is responsible for ensuring that
 * node->next is a node in the list.
 *
 * @param node
 */
void Delete(Node *prev);

void Free(void);
void Print(void);

#endif //C_PL_CODING_0_11_LINKEDLIST_LLIST_H_