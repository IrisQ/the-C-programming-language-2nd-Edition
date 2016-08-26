/********************************************
         Make '\b','\t','\' vasible
********************************************/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;

	while ((c = getchar()) != EOF) {
		if(c == '\t'){
			printf("\\t");
		}else if(c == '\b'){
			printf("\\b");
		}else{
			putchar(c);
		}
	}
	return 0;
}
