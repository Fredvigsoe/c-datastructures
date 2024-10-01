#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* alst_arraylist();  // Constructor
void alst_add(ArrayList* list, int value);   // add()
int alst_get(ArrayList* list, int index);    // get()
int alst_size(ArrayList* list);              // size()
void alst_remove(ArrayList* list);           // remove()
void alst_remove_index(ArrayList* list, int index);  // removeIndex()
void alst_insert_index(ArrayList* list, int index, int value); // insertIndex()
void alst_set(ArrayList* list, int index, int value);  // set()
void alst_clear(ArrayList* list);            // clear()
void alst_print_list(ArrayList* list);       // Helper to print the list for debugging

#endif // ARRAYLIST_H
