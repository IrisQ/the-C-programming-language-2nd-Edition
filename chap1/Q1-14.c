/********************************************
Print the frenquency of each character of 
input in column
Note: repeat, if input 2 q, will show 2 column 
of q :(
********************************************/
#include <stdio.h>

#define MAXNUM 100
#define EXIST 1

void printcolumn(char name,int count);

int main(int argc, char const *argv[])
{
	char c;			
	char name[MAXNUM];	/* each character */
	int count[MAXNUM];	/* corresponding frequency of char */
	int idx = 0;		/* next empty position for new char */
	int flag = 0;		/* 1:this char already exists in name[] */

	while ((c = getchar()) != EOF){
		if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
			for(int i = 0;i < idx;i++){
				if(c == name[i]){
					count[i]++;
					flag = EXIST;
					printcolumn(c,count[i]);
				}
			}
			if(!flag){
				name[idx] = c;
				count[idx] = 1;
				printcolumn(c,count[idx++]);
			}		
		flag = 0;
		}
	}
	return 0;
}

void printcolumn(char name,int count){
	printf("%c: ",name);
	while(count--){
		printf("%c", '-');
	}
	printf("\n");
}