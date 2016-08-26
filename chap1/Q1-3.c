/********************************************
Print table of fahr from 0-300 (step is 20)
and corresponding celsius temperature.
********************************************/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0; 		/* lower bound */
	upper = 300;	/* upper bound */
	step = 20; 		

	fahr = lower;
	printf("%s\n", "fahr VS celsius:");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}

	
