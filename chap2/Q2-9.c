/********************************************
use bitcount count the number of 1 in x
********************************************/
#include <stdio.h>

int bitcount(unsigned x);

int main(int argc, char const *argv[])
{
	printf("%d\n", bitcount(0111));
	return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &= (x - 1))
		b++;
	return b;
}
