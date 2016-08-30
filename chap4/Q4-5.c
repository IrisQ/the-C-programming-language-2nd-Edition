/* add sin,exp,pow into calculator */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 	/* max size of operand or operator */
#define NUMBER '0' 	/* signal that a number was found */
#define FUNCTION '1'
#define MAXVAL 100
#define BUFFSIZE 100

char buf[BUFFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */
int sp = 0;			/* next free stack position */
double val[MAXVAL];	/* value stack */
int func = 0;	/* 0:no function,1:sin,2:exp,3:pow */

int getop(char s[]);
void push(double f);
double pop();
int getch(void);
void ungetch(int);

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
	i = 0;
	/* get the string, might be name of function */
	if (isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			ungetch(c);
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