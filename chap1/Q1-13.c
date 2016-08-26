/********************************************
Print the length of each word in column
(in horizontal direction)
********************************************/
#include <stdio.h>

void printcolumn(int length);

int main(int argc, char const *argv[])
{
	char c;
	int length = 0;	/* length of word */
	
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n') {
			printcolumn(length);
			length = 0;
		} else {
			length++;			
		}
	}
	return 0;
}

void printcolumn(int length){
	while(length--){
		printf("%c", '-');
	}
	printf("\n");
}