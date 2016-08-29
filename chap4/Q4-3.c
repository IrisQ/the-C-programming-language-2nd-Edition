/* add '%' into calculator and consider negative numbers */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 	/* max size of operand or operator */
#define NUMBER '0' 	/* signal that a number was found */
#define MAXVAL 100
#define BUFFSIZE 100

char buf[BUFFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */
int sp = 0;			/* next free stack position */
double val[MAXVAL];	/* value stack */

int getop(char s[]);
void push(double f);
double pop();
int getch(void);
void ungetch(int);

main()
{
	int type;
	double op2,test;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch (type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				printf("top is: %f\n", test);
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

int getch(void){
	return ((bufp) > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp > BUFFSIZE)
		printf("BUF SIZE ALREADY FULL");
	else
		buf[bufp++] = c;
}
/* get next number or operator,escape ' ' and '\t' */
int getop(char s[]){
	int i,c;
	/*until s[0] get something that's not ' ' or '\t'*/
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	/*only store s[0], that's the end*/
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

/* push: push f onto value stack */
void push(double f){
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}else{
		printf("full, cannot push%f\n", f);
	}
}

/* pop: pop and return top value from stack */
double pop(){
	if(sp > 0){
		return val[--sp];
	}else{
		printf("empty, cannot pop");
		return 0.0;
	}
}