#include <stdlib.h>

typedef struct node{
    struct node *next;
    struct node *prev;
    char digit;
} node;

typedef struct list{
    node *head;
    node *tail;
} list;

/* Construct a list and associate the list head and tail with the allocated nodes */
void constructList(list *inst, int length) {
	int i;
    node *head = malloc(sizeof(node));
    inst -> head = head;
    /* construct a linked list */
    node *oldPtr = malloc(sizeof(node));
    oldPtr -> prev = head;
	head -> next = oldPtr;
    for (i = 2; i < length; i++) {
        node *newPtr = malloc(sizeof(node));
        oldPtr -> next = newPtr;
        newPtr -> prev = oldPtr;
        oldPtr = newPtr;
    }
    inst -> tail = oldPtr;   
}

/* Destruct a list, freeing all nodes except for the list itself. */
void destructList(list *inst) {
    node *curr = inst -> head;
    node *next;
    
    while ((next = curr -> next) != NULL) {
        free(curr);
        curr = next;
    }
}