#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// 06/10/2018
// I should try and add a seive algorithm to these sometime.

/*What is the 10001st prime number?*/

bool isPrime(uint64_t n);
uint64_t getPrimeNumberOfIndex(unsigned i);
unsigned getIndexFromPrimeNumber(uint64_t n);
int main(void);

bool isPrime(uint64_t n)
{
    for (uint64_t i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}

uint64_t getPrimeNumberOfIndex(unsigned i)
{
    uint64_t n; unsigned c = 0;
    for (n = 2; c < i; ++n) {
        if (isPrime(n)) c++;
        if (c == i) break;
    }
    return n;
}

// Added this one just to get the index of (Cicada) 3301
// 3301 = PrimeNumbers[ 464 ]
unsigned getIndexFromPrimeNumber(uint64_t n)
{
    if (!isPrime(n)) return 0;
    unsigned i; uint64_t a;
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