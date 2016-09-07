#include <stdio.h>

#define swap(t,x,y) {t tmp = x; x = y; y = tmp;}

int main () {
 	int x = 3,y = 0;
 	swap(int,x,y);
 	printf("x:%d,y:%d\n",x,y);

 	return 0;
}

