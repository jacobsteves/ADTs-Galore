#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "priqueue.h"

/*
 This is simple I/O test client for priqueue.c that
 uses a very specific input format.

 Failure to follow format might lead to undefined behaviour.

 l: prints priqueue_length
 a ITEM PRI: priqueue_add
 f: prints priqueue_front
 r: prints priqueue_remove
 p: priqueue_print
 q: quit
*/

// get_int() reads in an int from input
// effects: if unable to read in a number, prints message and exits
int get_int(void) {
  int i;
  if (scanf("%d", &i) != 1) {
    printf("exit: invalid number\n");
    exit(1);
  }
  return i;
}

int main(void){
  struct priqueue *pq = priqueue_create();
  while (1){
    char cmd;
    if (scanf(" %c", &cmd) != 1) break;
    if (cmd == 'q') break;
    if (cmd == 'l') {
      printf("length: %d\n",priqueue_length(pq));
    } else if (cmd == 'a') {
      int item = get_int();
      int pri = get_int();
      priqueue_add(pq, item, pri);
    } else if (cmd == 'f') {
      printf("front: %d\n",priqueue_front(pq));
    } else if (cmd == 'r') {
      printf("remove: %d\n",priqueue_remove(pq));
    } else if (cmd == 'p') {
      priqueue_print(pq);
    } else {
      printf("Invalid command (%c).\n",cmd);
      break;
    }
  }
  priqueue_destroy(pq);
}
