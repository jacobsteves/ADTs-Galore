#include "priqueue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct priqueue{
  int size;
  int *arr;
  int *pri;
};

struct priqueue *priqueue_create(void){
  struct priqueue *new = malloc(sizeof(struct priqueue));
  new->arr = NULL;
  new->pri = NULL;
  new->size = 0;
  return new;
}

int priqueue_length(const struct priqueue *pq){
  return pq->size;
}

int priqueue_front(const struct priqueue *pq){
  assert(pq);

  return pq->arr[0];
}

void shift_arr(int arr[], int len){
  for(int i = len - 1; i > 0; --i){
    arr[i] = arr[i - 1];
  }
}

void priqueue_add(struct priqueue *pq, int item, int priority){
  ++pq->size;
  int len = pq->size;
  int parent;
  pq->arr = realloc(pq->arr, pq->size * sizeof(int));
  pq->pri = realloc(pq->pri, pq->size * sizeof(int));
  pq->arr[pq->size - 1] = item;
  pq->pri[pq->size - 1] = priority;

  for(int i = len - 1; i > 0; i = ((i - 1) / 2)){
    parent = (i - 1) / 2;

    if(pq->pri[parent] < priority){
      pq->pri[i] = pq->pri[parent];
      pq->arr[i] = pq->arr[parent];
      pq->pri[parent] = priority;
      pq->arr[parent] = item;
    } else{
      //break;
    }
  }
}

int int_max(int a, int b, int c, int d){
  if(a > b) {
    return c;
  } else {
    return d;
  }
}

void swap_nodes(struct priqueue *pq, int max, int i){
  //printf("arr[max]: %d\n", pq->arr[max], pq->arr);
  int temp_arr = pq->arr[i];
  int temp_pri = pq->pri[i];
  pq->pri[i] = pq->pri[max];
  pq->arr[i] = pq->arr[max];
  pq->pri[max] = temp_pri;
  pq->arr[max] = temp_arr;
}

int priqueue_remove(struct priqueue *pq){
  --pq->size;
  int len = pq->size;
  int outlier_arr = pq->arr[len];
  int outlier_pri = pq->pri[len];
  int left_child;
  int right_child;
  int removed = priqueue_front(pq);
  if(len > 0){
    pq->arr = realloc(pq->arr, len * sizeof(int));
    pq->pri = realloc(pq->pri, len * sizeof(int));
    pq->arr[0] = outlier_arr;
    pq->pri[0] = outlier_pri;
  } else {
    free(pq->arr);
    free(pq->pri);
    pq->arr = NULL;
    pq->pri = NULL;
  }

  int i = 0;
  while(i < len){
    left_child = i*2+1;
    right_child = i*2+2;
    //printf("right: %d and left: %d\n", right_child, left_child);
    if(left_child < len && right_child < len){
      int max = int_max(pq->pri[left_child], pq->pri[right_child],
                        left_child, right_child);
      //printf("%d\n", max);
      if(pq->pri[max] > pq->pri[i]){
        swap_nodes(pq, max, i);
        i = max;
      } else {
        break;
      }
    } else if(left_child < len && pq->pri[left_child] > pq->pri[i]){
      swap_nodes(pq, left_child, i);
      i = left_child;
    } else if(right_child < len && pq->pri[right_child] > pq->pri[i]){
      swap_nodes(pq, right_child, i);
      i = right_child;
    } else {
      break;
    }
  }

  return removed;
}

void priqueue_print(const struct priqueue *pq){
  int len = pq->size;
  printf("[");
  if(len > 0){
    for(int i = 0; i < len; ++i){
      printf("(%d:%d)", pq->arr[i], pq->pri[i]);
      if(i != len - 1){
        printf(",");
      }
    }
  } else {
    printf("empty");
  }
  printf("]\n");
}

void priqueue_destroy(struct priqueue *pq){
  free(pq->arr);
  free(pq->pri);
  free(pq);
}
