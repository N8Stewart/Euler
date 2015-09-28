/*
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 * File of 50 digit numbers is attached.
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define FILENAME "numbers.txt"
#define LENGTH 50 // Each number is 50 digits long

void loadNumber(FILE *in, list *number);
void printNumber(list *number);

int main(void){
	FILE *in;
	int i;

	/* Create file handle */
	if((in = fopen(FILENAME, "r")) == NULL){
		printf("Unable to open file '%s'\n", FILENAME);
		return 1;
	}
    
	/* Construct sum and current number lists */
    list *sum = malloc(sizeof(list));
    constructList(sum, LENGTH);
 	list *currNum = malloc(sizeof(list));
 	constructList(currNum, LENGTH);
	
	/* Print the first 10 digits of sum */
	node *head = sum -> head;
	for (i = 0; i < 10; i++, head = head -> next) {
		head -> digit = i + 48;
	}
	printNumber(sum);

	/* Deconstruct all constructs */
    fclose(in);
 	destructList(sum);
    free(sum);
	free(currNum);
    
    return 0;
}

/* Construct a number using a linked list */
void loadNumber(FILE *in, list *number){
    
    node *head_ptr;
    int i;
    
    /* fill in the linked list */
	for(i = 0, head_ptr = number -> head; i < LENGTH; i++, head_ptr = head_ptr -> next)
        fscanf(in, "%c", &(head_ptr -> digit));
}

/* Print the first 10 digits of the number passed as a parameter */
void printNumber(list *number) {
	node *head = number -> head;
	int i = 0;
	while (head != NULL && i < 10) {
        printf("%c", head -> digit);
		head = head -> next;
		i++;
	}
    printf("\n");
}
