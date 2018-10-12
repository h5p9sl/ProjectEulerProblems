#include <stdio.h>

// 06/10/2018
// This was a refreshing problem after #3 and #4 lol
// 'Find the smallest number divisible by any number ranging from 1 to 20 without a remainder.'

typedef unsigned long ulong;

int main()
{
    ulong m = 20; // Max number
    for (ulong i = 1;; i++)
    {
        bool b = true;
        for (ulong j = 1; j <= m; j++) {
            if (i % j != 0) {
                b = false;
                break;
            }
        }
        if (b) {
            printf("The smallest number divisible by numbers 1 to %i is %i.\n", m, i);
            return 0;
        }
    }
}