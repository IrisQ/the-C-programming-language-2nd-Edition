/* write ungets, put the char[] back into input */
#include <stdio.h>
#include <string.h>

#define BUFFSIZE 100

char buf[BUFFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void);
void ungetch(int);
void ungets(char s[]);

main()
{
	/* for test: */
	char s[] = "fall out boy";
	ungets(s);
	for(int i = 0;i < 15;i++){
		putchar(getch());
	}
	
	return 0;
}


/* put the string s back into input */
void ungets(char s[]){
	int length = strlen(s) - 1;
	while(length >= 0){
		ungetch(s[length--]);
	}
}

/* get a char, may have to push it back */
int getch(void){
	return ((bufp) > 0) ? buf[--bufp] : getchar();
}

/* push the char back in input */
void ungetch(int c){
	if(bufp > BUFFSIZE)
		printf("BUF SIZE ALREADY FULL");
	else
		buf[bufp++] = c;
}
