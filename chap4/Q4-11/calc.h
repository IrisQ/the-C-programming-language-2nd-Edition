#include <stdio.h>

#define NUMBER '0' 	/* signal that a number was found */
#define FUNCTION '1'

int getop(char s[]);
void push(double f);
double pop();
int getch(void);
void ungetch(int);
