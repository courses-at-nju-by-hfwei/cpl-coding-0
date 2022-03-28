//
// Created by hengxin on 3/27/22.
//

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

//int atexit( void (*func)(void) );

//void (*signal( int sig, void (*handler) (int))) (int);

//int (*decl1)[13];
//int *decl2[13];

//void* bsearch( const void *key, const void *ptr,
//               size_t count, size_t size,
//               int (*comp)(const void*, const void*) );

//void qsort( void *ptr, size_t count, size_t size,
//            int (*comp)(const void *, const void *) );

//char * const src1;
//const char *src2;

//#define abs(x) ((x) > 0 ? (x) : -(x))

//#define abs(x) x > 0 ? x : -x
//
//int main() {
//  int a = 1;
//  int b = 2;
//  printf("%d\n", abs(a - b));
//
//  return 0;
//}

//#define square(x) x * x
//
//int main() {
//  int a = 1;
//  int b = 2;
//  printf("%d\n", square(a + b));
//
//  return 0;
//}

/**
gcc -DDEBUG=1 debug.c -o debug
./debug
**/

int main() {
#if DEBUG
  printf("DEBUG");
#endif
  printf(" OR NOT DEBUG");

  return 0;
}

//int main() {
//  unsigned short i = 13;
//  unsigned short j;
//
//  j = i << 2;
//  printf("%d\n", j);
//
//  j = i >> 2;
//  printf("%d\n", j);
//
//  return 0;
//}
//
//// A. void f(int *array);
//// B. void f(int *array, int len);
//// C. void f(int array[10]);
//// D. void f(int array[int len]);
//
//int main() {
//
//}

//// A. void f(int (*array)[2]);
//// B. void f(int array[][]);
//// C. void f(int array[3][2]);
//// D. void f(int array[][2]);
//
//int main() {
//
//}

//int main() {
//  unsigned short i = 13;
//  unsigned short j;
//
//  j = i <<= 2;
//  printf("%d\n", j);
//
//  j = i >>= 2;
//  printf("%d\n", j);
//
//  return 0;
//}

//typedef struct node {
//  int val;
//  struct node *next;
//} Node;

//typedef struct node {
//  int val;
//  Node *next;
//} Node;

//int *f();
//
//int main() {
//  const int *p = f();
//  printf("%d", *p);
//
//  return 0;
//}
//
//int *f() {
//  int i = 42;
//  // more code here
//  return &i;
//}

//char *color[] = {"red", "green", "blue"};

//int main() {
////  int * const p;
////  const int *q;
//}

//size_t f(const char *s);
//int main() {
//  char msg[20] = "Hello World!";
//  printf("%zu\n", f(msg));
//
//  return 0;
//}
//
//size_t f(const char *s) {
//  const char *sc;
//  for (sc = s; *sc != '\0'; sc++);
//
//  return (sc - s);
//}

//int main() {
////  A. int *p; p[3] = 10;
////  B. int q[];
////  C. int *pp; int array[10]; pp = array;
////  D. int *qq; int array2[10]; array2 = qq;
//}

//int main() {
//  int a[5] = {0};
//
//  a++;
//  a--;
//}

//int main() {
//  int a[5] = {0};
//
//  A. printf("%d\n", a[3]);
//  B. printf("%d\n", *(a + 3));
//  C. printf("%d\n", *(3 + a));
//  D. printf("%d\n", 3[a]);
//
//  return 0;
//}

//int main() {
//  int *p;
////  A. *--p;
////  B. (*p)--;
////  C. *p--;
////  D. --*p;
//}

//int main() {
//  int *p;
////  A. *++p;
////  B. (*p)++;
////  C. *p++;
////  D. ++*p;
//}

//int main() {
//  int array1[2] = {};
//  int array2[2] = {0};
//  int array3[2] = {1, 2, 3};
//  int array4[] = {1, 2, 3};
//
//  return 0;
//}

//#define LEN 10
//int main() {
//  int array[LEN] = {0};
//  for (int i = 0; i <= LEN; i++) {
//    array[i] = i;
//  }
//
//  return 0;
//}

//int main() {
//  int i;
//  int j;
//  double d;
//
//  scanf("%d%lf%d", &i, &d, &j);
//
//  printf("%d %f %d\n", i, d, j);
//
//  return 0;
//}

//int main() {
//  double d;
//
//  scanf("%lf", &d);
//
//  printf("%f\n", d);
//
//  return 0;
//}

//int main() {
//  int i = 42;
//  double d = 3.14;
//
//  printf("%d %d", i, d);
//
//  return 0;
//}

//// gcc pow.c -o pow

//#include<math.h>
//
//int main() {
//  printf("%f\n", pow(2, 3));
//
//  return 0;
//}

//int main() {
//  const char *luo = "Luo";
//  const char *zhang = "zhang";
//  if (strlen(luo) - strlen(zhang) > 0) {
//    printf(">");
//  } else {
//    printf("<=");
//  }
//
//  return 0;
//}

//int main() {
//  int array[] = {1, 2 };
//  int i = -1;
//  if (i <= sizeof array) {
//    printf("<=\n");
//  } else {
//    printf(">");
//  }
//
//  return 0;
//}

//typedef struct musician {
//  int age;
//  char *name;
//} Musician;
//
//int main() {
//  Musician luo = {.age = 67, .name = "Luo"};
//  Musician cui = luo;
//  cui.age = 61;
//  cui.name = "Cui";
//  printf("%d %s; %d %s",
//         luo.age, luo.name, cui.age, cui.name);
//}

//int main() {
//  int len = 0;
//  scanf("%d", &len);
//  int *numbers = malloc(len * sizeof *numbers);
//}

//int main(char *argv[]) {
//  printf("Hello World.");
//}

//int main(int argc, char *argv[]) {
//
//}