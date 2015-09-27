/*
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 * File of 50 digit numbers is attached.
 */
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "numbers.txt"
#define LENGTH 50 // Each number is 50 digits long

typedef struct node{
    struct node *next;
    char digit;
} node;

void loadNumber(FILE *in);


int main(void){
	FILE *in;
	int i;
	unsigned long long max_prod;
	unsigned long long curr_prod;
	int buffer;

	/* Create file handle */
	if((in = fopen(FILENAME, "r")) == NULL){
		printf("Unable to open file '%s'\n", FILENAME);
		return 1;
	}
	/* Load the 1000 digit number into the array */
	loadNumber(in);
	fclose(in);

	printf("Largest Product: %llu\n", max_prod);

	return 0;
}

/* Construct a number using a linked list and return a pointer to the head */
void loadNumber(FILE *in){
	
}