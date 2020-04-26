#include <stdio.h>

/* Print Fahrenheit- Celsius table
	for fahr = 0, 20 ... m 300 */

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; 	/* Lower limit of temperature table */
	upper = 300; 	/* Upper limit */
	step = 20; 	/* step size*/
	printf("Fahr\tCelsius\n");
	printf("----\t-------\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f\t%6.3f\n",fahr,celsius);
		fahr += step; 
	}
}
