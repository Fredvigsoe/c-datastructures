#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For memcpy

#define START_SIZE 10  // Minimum capacity


int main() {
    ArrayList* list = alst_arraylist();  // Create a new ArrayList

    alst_add(list, 10);
    alst_add(list, 20);
    alst_add(list, 30);
    alst_print_list(list);

    alst_insert_index(list, 1, 15);  // Insert at index 1
    alst_print_list(list);

    alst_remove_index(list, 2);  // Remove element at index 2
    alst_print_list(list);

    alst_set(list, 1, 25);  // Set value at index 1
    alst_print_list(list);

    printf("Size of list: %d\n", alst_size(list));

    alst_remove(list);  // Remove the last element
    alst_print_list(list);

    alst_clear(list);  // Clear the list
    alst_print_list(list);

    return 0;
}
// Constructor function
ArrayList* alst_arraylist() {
    ArrayList* list = malloc(sizeof(ArrayList));
    list->data = malloc(START_SIZE * sizeof(int));
    list->size = 0;
    list->capacity = START_SIZE;
    return list;
}

// Helper function to expand capacity
void alst_expand_capacity(ArrayList* list) {
    int new_capacity = list->capacity * 2;
    int* new_data = malloc(new_capacity * sizeof(int));
    memcpy(new_data, list->data, list->size * sizeof(int));
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

// Helper function to reduce capacity
void alst_reduce_capacity(ArrayList* list) {
    if (list->capacity <= START_SIZE) {
        return;  // Don't reduce below the starting size
    }
    int new_capacity = list->capacity / 2;
    if (new_capacity < START_SIZE) {
        new_capacity = START_SIZE;  // Keep a minimum capacity
    }
    int* new_data = malloc(new_capacity * sizeof(int));
    memcpy(new_data, list->data, list->size * sizeof(int));
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

// add() - Adds an object at the end
void alst_add(ArrayList* list, int value) {
    if (list->size == list->capacity) {
        alst_expand_capacity(list);  // Expand capacity if needed
    }
    list->data[list->size++] = value;  // Add element and increment size
}

// get() - Returns the object at the specified index
int alst_get(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1;  // Return error value if index is invalid
    }
    return list->data[index];
}

// size() - Returns the current size of the list
int alst_size(ArrayList* list) {
    return list->size;
}

// remove() - Removes the last object from the list
void alst_remove(ArrayList* list) {
    if (list->size == 0) {
        printf("List is empty\n");
        return;
    }
    list->size--;  // Decrement size
    if (list->size <= list->capacity / 2 && list->capacity > START_SIZE) {
        alst_reduce_capacity(list);  // Reduce capacity if size is halved
    }
}

// removeIndex() - Removes an object at the specified index
void alst_remove_index(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];  // Shift elements left
    }
    list->size--;  // Decrease size
    if (list->size <= list->capacity / 2 && list->capacity > START_SIZE) {
        alst_reduce_capacity(list);  // Reduce capacity if needed
    }
}

// insertIndex() - Inserts an object at the specified index
void alst_insert_index(ArrayList* list, int index, int value) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds\n");
        return;
    }
    if (list->size == list->capacity) {
        alst_expand_capacity(list);  // Expand capacity if needed
    }
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];  // Shift elements right
    }
    list->data[index] = value;  // Insert element at index
    list->size++;  // Increase size
}

// set() - Overwrites the object at the specified index with a new object
void alst_set(ArrayList* list, int index, int value) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }
    list->data[index] = value;  // Set the value at the given index
}

// clear() - Removes all elements from the list
void alst_clear(ArrayList* list) {
    free(list->data);  // Free the old data array
    list->data = malloc(START_SIZE * sizeof(int));  // Reallocate with initial capacity
    list->size = 0;  // Reset size
    list->capacity = START_SIZE;  // Reset capacity
}

// Helper function to print the list (for debugging purposes)
void alst_print_list(ArrayList* list) {
    printf("List (size=%d, capacity=%d): ", list->size, list->capacity);
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}
