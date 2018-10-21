#include <stdio.h>
#include <stdint.h>

// 06/06/2018

int main()
{
	uint64_t sum = 0;
	uint64_t foo[2] = { 0, 1 };
	while(foo[1] <= 4000000)
	{
		uint64_t bar = foo[0] + foo[1];
		if (bar % 2 == 0) {
			sum += bar;
		}
		foo[0] = foo[1];
		foo[1] = bar;
	}
	printf("FINAL: %llu\n", sum);
	return 0;
}