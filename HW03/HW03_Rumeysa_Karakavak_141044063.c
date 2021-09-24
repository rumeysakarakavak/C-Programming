/*--------------------------------------------------------------------------*/
/*																			*/
/* HW03_141044063_Rumeysa_Karakavak											*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 04/03/2016 by Rumeysa_Karakavak 								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/*	 Gets an integer by user.												*/
/*	 Checks the integer whether is negative or not.							*/
/*	 Lists operations and asks which operation user want to use.			*/
/*	 Calculates the results according to user's choice.						*/
/*																			*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#define FALSE -1
#define MOD 10

char YesOrNo();/*asks whether user wants to continue or not*/
int checkNegative(int number);/*checks is input negative*/
int listOtherCondition();/*lists other options*/
void odd(int number);/*checks the number whether is odd or not */
void factorial(int number);/*checks the number whether is factorial or not */
void narcissistic(int number);/*checks the number whether is 
									narcissistic or not */


int main()
{

	int integer; /*user's input*/
	int chooseFunction; /*return value of the listOtherCondition function*/
	int isNegative; /*return value of the checkNegative function*/                            


	printf("*********************************************************\n");
	printf("*                     WELCOME!                          *\n");
	printf("*   This program checks whether the given number        *\n");
	printf("*  is an odd, a factorial or a narcissistic number      *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n\n");


	
	printf("Please enter a positive integer: ");
	scanf("%d", &integer); /*get input by user*/
	
	/*check is input negative*/
	isNegative = checkNegative(integer);
	/*if input not equal negative value, show other options*/
	if(isNegative==FALSE)
	{
		chooseFunction= listOtherCondition();

		/*call the other functions according to users choice*/
		switch(chooseFunction)
		{
			case 1: odd(integer);
			break;

			case 2: factorial(integer);
			break;

			case 3: narcissistic(integer);
			break;
		}
	}
	
	/*if user wants to continue, repeat all of the operations*/
	/*if user does not to continue, terminate the program */
	while(YesOrNo()=='y')
	{
		scanf("%d", &integer);
		
		if (integer<0)
		{
			checkNegative(integer);
		}
		else
		{
			chooseFunction= listOtherCondition();
			switch(chooseFunction)
			{
				case 1: odd(integer);
				break;
	
				case 2: factorial(integer);
				break;
	
				case 3: narcissistic(integer);
				break;
			}
		}

	}
	


	
}

/*asks whether user wants to continue or not*/
/*get character y if user wants to continue
 *or get n for terminate the program*/
char YesOrNo()
{

	char continueChar;/*return character(y/n) for this function*/

	printf("Do you want to continue (y/n)? ");
	scanf(" %c", &continueChar);

	switch(continueChar)
	{

		case 'y':
		printf("\nPlease enter a positive integer: ");
		break;

		case 'n':
		printf("Good bye !\n");
		break;

	}

	return continueChar;

}	

/*checks is input negative*/
int checkNegative(int number)
{


	if (number<0)
	{
		printf("The entered number is not positive.\n");
	}

	else
	{
		return FALSE;/*if input is not negative, return false*/
	}
	

}



/*lists other options and gets integer from 1 to 3 for the choise*/
int listOtherCondition()
{

	int integer;/*value from 1 to 3*/

	printf("Which property would you like to check?\n");
	printf("1)Odd number\n");
	printf("2)Factorial number\n");
	printf("3)Narcissistic number\n");
	printf("Please enter(1/2/3): ");

	scanf(" %d", &integer);

	return integer;
}




/*checks the number whether is odd or not */
void odd(int number)

{

	if (number%2==0)/*if number is 2 times, number is even */
	{
		printf("%d is not an odd number !\n", number);
	}
	else
	{
		printf("%d is an odd number !\n", number);
	}
}



/*checks the number whether is factorial or not */
void factorial(int number)
{
	int i, x=1;

		for (i = 1; x< number; ++i)
		{
			x*=i;
		}
		if (x==number)
		{
			printf("%d is a factorial number !\n", number);
		}
		else
		{
			printf("%d is not a factorial number !\n", number);
		}
}




/*checks the number whether is narcissistic or not */
void narcissistic(number)
{
	int i, j;
	int narcissistic=0; /*value of the sum of the power of the digits*/ 
	int digit /*separated to digits of number */;
	int count=0; /*value of the power*/

		/*calculate value of power*/
		for (i = 1; i < number; i*=10)
		{	
			count++;
		}

		/*separate number*/
		for (j = 1; j < number; j*=10)
		{	
			digit = number/ j %MOD;
			narcissistic += pow(digit,count);
		}
		
		/*if sum of the power of the digits equal the user's input
		 *the number is narcissistic*/
		if (narcissistic == number)
		{
			printf("%d is narcissistic number !\n", number);
		}
		else
		{
			printf("%d is not narcissistic number !\n", number );
		}


}

/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/


