/* COMPLETE
 * The following iterative sequence is defined for the set of positive integers:
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)

 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?

 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned long long number; // The number which we are attempting to converge to 1
	int longest_chain = 0, longest_chain_number = 0;
	int starting_number;
	
	// Loop from 1 to 1,000,000 
	for (starting_number = 1, number = 1; starting_number < 1000000; number = ++starting_number) {
		int current_chain = 0;
		// If the number has not converged to one, iterate.
		while (number != 1) {
			if (number % 2) { // odd
				number = 3 * number + 1;	
			} else {
				number = number / 2;
			}
			current_chain++;
		}
		// Update longest chain
		if (current_chain > longest_chain) {
			longest_chain = current_chain;
			longest_chain_number = starting_number;
		}
	}
	
	printf("Longest Chain: %d achieved with starting number: %d\n", longest_chain, longest_chain_number);
    return 0;
}
