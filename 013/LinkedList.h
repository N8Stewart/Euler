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

void constructList(list *inst);
void destructList(list *inst);