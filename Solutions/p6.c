#include <stdint.h>
#include <stdio.h>
#include <math.h>

// 06/10/2018
// This one was nice and easy :D

/*Find the difference between the sum of the squares of the first one
 hundred natural numbers and the square of the sum.*/

uint64_t sumOfSquares(unsigned roof);
uint64_t squareOfSums(unsigned roof);
int main(void);

uint64_t sumOfSquares(unsigned roof)
{
    uint64_t sum = 0;
    for (unsigned i = 1; i <= roof; i++)
        sum += powl(i, 2);
    printf("sum of squares up to %u is %u\n", roof, sum);
    return sum;
}

uint64_t squareOfSums(unsigned roof)
{
    uint64_t square = 0;
    uint64_t sum = 0;
    for (unsigned i = 1; i <= roof; i++)
        sum += i;
    square = pow(sum, 2);
    printf("square of sum up to %u is %u\n", roof, square);
    return square;
}

int main(void)
{
    unsigned roof = 100;
    uint64_t a = sumOfSquares(roof);
    uint64_t b = squareOfSums(roof);
    uint64_t c = b - a;
    printf("The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is %u\n", c);
    return 0;
}