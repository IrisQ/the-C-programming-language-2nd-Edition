/********************************************
return the first position of any character in 
s2 which also exists in s1.
********************************************/
#include <stdio.h>
#include <string.h>

int any(char s1[],char s2[]);

int main(int argc, char const *argv[])
{
	char s1[] = "some birds are not meant to be caged.";
	char s2[] = "for example";
	printf("first position is: %d\n",any(s1,s2));
	return 0;
}

int any(char s1[],char s2[]){
	int i,j;	

	for(i = 0;s2[i] != '\0';i++){
		for(j = 0;s1[j] != '\0';j++){
			if(s2[i] == s1[j])
				return j;
		}
	}
	return -1;
}