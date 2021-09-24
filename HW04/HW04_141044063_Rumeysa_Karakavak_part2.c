/*--------------------------------------------------------------------------*/
/*																			*/
/* HW04_141044063_Rumeysa_Karakavak											*/
/*																			*/
/* part2.c 																	*/
/* ---------																*/
/* Created on 22/03/2016 by Rumeysa_Karakavak 								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/*	 Gets number, border width and character by user.						*/
/*	 Checks whether the number is negative and is more than 99999.			*/
/*	 Prints the number in the desired format.								*/			
/*																			*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define AREAOFNUMBER 7

/*Gets number, border width and character by user.*/
void getInputs(int* num, int* borderWidth, char* chr);

/*Prints the number in the desired format*/
int printNumber(int num, int borderWidth, char chr);

/*separates the entered number of digits*
 *counts the number of digits*
 *returns the value that is required to reverse the entered number*/
int seperateNumber(int num);

/*functions that are used to print the number*/
void middleCharacter(char chr);
void leftCharacter(char chr);
void rightCharacter(char chr);
void characterSpaceCharacter(char chr);
void twoCharacterLeft(char chr);
void twoCharacterRight(char chr);
void threeCharacter(char chr);

/*functions that are used to print the border*/
void leftAndRightBorder(char chr, int borderWidth);
void upAndDownBorder(char chr, int num, int borderWidth, int* count);
void spaceLine(int borderWidth, int count, char chr );


int main()
{
	int num, borderWidth;
	char chr;

	getInputs(&num, &borderWidth, &chr);

	return 0;

}

/*gets inputs by user.*/
void getInputs(int* num, int* borderWidth, char* chr)
{

	*num=0;
	*borderWidth=0;
	*chr=0;

	/*gets number, border width and character for print*/
	scanf("%d",num);
	scanf("%d", borderWidth);
	scanf(" %c", chr);

	printNumber(*num, *borderWidth, *chr);

}

/*prints the number in the desired format.*/
int printNumber(int num, int borderWidth, char chr)
{
	int i,digit,count=0;

	/*checks whether the number is negative and is more than 99999*/
	if (num>99999 || num<0)
	{
		return 0;
	}
	
	/*prints up border*/
	upAndDownBorder(chr, num, borderWidth, &count);
	/*prints space line*/
	spaceLine(borderWidth, count, chr );
	printf("\n");
	/*prints left border*/
	leftAndRightBorder(chr,borderWidth);

	/*prints the first line of the entered numbers*/
	for (i = seperateNumber(num); i <= num&& i>=1; i/=10)
		{	

			digit = num/ i %10;

			switch(digit)
			{
				case 1:
					middleCharacter(chr);
				break;

				case 2:
				case 3:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 0:
					threeCharacter(chr);
				break;

				case 4:
					characterSpaceCharacter(chr);
				break;

			}
		}
		/*prints right border*/
		leftAndRightBorder(chr,borderWidth);

		printf("\n");
		
		/*prints left border*/	
		leftAndRightBorder(chr,borderWidth);

		/*prints the second line of the entered numbers*/
	for (i = seperateNumber(num); i <= num&& i>=1; i/=10)
		{	
			digit = num/ i %10;

			switch(digit)
			{
				case 1:
					twoCharacterLeft(chr);
				break;

				case 2:
				case 3:
				case 7:
					rightCharacter(chr);
				break;

				case 5:
				case 6:
					leftCharacter(chr);
				break;

				case 4:	
				case 8:
				case 9:
				case 0:
					characterSpaceCharacter(chr);
				break;

			}
		}
		/*prints right border*/
		leftAndRightBorder(chr,borderWidth);

		printf("\n");
		
		/*prints left border*/	
		leftAndRightBorder(chr,borderWidth);

	/*prints the third line of the entered numbers*/
	for (i = seperateNumber(num); i <= num&& i>=1; i/=10)
		{	
			digit = num/ i %10;

			switch(digit)
			{
				case 1:
					middleCharacter(chr);
				break;

				case 2:
				case 4:
				case 5:
				case 6:
				case 8:
				case 9:
					threeCharacter(chr);
				break;

				case 3:
					twoCharacterRight(chr);
				break;

				case 7:	
					rightCharacter(chr);
				break;

				case 0:
					characterSpaceCharacter(chr);
				break;

			}
		}
		/*prints right border*/
		leftAndRightBorder(chr,borderWidth);

		printf("\n");
		
		/*prints left border*/	
		leftAndRightBorder(chr,borderWidth);

		/*prints the fourth line of the entered numbers*/
	for (i = seperateNumber(num); i <= num&& i>=1; i/=10)
		{	
			digit = num/ i %10;
			switch(digit)
			{
				case 1:
					middleCharacter(chr);
				break;
				case 2:
					leftCharacter(chr);
				break;
					case 3:
				case 4:	
				case 5:
				case 9:
				case 7:
					rightCharacter(chr);
					break;
				case 6:
				case 8:
				case 0:
					characterSpaceCharacter(chr);
				break;
			}
		}

		/*prints right border*/
		leftAndRightBorder(chr,borderWidth);

		printf("\n");
		
		/*prints left border*/	
		leftAndRightBorder(chr,borderWidth);

		/*prints the fifth line of the entered numbers*/
		for (i = seperateNumber(num); i <= num&& i>=1; i/=10)
		{	
			digit = num/ i %10;

			switch(digit)
			{
				case 1:
				case 2:
				case 3:
				case 5:
				case 6:
				case 8:
				case 9:
				case 0:
					threeCharacter(chr);
				break;

				case 4:
				case 7:
					rightCharacter(chr);
				break;
			}
		}

	/*prints right border*/
	leftAndRightBorder(chr,borderWidth);

	printf("\n");

	/*prints space line*/
	spaceLine(borderWidth, count, chr );
	
	printf("\n");

	/*prints down border*/
	upAndDownBorder(chr, num, borderWidth, &count);


	return 1;
}
/*separates the entered number of digits*
 *counts the number of digits*
 *returns the value that is required to reverse the entered number*/
int seperateNumber(int num)
{
	int i=1, k=1, count=0, number, startValue=1;

	for (i = 1; i < num; i*=10)
		{	
			number = num/ i %10;
			number=number+0;
			count=count+1;
		}

	for (k = 1; k < count; ++k)
		{
			startValue*=10;
		}

	return startValue;
}

/*prints like ...#... */
void middleCharacter(char chr)
{
	int i;

	for (i = 0; i < 3; ++i)
	{
		printf(" ");
	}

	printf("%c", chr);

	for (i = 0; i < 3; ++i)
	{
		printf(" ");
	}

}

/*prints like ..#.... */
void leftCharacter(char chr)
{
	int i;

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

	printf("%c", chr);

	for (i = 0; i < 4; ++i)
	{
		printf(" ");
	}

}

/*prints like ....#.. */
void rightCharacter(char chr)
{
	int i;

	for (i = 0; i < 4; ++i)
	{
		printf(" ");
	}

	printf("%c", chr);

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

}
/*prints like ..#.#.. */
void characterSpaceCharacter(char chr)
{
	int i;

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

	printf("%c %c", chr, chr);

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

}

/*prints like ..##... */
void twoCharacterLeft(char chr)
{
	int i;

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

	printf("%c%c", chr, chr);

	for (i = 0; i < 3; ++i)
	{
		printf(" ");
	}
}

/*prints like ...##.. */
void twoCharacterRight(char chr)
{
	int i;

	for (i = 0; i < 3; ++i)
	{
		printf(" ");
	}

	printf("%c%c", chr, chr);

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

}

/*prints like ..###.. */
void threeCharacter(char chr)
{
	int i;

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

	printf("%c%c%c", chr, chr, chr);

	for (i = 0; i < 2; ++i)
	{
		printf(" ");
	}

}
/*prints like ### what else ### (varies depending on the border width)*/
void leftAndRightBorder(char chr, int borderWidth)
{
	int s;

	for (s = 0; s < borderWidth; ++s)
	{
		printf("%c", chr);
	}	

}

/*prints like ########### (varies depending on the border width)*
 *counts the number of digits */
void upAndDownBorder(char chr, int num, int borderWidth, int* count)
{
	int i, j, digit=0;
	*count=0;

	for (i = 1; i <= num; i*=10)
		{	
			digit =num/ i %10;
			*count=*count+1;
		}

		digit=digit+1;


	for (j = 0; j < borderWidth; ++j)
	{
		for (i = 0; i <(*count*AREAOFNUMBER)+(2*borderWidth) ; ++i)
		{
			printf("%c",chr );
		}

		printf("\n");
	}


}

/*prints like ##.......## (varies depending on the border width)*/
void spaceLine(int borderWidth, int count, char chr )
{
	int i;

	for ( i = 0; i < borderWidth; ++i)
	{
		printf("%c" , chr);
	}
	for ( i = 0; i < count*AREAOFNUMBER; ++i)
	{
		printf(" ");
	}
	for ( i = 0; i < borderWidth; ++i)
	{
		printf("%c", chr);
	}
}
/*---------------------------------------------------------------------------*/ 
/*								End of part2.c 								 */
/*---------------------------------------------------------------------------*/