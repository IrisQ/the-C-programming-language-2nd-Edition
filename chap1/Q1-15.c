/********************************************
Use function:
Print table of celsius from 0-150 (step is 20)
and corresponding fahr temperature.
********************************************/
#include <stdio.h>

double celsius2fahr(double celsius);

int main(int argc, char const *argv[])
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0; 		/* lower bound */
	upper = 150;	/* upper bound */
	step = 10; 

	celsius = lower;
	printf("%s\n", "Celsius vs Fahr:");
	while (celsius <= upper) {
		fahr = celsius2fahr(celsius);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}

double celsius2fahr(double celsius){
	 return (9.0/5.0) * celsius + 32.0;
}