/********************************************
Use pointer for strcat
********************************************/
#include <stdio.h>

void strcat(char *s,char *t);

int main(int argc, char const *argv[]) {
	char s1[] = "Sweet";
	char s2[] = "Rock";
	strcat(s1,s2);
	printf("%s\n",s1);
	return 0;
}

/* copy the string t pointed to the tail of the string s pointed */
void strcat(char *s,char *t) {
	while(*s++ != '\0')
		;
	s--;
	while(*s++ = *t++)
		;
}
