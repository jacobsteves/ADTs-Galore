#include "../StrDeque.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

struct strdeque {
  int size;
  struct llnode *front;
  struct llnode *back;
};

struct llnode {
  char* item;
  struct llnode *next;
  struct llnode *prev;
};


struct strdeque *strdeque_create(void){
  struct strdeque *new_strdeque = malloc(sizeof(struct strdeque));
  struct llnode *mem_front = NULL;
  struct llnode *mem_back = NULL;
  new_strdeque->size = 0;
  new_strdeque->front = mem_front;
  new_strdeque->back = mem_back;
  return new_strdeque;
}

bool strdeque_is_empty(const struct strdeque *sdeq){
  return sdeq->front == NULL;
}

void strdeque_add_front(const char *str, struct strdeque *sdeq){
  int str_len = strlen(str) + 1;
  struct llnode *next = sdeq->front;
  struct llnode *new = malloc(sizeof(struct llnode));
  new->item = malloc(str_len * sizeof(char));
  new->next = next;
  new->prev = NULL;
  strcpy(new->item, str);
  ++sdeq->size;
  sdeq->front = new;
  if(sdeq->back == NULL){
    sdeq->back = new;
  }
}

void strdeque_add_back(const char *str, struct strdeque *sdeq){
  int str_len = strlen(str) + 1;
  struct llnode *node = malloc(sizeof(struct llnode));
  node->item = malloc(str_len * sizeof(char));
  strcpy(node->item, str);
  node->next = NULL;
  node->prev = sdeq->back;
  if (sdeq->front == NULL) {
    sdeq->front = node;
  } else {
    sdeq->back->next = node;
  }
  sdeq->back = node;
}

void strdeque_remove_front(struct strdeque *sdeq){
  --sdeq->size;

  struct llnode *temp = sdeq->front;
  sdeq->front = sdeq->front->next;

  if (sdeq->front == NULL) {
    //free(sdeq->back->item);
    //free(sdeq->back);
    sdeq->back = NULL;
  } else {
    sdeq->front->prev = NULL;
  }

  free(temp->item);
  free(temp);
}

void strdeque_remove_back(struct strdeque *sdeq){
  --sdeq->size;
  struct llnode *temp = sdeq->back;
  sdeq->back = sdeq->back->prev;

  if (sdeq->back == NULL) {
    sdeq->front = NULL;
  } else {
    sdeq->back->next = NULL;
  }

  free(temp->item);
  free(temp);
}

void strdeque_destroy(struct strdeque *sdeq) {
  while (!strdeque_is_empty(sdeq)) {
    strdeque_remove_front(sdeq);
  }
  free(sdeq);
}

const char *strdeque_front(const struct strdeque *sdeq){
  return sdeq->front->item;
}

const char *strdeque_back(const struct strdeque *sdeq){
  return sdeq->back->item;
}
