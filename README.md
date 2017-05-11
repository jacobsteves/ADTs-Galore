# Intro to ADTs Galore
These ADTs all allocate memory. Each interface contains the function needed to free the memory allocate. You must free anything you initially allocate space to.

# Abstract Data Type Modules
## PriorityQueue
An ADT module like a regular queue, except each additional element has a given priority. Elements with a higher priority are served before elements with lower priority.

## Inventory
A inventory ADT is exactly what it sounds like. It stores items in an object. You can look up the quantity of an item, add an item, remove an item, add quantity, etc.

## StrDeque
A StrDeque is a double-ended string queue ADT module. Items can be either added or removed from the back, or added or removed from the front.

## BST
A bst is a binary search tree. Each node in the bst is larger than its left child, yet smaller than its right child. When removing nodes, it is very important to not remove its children.

## Sequence
A sequence is an ADT where items can be added, removed, or viewed at any point.

### ArrSequence
This implementation uses an array rather than a linked list.

### LLSequence
This implementation uses a linked list rather than an array.

# Misc
## SetUp
To start, copy this repo to any IDE running C. From there, use the information in the interface to set up your desired ADT.

## Tests
Simply run the function in the appropriate testing file to test it. This will test all endpoints.
