/*--------------------------------------------------------------------------*/
/*																			*/
/* HW06_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part3.c 																	*/
/* ---------																*/
/* Created on 09/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* Counts the occurrences of a substring in a given string.					*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
int count(char *str, char *substr);


int count(char *str, char *substr)
{
	int i=0;
    int a=0;
	int lengthOfstr=strlen(str);
	int lengthOfSubstr=strlen(substr);

	if (lengthOfstr<lengthOfSubstr)
	{
		return 0;
	}


	for (i = 0; i < lengthOfstr; ++i)
	{
		if (str[i]==substr[1])
		{
			a+=1;
		}
	}
	printf("%d\n",a );

return a;
	

}

/*---------------------------------------------------------------------------*/ 
/*								End of part3.c 								 */
/*---------------------------------------------------------------------------*/
