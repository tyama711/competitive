#include <stdio.h>
#include <math.h>

bool check(unsigned long n) {
	unsigned long b = n / sqrt(2) + 1;
	return (2*b*(b-1) == n*(n-1));
}

int main(void) {
	unsigned long i;

	for (i = (unsigned long)pow(10,12); ;) {
		if (check(i))
			break;
		i += 1 + 2*(i%4);
	}
	printf("%lu\n",(unsigned long)(i / sqrt(2) + 1));
	
	return 0;
}
