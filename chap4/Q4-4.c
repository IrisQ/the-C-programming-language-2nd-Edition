/* add new stack operations */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXVAL 100

int sp = 0;			/* next free stack position */
double val[MAXVAL];	/* value stack */

void push(double f);
double pop();

/* own codes on stack */
void copyop();
void printtop();
void switchop();
void emptyop();
void printstack();

main()
{
	push(5.0);
	push(8.0);
	push(6.3);
	printstack();
	switchop();
	printstack();
	copyop();
	printstack();
	return 0;
}

/* used for testing codes */
void printstack(){
	for(int i = 0;i < sp;i++){
		printf("%f ",val[i]);
	}
	printf("\n");
}

/* copy the element on the top without poping it */
void copyop(){
	if(sp > 0){
		push(val[sp - 1]);
	}else{
		printf("stack is empty!\n");
	}
}

/* print the element on the top without poping it */
void printtop(){
	if(sp > 0)
		printf("%f\n",val[sp - 1]);
	else
		printf("stack is empty!\n");
}

/* switch the two numbers on the top of stack */
void switchop(){
	if(sp > 1){
		double a = pop();
		double b = pop();
		push(a);
		push(b);
	}else{
		printf("not enough items in the stack.\n");
	}
}

/* empty the stack */
void emptyop(){
	sp = 0;
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