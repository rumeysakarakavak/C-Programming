/*--------------------------------------------------------------------------*/
/*																			*/
/* HW07_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 15/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* whether the given string is a palindrome or not							*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
int isPalindrome(char *str);
int recursiveFunction(char *str, char *rstr);
void reverseArray(char * str, char *rstr);



int isPalindrome(char *str)
{
	char myString[30];
	char reverseString[30];
	int i=0;
	int j=0;
	int result=0;
	*myString=0;
	*reverseString=0;

	while(str[i]!='\0')
	{
		if ((str[i]<=90 && str[i]>=65)||(str[i]>=97 && str[i]<=122))
		{

			myString[j]=str[i];
			j+=1;

		}
		i+=1;
	}

	i=0;
	while(myString[i]!='\0')
	{
		if ((myString[i]<=90 && myString[i]>=65))
		{

			myString[i]=(int)myString[i]+32;

		}
		i+=1;
	}

	i=0;
	while(str[i]!='\0')
	{
		
			reverseString[j-i-1]=myString[i];

		i+=1;
	}
	

	
	if (i<=1)
	{
		result =0;
		
		}
		if (reverseString[0]!=myString[0])
		{
			result=0;
		}
		else
		{	
			isPalindrome(&str[1]);
			result=1;
		}
	
	

	
	return  result;

}
/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/

