//
// Created by hfwei on 2022/9/17.
//

// (1)
//#include <stdio.h>
//
//int main() {
//   int i;
//   double x;
//   double y;
//
//    scanf("%lf%d%lf", &x, &i, &y);
//    printf("%f %d %f", x, i, y);
//
//    return 0;
//}

//void f(char *dest, const char *src) {
//    while ((*dest++ = *src++));
//}

//#include <stdio.h>

//void qsort(void *ptr, size_t count, size_t size,
//           int (*comp)(const void *, const void *));

//#include <stdio.h>
//
//#define abs(x) x > 0 ? x : (-x)
//
//int main() {
//  int a = 1;
//  int b = 2;
//  printf("%d\n", abs(a - b));
//
//  return 0;
//}

#include <stdio.h>

int main() {
    int array[] = {1, 2};

    int i = -1;
    if (i <= sizeof array) {
        printf("<=\n");
    } else {
        printf(">");
    }

    return 0;
}

//#include <stdio.h>
//
//int *f();
//int i = 42;
//
//int main() {
//  const int *p = f();
//  printf("%d", *p);
//
//  return 0;
//}
//
//int *f() {
//  int i = 100;
//  return &i;
//}

// A. void f(int array[][]);
// B. void f(int (*array)[2]);
// C. void f(int (*)[2]);
// D. void f(int array[][2]);

//#include <stdio.h>
//
//int f(const int *array);
//
//int main() {
//    int array[] = {1, 2, 3, 4, 5, 6} ;
//
//    printf("%zu %d", sizeof array, f(array));
//
//    return 0;
//}
//
//int f(const int *array) {
//    return sizeof array;
//}

//#include <stdio.h>
//
//typedef struct musician {
//  int age;
//  char *name;
//} Musician;
//
//int main() {
//  Musician luo = {.age = 67, .name = "Luo"};
//  Musician *cui = &luo;
//  cui->age = 61;
//  cui->name = "Cui";
//  printf("%d %s; %d %s",
//         luo.age, luo.name, cui->age, cui->name);
//}
