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
	int *currCell;
	FILE *in;
	int i, j, k;
	unsigned long long maxProd;
	unsigned long long currProd[4];
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
	
	maxProd = 0;
    /* Figure out the largest list of adjacent numbers */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
			currCell = matrix + (i * COLUMNS) + j;
			currProd[0] = 0; currProd[1] = 0; currProd[2] = 0; currProd[3] = 0;
			if (i <= ROWS - LENGTH) { /* Compute south */
				currProd[0] = *currCell * *(currCell + (1 * COLUMNS)) * *(currCell + (2 * COLUMNS)) * *(currCell + (3 * COLUMNS));
				if (j <= COLUMNS - LENGTH) { /* Compute south-east */
					currProd[1] = *currCell * *(currCell + (1 * COLUMNS) + 1) * *(currCell + (2 * COLUMNS) + 2) * *(currCell + (3 * COLUMNS) + 3); 
				}
				if (j >= LENGTH - 1) { /* Compute south-west */
					currProd[2] = *currCell * *(currCell + (1 * COLUMNS) - 1) * *(currCell + (2 * COLUMNS) - 2) * *(currCell + (3 * COLUMNS) - 3);
				}
			}
			if (j <= COLUMNS - LENGTH) { /* Compute east */
				currProd[3] = *currCell * *(currCell + 1) * *(currCell + 2) * *(currCell + 3);
			}
			/* If any of the calculated products are greater than the max, overwrite the max */
			for (k = 0; k < LENGTH; k++) 
				if (currProd[k] > maxProd) 
					maxProd = currProd[k];
			
        }
    }

    /* Free the memory allocated on the heap for the matrix */
    free(matrix);

	printf("Max Product = %llu\n", maxProd);

}

void loadNumber(int *matrix, FILE *in) {
    int i;

	/* Fill the array with every number in the file */
	for(i = 0; i < ROWS * COLUMNS; i++){
		fscanf(in, "%2d", (matrix + i));
	}
}
