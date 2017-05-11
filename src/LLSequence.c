#include "../LLSequence.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct sequence {
  int size;
  struct llnode *front;
};

struct llnode {
  int val;
  struct llnode *next;
};

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< HELPERS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

static int seq_is_empty(const struct sequence *seq){
  return seq->front == NULL;// || seq->size == 0;
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Main <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

struct sequence *sequence_create(void){
  struct sequence *new_seq = malloc(sizeof(struct sequence));
  struct llnode *mem = NULL;
  new_seq->size = 0;
  new_seq->front = mem;
  return new_seq;
}

int sequence_length(const struct sequence *seq){
  assert(seq);
  return seq->size;
}

int sequence_item_at(const struct sequence *seq, int pos){
  assert(seq);
  struct llnode *cur = seq->front;
  for(int i = 0; i <= pos; ++i){
    if (i == pos){
      return cur->val;
    }
    cur = cur->next;
  }
  return cur->val;
}


void sequence_insert_at(struct sequence *seq, int pos, int val){
  assert(seq);
  struct llnode *cur = seq->front;
  struct llnode *new = malloc(sizeof(struct llnode));

  new->val = val;
  if(seq->size == 0){
    new->next = NULL;
    seq->front = new;
  } if(pos == 0){
    new->next = seq->front;
    seq->front = new;
  } else{
    for(int i = 0; i < pos; ++i){
      if(i == pos - 1){
        new->next = cur->next->next;
        cur->next = new;
        break;
      } else {
        cur = cur->next;
      }
    }
  }
  ++seq->size;

}

void remove_front(struct sequence *lst) {
  assert(lst->front);
  --lst->size;
  struct llnode *backup = lst->front;
  if(lst->size == 0){
    lst->front = NULL;
  } else {
    lst->front = lst->front->next;
  }
  free(backup);
}

int sequence_remove_at(struct sequence *seq, int pos) {
  int removed = -1;
  int i = 0;
  --seq->size;
  if (seq->front == NULL) {
    return -1;
  }
  if (0 == pos) {
    removed = seq->front->val;
    remove_front(seq);
    return removed;
  }
  struct llnode *prevnode = seq->front;
  while (prevnode->next && (pos - 1) > i) {
    prevnode = prevnode->next;
    ++i;
  }
  if (prevnode->next == NULL) return -1;
  struct llnode *backup = prevnode->next;
  removed = prevnode->next->val;
  prevnode->next = prevnode->next->next;
  free(backup);
  return removed;
}

void sequence_print(const struct sequence *seq){
  assert(seq);
  int size = seq->size;
  struct llnode *cur = seq->front;
  if(size == 0){
    printf("[empty]\n");
  } else {
    printf("[");
    for(int i = 0; i < seq->size; ++i){
      if(i == seq->size - 1){
        printf("%d", cur->val);
      } else {
        printf("%d,", cur->val);
      }
      cur = cur->next;
    }
    printf("]\n");
  }
}

void sequence_destroy(struct sequence *seq){
  while (!seq_is_empty(seq)) {
    remove_front(seq);
  }
  free(seq);
}
