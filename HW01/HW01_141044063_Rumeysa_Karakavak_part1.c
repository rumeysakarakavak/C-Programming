/*--------------------------------------------------------------------------*/
/*																			*/
/* HW01_141044063_Rumeysa_Karakavak											*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 19/02/2016 by Rumeysa_Karakavak 								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/*	 Gets midterms, homeworks and final exam weights by student.			*/
/*	 Gets midterms, homeworks and final exam grades by student.				*/
/*	 Calculates the overall grade of the student.							*/
/*																			*/
/*																			*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define PERCENTAGE 100


int main()
{

	int midWeight1, midWeight2, midWeight3;  /*midterms weight*/
	int hwWeight1, hwWeight2, finalExamWeight; /*homeworks and final weight*/
	int midGrade1, midGrade2, midGrade3;  /*midterms grade*/
	int hwGrade1, hwGrade2, finalExamGrade; /*homeworks and final grade*/
	double finalGrade =0.0; /*the overall grade of the student*/

	/*Get midterms weight*/
	printf("Please enter the 1. midterm weight: ");
	scanf("%d", &midWeight1);
	printf("Please enter the 2. midterm weight: ");
	scanf("%d", &midWeight2);
	printf("Please enter the 3. midterm weight: ");
	scanf("%d", &midWeight3);

	/*Get homeworks weight*/
	printf("Please enter the 1. homework weight: ");
	scanf("%d", &hwWeight1);
	printf("Please enter the 2. homework weight: ");
	scanf("%d", &hwWeight2);

	/*Get final exam weight*/
	printf("Please enter the final exam weight: ");
	scanf("%d", &finalExamWeight);

	/*Get midterms grade*/
	printf("Please enter the 1. midterm grade: ");
	scanf("%d", &midGrade1);
	printf("Please enter the 2. midterm grade: ");
	scanf("%d", &midGrade2);
	printf("Please enter the 3. midterm grade: ");
	scanf("%d", &midGrade3);

	/*Get homeworks grade*/
	printf("Please enter the 1. homework grade: ");
	scanf("%d", &hwGrade1);
	printf("Please enter the 2. homework grade: ");
	scanf("%d", &hwGrade2);

	/*Get final exam grade*/
	printf("Please enter the final exam grade: ");
	scanf("%d", &finalExamGrade);

	/*Calculate overall grade using grades, weights, and percentage*/
	finalGrade = ((double)midWeight1*midGrade1/PERCENTAGE)+
				 ((double)midGrade2*midWeight2/PERCENTAGE)+
				 ((double)midGrade3*midWeight3/PERCENTAGE)+
				 ((double)hwGrade1*hwWeight1/PERCENTAGE)+
				 ((double)hwGrade2*hwWeight2/PERCENTAGE)+
				 ((double)finalExamGrade*finalExamWeight/PERCENTAGE);
	
	printf("Your final grade is: %.2f\n", finalGrade );


	return 0;

}
/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/