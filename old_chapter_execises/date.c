/*
 * =====================================================================================
 *
 *       Filename:  date.c
 *
 *    Description:  Struct to store time and date, write a function to 
 *    find the difference between two times in minutes:
 *
 *        Version:  1.0
 *        Created:  04/19/2020 05:17:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */


#include <stdio.h>

struct time {
	int hour;
	int minute;
	int year;
	int month;
	int day;
};

int time_diff(struct time time1, struct time time2);

int main()
{

	int diff;

struct time	dates[1] = {
		{8, 22, 2020, 4, 19},
		{9, 22, 2020, 4, 19}                                                      
	};	
	
	diff = time_diff(dates[0], dates[1] );
	printf("The difference is %d\n", diff);
	return (0);
}

int time_diff(struct time time1, struct time time2)

{
	int min1;
	int min2;

	min1 = time1.minute + time1.hour*60;
    min2 = time2.minute + time2.hour*60;                                        
 
	if( min2 >= min1 )
		return (min2 - min1);
	else
	    return (min1 - min2);                                                   

}



