/* COMPLETE
 * Largest Product in a Series
 * The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
 * ## Large number that I have not included due to space ##
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. 
 * What is the value of this product?
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define LENGTH 13 /* Length of partial product. Can be used to check that the 4-tuple is correct */
#define FILENAME "number.txt"

void loadNumber(int * array, FILE *in);

int main(void){
	int number[SIZE];
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
	loadNumber(number, in);
	fclose(in);


	buffer = 0;
	curr_prod = 1;
	max_prod = 1;
	/* run through the array calculating the partial products and comparing them to the max product */
	for(i = 0; i < SIZE; i++){
		/* Check if the number in position i is a 0. If it is, move i 13 spots. */
		if(number[i] == 0){
			buffer = LENGTH;
			curr_prod = 1;
			/* We have hit a 0, so we must move LENGTH digits down the line to get the next nonzero partial product */
			while(buffer > 0 && i < SIZE){
				i++;
				buffer--;
				/* Hit another 0. Reset the buffer. */
				if(number[i] == 0){
					buffer = LENGTH;
					curr_prod = 1;
				}else{
					curr_prod *= number[i];
				}
			}
			if(i >= SIZE){
				break;
			}else{
				buffer = LENGTH;
				/* Compare the current with the max and swap if necessary */
				if(curr_prod > max_prod){
					max_prod = curr_prod;
				} 
				continue;
			}
		}

		if(buffer == LENGTH){
			/* Divide the product by the earliest number and multiply by the most recent */
			curr_prod = curr_prod / number[i-LENGTH] * number[i]; 
		}else{
			/* Multiply by the most recent */
			curr_prod *= number[i];
			buffer++;
		}

		/* Compare the current with the max and swap if necessary */
		if(curr_prod > max_prod){
			max_prod = curr_prod;
		} 
	}

	printf("Largest Product: %llu\n", max_prod);

	return 0;
}

/* Load from memory the number in the text file. This function makes it dynamic */
void loadNumber(int *array, FILE *in){
	int i;
	char number[2];
	number[1] = '\0';

	/* Fill the array with every number in the file */
	for(i = 0; i < SIZE; i++){
		fscanf(in, "%c", number);
		*(array + i) = atoi(number);
	}
}
