/*--------------------------------------------------------------------------*/
/*																			*/
/* HW06_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 09/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* Calculates the character frequency of a given string.					*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>

void freq(char *str, int *fr);



void freq(char *str, int *fr)
{

	int i= 0;
	int j=0;
	int k=0;
	int count=0;
	/*array of uppercase*/
	char uppercase[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	/*array of lowercase*/
	char lowercase[27]="abcdefghijklmnopqrstuvwxyz";
	/*array of numbers*/
	char numbers[10]="0123456789";
	*fr=0;

    /*fill array with 0*/
	for (i = 0; i < 27; ++i)
	{
		fr[i]=0;
	}


	
	i=0;
	while(str[i]!='\0')
	{

		count+=1;
		i+=1;
	}

		/*search for characters*/
		for (k = 0; k <=count; ++k)
		{
			
			for (j = 0; j < 27; ++j)
			{
			
				if (str[k]==uppercase[j])
				{
					
					fr[j]+=1;
				}
				if (str[k]==lowercase[j])
				{
					
					fr[j]+=1;
				}		
			}
		}

     /*fill array with 0*/
      for (i = 26; i < 36; ++i)
    	{
		    fr[i]=0;
	    }

		/*search for numbers*/
		for (k = 0; k <=count; ++k)
		{
			
			for (j = 0; j < 10; ++j)
		    {
			
				if (str[k]==numbers[j])
				{
					
					fr[j+26]+=1;
		    	}			
		    }
		}

    /*search for the others*/
    fr[36]=0;

    	for (k = 0; k <count; ++k)
    	{
				
			/*if uppercase*/
	    	if ((str[k]<=90&&str[k]>=65))
			{
					
				fr[36]+=0;
			}	
            /*if lowercase*/
			else if ((str[k]>=97 && str[k]<=122))
			{
				fr[36]+=0;
			}	
            /*if number*/
			else if ((str[k]>=48 && str[k]<=57))
			{
				fr[36]+=0;
			}
            /*if others*/
			else
			{
			    fr[36]+=1;
			    
			}	

		}


}
/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/