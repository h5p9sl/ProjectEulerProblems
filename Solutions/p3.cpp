#include <stdlib.h>
#include <vector>
#include <stdio.h>

// 07/06/2018

uint64_t divide(uint64_t x);
bool inline isPrime(uint64_t x);
void addPrimeNumbers(uint64_t x);

std::vector<uint64_t> PrimeNumbers;

int main()
{
	const uint64_t foo = 600851475143;

	// Find all prime numbers and add them to the vector
	addPrimeNumbers(foo);

	// Find biggest prime number
	unsigned int biggestIndex = 0;
	for (unsigned int i = 1; i < PrimeNumbers.size(); i++)
	{
		if (PrimeNumbers.at(i) > PrimeNumbers.at(biggestIndex))
		{
			biggestIndex = i;
		}
	}

	printf("BIGGEST PRIME = %llu\n", PrimeNumbers.at(biggestIndex));
	printf("%llu = ", foo);

	for (unsigned int i = 0; i < PrimeNumbers.size(); i++)
	{
		if (i == PrimeNumbers.size()-1)
		{
			printf("%llu\n", PrimeNumbers.at(i));
			break;
		}
		printf("%llu * ", PrimeNumbers.at(i));
	}

	return 0;
}

void addPrimeNumbers(uint64_t j)
{
	uint64_t foo = j;
	while (!isPrime(foo))
	{
		uint64_t x = divide(foo);
		foo /= x;
		if (isPrime(x)) {
			PrimeNumbers.push_back(x);
		}
		else {
			addPrimeNumbers(x);
		}
	}
	PrimeNumbers.push_back(foo);
}

bool inline isPrime(uint64_t x)
{
	return (divide(x) == 1) ? true : false;
}

uint64_t divide(uint64_t x)
{
	for (uint64_t i = 2; i < x; i++)
	{
		if (x % i == 0) // x is divisible by i
			return i;
	}
	return 1; // x is a prime number
}