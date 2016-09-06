#include <stdio.h>
#include "calc.h"
#define BUFFSIZE 100

static char buf[BUFFSIZE];	/* buffer for ungetch */
static int bufp = 0;		/* next free position in buf */

/* get a (possibly pshed-back) character */
int getch(void){
	return ((bufp) > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c){
	if(bufp > BUFFSIZE)
		printf("BUF SIZE ALREADY FULL");
	else
		buf[bufp++] = c;
}
