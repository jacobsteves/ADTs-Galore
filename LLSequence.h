struct sequence;

// INFO:
// A sequence is an ADT where items can be added, removed, or viewed at any point.
// This implementation uses linked lists rather than an array.

// sequence_create() returns a pointer to a new (empty) sequence
// effects: allocates memory (caller must call sequence_destroy)
// time: O(1)
struct sequence *sequence_create(void);

// sequence_destroy(seq) frees all dynamically allocated memory
// requires: pointers to a sequence are valid
// effects: the memory at seq is invalid (freed)
// time: O(n)
void sequence_destroy(struct sequence *seq);

// sequence_length(seq) returns the number of items in seq
// requires: pointers to a sequence are valid
// time: O(1)
int sequence_length(const struct sequence *seq);

// sequence_item_at(seq, pos) returns the item in seq at position pos
// requires: 0 <= pos < sequence_length(seq), pointers to a sequence are valid
// time: O(n)
int sequence_item_at(const struct sequence *seq, int pos);

// sequence_insert_at(seq, pos, val) inserts a new item with value val
//   at position pos in seq
//   (changing the position of items at position >= pos)
// requires: 0 <= pos <=  sequence_length(seq), pointers to a sequence are valid
// effects: seq is modified
// time: O(n)
void sequence_insert_at(struct sequence *seq, int pos, int val);

// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the removed value
//   (changing the position of items > pos)
// requires: 0 <= pos <  sequence_length(seq), pointers to a sequence are valid
// effects: seq is modified
// time: O(n)
int sequence_remove_at(struct sequence *seq, int pos);

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0,item_1,...,item_last]\n"
//   or "[empty]\n"
// requires: pointers to a sequence are valid
// effects: prints out a message
// time : O(n)
void sequence_print(const struct sequence *seq);
