#include "../ArrSequence.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct sequence {
  int size;
  int *arr;
};

struct sequence *sequence_create(void){
  struct sequence *new_seq = malloc(sizeof(struct sequence));
  int len = 1;
  int *mem = malloc(len * sizeof(int));
  new_seq->size = 0;
  new_seq->arr = mem;
  return new_seq;
}

void sequence_destroy(struct sequence *seq){
  assert(seq);
  free(seq->arr);
  free(seq);
}

int sequence_length(const struct sequence *seq){
  assert(seq);
  return seq->size;
}

int sequence_item_at(const struct sequence *seq, int pos){
  assert(seq);
  return seq->arr[pos];
}

void sequence_insert_at(struct sequence *seq, int pos, int val){
  assert(seq);
  ++seq->size;
  seq->arr = realloc(seq->arr, seq->size * sizeof(int));
  for(int i = seq->size - 1; i > pos; --i){
    seq->arr[i] = seq->arr[i - 1];
  }
  seq->arr[pos] = val;
}

int sequence_remove_at(struct sequence *seq, int pos){
  assert(seq);
  int item = seq->arr[pos];
  --seq->size;
  int len = seq->size;
  for(int i = pos; i < len; ++i){
    seq->arr[pos] = seq->arr[pos + 1];
  }
  seq->arr = realloc(seq->arr, len * sizeof(int));
  return item;
}

void sequence_print(const struct sequence *seq){
  assert(seq);
  int size = seq->size;
  if(size == 0){
    printf("[empty]\n");
  } else {
    printf("[");
    for(int i = 0; i < seq->size; ++i){
      if(i == seq->size - 1){
        printf("%d", seq->arr[i]);
      } else {
        printf("%d,", seq->arr[i]);
      }
    }
    printf("]\n");
  }
}
