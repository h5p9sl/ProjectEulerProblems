#include <stdio.h>
#include <stdbool.h>

// 06/10/2018
// I should try and add a seive algorithm to these sometime.

typedef unsigned long ulong;

/*What is the 10001st prime number?*/

bool isPrime(ulong n);
ulong getPrimeNumberOfIndex(unsigned i);
unsigned getIndexFromPrimeNumber(ulong n);
int main(void);

bool isPrime(ulong n)
{
    for (ulong i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}

ulong getPrimeNumberOfIndex(unsigned i)
{
    ulong n; unsigned c = 0;
    for (n = 2; c < i; ++n) {
        if (isPrime(n)) c++;
        if (c == i) break;
    }
    return n;
}

// Added this one just to get the index of (Cicada) 3301
// 3301 = PrimeNumbers[ 464 ]
unsigned getIndexFromPrimeNumber(ulong n)
{
    if (!isPrime(n)) return 0;
    unsigned i; ulong a;
    // This method is in no way efficient. But, fuck it.
    for (i = 0; a != n; ++i) {
        a = getPrimeNumberOfIndex(i);
        if (a == n) break;
    }
    return i;
}

int main(void)
{
    unsigned index = 10001;
    printf("The %u(th/st) prime number is %u\n", index, getPrimeNumberOfIndex(index));
    return 0;
}