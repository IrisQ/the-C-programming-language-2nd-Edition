/********************************************
write a loop without && and || as below:
for (i=0; i<lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;
********************************************/
#include <stdio.h>

#define MAXNUM 100	/* maximum length of s */

int main(int argc, char const *argv[])
{
	char s[MAXNUM];
	char c;
	int i;

	for (i = 0; i < MAXNUM; i++){
		if((c = getchar()) != '\n'){
			if(c != EOF){
				s[i] = c;
			}else{
				break;
			}
		}else{
			break;
		}		
	}
	s[i] = '\0';
	printf("%s", s);
	return 0;
}
