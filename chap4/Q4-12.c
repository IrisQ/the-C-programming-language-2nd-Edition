/********************************************
itoa() method using recursion.
itoa: convert integer n into characters in s
********************************************/
#include <stdio.h>
#define MAXLEN 20	

char s[MAXLEN];

void itoa (int num,int flag);

/* transfer integer to string */
int main(int argc, char const *argv[])
{
	itoa(-123,1);
	itoa(123,1);
	return 0;
}


/* flag == 1: this is a new itoa method
   flag == 0: in reversion of an existed itoa method*/
void itoa (int num,int flag) {
	static int i;
	static int bits;	/* the position of '\0' */
	if (flag) {
		i = 0;
		bits = 0;
	}

	if (num < 0) {		
		s[i++] = '-';
		num = -num;
		bits++;
	} 

	if (num / 10) {			/* eg:-123 => 123 => 12 => 1 */
		itoa(num / 10,0);	/* store 3 <= 2 <= 1 */
	} 

	if (i >= MAXLEN - 1) {
		printf("cannot store\n");
	} else {
		s[i++] = (num % 10) + '0';
		s[++bits] = '\0'; 
	}
	/* for test: */
	printf("%d, %s\n", num,s);
}

