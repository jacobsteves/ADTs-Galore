#include <assert.h>
#include "../../Inventory.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// a simple test client for inventory.c

int main(void) {
  struct inventory *inv = inventory_create();
  assert(inventory_lookup(inv, "apples") == -1);
  inventory_add(inv, "apples", 3);
  assert(inventory_lookup(inv, "apples") == 3);
  inventory_remove(inv, "apples", 1);
  assert(inventory_lookup(inv, "apples") == 2);
  inventory_add(inv, "bananas", 3);
  assert(inventory_lookup(inv, "bananas") == 3);
  inventory_remove(inv, "bananas", 2);
  assert(inventory_lookup(inv, "bananas") == 1);
  inventory_remove(inv, "bananas", 0);
  assert(inventory_lookup(inv, "bananas") == 1);
  inventory_remove(inv, "bananas", 1);
  assert(inventory_lookup(inv, "bananas") == 0);
  assert(inventory_lookup(inv, "apples") == 2);
  inventory_add(inv, "bananas", 3);
  inventory_add(inv, "carrots", 1);
  inventory_add(inv, "elephants", 7);
  inventory_add(inv, "bnonos", 4);
  assert(inventory_lookup(inv, "bnonos") == 4);
  assert(inventory_lookup(inv, "elephants") == 7);
  assert(inventory_lookup(inv, "carrots") == 1);
  inventory_remove(inv, "carrots", 1);
  assert(inventory_lookup(inv, "carrots") == 0);
  inventory_destroy(inv);
}
