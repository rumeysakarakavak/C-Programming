/*--------------------------------------------------------------------------*/
/*																			*/
/* HW04_141044063_Rumeysa_Karakavak											*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 23/03/2016 by Rumeysa_Karakavak 								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/*	 Gets degree, n value and character by user.							*/
/*	 If entered character is E or e, terminate the program					*/
/*	 Converting degrees to radians, calculates the sine*					*/
/*	 *and cosine using the Taylor series.									*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define PI 3.14
#define RADIAN 180

/*Gets required degree and n value to calculate the sine or cosine*/
void getInputs(int* degree, int* n, int* exit);

/*Depending on the degree entered*
 *calculates the sine value using the Taylor series.*/
double sine(int degree, int n);

/*Depending on the degree entered*
 *calculates the cosine value using the Taylor series.*/
double cosine(int degree, int n);




int main()
{
	int degree, n;
	int exit;

	getInputs(&degree, &n, &exit);

	return 0;

}

/*gets required degree and n value to calculate the sine or cosine*/
/*if entered character is E or e, terminate the program*/
void getInputs(int* degree, int* n, int* exit)
{
	char exitInput;
	*degree=0, *n=0, *exit=0;

	/*get degree, n and character*/
	scanf("%d", degree);
	scanf(" %d", n);
	scanf(" %c", &exitInput);

	/*if entered character is E or e, terminate the program*/
	if (exitInput=='E'||exitInput=='e')
	{
		*exit = 1; 
		return;
	}
	else
	{
		*exit = 0;
	}

}


/*Depending on the degree entered*
 *calculates the sine value using the Taylor series.*/
double sine(int degree, int n)
{
	int i=0, negative=-1 ,x=1;
	double final=0, totalFinal=0,degreeOfX=1;

	/*if entered degree more than 360, get mode*/
	degree= degree%360;

	for (i = 1; i < (2*n)+1; i+=1)
	{
		/*factorial of i*/
		x*=i;
		/*power of angle*/	
		degreeOfX*= (degree*PI/RADIAN);/*conversion from degrees to radians*/

		/*if i is odd, calculate sine using taylor series*/
		if (i%2==1)
		{
			/*power of (-1)*/
			negative*=(-1);
			/*changing value depending on the odd value*/
			final= negative*(degreeOfX/x);
			/*the sum of the resulting values*/
			totalFinal+=final;
		}
		
	}
	printf("sin(%d) where n is %d = %.4f\n", degree, n, totalFinal);

	return totalFinal;

}


/*Depending on the degree entered*
 *calculates the cosine value using the Taylor series.*/
double cosine(int degree, int n)
{

	int i=0, negative=-1 ,x=1;
	double final=0, totalFinal=0,degreeOfX=1;

	/*if entered degree more than 360, get mode*/
	degree= degree%360;

	for (i = 1; i < (2*n); i+=1)
	{
		/*factorial of i*/
		x*=i;
		/*power of angle*/	
		degreeOfX*= (degree*PI/RADIAN);/*conversion from degrees to radians*/

		/*if i is even, calculate cosine using taylor series*/
		if (i%2==0)
		{
			/*power of (-1)*/
			negative*=(-1);
			/*changing value depending on the even value*/
			final= negative*(degreeOfX/x);
			/*the sum of the resulting values*/
			totalFinal+=final;
		}
		
	}

	/*the process required by the formula*/
	totalFinal=1-totalFinal;

	printf("cos(%d) where n is %d = %.4f\n", degree, n,totalFinal);

	return totalFinal;
}

/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/


