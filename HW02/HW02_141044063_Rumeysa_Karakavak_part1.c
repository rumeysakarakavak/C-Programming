/*--------------------------------------------------------------------------*/
/*																			*/
/* HW01_141044063_Rumeysa_Karakavak											*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 25/02/2016 by Rumeysa_Karakavak 								*/
/*																			*/
/* Description																*/
/* -----------																*/
/*	 Gets midterm, homework and final exam weight by students.				*/
/*	 Gets midterm, homework and final exam grade by students.				*/
/*	 Calculates the overall grade of the students.							*/
/*																			*/
/*																			*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define PERCENTAGE 100


void calculateLastGrade();


int main()
{
	
	/*calculate the overall grade of the first student*/
	calculateLastGrade();
	
	return 0;

}


void calculateLastGrade()
{
	int midtermWeight, homeworkWeight,  finalExamWeight;
	int midtermGrade, homeworkGrade, finalExamGrade;
	double finalGrade =0.0; /*the overall grade of the student*/

	/*Get midterm weight*/
	printf("Please enter the 1. midterm weight:");
	scanf("%d", &midtermWeight);
	/*Get homework weight*/
	printf("Please enter the 1. homework weight:");
	scanf("%d", &homeworkWeight);
	/*Get final exam weight*/
	printf("Please enter the final exam weight:");
	scanf("%d", &finalExamWeight);

	
	/*Get midterm grade*/
	printf("Please enter the 1. midterm grade:");
	scanf("%d", &midtermGrade);
	/*Get homework grade*/
	printf("Please enter the 1. homework grade:");
	scanf("%d", &homeworkGrade);
	/*Get final exam grade*/
	printf("Please enter the final exam grade:");
	scanf("%d", &finalExamGrade);


	/*Calculate overall grade using grade, weight and percentage*/
	finalGrade = ((double)midtermWeight*midtermGrade/PERCENTAGE) +
				 ((double)homeworkGrade*homeworkWeight/PERCENTAGE) + 
				 ((double)finalExamGrade*finalExamWeight/PERCENTAGE);
	
	printf("Your final grade is: %f\n", finalGrade );
}


/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/