/* COMPLETE
 * Largest Palindrome Product
 * A palindromic number reads the same both ways. 
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <string.h>

int checkPalindrome(char *product, int len);
int itoa(int num, char *s);

int main(void){

	int num1, num2;
	int product;
	int found;
	char char_product[7]; /* 999 * 999 = 998001 so max size is 6 (7 with null character) */
	int len;
	int max_product;

	max_product = 0;
	/* Loop through 999 to 100 decreasingly on two numbers to find the largest palindrome product */
	for(num1 = 999; num1 > 100; num1--){
		for(num2 = 999; num2 > 100; num2--){
			product = num1 * num2;
			len = itoa(product, char_product); /* Convert the product to character to check palindrome */
			/* Check if product is a palindrome */
			if(checkPalindrome(char_product, len) == 1) {
				/* Check if product is greater than the max_product */
				if(product > max_product){
					max_product = product;
				}
			}
		}
	}

	printf("Largest Palindrome Product: %d\n", max_product);

	return 0;
	
}

/* Returns size of string s */
int itoa(int num, char *s){
	int ascii_zero;
	int digit;
	int pos; /* Position of digit on the string */

	ascii_zero = 48; /* Ascii value of 0 is 48 */

	/* Recursively dive into the number */
	if(num == 0){
		return 0;
	}else{
		digit = num % 10;
		pos = itoa(num/10, s);
		/* Begin placing digits onto the string s */
		s[pos] = (char)(digit + ascii_zero);
		s[pos+1] = '\0'; /* Put null character onto the end of the current string */
		return pos + 1;
	}
}

/* Return 1 if palindrome, 0 if not */
int checkPalindrome(char *product, int len){
	int i, j;

	/* Palindrome check */
	for(i = 0, j = (len-1); i < j; i++, j--){
		if(product[i] != product[j]) return 0;
	}

	return 1;
}
