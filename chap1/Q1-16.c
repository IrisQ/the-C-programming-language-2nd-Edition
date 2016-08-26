/********************************************
        Print input of random length
********************************************/
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);

main()
{
	int len; 			/* current line length */
	char line[MAXLINE]; /* current input line */

	while ((len = getline(line, MAXLINE)) > 0){
		printf("%s", line);
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



