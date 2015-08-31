/* COMPLETE
 * Largest Prime Factor
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */

 #include <stdio.h>

 /* Define the number to be factored */
 #define NUMBER 600851475143

int main(void){

	unsigned long long number;
	unsigned long long factor;
	unsigned long long largest_factor;

	/* Initialize variables */
	number = NUMBER;
	factor = 2;
	largest_factor = 1;

	/* Loop until the factors of the number are 1 and largest_factor */
	while(number != 1){

		/* If factor is a factor of the number, divide number by factor and store factor as the largest factor */
		if(number % factor == 0){
			largest_factor = factor;
			number /= factor;
			factor = 2;
		}else{ /* Not a factor, so increment factor and iterate again */
			factor++;
		}
		
	}

	printf("Largest Prime Factor: %llu\n", largest_factor);

	return 0;
	
}
