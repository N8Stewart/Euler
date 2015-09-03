/* COMPLETE
 * Special Pythagorean Triplet
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a2 + b2 = c2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */
#include <stdio.h>

int main(void){

    int a, b, c;
    
    /* Bounds found using logic */
    int cmin = 335;
    int cmax = 997;
    int bmin = 2;
    int bmax = 499;
    int amin = 1;
    int amax = 332;
    
    /* Very naive approach is to loop over bounds of a, b, and c. */
    for (c = cmin; c <= cmax; c++) {
        for (b = bmin; b <= bmax; b++) {
            if (c + b + amax < 1000 || c + b + amin > 1000) // No point in looping through all the a's max/min a does not match reqs
                continue;
            for (a = amin; a <= amax; a++) {
                if (a + b + c != 1000 ){ // violates a precondition   
                    continue;
                } else {
                    if ( (a * a + b * b) == c * c) {
                        printf("a^2 + b^2 = c^2 when a=%d, b=%d, c=%d. a * b * c = %d\n", a, b, c, a*b*c);
                        return 0;
                    }
                }
            }
        }
    }
    
    printf("Unable to find a, b, c such that a^2 + b^2 = c^2 and a + b + c = 1000");
	return -1;

}