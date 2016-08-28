/********************************************
Use switch to realize the functions.
********************************************/
#include <stdio.h>

void escape(char s[],char t[]);
void escape2work(char s[],char t[]);

int main(int argc, char const *argv[])
{
	char s1[] = "sweet";
	char s2[] = "	rock";
	char s3[] = "rock\n!";
	escape(s1,s2);
	escape2work(s1,s3);
	return 0;
}

/* copy string t into s and transfer \t,\n into 
visible characters */
void escape(char s[],char t[]){
	int i = 0;
	while(s[i++] != '\0')
		;
	i--;

	for(int j = 0;t[j] != '\0';j++){
		switch(t[j]){
			case '\n':
				s[i++] = '\\'; s[i++] = 'n';break;
			case '\t': 
				s[i++] = '\\'; s[i++] = 't';break;
			default:  
				s[i++] = t[j]; break;
		}
	}
	s[i] = '\0';

	/* for test: */
	printf("work to visible:\n");
	printf("%s\n",s);
}

/*opposite function with escape, transform visible 
'\t' or '\n' into work.*/
void escape2work(char s[],char t[]){
	int i = 0;
	int flag = 0;	/* if flag == 1 then prior character is \ */

	while(s[i++] != '\0')
		;
	i--;

	for(int j = 0;t[j] != '\0';j++){
		switch(t[j]){
			case '\\':
				flag = 1; s[i++] = '\\'; break;
			case 't': 
				if(flag == 1){
					i--;
					s[i++] = '\t';
					flag = 0;
				}else{
					s[i++] = t[j];
				}
				break;
			case 'n':
				if(flag == 1){
					i--;
					s[i++] = '\n';
					flag = 0;
				}else{
					s[i++] = t[j];
				}
				break;
			default:  
				s[i++] = t[j]; break;
		}
	}
	s[i] = '\0';

	/* for test: */
	printf("visiable to work:\n");
	printf("%s\n", s);
}