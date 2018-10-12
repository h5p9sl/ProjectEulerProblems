#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>

// 11/10/2018
// What is the first triangle number to have over 500 divisors?

using namespace std::chrono;

unsigned numberOfDivisors(unsigned number);
inline unsigned getTriangleNumber(unsigned index);
unsigned firstTriangleOfDivisorCount(unsigned count);

unsigned numberOfDivisors(unsigned number)
{
    unsigned nod = 0;
    unsigned sqrt = (unsigned)sqrtf(number);
 
    for(unsigned i = 1; i<= sqrt; i++){
        if(number % i == 0){
            nod += 2;
        }
    }
    //Correction if the number is a perfect square
    if (sqrt * sqrt == number) {
        nod--;
    }
 
    return nod;
}

inline unsigned getTriangleNumber(unsigned index)
{
    unsigned result = 0;
    for (unsigned i = 1; i < index; i++)
        result += i;
    return result;
}

unsigned firstTriangleOfDivisorCount(unsigned count)
{
    unsigned result = 0;

    // Continuously generate triangle numbers until one
    // that has over X divisors is found
    unsigned triNumber;
    for (unsigned i = 2; result == 0; i++) {
        triNumber = getTriangleNumber(i);
        unsigned divisors = numberOfDivisors(triNumber);
        if (divisors > count) result = triNumber;
    }

    return result;
}

int main()
{
    auto t1 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    std::cout << firstTriangleOfDivisorCount(500) << std::endl;

    auto t2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    auto duration = (t2 - t1) / powf(1000.f, 3);
    std::cout << "Program finished in " << duration << " seconds." << std::endl;
    return 0;
}