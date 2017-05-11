// A module for an inventory ADT with string items and int qtys

struct inventory;

// NOTE: All of the following functions REQUIRE:
//       pointers to an inventory (e.g., inv) are valid (not NULL)
//       item strings are valid

//       for time, n == total number of items in the inventory
//                 m == length of the item (string)

// inventory_create() returns a new empty inventory
// effects: allocates memory (caller must call inventory_destroy)
// time: O(1)
struct inventory *inventory_create(void);

// inventory_destroy(inv) frees all dynamically allocated memory
// effects: the memory at inv is invalid (freed)
// time : O(n)
void inventory_destroy(struct inventory *inv);

// inventory_lookup(inv, item) determines the quantity of items in inv,
//   or returns -1 if item is not in the inventory
//   note: an item with quantity 0 returns 0 (not -1)
// time: O(mlogn)
int inventory_lookup(const struct inventory *inv, const char *item);

// inventory_add(inv, item, qty) adds qty items to inv
// requires: qty >= 0
// effects: inv is modified
// time: O(mlogn) if item is already in the inventory
//       O(mn) if item does not exist in the inventory
void inventory_add(struct inventory *inv, const char *item, int qty);

// inventory_remove(inv, item, qty) removes qty items from inv
// requires: 0 < qty <= inventory_lookup(inv, item)
// effects: inv is modified
// time: O(mlogn)
void inventory_remove(struct inventory *inv, const char *item, int qty);
