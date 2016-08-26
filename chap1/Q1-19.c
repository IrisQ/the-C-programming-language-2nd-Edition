/********************************************
reverse(s): reverse the order of characters
of string s
********************************************/
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void reverse(char s[]);

char r[MAXLINE];		/* store the reversed string */

main()
{
	int len; 			/* current line length */
	char line[MAXLINE]; /* current input line */	

	while ((len = getline(line, MAXLINE)) > 0){
		reverse(line);
		printf("%s\n", r);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar())!=EOF && c !='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* reverse the order of characters in string s */
void reverse(char s[]){
	int len = strlen(s);
	for (int i = 0;i < (len - 1);i++)
		r[i] = s[len - i - 2];
}
