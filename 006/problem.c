/* COMPLETE
 * Sum Square Difference
 * The sum of the squares of the first ten natural numbers is:
 *		1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is:
 * 		(1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <limits.h>

 int main(void){

 	int i, j;

 	unsigned long long sum_square;
 	unsigned long long sum;
 	unsigned long long difference;
 	sum_square = 0;
 	sum = 0;
 	difference = 0;

 	/* Calculate the square of sum of 1 to 100 */
 	for(i = 1; i <= 100; i++){
 		sum_square += i;
 	}
 	sum_square *= sum_square;

 	/* Calculate the sum of squares for 1 to 100 */
 	for(i = 1; i <= 100; i++){
 		sum += i * i;
 	}

 	/* Take the difference between the two and output to console */
 	difference = sum_square - sum;

 	printf("Sum Square Difference: %llu\n", difference);

 	return 0;

 }