//
// Created by hfwei on 2022/12/8.
//

#include <stdio.h>
#include <stdalign.h>
#include <string.h>
#include <stdlib.h>

typedef enum gender {
  MALE, FEMALE,
} Gender;

typedef struct score {
  int c_score;
  int java_score;
  int python_score;
} Score;

typedef struct musician {
  char *name;
  Gender gender;
  char *album;
  Score scores;
} Musician;

void PrintMusician(const Musician *musician);
int CompareMusicians(const void *m1, const void *m2);

int main() {
  Musician luo = {
      "Luo Dayou",
      MALE,
      "ZhiHuZheYe",
      20,
      30,
      40,
  };
  printf("sizeof luo : %zu\n", sizeof luo);
  printf("alignof Musician : %zu\n", alignof(Musician));
  printf("sizeof members in Musician : %zu\n",
         2 * sizeof(char *) + sizeof(char) + 3 * sizeof(int));

  Musician cui = {
      .name = "Cui Jian",
      .gender = MALE,
      .album = "XinChangZhengLuShangDeYaoGun",
      .scores = {20, 30, 40},
  };

  char album[] = "YiKeBuKenMeiSuDeXin";
  Musician zhang = {
      .name = "Zhang Chu",
      .gender = MALE,
      .album = album,
      .scores = {
          .c_score = 20,
          .java_score = 30,
          .python_score = 40,
      },
  };
  // PrintMusician(&zhang);

  // Musician guo = zhang;
  // guo.name = "guo";
  // strcpy(guo.album, "YiKeMeiSuDeXin");
  // PrintMusician(&guo);
  // PrintMusician(&zhang);

  Musician musicians[] = {luo, cui, zhang};
  int len = sizeof musicians / sizeof *musicians;
  for (int i = 0; i < len; i++) {
    PrintMusician(musicians + i);
  }

  qsort(musicians, len,
        sizeof *musicians, CompareMusicians);
  for (int i = 0; i < len; i++) {
    PrintMusician(musicians + i);
  }

  return 0;
}

void PrintMusician(const Musician *musician) {
  printf("\n%s\t%c\t%s\t%d\t%d\t%d\t\n",
         musician->name,
         musician->gender == MALE ? 'M' : 'F',
         musician->album,
         musician->scores.c_score,
         musician->scores.java_score,
         musician->scores.python_score);
}

int CompareMusicians(const void *m1, const void *m2) {
  return strcmp(((const Musician *) m1)->album,
                ((const Musician *) m2)->album);
}