/*--------------------------------------------------------------------------*/
/*																			*/
/* HW01_121044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part2.c 																	*/
/* ---------																*/
/* Created on 19/02/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/*	  Gets current date and birthdate by the user.							*/
/*	  Calculates how many days you have live on the world.					*/
/*	  Gets the other planet's data -hours, days, months-.					*/
/*	  Calculates how many days, months and years did you live on the planet.*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define DAYS_OF_MONTH 30
#define DAYS_OF_YEAR 365
#define MONTHS_OF_YEAR 12
#define HOURS_OF_DAY 24
#define DEPLOY 1
#define ADDITION_DAYS 5


int main()
{
	int currentYear, currentMonth, currentDay;
	int birthYear, birthMonth, birthDay;
	int totalDays=0; /*says how many days did you live on world*/
	int planetHours, planetDays, planetMonths; 
	int totalWorldHours; /*says how many hours did you live on world*/

	/*totalDaysOnPlanet, totalMonthsOnPlanet and totalYearsOnPlanet 
	  say how many days, months and years did you live on the  planet.*/
	int totalDaysOnPlanet, totalMonthsOnPlanet, totalYearsOnPlanet;
	
	/*totalHoursInAMonthPlanet says how many hours in a month. 
	 *totalHoursInAYearPlanet says how many hours in a year.*/
	int totalHoursInAMonthPlanet, totalHoursInAYearPlanet;
	/*various calculations*/
	int remainHours, lastRemainHours;

	/*Get current date*/
	printf("Please enter the current date. \nYear: ");
	scanf("%d", &currentYear);
	printf("Month: ");
	scanf("%d", &currentMonth);
	printf("Day:");
	scanf("%d", &currentDay);

	/*Get birthdate*/
	printf("Please enter your birthdate.\nYear: ");
	scanf("%d", &birthYear);
	printf("Month:");
	scanf("%d", &birthMonth);
	printf("Day: ");
	scanf("%d", &birthDay);


	/*Subtract birthyear and 1 year than current year and multiply 365.*/
	totalDays  = (((currentYear-DEPLOY)-birthYear)*DAYS_OF_YEAR);
	/*Turn a year to 12 months.Sum current month and 12 months.	
	 *Subtract birth month and 1 month than summation and multiply 30.
	 *Add to totalDays.	*/
	totalDays += (MONTHS_OF_YEAR+currentMonth-birthMonth-DEPLOY)*DAYS_OF_MONTH;
	/*Turn a month to 30 days.Sum current day and 30 days.	
	 *Subtract birth day than summation.
	 *Add to totalDays.	*/
	totalDays += (DAYS_OF_MONTH+currentDay-birthDay);
	/*Add 5 days left over from the deployed year to totalDays.*/
	totalDays += ADDITION_DAYS;

	/*Display how many days did you live on world */
	printf("You have lived %d days.\n",totalDays );

	/*Get other planet's information.*/
	printf("Please enter about the time of another planet:");
	printf("\nHow many hours is a day? ");
	scanf("%d", &planetHours);
	printf("How many days is a month? ");
	scanf("%d", &planetDays);
	printf("How many months is a year? ");
	scanf("%d", &planetMonths);

	/*Multiply lived days and 24 hours*/
	totalWorldHours = (totalDays*HOURS_OF_DAY);
	/*Calculate how many hours in a year on the planet.*/
	totalHoursInAYearPlanet = (planetHours*planetDays*planetMonths);
	/*Calculate how many hours in a month on the planet.*/
	totalHoursInAMonthPlanet = (planetHours*planetDays);

	/*Divide total world hours by total hours in a year on the planet.
	 *Calculate how many years did you live on the planet. */
	totalYearsOnPlanet = (totalWorldHours/totalHoursInAYearPlanet);

	/*Multiply lived years and total hours in a year.
	 *Subtract this multiplication than total world hours .*/
	remainHours =(totalWorldHours-(totalYearsOnPlanet*totalHoursInAYearPlanet));
	/*Divide remain hours by total hours in a month on the planet.
	 *Calculate how many months did you live on the planet.*/
	totalMonthsOnPlanet = remainHours/totalHoursInAMonthPlanet;

	/*Multiply lived months and total hours in a month.
	 *Subtract this multiplication than remain hours.*/
	lastRemainHours =remainHours-(totalMonthsOnPlanet*totalHoursInAMonthPlanet);
	/*Divide last remain hours by total hours in a day on the planet.
	 *Calculate how many days did you live on the planet.*/
	totalDaysOnPlanet = lastRemainHours/planetHours;

	/*Display the data.*/
	printf("If you lived in a planet where a day is %d hours, ", planetHours);
	printf("a month is %d days ", planetDays);
	printf("and a year is %d months: ", planetMonths);
	printf("you were %d years, " ,totalYearsOnPlanet);
	printf("%d months and ", totalMonthsOnPlanet);
	printf("%d days old.\n", totalDaysOnPlanet );


	return 0;
	
}

/*---------------------------------------------------------------------------*/ 
/*								End of part2.c 								 */
/*---------------------------------------------------------------------------*/


