/**unfinished--using pointers:
 * realize getline,atoi,itoa,reverse,strindex,getop
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXCHAR 20

int getline(char *s,int max);
int atoi(char *s);
void reverse(char *s);

int main(int argc, char const *argv[]) {
	char s[MAXCHAR];	/* for testing getline */
	char s1[] = "-798";
	printf("length of s: %d\n", getline(s,MAXCHAR));
	printf("content of s: %s\n",s);	
	printf("integer: %d\n", atoi(s1));
	reverse(s);
	printf("reverse of s: %s\n",s);	
	return 0;
}

/* getline: get line into s, return length */
int getline(char *s,int max) {
	char *origins = s;
	char c;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - origins - 1;
}

/* atoi: convert s to integer */
int atoi(char *s) {
	int sign = 1;
	int num = 0;
	if (*s == '-') {
		sign = -1;
		s++;
	}
	while(isdigit(*s)) {
		num = num*10 + *s++ - '0';
	}
	return num*sign;
}

/* reverse: reverse string s in place */
void reverse(char *s) {
	char tmp;
	char *j = s + strlen(s) - 1;
	for (;s < j;s++,j--) {
		tmp = *s;
		*s = *j;
		*j = tmp;
	}
}

