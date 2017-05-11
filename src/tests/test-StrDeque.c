#include <assert.h>
#include <string.h>
#include "../../StrDeque.h"

// a simple test client for strdeque.c

const char *apple = "apple";
const char *zebra = "zebra";
const char *hello = "hello";
const char *giraffe = "giraffe";

int main(void) {
  char buffer[10];
  struct strdeque *sdeq = strdeque_create();
  strcpy(buffer, apple);
  strdeque_add_front(buffer, sdeq);
  strcpy(buffer, zebra);
  strdeque_add_back(buffer, sdeq);
  assert(strcmp(strdeque_front(sdeq), apple) == 0);
  assert(strcmp(strdeque_back(sdeq), zebra) == 0);
  strdeque_remove_front(sdeq);
  assert(strcmp(strdeque_front(sdeq), zebra) == 0);
  strdeque_remove_back(sdeq);
  assert(strdeque_is_empty(sdeq));

  strcpy(buffer, hello);
  strdeque_add_back(buffer, sdeq);
  assert(strcmp(strdeque_front(sdeq), hello) == 0);
  assert(strcmp(strdeque_back(sdeq), hello) == 0);
  strcpy(buffer, giraffe);
  strdeque_add_back(buffer, sdeq);
  assert(strcmp(strdeque_front(sdeq), hello) == 0);
  assert(strcmp(strdeque_back(sdeq), giraffe) == 0);

  strdeque_destroy(sdeq);
}
