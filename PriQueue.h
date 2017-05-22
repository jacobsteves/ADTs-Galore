struct priqueue;

// INFO:
// A priqueue is an ADT module like a regular queue, except each additional element has a given priority.
// Elements with a higher priority are served before elements with lower priority.

// priqueue_create() returns a pointer to a new (empty) priqueue
// effects: allocates memory (user must call priqueue_destroy)
// requires: pointers to a priqueue are valid
// time: O(1)
struct priqueue *priqueue_create(void);

// priqueue_destroy(pq) frees all dynamically allocated memory
// effects: the memory at pq is freed and now invalid
// requires: pointers to a priqueue (e.g., pq) are valid (not NULL)
// time: O(1)
void priqueue_destroy(struct priqueue *pq);

// priqueue_length(pq) determines how many items are in pq
// requires: pointers to a priqueue are valid
// time: O(1)
int priqueue_length(const struct priqueue *pq);

// priqueue_add(pq, item, priority) inserts item with priority into pq
// effects: modifies pq
// requires: pointers to a priqueue are valid
// time: O(logn)
void priqueue_add(struct priqueue *pq, int item, int priority);

// priqueue_front(pq) returns the item with the highest priority.
//   If there are multiple items with the same priority,
//   the order does not matter.
// requires: pq is not empty, pointers to a priqueue are valid
// time : O(1)
int priqueue_front(const struct priqueue *pq);

// priqueue_remove(pq) removes and returns the item with the maximum
//   priority in pq.
//   If there are multiple items with the same priority,
//   the order does not matter.
// requires: pq is not empty, pointers to a priqueue are valid
// effects: modifies pq
// time: O(logn)
int priqueue_remove(struct priqueue *pq);

// NOTE: priqueue_print is just for testing. It violates the principles of
//       information hiding.

// priqueue_print(pq) prints pq
// effects: displays output
// example: It prints in the order it is stored in the array.
//   For example, if the heap is currently
//             (1,99)
//             /    \
//         (5,20)  (2,30)
//   then it will be printed as "[(1:99),(5:20),(2:30)]\n"
//   where each node is printed as (item:priority).
// requires: pointers to a priqueue are valid
// time: O(n)
void priqueue_print(const struct priqueue *pq);
