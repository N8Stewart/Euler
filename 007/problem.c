/* COMPLETE
 * 10001st Prime
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

 int main(int argc, char **argv){

 	int i, j;
 	int prime, index;
 	int limit;
 	int num;
 	int n;

 	if(argc != 2){

 		printf("Invalid usage. Calculate nth prime using following syntax.\n");
 		printf("\t./%s <n>\n", argv[0]);
 		printf("\twhere n is the nth prime to be calculated.\n");

 	}

 	n = atoi(argv[1]);

 	/* set num to 0 initially. Insert the result into this variable. Used as flag and return value */
 	prime = 0;
 	index = 0;
 	num = 0;
 	i = 2;

 	while(index < n){
 		limit = sqrt(i); /* No roots higher than this value */
 		for(j = 2; j <= limit; j++){

 			/* If i is divisible by j, move to next value */
 			if(i % j == 0){
 				num = -1;
 				break;
 			}

 		}

 		/* Check if flag has been set on whether the number is prime. */
 		if(num == -1){
 			num = 0;
 		}else{
 			index++;
 			prime = i;
 		}

 		i++; /* Move onto next number and evaluate primeness */

 	}

 	printf("10001st prime: %d\n", prime);

 	return 0;

 }