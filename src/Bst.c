#include "../Bst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int PRE_ORDER = 0;
const int IN_ORDER = 1;
const int POST_ORDER = 2;

bool bst_is_empty(struct bst *t){
  return t->root == NULL || t->root->size == 0;
}

struct bst *bst_create(void){
  struct bst *t = malloc(sizeof(struct bst));
  t->root = NULL;
  return t;
}

int bst_size(struct bst *t){
  if(t->root == NULL){
    return 0;
  } else {
    return t->root->size;
  }
}

struct bstnode *new_leaf(int i) {
  struct bstnode *leaf = malloc(sizeof(struct bstnode));
  leaf->item = i;
  leaf->left = NULL;
  leaf->right = NULL;
  leaf->size = 1;
  return leaf;
}

void bst_insert(int i, struct bst *t){
  struct bstnode *curnode = t->root;
  struct bstnode *prevnode = NULL;
  while (curnode) {
    if (curnode->item == i) return;
    ++curnode->size;
    prevnode = curnode;
    if (i < curnode->item) {
      curnode = curnode->left;
    } else {
      curnode = curnode->right;
    }
  }
  if (prevnode == NULL) { // tree was empty
    t->root = new_leaf(i);
  } else if (i < prevnode->item) {
    prevnode->left = new_leaf(i);
  } else {
    prevnode->right = new_leaf(i);
  }
}

struct bstnode *remove_node(int i, struct bstnode *node){
  --node->size;
  // i did not exist:
  if (node == NULL) {
    return NULL;
  }
  // search for the node that contains the i
  if (i < node->item) {
    node->left = remove_node(i, node->left);
  } else if (i > node->item) {
    node->right = remove_node(i, node->right);
  } else if (node->left == NULL) {
    struct bstnode *new_root = node->right;
    //free(node->value);
    free(node);
    return new_root;
  } else if (node->right == NULL) {
    struct bstnode *new_root = node->left;
    //free(node->value);
    free(node);
    return new_root;
  } else {
    // find the next largest i
    struct bstnode *next = node->right;
    while (next->left) {
      next = next->left;
    }
    // remove the old value
    //free(node->value);
    // replace the i/value of this node
    node->item = next->item;
    //node->value = my_strdup(next->value);
    // remove the next largest i
    node->right = remove_node(next->item, node->right);
  }
  return node;
}

void bst_remove (int i, struct bst *t){
  t->root = remove_node(i, t->root);
}

int select_node(int k, struct bstnode *node) {
  assert(node && 0 <= k && k < node->size);
  int left_size = 0;
  if (node->left) {
    left_size = node->left->size;
  }
  if (k < left_size) {
    return select_node(k, node->left);
  }
  if (k == left_size) {
    return node->item;
  }
  return select_node(k - left_size - 1, node->right);
}

int bst_select(int k, struct bst *t) {
  return select_node(k, t->root);
}

bool bst_find(int i, struct bst *t){
  struct bstnode *curnode = t->root;
  while (curnode) {
    if (curnode->item == i) {
      return true;
    }
    if (i < curnode->item) {
      curnode = curnode->left;
    } else {
      curnode = curnode->right;
    }
  }
  return false;
}

void print_inorder(struct bst *t){
  int *a = bst_to_sorted_array(t);
  printf("[");
  if (a) {
    for (int k=0; k < bst_size(t); ++k) {
      if (k) printf(",");
      printf("%d", a[k]);
    }
    free(a);
  } else {
    printf("empty");
  }
  printf("]\n");
}

void print_preorder(struct bstnode* node, int first)
{
    if (node == NULL){
        return;
    }else if (!first){
      printf(",");
    }
    printf("%d", node->item);
    print_preorder(node->left, 0);
    print_preorder(node->right, 0);
}

void print_postorder(struct bstnode* node, int first){
  if (node == NULL){
        return;
    }
    print_postorder(node->left, 0);
    print_postorder(node->right, 0);
    printf("%d", node->item);

    if (!first){
      printf(",");
    }
}

void bst_print (int o, struct bst *t){
  if(t->root == NULL){
    printf("[empty]\n");
  } else if (o == PRE_ORDER){
    //printf("size: %d\n", t->root->size);
    //printf("val: %d\n", t->root->item);

    printf("[");
    //print_preorder(t->root, val, &count);
    print_preorder(t->root, 1);
    printf("]\n");

  } else if (o == IN_ORDER){
    print_inorder(t);
  } else {
    printf("[");
    print_postorder(t->root, 1);
    printf("]\n");
  }
}

void arr_insert(struct bstnode *node, int arr[], int *val){
  if(node == NULL){
    return;
  }
  arr_insert(node->left, arr, val);
  arr[*val] = node->item;
  ++(*val);
  arr_insert(node->right, arr, val);
}

int *bst_to_sorted_array(struct bst *t){
  int *arr = malloc(t->root->size * sizeof(int));
  int val = 0;
  arr_insert(t->root, arr, &val);
  return arr;
}

int bst_range (int start, int end, struct bst *t){
  int *arr = bst_to_sorted_array(t);
  int counter = 0;
  for(int i = 0; i < t->root->size; ++i){
    if (arr[i] >= start && arr[i] <= end){
      ++counter;
    }
  }
  free(arr);
  return counter;
}

int count_len(struct bstnode *node){
  int len = 0;
  if(node){
    ++len;
    len = len + count_len(node->left) + count_len(node->right);
  }
  return len;
}

struct bstnode *balance_bst(int *a, int start, int end){
  if(start > end) {
    return NULL;
  }
  int pivot = (start + end) / 2;
  struct bstnode *new_root = new_leaf(a[pivot]);
  new_root->left = balance_bst(a, start, pivot - 1);
  new_root->right = balance_bst(a, pivot + 1, end);
  new_root->size = 1 + count_len(new_root->left) + count_len(new_root->right);

  return new_root;
}

struct bst *sorted_array_to_bst(int *a, int len){
  struct bst *new = bst_create();
  new->root = balance_bst(a, 0, len-1);
  return new;
}

void bst_rebalance(struct bst *t){
  int len = t->root->size;
  int *sorted = bst_to_sorted_array(t);

  // destroy all current nodes as we are overriding t
  while(!bst_is_empty(t)){
    bst_remove(bst_select(0, t), t);
  }

  t->root = balance_bst(sorted, 0, len -1);
  free(sorted);
}

void bst_destroy(struct bst *t){
  while(!bst_is_empty(t)){
    bst_remove(bst_select(0, t), t);
  }
  free(t->root);
  free(t);
  //printf("this will eventually destory it lel\n");
}
