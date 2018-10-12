#include <stdio.h>
#include <math.h>

// 06/10/2018
// This one was nice and easy :D

typedef unsigned long ulong;

/*Find the difference between the sum of the squares of the first one
 hundred natural numbers and the square of the sum.*/

ulong sumOfSquares(unsigned roof);
ulong squareOfSums(unsigned roof);
int main(void);

ulong sumOfSquares(unsigned roof)
{
    ulong sum = 0;
    for (unsigned i = 1; i <= roof; i++)
        sum += powl(i, 2);
    printf("sum of squares up to %u is %u\n", roof, sum);
    return sum;
}

ulong squareOfSums(unsigned roof)
{
    ulong square = 0;
    ulong sum = 0;
    for (unsigned i = 1; i <= roof; i++)
        sum += i;
    square = pow(sum, 2);
    printf("square of sum up to %u is %u\n", roof, square);
    return square;
}

int main(void)
{
    unsigned roof = 100;
    ulong a = sumOfSquares(roof);
    ulong b = squareOfSums(roof);
    ulong c = b - a;
    printf("The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is %u\n", c);
    return 0;
}