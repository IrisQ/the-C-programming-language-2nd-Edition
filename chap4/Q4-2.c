/* expand atof() make it able to deal with e */
#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main(){
	char s[] = "31.4159e+5";
	double out = atof(s);
	printf("%8.4f\n", out);
}


/* atof: convert string s to double */
double atof(char s[])
{
	double val, power,power2;
	int i, sign,sign2;
	double base;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	base = sign * val / power;
	printf("%6.4f\n", base);

	if(s[i] == 'e' || s[i] == 'E')
		i++;

	sign2 = (s[i] == '+') ? 1:-1;
	i++;

	for (power2 = 0.0; isdigit(s[i]); i++)
		power2 = 10.0 * power2 + (s[i] - '0');
	power2 = pow(10,power2);
	printf("%6.4f\n", power2);
	return base * power2;
}
