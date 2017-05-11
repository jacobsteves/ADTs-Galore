#include "../Inventory.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources:

// None

// Name: Jacob Steves
// login ID: jgsteves
/////////////////////////////////////////////////////////////////////////////

struct inventory{
  int size;
  int *qty;
  char **items;
};

// <<<<<<<<<<<<<<<<<<<<<< HELPERS <<<<<<<<<<<<<<<<<<<<<<<<<

// inventory_pos(inv, item) determines the pos item is in inv, if item
//     does not exist in inv, it returns -1
// time: O(logn)
static int inventory_pos(const struct inventory *inv, const char *item){
  int left = 0;
  int right = inv->size - 1;
  int n = (left + right) / 2;
  while(left <= right){
    if(strcmp(inv->items[n], item) == 0){
      return n;
    } else if(strcmp(inv->items[n], item) < 0){
      right = n - 1;
    } else {
      left = n + 1;
    }

    n = (left + right) / 2;
  }
  return -1;
}

// <<<<<<<<<<<<<<<<<<<<<< MAIN <<<<<<<<<<<<<<<<<<<<<<<<<

void inventory_print(const struct inventory *inv){
  int len = inv->size;
  for(int i = 0; i < len; ++i){
    printf("Str: %s, Qty: %d\n", inv->items[i], inv->qty[i]);
  }
}
struct inventory *inventory_create(void){
  struct inventory *new_inv = malloc(sizeof(struct inventory));
  int len = 1;
  int *qty = malloc(len * sizeof(int));
  char **items = malloc(len * sizeof(char *));
  new_inv->size = 0;
  new_inv->qty = qty;
  new_inv->items = items;
  return new_inv;
}

void inventory_destroy(struct inventory *inv){
  assert(inv);

  free(inv->qty);
  for(int i = 0; i < inv->size; ++i){
    free(inv->items[i]);
  }
  free(inv->items);
  free(inv);
}

int inventory_lookup(const struct inventory *inv, const char *item){
  assert(inv);
  //inventory_print(inv);
  int pos = inventory_pos(inv, item);
  if (pos != -1){
    return inv->qty[pos];
  } else {
    return pos;
  }
}

void inventory_add(struct inventory *inv, const char *item, int qty){
  assert(inv);

  int pos = inventory_pos(inv, item);
  int str_len = strlen(item);

  if (pos != -1){
    inv->qty[pos] += qty;
  } else {

    ++inv->size;
    inv->qty = realloc(inv->qty, inv->size * sizeof(int));
    inv->items = realloc(inv->items, inv->size * sizeof(char *));

    if(inv->size == 1){
      inv->qty[0] = qty;
      inv->items[0] = malloc((str_len + 1) * sizeof(char *));
      strcpy(inv->items[0], item);
    }
    else {
      for(int i = inv->size - 2; i >= 0; --i){

        if(strcmp(inv->items[i], item) > 0){
          inv->qty[i + 1] = qty;
          inv->items[i + 1] = malloc((str_len + 1) * sizeof(char *));
          strcpy(inv->items[i + 1], item);
          break;
        } else{
          inv->items[i + 1] = inv->items[i];
          inv->qty[i + 1] = inv->qty[i];
          if(i == 0){
            inv->qty[i] = qty;
            inv->items[i] = malloc((str_len + 1) * sizeof(char *));
            strcpy(inv->items[i], item);
          }
        }
      }
    }
  }
}

void inventory_remove(struct inventory *inv, const char *item, int qty){
  assert(inv);

  int pos = inventory_pos(inv, item);
  if (pos != -1){
    inv->qty[pos] -= qty;
  }
}
