struct priqueue;

// NOTES: All of the following functions REQUIRE:
//        pointers to a priqueue (e.g., pq) are valid (not NULL)
//
//       For times, n is the size of the priqueue
//
//       While the contracts below indicate that the order for "ties"
//       does not matter, you must follow the priqueue instructions
//
//       There can be duplicates in a priqueue
//       that have the same item and/or priority


// priqueue_create() returns a pointer to a new (empty) priqueue
// effects: allocates memory (caller must call priqueue_destroy)
// time: O(1)
struct priqueue *priqueue_create(void);

// priqueue_destroy(pq) frees all dynamically allocated memory
// effects: the memory at pq is invalid (freed)
// time: O(1)
void priqueue_destroy(struct priqueue *pq);

// priqueue_length(pq) determines how many items are in pq
// time: O(1)
int priqueue_length(const struct priqueue *pq);

// priqueue_add(pq, item, priority) inserts item with priority into pq
// effects: modifies pq
// time: O(logn)
void priqueue_add(struct priqueue *pq, int item, int priority);

// priqueue_front(pq) returns the item with the highest priority.
//   If there are multiple items with the same priority,
//   the order does not matter.
// requires: pq is not empty
// time : O(1)
int priqueue_front(const struct priqueue *pq);

// priqueue_remove(pq) removes and returns the item with the maximum
//   priority in pq.
//   If there are multiple items with the same priority,
//   the order does not matter.
// requires: pq is not empty
// effects: modifies pq
// time: O(logn)
int priqueue_remove(struct priqueue *pq);

// NOTE: priqueue_print violates the principle of information hiding
//       but is required to properly test your code

// priqueue_print(pq) prints pq
// effects: displays output
// example: It prints in the order it is stored in the array.
//   For example, if the heap is currently
//             (1,99)
//             /    \
//         (5,20)  (2,30)
//   then it will be printed as "[(1:99),(5:20),(2:30)]\n"
//   where each node is printed as (item:priority).
//   If empty, it prints as "[empty]\n"
// time: O(n)
void priqueue_print(const struct priqueue *pq);
