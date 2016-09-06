#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100 	/* max size of operand or operator */

main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch (type){
			case NUMBER:
				push(atof(s));
				break;
			case FUNCTION:	/* function of sin,exp,pow */
				if(!strcmpi(s,"sin"))	
					push(sin(pop()));
				else if(!strcmpi(s,"exp"))
					push(exp(pop()));
				else if(!strcmpi(s,"pow"))
					push(pow(pop(),pop()));
				else 
					printf("Sorry,no %s function exist.\n",s);
				break;

			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else printf("%s\n", "0 divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else printf("%s\n", "0 divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error, unknown%s\n", s);
				break;
		}
	}
	return 0;
}