/********************************************
set n bits of y on the right to the n bits of x 
started from p-th.
********************************************/
#include <stdio.h>

unsigned setbits(unsigned x,int p,int n,unsigned y);

int main(int argc, char const *argv[])
{
	printf("%u\n", setbits(29,4,3,117));
	return 0;
}

unsigned setbits(unsigned x,int p,int n,unsigned y){
	unsigned x2 = x & ~(~(~0U << n) << (p - n + 1));
	unsigned y2 = y & (~(~0U << n));
	return x2 | y2 << (p - n + 1);
}
