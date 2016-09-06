#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

static int sp = 0;			/* next free stack position */
static double val[MAXVAL];	/* value stack */

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