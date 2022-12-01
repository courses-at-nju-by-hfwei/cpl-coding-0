/**
 * file: decl.c
 *
 * Created by hengxin on 12/01/22.
 */

int main() {
  // argv is a pointer to pointer to char
  char **argv;

  // names is an array consisting of 10 pointers to int
  int *names[10];

  // musician_score_table is a pointer to an array
  // consisting of 10 integers
  int (*musician_score_table)[10];

  // StrCpyStd is a function
  int *StrCpyStd(char *dest, const char *src);


  // comp is a pointer to function returning int
  int (*comp)(const void *left, const void *right);

  // <stdlib.h>
  // Registers the function pointed to by func to be called on normal program termination.
  int atexit(void (*func)(void));

  // Sets the error handler for signal sig.
  // Previous signal handler on success or SIG_ERR on failure
  void (*signal(int sig, void (*handler)(int)))(int);

  // func is a function returning pointer to array[] of
  // pointer to function returning char
  char (*(*func(int num, char *str))[])();

  // array[3] of pointer to function
  // returning pointer to array[5] of char
  char (*(*arr[3])())[5];
}