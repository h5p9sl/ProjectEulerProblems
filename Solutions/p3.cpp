#include <stdlib.h>
#include <vector>
#include <stdio.h>

// 07/06/2018

unsigned long long divide(unsigned long long x);
bool inline isPrime(unsigned long long x);
void addPrimeNumbers(unsigned long long x);

std::vector<unsigned long long> PrimeNumbers;

int main()
{
	const unsigned long long foo = 600851475143;

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

void addPrimeNumbers(unsigned long long j)
{
	unsigned long long foo = j;
	while (!isPrime(foo))
	{
		unsigned long long x = divide(foo);
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

bool inline isPrime(unsigned long long x)
{
	return (divide(x) == 1) ? true : false;
}

unsigned long long divide(unsigned long long x)
{
	//for (unsigned long long i = x-1; i > 1; i--)
	//{
	//	if (x % i == 0) // x is divisible by i
	//		return i;
	//}
	for (unsigned long long i = 2; i < x; i++)
	{
		if (x % i == 0) // x is divisible by i
			return i;
	}
	return 1; // x is a prime number
}