/**
 * file: musician.c
 *
 * Created by hengxin on 12/12/21.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum gender {
  MALE, FEMALE
} Gender;

typedef struct score {
  int c_score;
  int java_score;
  int python_score;
} Score;

typedef struct musician {
  char *name;
//  enum {MALE, FEMALE} gender;
  Gender gender;

  char *album;

  Score score;
} Musician;

void PrintMusician(const Musician *m);
int TotalScore(const Musician *m);
int CompareMusicians(const void *m1, const void *m2);

int main() {
//  char *name = "Luo Dayou";
//  char *album = NULL;
//  int c_score = 0;
//  int java_score = 10;
//  int python_score = 20;

  Musician luo = {
      "Luo Dayou", MALE,
      "之乎者也",
      20, 30, 40
  };

  Musician cui = {
      .name = "Cui Jian",
      .gender = MALE,
      .album = "新长征路上的摇滚",
      .score = {
          .c_score = 10,
          .java_score = 20,
          .python_score = 30
      }
  };

  Musician zhang = {
      .name = "Zhang Chu",
      .gender = MALE,
//      .album = "一颗不肯媚俗的心",
      .score = {
        .c_score = 0,
        .java_score = 10,
        .python_score = 20
      }
  };
  zhang.album = malloc(50 * sizeof *zhang.album);
  strcpy(zhang.album, "一颗不肯媚俗的心");

  PrintMusician(&luo);
  PrintMusician(&cui);
  PrintMusician(&zhang);

  Musician li = zhang;
  li.name = "Li Chaoxi";
  // It is even possible for an enum variable
  // to hold an integer that does not represent any of the enumeration values.
  li.gender = 'F';
  strcpy(li.album, "两颗不肯媚俗的心");

  PrintMusician(&li);
  PrintMusician(&zhang);

  Musician musicians[] = {luo, cui, zhang};
  int len = sizeof musicians / sizeof *musicians;
  for (int i = 0; i < len; i++) {
    PrintMusician(musicians + i);
  }

  qsort(musicians, len, sizeof(*musicians), CompareMusicians);
  for (int i = 0; i < len; i++) {
    PrintMusician(musicians + i);
  }

  free(zhang.album);
}

void PrintMusician(const Musician *m) {
  printf("\n");
  printf("%s\n%c\n%s\n%d\t%d\t%d\n",
         m->name,
         m->gender == MALE ? 'M' : 'F',
         m->album,
         m->score.c_score, m->score.java_score, m->score.python_score);
  printf("\n");
}

int CompareMusicians(const void *m1, const void *m2) {
  return TotalScore(m1) - TotalScore(m2);
}

int TotalScore(const Musician *m) {
  return m->score.c_score + m->score.java_score + m->score.python_score;
}