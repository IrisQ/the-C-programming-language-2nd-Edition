/********************************************
reverse() using recursion.
reverse: reverse string s in place
********************************************/
#include <stdio.h>
#include <string.h>

void reverse(char s[],int flag);

int main(int argc, char const *argv[])
{
	char s[] = {'s','w','e','e','t','r','o','c','k'};
	reverse(s,0);
	reverse(s1,0);
	return 0;
}

void reverse(char s[],int flag) {
	static int ptr = 0;	/* the position to switch */
	static int len = strlen(s);
	char tmp;

	if (!flag) {
		ptr = 0;
		len = strlen(s);
	} 
	/*  */
	if (flag == (len / 2 - 1) && (len % 2 == 0)) {
		tmp = s[flag];			/* even length, last pair to switch */
		s[flag] = s[flag + 1];
		s[flag + 1] = tmp;
		printf("even: %s\n", s);
	} else if ((flag == len / 2) && (len % 2 == 1)) {
		printf("odd: %s\n", s);	/* odd length, already get to middle item */
	} else {			/* switch items,eg: s[0] and s[7],s[1] and s[6] */
		tmp = s[ptr];
		s[ptr] = s[len - ptr - 1];
		s[len - ptr - 1] = tmp;
		reverse(s,++ptr);
	}
}