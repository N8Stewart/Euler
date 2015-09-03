/*
 * What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
 * (Grid in separate text file to be loaded during runtime)
 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 20
#define LENGTH 4 /* the length of the adjacent numbers */
#define FILENAME "grid.txt"

/* Load the matrix from file 'in' into the matrix 'matrix' */
void loadNumber(int *matrix, FILE *in);

int main(void){
	int *matrix;
	FILE *in;
	int i, j;
	unsigned long long max_prod;
	unsigned long long curr_prod;
	int buffer;
    
    /* create space on heap for matrix */
    matrix = malloc(sizeof(int) * ROWS * COLUMNS);

	/* Create file handle */
	if((in = fopen(FILENAME, "r")) == NULL){
		printf("Unable to open file '%s'\n", FILENAME);
		return 1;
	}
	/* Load the 20x20 grid of two digit numbers into the matrix */
	loadNumber(matrix, in);
	fclose(in);
    
    /* Output the matrix to ensure it has been loaded correctly */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%02d ", *(matrix + (i * COLUMNS) + j));
        }
        printf("\n");
    }
    
    /* Figure out the largest list of adjacent numbers */
    
    /* Free the memory allocated on the heap for the matrix */
    free(matrix);

}

void loadNumber(int *matrix, FILE *in) {
    int i;

	/* Fill the array with every number in the file */
	for(i = 0; i < ROWS * COLUMNS; i++){
		fscanf(in, "%2d", (matrix + i));
	}
}