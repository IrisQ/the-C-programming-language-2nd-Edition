/********************************************
htois: transfor the input s into int which 
has equal value. s could contain:0-9,a-f,A-F
********************************************/
#include <stdio.h>

int htoi(char s[]);

int main(int argc, char const *argv[])
{
	char s1[] = "0x1B",s2[] = "0X0a",s3[] = "8F";
	printf("before change:%s,%s,%s\n", s1,s2,s3);
	printf("after change :%d,%d,%d\n", htoi(s1),htoi(s2),htoi(s3));

	return 0;
}

int htoi(char s[]){
	int out = 0;
	int idx = 0;	
	/* if includes 0x or 0X: */
	if(s[1] == 'x' || s[1] == 'X'){
		idx = 2;
	}
	for(;s[idx] != '\0' ;idx++){
		if (s[idx] >= '0' && s[idx] <= '9')
			out = out * 16 + s[idx] - '0';
		if (s[idx] >= 'a' && s[idx] <= 'f')
			out = out * 16 + s[idx] - 'a' + 10;
		if (s[idx] >= 'A' && s[idx] <= 'F')
			out = out * 16 + s[idx] - 'A' + 10;
	}
	return out;
}