/*--------------------------------------------------------------------------*/
/*																			*/
/* HW06_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part2.c 																	*/
/* ---------																*/
/* Created on 09/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* Finds substring in a given string                    					*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

char *matcher(char *haystack, char *needle);



char *matcher(char *haystack, char *needle)
{

	int i=0;
	int j=0;
	int m=0;
	int a=0;
	int k[10];
	int lengthOfNeedle=0;
    int lengthOfHaystack=0;
	char oddIndex[10];
	
	

	lengthOfHaystack=strlen(haystack);
	lengthOfNeedle=strlen(needle);
	
	if (lengthOfHaystack<lengthOfNeedle)
	{
		return NULL;
	}

	j=0;
	for (i = 0; i < lengthOfNeedle; ++i)
	{
		if (i%2==0)
		{	
		oddIndex[j]= needle[i];
			j+=1;
		}
		
	}

    for (m = 0; m < j; ++m)
    {

	    for (i = 0; i <lengthOfHaystack; ++i)
	    {
		    if (haystack[i]==oddIndex[m])
		    {
		    	k[m]=i;
		    	i=lengthOfHaystack-1;
		    }

    	}
	
    }
   
	a=k[0];
	return &haystack[a];
}

/*---------------------------------------------------------------------------*/ 
/*								End of part2.c 								 */
/*---------------------------------------------------------------------------*/