/********************************************
Count the number of '\t','\n',' ' seperately
********************************************/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int space = 0;
	int nl = 0;
	int tl = 0;
	char c;

	while((c = getchar()) != EOF){
		if(c == '\t')
			++tl;
		if(c == '\n')
			++nl;
		if(c == ' ')
			++space;
	}
	printf("tab:%d\tnewline:%d\tspace:%d\n", tl,nl,space);
	return 0;
}