#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct node {
    struct node* nextNode;
    struct node* prevNode;
    int data;
} node;

typedef struct linklist {
    struct node* head; 
    struct node* tail;
} linklist;

linklist* create_list();
node* create_node(int data);
void dump_list(linklist* list);
void add_node_to_start(linklist* list, int data);
void add_node_to_end(linklist* list, int data);
void add_node_by_index(linklist* list, unsigned int index, int value);
void remove_first(linklist* list);
void remove_last(linklist* list);
void remove_node_by_index(linklist* list, unsigned int index);
void swap_by_index(linklist* list, unsigned int indexA, unsigned int indexB);

#endif // LINKLIST_H