/**
 * Merge two sorted arrays into one
 *
 * Created by hengxin on 10/30/21.
 */

#include <stdio.h>
#include <math.h>

#define LEN_L 5
#define LEN_R 6

int L[LEN_L] = {1, 3, 5, 7, 9};
int R[LEN_R] = {0, 2, 4, 6, 8, 10};

/**
 * Please fill in the comment.
 *
 * @param left
 * @param len_left
 * @param right
 * @param len_right
 */
void Merge(const int left[], int len_left, const int right[], int len_right);

int main() {
  Merge(L, LEN_L, R, LEN_R);
  return 0;
}

void Merge(const int left[], int len_left, const int right[], int len_right) {
  int l = 0;
  int r = 0;

  while (l < len_left && r < len_right) {
    if (left[l] <= right[r]) {
      printf("%d ", left[l]);
      l++;
    } else { // left[l] > right[r]
      printf("%d ", right[r]);
      r++;
    }
  }

  while (l < len_left) {
    printf("%d ", left[l]);
    l++;
  }
  while (r < len_right) {
    printf("%d ", right[r]);
    r++;
  }
}
