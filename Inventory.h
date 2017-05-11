// A module for an inventory ADT with string items and int qtys

struct inventory;

// INFO:
// A inventory ADT is exactly what it sounds like. It stores items in an object.
// You can look up the quantity of an item, add an item, remove an item, add quantity, etc.

// inventory_create() returns a new empty inventory
// requires: pointers to a inventory are valid
// effects: allocates memory (caller must call inventory_destroy)
// time: O(1)
struct inventory *inventory_create(void);

// inventory_destroy(inv) frees all dynamically allocated memory
// requires: pointers to a inventory are valid
// effects: the memory at inv is invalid (freed)
// time : O(n)
void inventory_destroy(struct inventory *inv);

// inventory_lookup(inv, item) determines the quantity of items in inv,
//   or returns -1 if item is not in the inventory
//   note: an item with quantity 0 returns 0 (not -1)
// requires: pointers to a inventory are valid
// time: O(mlogn)
int inventory_lookup(const struct inventory *inv, const char *item);

// inventory_add(inv, item, qty) adds qty items to inv
// requires: qty >= 0, pointers to a inventory are valid
// effects: inv is modified
// time: O(mlogn) if item is already in the inventory
//       O(mn) if item does not exist in the inventory
void inventory_add(struct inventory *inv, const char *item, int qty);

// inventory_remove(inv, item, qty) removes qty items from inv
// requires: 0 < qty <= inventory_lookup(inv, item), pointers to a inventory are valid
// effects: inv is modified
// time: O(mlogn)
void inventory_remove(struct inventory *inv, const char *item, int qty);
