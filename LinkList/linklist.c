#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist* create_list(){
    linklist* newList = malloc(sizeof(linklist));

    if (newList == NULL){
        printf("Fejl med newList\n");
        return NULL;
    }
    newList->head = NULL;
    newList->tail = NULL;

    printf("Oprettet en tom linked list med adresse: %p\n", (void*)newList);
    return newList;
    
}

node* create_node(int data) {
    node* newNode = malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Fejl med allokering af node\n");
        return NULL;
    }

    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    newNode->data = data;  

    printf("Oprettet en ny node med data: %d, adresse: %p\n", data, (void*)newNode);
    return newNode;
}

void add_node_to_start(linklist* list, int data) {
    if (list == NULL) {
        printf("Listen er NULL, kan ikke tilføje node.\n");
        return;
    }

    node* newNode = create_node(data);  // Opret en ny node

    // Hvis listen er tom, sætter vi både head og tail til den nye node
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        printf("Tilføjet som første node med data: %d\n", data);
    } else {
        // Hvis listen ikke er tom, indsættes noden i starten
        newNode->nextNode = list->head;  // Den nye nodes nextNode peger på den nuværende head
        list->head->prevNode = newNode;   // Den nuværende heads prevNode peger på den nye node
        list->head = newNode;              // Opdater head til den nye node
        printf("Tilføjet ny node med data: %d til starten\n", data);
    }
}

void add_node_to_end(linklist* list, int data) {
    if (list == NULL) {
        printf("Listen er NULL, kan ikke tilføje node.\n");
        return;
    }

    node* newNode = create_node(data);  

    // Hvis listen er tom, sætter vi både head og tail til den nye node
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        printf("Tilføjet som første node med data: %d\n", data);
    } else {
        // Hvis listen ikke er tom, tilføj noden til slutningen
        list->tail->nextNode = newNode; // Sæt den nuværende tail's nextNode til den nye node
        newNode->prevNode = list->tail; // Sæt den nye nodes prevNode til den nuværende tail
        list->tail = newNode; // Opdater tail til den nye node
        printf("Tilføjet ny node med data: %d til slutningen\n", data);
    }
}

void add_node_by_index(linklist* list, unsigned int index, int value) {
    if (list == NULL) {
        printf("Listen er NULL, kan ikke tilføje node.\n");
        return;
    }

    if (index == 0) { // Hvis vi skal tilføje som første node
        add_node_to_start(list, value);
        return;
    }

    node* currentNode = list->head; // Start ved head
    for (unsigned int i = 0; i < index; i++) {
        currentNode = currentNode->nextNode; // Bevæger os til den ønskede node
        if (currentNode == NULL) { // Hvis index er uden for grænserne
            add_node_to_end(list, value); // Tilføj til slutningen
            return;
        }
    }

    // Opret en ny node
    node* newNode = create_node(value);
    node* nodeBefore = currentNode->prevNode;

    // Opdater linkene
    newNode->nextNode = currentNode;
    newNode->prevNode = nodeBefore;

    if (nodeBefore != NULL) {
        nodeBefore->nextNode = newNode; // Opdater next på node før
    }
    currentNode->prevNode = newNode; // Opdater prev på currentNode

    if (currentNode == list->head) { // Hvis vi indsætter ved head
        list->head = newNode; // Opdater head til den nye node
    }

    printf("Tilføjet node med data: %d ved index: %d\n", value, index);
}

void remove_first(linklist* list) {
    if (list->head == NULL) { // Tjekker om listen er tom
        printf("Listen er tom, kan ikke fjerne første node.\n");
        return;
    }

    node* nodeToRemove = list->head; // Gem den node, der skal fjernes

    if (list->head == list->tail) { // Hvis der kun er én node
        list->head = NULL; // Opdater head til NULL
        list->tail = NULL; // Opdater tail til NULL
    } else {
        list->head = list->head->nextNode; // Opdater head til næste node
        list->head->prevNode = NULL; // Sæt den nye heads prevNode til NULL
    }

    printf("Fjernet første node med data: %d\n", nodeToRemove->data);
    free(nodeToRemove); // Frigiv hukommelsen for den fjernede node
}

void remove_last(linklist* list) {
    if (list->tail == NULL) { // Tjekker om listen er tom
        printf("Listen er tom, kan ikke fjerne sidste node.\n");
        return;
    }

    node* nodeToRemove = list->tail; // Gem den node, der skal fjernes

    if (list->head == list->tail) { // Hvis der kun er én node
        list->head = NULL; // Opdater head til NULL
        list->tail = NULL; // Opdater tail til NULL
    } else {
        list->tail = list->tail->prevNode; // Opdater tail til forrige node
        list->tail->nextNode = NULL; // Sæt den nye tails nextNode til NULL
    }

    printf("Fjernet sidste node med data: %d\n", nodeToRemove->data);
    free(nodeToRemove); // Frigiv hukommelsen for den fjernede node
}

void remove_node_by_index(linklist* list, unsigned int index) {
    if (list->head == NULL) { // Tjekker om listen er tom
        printf("Listen er tom, kan ikke fjerne node ved index: %d\n", index);
        return;
    }

    if (index == 0) { // Hvis vi skal fjerne den første node
        remove_first(list);
        return;
    }

    node* currentNode = list->head; // Start ved head
    for (unsigned int i = 0; i < index; i++) {
        currentNode = currentNode->nextNode; 
        if (currentNode == NULL) { // Hvis index er uden for grænserne
            printf("Index %d er uden for listen, fjerner sidste node.\n", index);
            remove_last(list);
            return;
        }
    }

    node* nodeBefore = currentNode->prevNode;
    node* nodeAfter = currentNode->nextNode;

    if (nodeBefore != NULL) {
        nodeBefore->nextNode = nodeAfter; // Opdater next på node før
    }
    if (nodeAfter != NULL) {
        nodeAfter->prevNode = nodeBefore; // Opdater prev på node efter
    }

    printf("Fjernet node med data: %d ved index: %d\n", currentNode->data, index);
    free(currentNode); // Frigiv hukommelsen for den fjernede node
}


void dump_list(linklist* list) {
    if (list == NULL) {
        printf("Listen er NULL\n");
        return;
    }
    printf("----------------------------------\n");
    printf("Liste indhold:\n");
    node* current = list->head;
    while (current != NULL) {
        printf("Node data: %d, adresse: %p, next: %p, prev: %p\n", 
               current->data, (void*)current, (void*)current->nextNode, (void*)current->prevNode);
        current = current->nextNode;
    }
    printf("----------------------------------\n");
}

void swap_by_index(linklist* list, unsigned int indexA, unsigned int indexB) {
    if (list == NULL || list->head == NULL) {
        printf("Listen er NULL eller tom, kan ikke bytte noder.\n");
        return;
    }

    // Hent noderne ved index
    node* nodeA = list->head;
    node* nodeB = list->head;
    
    // Find nodeA
    for (unsigned int i = 0; i < indexA; i++) {
        if (nodeA == NULL) {
            printf("Index %d er uden for listen, kan ikke finde nodeA.\n", indexA);
            return;
        }
        nodeA = nodeA->nextNode;
    }

    // Find nodeB
    for (unsigned int i = 0; i < indexB; i++) {
        if (nodeB == NULL) {
            printf("Index %d er uden for listen, kan ikke finde nodeB.\n", indexB);
            return;
        }
        nodeB = nodeB->nextNode;
    }

    // Tjek om vi har fundet begge noder
    if (nodeA == NULL || nodeB == NULL) {
        printf("En eller begge noder findes ikke, kan ikke bytte.\n");
        return;
    }

    if (nodeA == nodeB) {
        printf("Noderne er de samme, ingen bytte.\n");
        return;
    }

    // Håndterer situationer hvor noderne er naboer
    if (nodeA->nextNode == nodeB) { // nodeA er før nodeB
        // Opdater links
        nodeA->nextNode = nodeB->nextNode;
        nodeB->prevNode = nodeA->prevNode;

        if (nodeA->prevNode) {
            nodeA->prevNode->nextNode = nodeB;
        } else {
            list->head = nodeB; // Opdater head hvis nodeA var head
        }

        if (nodeB->nextNode) {
            nodeB->nextNode->prevNode = nodeA; // Opdater prev på nodeB's next
        } else {
            list->tail = nodeA; // Opdater tail hvis nodeB var tail
        }

        nodeB->nextNode = nodeA; // nodeB peger nu på nodeA
        nodeA->prevNode = nodeB; // nodeA peger tilbage til nodeB
    } else if (nodeB->nextNode == nodeA) { // nodeB er før nodeA
        // Opdater links
        nodeB->nextNode = nodeA->nextNode;
        nodeA->prevNode = nodeB->prevNode;

        if (nodeB->prevNode) {
            nodeB->prevNode->nextNode = nodeA;
        } else {
            list->head = nodeA; // Opdater head hvis nodeB var head
        }

        if (nodeA->nextNode) {
            nodeA->nextNode->prevNode = nodeB; // Opdater prev på nodeA's next
        } else {
            list->tail = nodeB; // Opdater tail hvis nodeA var tail
        }

        nodeA->nextNode = nodeB; // nodeA peger nu på nodeB
        nodeB->prevNode = nodeA; // nodeB peger tilbage til nodeA
    } else { // Noderne er ikke naboer
        node* prevA = nodeA->prevNode;
        node* nextA = nodeA->nextNode;
        node* prevB = nodeB->prevNode;
        node* nextB = nodeB->nextNode;

        // Opdater links for nodeA
        if (prevA) {
            prevA->nextNode = nodeB;
        } else {
            list->head = nodeB; // Opdater head hvis nodeA var head
        }

        if (nextA) {
            nextA->prevNode = nodeB;
        }

        // Opdater links for nodeB
        if (prevB) {
            prevB->nextNode = nodeA;
        } else {
            list->head = nodeA; // Opdater head hvis nodeB var head
        }

        if (nextB) {
            nextB->prevNode = nodeA;
        }

        // Byt next pointers
        nodeA->nextNode = nextB;
        nodeB->nextNode = nextA;

        // Byt prev pointers
        nodeA->prevNode = prevB;
        nodeB->prevNode = prevA;
    }

    printf("Byttede noder ved index: %d og %d\n", indexA, indexB);
}




int main() {
    // Opret en tom liste
    linklist* myList = create_list();

    if (myList == NULL) {
        printf("Fejl ved oprettelse af listen.\n");
        return 1;
    }

    // Tilføj noder til slutningen
    printf("-----------TILFØJER NODES TIL SLUTNINGEN-------------\n");
    add_node_to_end(myList, 20);
    add_node_to_end(myList, 30);
    add_node_to_end(myList, 40);
    printf("-----------------------------------------------------\n");

    
    dump_list(myList);

    // Tilføj node til starten
    printf("-----------TILFØJER NODE TIL STARTEN-------------\n");
    add_node_to_start(myList, 10);
    printf("-------------------------------------------------\n");

    
    dump_list(myList);

    // Tilføj node ved index
    printf("-----------TILFØJER NODE TIL INDEX-------------\n");
    add_node_by_index(myList, 2, 25); // Indsæt 25 ved index 2
    printf("-----------------------------------------------\n");

    dump_list(myList);

    // Fjern en node ved index
    printf("-----------FJERNER NODE VED INDEX-------------\n");
    remove_node_by_index(myList, 1); // Fjern node ved index 1
    printf("----------------------------------------------\n");

    dump_list(myList);

    // Swap noderne ved index 0 og 1 (10 og 25)
    printf("-----------BYTTER NODES PÅ INDEX 0 og 1 (10 og 25)-------------\n");
    swap_by_index(myList, 0, 1); // Swap 10 og 25
    printf("----------------------------------------------------------------\n");

    dump_list(myList);

    // Swap noderne ved index 1 og 2 (30 og 10)
    printf("-----------BYTTER NODES PÅ INDEX 1 og 2 (30 og 10)-------------\n");
    swap_by_index(myList, 1, 2); // Swap 30 og 10
    printf("----------------------------------------------------------------\n");


    dump_list(myList);

    // Fjern første node
    remove_first(myList);
    dump_list(myList);

    // Fjern sidste node
    remove_last(myList);
    dump_list(myList);

    // Prøv at fjerne en node ved index, der ikke eksisterer
    remove_node_by_index(myList, 10); // Ugyldigt index
    dump_list(myList);

    // Tilføj node til slutningen igen
    add_node_to_end(myList, 50);
    dump_list(myList);

    // Ryd op
    remove_last(myList); // Fjern den sidste node 
    remove_last(myList); // Fjern den sidste node 
    remove_first(myList); // Fjern den første node (fejl fordi den er tom)
    
    // Afslut listen
    free(myList); // Frigiv hukommelse til listen
    return 0;
}




