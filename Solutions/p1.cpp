#include <stdio.h>

// 05/06/2018

int main()
{
    int sum = 0;
    for (unsigned i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    printf("%i\n", sum);
    return 0;
}