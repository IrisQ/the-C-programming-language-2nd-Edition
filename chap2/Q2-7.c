/********************************************

********************************************/
#include <stdio.h>

unsigned invert(unsigned x,int p,int n);

int main(int argc, char const *argv[])
{	
	printf("%u,%u\n", 21u,invert(21u,2,3));
	return 0;
}

unsigned invert(unsigned x,int p,int n){
	unsigned mask = ~(~0u << n) << (p - n + 1);
	return x ^ mask;
}