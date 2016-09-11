/**
 * strend: if string t appears at the end of s, return 1;
 * otherwise return 0.
 */

#include <stdio.h>

int strend(char *s,char *t);

int main(int argc, char const *argv[]) {
	char s1[] = "SweetRock";
	char s2[] = "SweetRockkkk";
	char s3[] = "SweetRockkkkRock";
	char t[] = "Rock";
	printf("%d\n", strend(s1,t));	/* should be 1 */
	printf("%d\n", strend(s2,t));	/* should be 0 */
	printf("%d\n", strend(s3,t));	/* should be 1 */
	return 0;
}

int strend(char *s,char *t) {
	int sign = 0;
	/* if there are several chances that t could be match of s
	   count the number of times t has been added. */
	int count = 0;			
	while(*s++ != '\0') {
		if (*s == *t) {
			while((*++s == *++t) && (*s != '\0')) {
				count++;
			}
			if ((*s == *t) && (*s == '\0')) {
				return 1;
			} else {
				t -= count;
				count = 0;
			}
		}
	}
	return 0;
}