/* COMPLETE
 * Smallest Multiple
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <limits.h>

 int main(void){

 	int i, j, num;

 	/* set num to 0 initially. Insert the result into this variable. Used as flag and return value */
 	num = 0;

 	/* One of the values between 1 and ~2million has a factor of every number [1, 20]. */
 	for(i = 1; i < INT_MAX; i++){
 		for(j = 2; j <= 20; j++){

 			/* If i is not divisible by j, move to next value */
 			if(i % j != 0){
 				num = -1;
 				break;
 			}

 		}
 		/* Check the flag to see if j is a factor of i. 
 		If it is, move onto the next number until we reach the smallest multiple */
 		if(num == -1){
 			num = 0;
 			continue;
 		}

 		/* If the program reaches this point, it has found the answer */
 		num = i;
 		break;

 	}

 	printf("Smallest Multiple: %d\n", num);

 	return 0;

 }