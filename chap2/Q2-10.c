/********************************************
lower: transfer capital letter into lower letter,
use A ? B : C
********************************************/
#include <stdio.h>

int lower(int c);

int main(int argc, char const *argv[])
{
	char c = 'V';
	printf("%c\n", lower(c));
	return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}