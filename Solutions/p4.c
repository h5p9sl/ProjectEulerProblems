#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// 05/10/2018
// Edited & optimized on 11/10/2018

bool isPalindrome(uint64_t num);
uint64_t largestPalindrome();

bool isPalindrome(uint64_t num)
{
    uint64_t reversed = 0, n = num;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return num == reversed;
}

uint64_t largestPalindrome()
{
    uint64_t result;
    for (unsigned i = 100; i <= 999; i++) {
        for (unsigned j = 100; j <= 999; j++) {
            if (i*j > result && isPalindrome(i*j))
                result = i*j;
        }
    }
    return result;
}

int main()
{
    printf("%u is the largest Palindrome made from two 3-digit factors.", largestPalindrome());
    return 0;
}