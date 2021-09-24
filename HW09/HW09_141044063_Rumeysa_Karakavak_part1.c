/*--------------------------------------------------------------------------*/
/*																			*/
/* HW09_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 29/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* C program that keeps information about world countries.					*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>


typedef struct 
{
	char countryName[25];
	int population,
		soldiersInArmy;
	double kmSquares;

	char neighbors[10][25];

}	countriesT;

/*fills the struct*/
countriesT fillStruct(void);
/*gets choice and calls the function depending on entered character*/
void chosen(countriesT country[]);
/*prints the powerful country in terms of military*/
void military(countriesT country[100]);
/*prints the largest country*/
void areaOfLand(countriesT country[100]);
/*prints the country is accessible or inaccessible*/
void visitACountry(countriesT country[100]);

int main()
{
	countriesT country[100];
	chosen(country);
	

	return 1;
}

/*fills the struct*/
countriesT fillStruct()
{
	countriesT country;
	int i=0;
	/*get country name*/
	scanf("%s", country.countryName);
	/*get population, km and number of soldiers in army*/
	scanf("%d %lf %d", &country.population, &country.kmSquares,
					   &country.soldiersInArmy);

	/*get neighbors*/
	scanf("%s", &country.neighbors[i][25]);

	/*get neighbors*/
	while(i<10 && strcmp(&country.neighbors[i][25], "-1")!=0)
	{
		i++;
		scanf("%s", &country.neighbors[i][25]);
		
	}

	return country;
}

/*gets choice and calls the function depending on entered character*/
void chosen(countriesT country[100])
{
	int i=0;
	
	char choose;

	printf("Make your choice:\n");
	/*get user's choice*/
	scanf("%c", &choose);

	while(choose!='e')
	{
		switch(choose)
		{	
			/*if input is a, fill the struct*/
			case 'a':
			country[i] =fillStruct();
			i++;

			printf("Make your choice:\n");

			break;


			/*if input is b, print the powerful country in terms of military*/
			case 'b':
			military(country);
			printf("Make your choice:\n");
			
			break;

			/*if input is c, print the largest country*/
			case 'c':
			areaOfLand(country);
			printf("Make your choice:\n");

			break;

			/*if input is d, print the country is accessible or inaccessible*/
			case 'd':
			visitACountry(country);
			printf("Make your choice:\n");
			break;
		}
		/*get choice*/
		scanf("%c", &choose);
	}


	if (choose=='e')
	{
		printf("Good Bye\n");
	}	
}


/*prints the powerful country in terms of military*/
void military(countriesT country[100])
{
	int i=0,j=0, k=0, l=0, m=0, h=0;
	int count=0, count1=0, count2 =0;
	countriesT temp;
	char array[10][25];
	char array1[90][25];
	countriesT neighbourhood[100];

	count=0;

			scanf("%s", temp.countryName);
			
			
			/*find the given string's index*/
			for (k = 0; k < 100; ++k)
			{
				if (strcmp((temp.countryName), (country[k].countryName))==0)
				{
					count=k;
					k=99;
				}
			}

			/*finds the neighbors and copies this neighbor to another array*/
			i=0;
			while(strcmp(&country[count].neighbors[i][25], "-1")!=0 && i<10)
			{
				
				strcpy(&array[i][25],&country[count].neighbors[i][25]);
				i++;
			}

			count1=0;
			l=0;
			for (k = 0; k < i; ++k)
			{
				for ( j = 0; j < 100; ++j)
				{	/*check the country's neighbours, 
						is defined in other countries*/
					if (strcmp((&array[k][25]),(country[j].countryName))==0)
					{
						neighbourhood[m]=country[j];

						/*copy the neighbor's of neighbors to another array*/
						h=0;
						while(strcmp(&neighbourhood[m].neighbors[h][25],"-1")!=0 
								&& l<100)
						{
			
							strcpy(&array1[l][25],
								&neighbourhood[m].neighbors[h][25]);
							
							l++;
							h++;

						}
					
						
						m++;
						count1++;

						j=100;
					}

				}
				
			}


			for (k = 0; k < l; ++k)
			{
				for ( j = 0; j < 100; ++j)
				{	/*check the country's neighbor's of neighbors, 
						is defined in struct*/
					if (strcmp((&array1[k][25]),(country[j].countryName))==0)
					{

						neighbourhood[m]=country[j];
						m++;
						count1++;

						j=100;
					}

				}
				
			}

	
				j=0;
				count2=0;
				/*compare the number of the soldiers in army*/
				for (i = 0; i <= count1; ++i)
				{
					if ((neighbourhood[i].soldiersInArmy)<
						(neighbourhood[i+1].soldiersInArmy))
						{
							neighbourhood[i].soldiersInArmy = 
							neighbourhood[i+1].soldiersInArmy;
							count2++;
						}
				}
				if (neighbourhood[count2].soldiersInArmy>
					country[count].soldiersInArmy)
				{
					printf("%s\n",neighbourhood[count2].countryName );
				}

				else if(neighbourhood[count2].soldiersInArmy<
						country[count].soldiersInArmy)
				{
					printf("%s\n",country[count].countryName );
				}
				
				
}

/*prints the largest country*/
void areaOfLand(countriesT country[100])
{
	int i=0,j=0, k=0, l=0, m=0, h=0;
	int count=0, count1=0, count2 =0;
	countriesT temp;
	char array[10][25];
	char array1[90][25];
	countriesT neighbourhood[100];

	count=0;

			scanf("%s", temp.countryName);
			
			
			/*find the given string's index*/
			for (k = 0; k < 100; ++k)
			{
				if (strcmp((temp.countryName), (country[k].countryName))==0)
				{
					count=k;
					k=100;
				}
			}

			/*finds the neighbors and copies this neighbor to another array*/
			i=0;
			while(strcmp(&country[count].neighbors[i][25], "-1")!=0 && i<10)
			{
				
				strcpy(&array[i][25],&country[count].neighbors[i][25]);
				i++;
			}


			count1=0;
			l=0;
			for (k = 0; k < i; ++k)
			{
				for ( j = 0; j < 100; ++j)
				{	/*check the country's neighbours, 
						is defined in other countries*/
					if (strcmp((&array[k][25]),(country[j].countryName))==0)
					{
						neighbourhood[m]=country[j];

						/*copy the neighbor's of neighbors to another array*/
						h=0;
						while(strcmp(&neighbourhood[m].neighbors[h][25],"-1")!=0 
							  && l<100)
						{
							
							strcpy(&array1[l][25],
								   &neighbourhood[m].neighbors[h][25]);
							l++;
							h++;

						}
				
						m++;
						count1++;
						j=100;
					}

				}
				
			}
	
			for (k = 0; k < l; ++k)
			{
				for ( j = 0; j < 100; ++j)
				{	/*check the country's neighbor's of neighbors, 
						is defined in struct*/
					if (strcmp((&array1[k][25]),(country[j].countryName))==0)
					{
						neighbourhood[m]=country[j];
						m++;
						count1++;

						j=100;
					}

				}
				
			}

		
				j=0;
				count2=0;
				/*compare the area of the countries*/
				for (i = 0; i <= count1; ++i)
				{
					if ((neighbourhood[i].kmSquares)<
						(neighbourhood[i+1].kmSquares))
					{
							neighbourhood[i].kmSquares =
							neighbourhood[i+1].kmSquares;
							count2++;
					}
				}

				if (neighbourhood[count2].kmSquares>country[count].kmSquares)
				{
					printf("%s\n",neighbourhood[count2].countryName );
				}

				else if(neighbourhood[count2].kmSquares<
						country[count].kmSquares)
				{
					printf("%s\n",country[count].countryName );
				}
		
}


/*prints the country is accessible or inaccessible*/
void visitACountry(countriesT country[100])
{
	countriesT temp[2];
	int k=0, i=0, j=0, l=0;
	int result=0, total=0;
	int count2=0 ,count=0;
	char array[10][25];
	char array2[10][25];


			scanf("%s %s", temp[0].countryName, temp[1].countryName);

			for (k = 0; k < 100; ++k)
			{
				if (strcmp((temp[0].countryName), (country[k].countryName))==0)
				{
					count=k;
				}

				if (strcmp((temp[1].countryName), (country[k].countryName))==0)
				{
					count2=k;
				}
			}

			i=0;
			while(strcmp(&country[count].neighbors[i][25], "-1")!=0 && i<10)
			{
				strcpy(&array[i][25],&country[count].neighbors[i][25]);
				i++;
			}

			j=0;
			while(strcmp(&country[count2].neighbors[j][25], "-1")!=0 && j<10)
			{

				strcpy(&array2[j][25],&country[count2].neighbors[j][25]);
				j++;
			}

			for (k = 0; k < i; ++k)
			{
				for (l = 0; l < j; ++l)
				{
					if (strcmp(&array[k][25], &array2[l][25])==0)
					{
						result=1;
					}
				}
				
			}

			if (result==1)
			{
				printf("%d\n", total );
			}

			if (result!=1)
			{
				printf("INACCESSIBLE\n");
			}

}
/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/