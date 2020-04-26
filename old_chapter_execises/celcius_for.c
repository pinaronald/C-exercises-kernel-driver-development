#include <stdio.h>

#define LOWER 0 	/* lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP 20		/* step size */

/* Print Fahrenheit- Celsius table
	for fahr = 0, 20 ... m 300 */

main()
{
	int fahr;

	printf("\nFahr\tCelsius\n");
	printf("----\t-------\n");

for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)  
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));	
}
