#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* get next number or operator,escape ' ' and '\t' */
int getop(char s[]){
	int i,c;
	static char buf;
	/*until s[0] get something that's not ' ' or '\t'*/
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	/*only store s[0], that's the end*/
	s[1] = '\0';
	i = 0;

	/* get the string, might be name of function */
	if (isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			buf = c;
		return FUNCTION;
	}
	if(!isdigit(c) && c != '.')
		return c;	/* not a number */
	if (isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		buf = c;
	return NUMBER;
}