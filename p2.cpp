#include <stdio.h>

// 06/06/2018

typedef unsigned long long uLLong;

int main()
{
	uLLong sum = 0;
	uLLong foo[2] = { 0, 1 };
	while(foo[1] <= 4000000)
	{
		uLLong bar = foo[0] + foo[1];
		if (bar % 2 == 0) {
			sum += bar;
		}
		foo[0] = foo[1];
		foo[1] = bar;
	}
	printf("FINAL: %llu\n", sum);
	return 0;
}