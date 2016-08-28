/********************************************
       only test once in while loop
********************************************/
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, char const *argv[])
{
	int num[] = {1,3,5,7,9,11};
	printf("%d\n",binsearch(7,num,5));
	printf("%d\n",binsearch(2,num,5));
	printf("%d\n",binsearch(9,num,5));
	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n1]
*/
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (high - low > 1) {
		mid = (low + high)/2;
		if (x <= v[mid])
			high = mid;
		else 
			low = mid + 1;
	}
	if(x == v[high])
		return high;
	else if (x == v[low])
		return low;
	else
		return -1;	/* no match */
}
