/********************************************
Check the output of the expression:
"getchar() != EOF" is 0 or 1
********************************************/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("%d\n", getchar() != EOF);
	return 0;
}