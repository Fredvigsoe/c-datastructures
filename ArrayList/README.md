# ArrayList Implementation in C

Tested on Mac(ARM64)

This repository contains an implementation of a dynamic array (ArrayList) in C. The ArrayList provides similar functionality to arrays but with dynamic resizing, which allows it to grow or shrink as elements are added or removed.

## Files

- `arraylist.c`: Contains the implementation of the ArrayList functions.
- `arraylist.h`: Header file with function declarations and structure definitions.

## Features

The ArrayList implementation provides the following functionalities:

- **Create ArrayList**: Initialize a new dynamic array.
- **Add Element**: Add an element to the end of the ArrayList.
- **Get Element**: Retrieve an element at a specific index.
- **Remove Element**: Remove an element at a specific index.
- **Resize ArrayList**: Automatically resize the array when needed.
- **Free ArrayList**: Deallocate memory used by the ArrayList.

## Function Overview

### `ArrayList* arraylist_create(size_t initial_capacity)`

Creates a new `ArrayList` with a specified initial capacity.

### `void arraylist_add(ArrayList* list, int element)`

Adds an element to the end of the ArrayList. Resizes the array if necessary.

### `int arraylist_get(ArrayList* list, size_t index)`

Retrieves the element at the specified index. Returns an error if the index is out of bounds.

### `void arraylist_remove(ArrayList* list, size_t index)`

Removes the element at the specified index and shifts the remaining elements to the left.

### `void arraylist_free(ArrayList* list)`

Frees the memory allocated for the ArrayList.


## Example Usage

Here is an example of how to use the ArrayList in a C program:

```c
#include <stdio.h>
#include "arraylist.h"

int main() {
    // Create a new ArrayList with an initial capacity of 4
    ArrayList* list = arraylist_create(4);

    // Add elements to the ArrayList
    arraylist_add(list, 10);
    arraylist_add(list, 20);
    arraylist_add(list, 30);
    arraylist_add(list, 40);

    // Get and print elements from the ArrayList
    printf("Element at index 0: %d\n", arraylist_get(list, 0));  // Output: 10
    printf("Element at index 2: %d\n", arraylist_get(list, 2));  // Output: 30

    // Remove an element from the ArrayList
    arraylist_remove(list, 1);  // Removes the element at index 1 (20)

    // Print the updated list
    printf("Element at index 1 after removal: %d\n", arraylist_get(list, 1));  // Output: 30

    // Free the memory allocated for the ArrayList
    arraylist_free(list);


    return 0;
}
```

## Compile and run the program
To compile and run the program, copy and paste the following in the terminal:
```bash
gcc -o arraylist_example arraylist.c arraylist.h
./arraylist_example
