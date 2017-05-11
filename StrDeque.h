#include <stdbool.h>

// A module for an string double-ended queue [strdeque]

struct strdeque;

// NOTE: All of the following functions REQUIRE:
//       pointers to a strdeque (e.g., sdeq) are valid (not NULL)
//       pointers to a string (e.g., str) are valid strings

// strdeque_create() returns a pointer to a new (empty) strdeque
// effects: allocates memory (caller must call strdeque_destroy)
// time: O(1)
struct strdeque *strdeque_create(void);

// strdeque_destroy(sdeq) frees all dynamically allocated memory
// effects: the memory at sd is invalid (freed)
// time: O(n)
void strdeque_destroy(struct strdeque *sdeq);

// strdeque_is_empty(sdeq) determines if sdeq is empty
// time: O(1)
bool strdeque_is_empty(const struct strdeque *sdeq);

// strdeque_add_front(str, sdeq) adds str to the front of sdeq
// note: makes a copy of str
// effects: modifies sdeq
// time: O(m), where m is the length of str
void strdeque_add_front(const char *str, struct strdeque *sdeq);

// strdeque_add_back(str, sdeq) adds str to the back of sdeq
// note: makes a copy of str
// effects: modifies sdeq
// time: O(m), where m is the length of str
void strdeque_add_back(const char *str, struct strdeque *sdeq);

// strdeque_remove_front(sdeq) removes front of sdeq
// requires: sdeq is not empty
// effects: modifies sdeq
// time: O(1)
void strdeque_remove_front(struct strdeque *sdeq);

// strdeque_remove_back(sdeq) removes back of sdeq
// requires: sdeq is not empty
// effects: modifies sdeq
// time: O(1)
void strdeque_remove_back(struct strdeque *sdeq);

// strdeque_front(sdeq) returns the string at the front of sdeq
// requires: sdeq is not empty
// time: O(1)
const char *strdeque_front(const struct strdeque *sdeq);

// strdeque_back(sdeq) returns the string at the back of sdeq
// requires: sdeq is not empty
// time: O(1)
const char *strdeque_back(const struct strdeque *sdeq);
