/*--------------------------------------------------------------------------*/
/*																			*/
/* HW01_141044063_Rumeysa_Karakavak											*/
/*																			*/
/* part2.c 																	*/
/* ---------																*/
/* Created on 25/02/2016 by Rumeysa_Karakavak 								*/
/*																			*/
/* Description																*/
/* -----------																*/
/*	 Gets width and height for rectangle by user.							*/
/*	 Calculates area and perimeter of the rectangle. 						*/
/*	 Gets edge length for square by user.									*/
/*	 Calculates area and perimeter of the square. 							*/
/*	 Gets radius for circle by user.										*/
/*	 Calculates area and perimeter of the circle. 							*/
/*																			*/
/*																			*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define PI 3.14
#define COEFFICIENT 2


int areaOfRectangle(int width, int height);/*calculates area of the rectangle*/
int perimeterOfRectangle(int width, int height);/*calculates perimeter
													 of the rectangle*/
int areaOfSquare(int edgeLength);/*calculates area of the square*/
int perimeterOfSquare(int edgeLength);/*calculates perimeter of the square*/
double areaOfCircle(int radius);/*calculates area of the circle*/
double perimeterOfCircle(int radius);/*calculates perimeter of the circle*/




int main()
{
	int widthForRectangle, heightForRectangle;
	int edgeLengthForSquare;
	int radiusForCircle;
	int areaRectangle, perimeterRectangle;
	int areaSquare, perimeterSquare;
	double areaCircle, perimeterCircle;

	/*Get width and height for the rectangle*/
	printf("Please enter the width of the rectangle:");
	scanf("%d", &widthForRectangle);
	printf("Please enter the height of the rectangle:");
	scanf("%d", &heightForRectangle);
	/*Call functions for print area and perimeter of the rectangle*/
	areaRectangle = areaOfRectangle (widthForRectangle, heightForRectangle);
	printf("The area of the rectangle is: %d\n" , areaRectangle);
	perimeterRectangle = 
	perimeterOfRectangle(widthForRectangle, heightForRectangle);
	printf("The perimeter of the rectangle is: %d\n", perimeterRectangle);


	/*Get width for the square*/
	printf("Please enter the edge length of the square:");
	scanf("%d", &edgeLengthForSquare);
	/*Call functions for print area and perimeter of the square*/
	areaSquare = areaOfSquare(edgeLengthForSquare);
	printf("The area of the square is: %d\n" , areaSquare);
	perimeterSquare = perimeterOfSquare(edgeLengthForSquare);
	printf("The perimeter of the square is: %d\n" , perimeterSquare);


	/*Get radius for the circle*/
	printf("Please enter the radius of the circle:");
	scanf("%d", &radiusForCircle);
	/*Call functions for print area and perimeter of the circle*/
	areaCircle = areaOfCircle(radiusForCircle);
	printf("The area of the circle is: %.2f\n" ,areaCircle);
	perimeterCircle = perimeterOfCircle(radiusForCircle);
	printf("The perimeter of the circle is: %.2f\n" , perimeterCircle);




}

int areaOfRectangle(int width, int height)
{

	int areaOfRectangle;

	/*Multiply width and height for calculate of the area*/
	areaOfRectangle = width * height;

	return areaOfRectangle;

}

int perimeterOfRectangle(int width, int height)
{

	int perimeterOfRectangle;

	/*Sum width and height.Multiply this summation and 2.*/
	perimeterOfRectangle = ((width + height) * COEFFICIENT);

	return perimeterOfRectangle;
}

int areaOfSquare(int edgeLength)
{

	int areaOfSquare;

	/*Multiply edge length and edge length for calculate of the area*/
	areaOfSquare = edgeLength * edgeLength ;

	return areaOfSquare;

}

int perimeterOfSquare(int edgeLength)
{

	int perimeterOfSquare;

	/*Multiply edge length, coefficient and coefficient (4)*/
	perimeterOfSquare = (edgeLength * COEFFICIENT) * COEFFICIENT ;

	return perimeterOfSquare;
	
}

double areaOfCircle(int radius)
{

	double areaOfCircle;

	/*Multiply PI, radius and radius for calculate of the area*/
	areaOfCircle = PI * radius *radius;

	return areaOfCircle;
}

double perimeterOfCircle(int radius)
{

	double perimeterOfCircle;

	/*Multiply coefficient ,PI and radius for calculate of the perimeter*/
	perimeterOfCircle = COEFFICIENT * PI * radius;

	return perimeterOfCircle;
}

/*---------------------------------------------------------------------------*/ 
/*								End of part2.c 								 */
/*---------------------------------------------------------------------------*/
