/*--------------------------------------------------------------------------*/
/*																			*/
/* HW07_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part2.c 																	*/
/* ---------																*/
/* Created on 15/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* Calculates the probabilities air hockey.									*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int randNumber(int angle);
int reflection(int angle);
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, 
			 double kickAngle, double ballRadius, double goalWidth);

int recursive(double wallWidth, double wallHeight, double ballCenterX, 
			  double kickAngle, double ballRadius, double goalWidth);



/* generates a random number*/
int randNumber(int angle)
{

	srand(angle);
	return rand();

}

/*calculates angle with reflection*/
int reflection(int angle)
{
	
	int range;
	int reflectionAngle;

	range = randNumber(angle)%6;

	reflectionAngle = range + angle;


	if (reflectionAngle>175)
	{
		reflectionAngle = 175;
	}

	if (reflectionAngle<5)
	{
		reflectionAngle = 5;
	}


	return reflectionAngle;
}

/*returns whether the disc will be in the goal or not*/
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, 
			 double kickAngle, double ballRadius, double goalWidth)
{

	int result = 0;
	double verticalDistance;


	/*not added reflection angle for the first time*
	 *calculates the vertical distance 			   */
	verticalDistance = (wallWidth - ballCenterX) * sin(kickAngle*3.14/180) ;
	/*calculates the remain wall height*/
	wallHeight = wallHeight - verticalDistance;


	/*calls the recursive function*/
	if (recursive(wallWidth, wallHeight, ballCenterX, 
			 	  kickAngle, ballRadius,goalWidth))
	{
		result = 1;
	}

	if (wallWidth < ballRadius || wallWidth< goalWidth)
	{
		result = 0;
	}


	return result;
}

/*checks whether the disc will be in the goal or not*/
int recursive(double wallWidth, double wallHeight, double ballCenterX, 
			  double kickAngle, double ballRadius, double goalWidth)

{

	double verticalDistance;/*the path of the ball's y axis*/
	double reflectionAngle;/*angle occur when the ball hit edge*/
	double goal;/*situations that shot goal*/
	int result=0;

	/*kick angle + reflection*/
	reflectionAngle = reflection(kickAngle);
	/*the path of the ball's y axis*/
	verticalDistance = (wallWidth -ballCenterX) * sin(reflectionAngle*3.14/180);
	

	/*if wall height less than vertical distance calculate whether goal or not*/
	if (wallHeight<verticalDistance)
	{

		goal = wallHeight / sin(reflectionAngle*3.14/180);

		if (goal>=((wallWidth- goalWidth)/2) - ballRadius && 
			goal<=((wallWidth- goalWidth)/2+ goalWidth+ ballRadius))

		{
			result = 1;
		}

	}


	else
	{
		
		result=recursive(wallWidth, wallHeight-verticalDistance, ballCenterX, 
			 			 reflectionAngle, ballRadius,goalWidth);

	}

	if (kickAngle==90)
	{
		result = 1;
	}


	return result;

}

/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/