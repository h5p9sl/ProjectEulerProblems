#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 11/10/2018
// There is exactly one Pythagorean triplet in which (a + b + c) = 1000. Find the product (abc).

int main()
{
    const int s = 1000;
    for (int a = 1; a < s; a++)
    {
        for (int b = 1; b < s; b++)
        {
            float c = sqrtf( powf(a,2.f) + powf(b,2.f) );
            if (a+b+c != s) continue;
            printf("The product of abc is %.0f\n", a*b*c);
            return 0;
        }
    }
    return 1;
}