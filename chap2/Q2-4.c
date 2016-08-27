/********************************************
delete the characters of s1 which also exist 
in s2.
********************************************/
#include <stdio.h>
#include <string.h>

void squeeze(char s1[],char s2[]);

int main(int argc, char const *argv[])
{
	char s1[] = "abcdefgc";
	char s2[] = "befg";
	printf("origin s1:%s\n", s1);
	printf("origin s2:%s\n", s2);
	squeeze(s1,s2);
	return 0;
}

void squeeze(char s1[],char s2[]){
	int i = 0;
	int newidx = 0;
	int flag = 0;

	for(;s1[i] != '\0';i++){
		for(int j = 0;s2[j] != '\0';j++){
			if(s1[i] == s2[j]){
				flag = 1;
			}
		}
		if(!flag){
			s1[newidx++] = s1[i];
		}
		flag = 0;		
	}
	s1[newidx] = '\0';

	/* for test: */
	printf("After squeeze,s1:%s\n", s1);
}