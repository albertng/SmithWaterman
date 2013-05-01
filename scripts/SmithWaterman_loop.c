#include <stdio.h>
#include <time.h>

const int MATCH = 2;
const int MISMATCH = -1;
const int GAP = -1;

int main(void) {
  int max_score = 0;
  char* short_read = "ACAGACTA";
  char* reference = "AGCACACA";
  int insertion_score, deletion_score, match_score, i, j, k;
  int scoring_matrix[9][9];
  clock_t start, diff;
  float cups;

  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      scoring_matrix[i][j] = 0;
    }
  }
  for(i = 1; i < 9; i++) {
    for(j = 1; j < 9; j++) {
      insertion_score = scoring_matrix[i-1][j] + GAP;
      deletion_score = scoring_matrix[i][j-1] + GAP;
      if(short_read[j-1] == reference[i-1]){
        match_score = scoring_matrix[i-1][j-1] + MATCH;
      } else {
        match_score = scoring_matrix[i-1][j-1] + MISMATCH;
      }
      if(insertion_score > deletion_score && insertion_score > match_score) {
        scoring_matrix[i][j] = insertion_score;
      } else if(deletion_score > insertion_score && deletion_score > match_score) {
        scoring_matrix[i][j] = deletion_score;
      } else {
        scoring_matrix[i][j] = match_score;
      }
      if(scoring_matrix[i][j] > max_score) {
        max_score = scoring_matrix[i][j];
      }
    }
  }

  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      printf("%d ", scoring_matrix[i][j]);
    }
    printf("\n");
  }
  printf("%d\n", max_score);

  start = clock();
     
  for(k = 0; k < 10000; k++) {
    for(i = 1; i < 9; i++) {
      for(j = 1; j < 9; j++) {
        insertion_score = scoring_matrix[i-1][j] + GAP;
        deletion_score = scoring_matrix[i][j-1] + GAP;
        if(short_read[j-1] == reference[i-1]){
          match_score = scoring_matrix[i-1][j-1] + MATCH;
        } else {
          match_score = scoring_matrix[i-1][j-1] + MISMATCH;
        }
        if(insertion_score > deletion_score && insertion_score > match_score) {
          scoring_matrix[i][j] = insertion_score;
        } else if(deletion_score > insertion_score && deletion_score > match_score) {
          scoring_matrix[i][j] = deletion_score;
        } else {
          scoring_matrix[i][j] = match_score;
        }
        if(scoring_matrix[i][j] > max_score) {
          max_score = scoring_matrix[i][j];
        }
      }
    }
  }
  diff = clock() - start;
  cups = 8*8*10000 / ((float) diff / (float) CLOCKS_PER_SEC);
  printf("%f cell updates per sec\n", cups);
  return 0;
}  
