/* COMPLETE
 * Summation of Primes
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 2000000

 int main(void){

 	int i, j;
 	unsigned long long sum;
 	int limit;
 	int num;

 	/* set num to 0 initially. Insert the result into this variable. Used as flag and return value */
  	num = 0;
 	sum = 0;

 	for(i = 2; i < LIMIT; i++){
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
 		}else{ /* i is prime, so add it to sum */
 			sum += i;
 		}

 	}

 	printf("Summation of Primes: %llu\n", sum);

 	return 0;

 }