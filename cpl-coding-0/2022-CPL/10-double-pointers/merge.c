//
// Created by hengxin on 10/19/22.
//

#include <stdio.h>
#include <stdlib.h>

#define LEN_L 4
#define LEN_R 5

int *Merge(const int L[], int llen, const int R[], int rlen);

int main() {
  int L[LEN_L] = {2, 4, 6, 8};
  int R[LEN_R] = {1, 3, 5, 7, 9};

  int *merge = Merge(L, LEN_L, R, LEN_R);

  for (int i = 0; i < LEN_L + LEN_R; i++) {
    printf("%d ", merge[i]);
  }

  return 0;
}

int *Merge(const int L[], int llen, const int R[], int rlen) {
  int *merge = malloc((llen + rlen) * sizeof *merge);

  int l = 0;
  int r = 0;
  int m = 0;

  while (l < llen && r < rlen) {
    if (L[l] <= R[r]) {
      merge[m++] = L[l];
      l++;
    } else { // L[l] > R[r]
      merge[m++] = R[r];
      r++;
    }
  }

  while (l < llen) {
    merge[m++] = L[l];
    l++;
  }

  while (r < rlen) {
    merge[m++] = R[r];
    r++;
  }

  return merge;
}