# LinkedLists Implementation in C

Tested on Mac(ARM64)

This repository contains an implementation of a doubly linked list in C. The linked list allows for efficient insertions and deletions from both ends and supports various functionalities for managing nodes.
## Files

- `linklist.c`: Contains the implementation of the linked list functions.
- `linklist.h`: Header file with function declarations and structure definitions.

## Features

The linked list implementation provides the following functionalities:

- **Create List**: Initialize a new empty linked list.
- **Add Node to Start**: Add a node at the beginning of the list.
- **Add Node to End**: Add a node at the end of the list.
- **Add Node by Index**: Insert a node at a specific index.
- **Remove First Node**: Remove the first node from the list.
- **Remove Last Node**: Remove the last node from the list.
- **Remove Node by Index**: Remove a node at a specific index.
- **Dump List**: Print the contents of the list along with node addresses.
- **Swap Nodes by Index**: Swap two nodes in the list by their indices.

## Function Overview

### `linklist* create_list()`
Creates a new `linklist` structure for managing nodes.

### `node* create_node(int data)`
Creates a new node with specified data.

### `void add_node_to_start(linklist* list, int data)`
Adds a node to the beginning of the linked list.

### `void add_node_to_end(linklist* list, int data)`
Adds a node to the end of the linked list.

### `void add_node_by_index(linklist* list, unsigned int index, int value)`
Inserts a node at a specific index in the linked list.

### `void remove_first(linklist* list)`
Removes the first node from the linked list.

### `void remove_last(linklist* list)`
Removes the last node from the linked list.

### `void remove_node_by_index(linklist* list, unsigned int index)`
Removes a node at a specific index from the linked list.

### `void dump_list(linklist* list)`
Prints the contents of the linked list along with node addresses.

### `void swap_by_index(linklist* list, unsigned int indexA, unsigned int indexB)`
Swaps two nodes in the linked list by their indices.



## Example Usage

Here is an example of how to use the linked list in a C program:

```c
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main() {
    // Create an empty linked list
    linklist* myList = create_list();

    if (myList == NULL) {
        printf("Fejl ved oprettelse af listen.\n");
        return 1;
    }

    // Add nodes to the end
    printf("-----------TILFØJER NODES TIL SLUTNINGEN-------------\n");
    add_node_to_end(myList, 20);
    add_node_to_end(myList, 30);
    add_node_to_end(myList, 40);
    printf("-----------------------------------------------------\n");
    
    dump_list(myList);

    // Add a node to the start
    printf("-----------TILFØJER NODE TIL STARTEN-------------\n");
    add_node_to_start(myList, 10);
    printf("-------------------------------------------------\n");
    
    dump_list(myList);

    // Add a node by index
    printf("-----------TILFØJER NODE TIL INDEX-------------\n");
    add_node_by_index(myList, 2, 25); // Insert 25 at index 2
    printf("-----------------------------------------------\n");
    dump_list(myList);

    // Remove a node by index
    printf("-----------FJERNER NODE VED INDEX-------------\n");
    remove_node_by_index(myList, 1); // Remove node at index 1
    printf("----------------------------------------------\n");
    dump_list(myList);

    // Swap nodes at index 0 and 1 (10 and 25)
    printf("-----------BYTTER NODES PÅ INDEX 0 og 1 (10 og 25)-------------\n");
    swap_by_index(myList, 0, 1); // Swap 10 and 25
    printf("----------------------------------------------------------------\n");
    dump_list(myList);

    // Swap nodes at index 1 and 2 (30 and 10)
    printf("-----------BYTTER NODES PÅ INDEX 1 og 2 (30 og 10)-------------\n");
    swap_by_index(myList, 1, 2); // Swap 30 and 10
    printf("----------------------------------------------------------------\n");
    dump_list(myList);

    // Remove first node
    remove_first(myList);
    dump_list(myList);

    // Remove last node
    remove_last(myList);
    dump_list(myList);

    // Try to remove a node by index that doesn't exist
    remove_node_by_index(myList, 10); // Invalid index
    dump_list(myList);

    // Add a node to the end again
    add_node_to_end(myList, 50);
    dump_list(myList);

    // Cleanup
    remove_last(myList); // Remove the last node 
    remove_last(myList); // Remove the last node 
    remove_first(myList); // Remove the first node (error because it's empty)
    
    // Free the list memory
    free(myList); // Free memory for the list
    return 0;
}

```

## Compile and run the program
To compile and run the program, copy and paste the following in the terminal:
```bash
gcc -o linkedlist_demo linklist.c linklist.h
./linkedlist_demo
