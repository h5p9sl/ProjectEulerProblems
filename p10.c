#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// 10/10/2018
// Find the sum of all of the primes under 2000000 (two million).

uint64_t sumOfPrimes(unsigned below)
{
    // Generate primes using Sieve of Eratosthenes
    bool* primes = malloc(sizeof(bool) * below);
    memset(primes, true, sizeof(bool) * below);

    for (unsigned i = 2; i <= below; i++) {
        if (primes[i] == false) continue;
        for (unsigned j = i+i; j <= below; j+=i) primes[j] = false;
    }

    // Calculate the sum of all the primes
    uint64_t sum = 0;
    uint64_t count = 0;
    for (unsigned i = 2; i <= below; i++) {
        if (primes[i] == true) {
            sum += i;
            count++;
        }
    }
    
    printf("There are %u prime numbers below %u.\n", count, below);

    free(primes);
    return sum;
}

int main(void)
{
    const unsigned below = 2000000;
    printf("The sum of all prime numbers under %u is %lld.\n", below, sumOfPrimes(below));
    return 0;
}