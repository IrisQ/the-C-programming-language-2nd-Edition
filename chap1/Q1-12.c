/********************************************
        Print one word on each line
********************************************/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n') {
			putchar('\n');
		} else {
			putchar(c);
		}
	}
	return 0;
}
