#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../../LLSequence.h"

/*
 This is simple I/O test client for sequence.c that
 uses a very specific input format.

 Failure to follow format might lead to undefined behaviour.

 l: print sequence_length
 a INT: print sequence_item_at
 i INT INT: sequence_insert_at
 r INT: sequence_remove_at
 p: sequence_print
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
  struct sequence *seq = sequence_create();
  while (1){
    char cmd;
    if (scanf(" %c", &cmd) != 1) break;
    if (cmd == 'q') break;
    if (cmd == 'l') {
      printf("length: %d\n",sequence_length(seq));
    } else if (cmd == 'a') {
      int at = get_int();
      printf("item_at(%d): %d\n",at,sequence_item_at(seq,at));
    } else if (cmd == 'i') {
      int at = get_int();
      int val = get_int();
      sequence_insert_at(seq,at,val);
    } else if (cmd == 'r') {
      int at = get_int();
      sequence_remove_at(seq,at);
    } else if (cmd == 'p') {
      sequence_print(seq);
    } else {
      printf("Invalid command (%c).\n",cmd);
      break;
    }
  }
  sequence_destroy(seq);
}
