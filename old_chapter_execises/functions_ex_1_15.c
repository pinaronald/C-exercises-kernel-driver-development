#include <stdio.h>

int conv_fahrt(int n);

/* print Fahrenheit to Celsius table*/

main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = 0;
	
	while (fahr <= upper){
		printf("%d\t%d\n", fahr, conv_fahrt(fahr));
		fahr += step;
	}
	return 0;	
}

int conv_fahrt(int f)
{
	int cel;
	cel = 5 * (f-32) / 9;
	return cel;
	
}
