#include <stdio.h>

// 18/10/2018

unsigned CollatzConjecture(unsigned start)
{
    unsigned count = 1;
    while (start > 1)
    {
        if (start % 2 == 0) start /= 2;
        else start = start * 3 + 1;
        count++;
    }
    return count;
}

int main()
{
    unsigned largestCount, largestStart;
    for (unsigned i = 1; i < 1000000; i++)
    {
        unsigned count = CollatzConjecture(i);
        if (count > largestCount)
        {
            largestCount = count;
            largestStart = i;
        }
    }

    printf("%u\n", largestStart);

    return 0;
}