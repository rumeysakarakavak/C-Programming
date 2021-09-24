/*--------------------------------------------------------------------------*/
/*																			*/
/* HW10_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 04/05/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* simple database management system which reads information about 			*/
/* a department in a university such as students, lectures, and professors  */
/* and outputs a file which includes some summary information.				*/
/*--------------------------------------------------------------------------*/
/* Reads information about students, lectures, lecturers, schedules 		*/
/* from input file.															*/
/*																			*/
/* Writes information about how many students will attend of the lecture,   */
/* number of students that takes the lecture will be listed	and 			*/
/* which day students have lecture to output file.							*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#define LENGTH 30
#define SIZE 20


typedef struct 
{
	int id;
	char name[LENGTH],
		 surname[LENGTH];

}studentT;


typedef struct 
{
	char degree[LENGTH];
	int id;
	char name[LENGTH],
		 surname[LENGTH];
		 
}lecturerT;


typedef struct 
{
	int code;
	char name[LENGTH];
	int id;
		 
}lectureT;


typedef struct 
{
	char class[LENGTH],
		 day[LENGTH];
	int startingTime,
		durationTime,
		codeOfLecture;
		 
}scheduleT;


typedef struct 
{
	int id,
		codeOfLecture;
		 
}courseT;

int main()
{
	FILE *inputFile, *outputFile; /*files*/

	studentT student[SIZE];
	lecturerT lecturer[SIZE];
	lectureT lecture[SIZE];	/*struct arrays that are to be acted on*/
	scheduleT schedule[SIZE];
	courseT course[SIZE];

	/*variables for struct array's size*/
	int numberOfStudents=0, numberOfLecturer=0, numberOfLecture=0,
	    numberOfSchedule=0,	numberOfCourse=0;

	/*variables for loops*/
	int i=0, j=0, k=0;
	int count=0; 	
	int forComma=0;

	/*various arrays where information is kept*/
	int numberOfTakenLecture[SIZE], numberOfStudentInLecture[SIZE];
	int lectureArray[SIZE][SIZE];

	int result = 0; /*return value for main function*/

	/*open input and output files*/
	inputFile = fopen("input.dat" , "rb");
	outputFile = fopen("output.txt", "w");

	/*if files couldn't open, return 0;*/
	if(inputFile==NULL || outputFile==NULL)
	{
		result = -1;
	}

	/*reads student's information*/
	fread(&numberOfStudents, sizeof(int), 1, inputFile);
	fread(student, sizeof(studentT), numberOfStudents, inputFile);

	/*reads lecturer's information*/
	fread(&numberOfLecturer, sizeof(int), 1, inputFile);
	fread(lecturer, sizeof(lecturerT), numberOfLecturer, inputFile);

	/*reads lecture's information*/
	fread(&numberOfLecture, sizeof(int), 1, inputFile);
	fread(lecture, sizeof(lectureT), numberOfLecture, inputFile);

	/*reads schedule's information*/
	fread(&numberOfCourse, sizeof(int), 1, inputFile);
	fread(schedule, sizeof(scheduleT), numberOfCourse, inputFile);

	/*reads course's information*/
	fread(&numberOfSchedule, sizeof(int), 1, inputFile);
	fread(course, sizeof(courseT), numberOfSchedule, inputFile);

	
/*counts how many courses taken by the students*/

	for (j = 0; j < numberOfStudents; ++j)
	{	
		k=0;
		for (i = 0; i <SIZE; ++i)
		{	
			if(course[i].id == student[j].id)
			{
				
				lectureArray[j][k] = course[i].codeOfLecture;
				k++;
			}
			
		}
		numberOfTakenLecture[j]=k;
	
	}

/*counts how many students will attend of the lecture*/

	count=0;
	for (j = 0; j < numberOfLecture; ++j)
	{
		for (i = 0; i < SIZE; ++i)
		{
			if(course[i].codeOfLecture == lecture[j].code)
			{
				count++;
			}
			
		}
		numberOfStudentInLecture[j]=count;
		count=0;
	}

/*for print the lecture name,lecturer name and surname,
  and number of students that takes the lecture will be listed*/
	
	fprintf(outputFile,"Lecture-Lecturer\n");

	for (i = 0; i < SIZE; ++i)
	{	
		for (j = 0; j < numberOfLecture; ++j)
		{
			if(lecture[i].id == lecturer[j].id)
			{	
				fprintf(outputFile,"%s %s ",lecture[i].name,lecturer[j].name);
				fprintf(outputFile,"%s ",lecturer[j].surname );
		        fprintf(outputFile,"%d\n",numberOfStudentInLecture[i] );
			}
			
		}
	}

	fprintf(outputFile,"\n\n");



/*for print the student id, name, surname and how many lecture have*/

	fprintf(outputFile,"Student-Lecture\n");

	for (i = 0; i < numberOfStudents; ++i)
	{
		fprintf(outputFile,"%d ",student[i].id );
		fprintf(outputFile,"%s %s ",student[i].name, student[i].surname );
		fprintf(outputFile,"%d\n",numberOfTakenLecture[i] );
	}

	fprintf(outputFile,"\n\n");




/*for print the student id, name, surname and which day have lecture*/

	fprintf(outputFile,"Student-Day\n");

	for (j = 0; j < numberOfStudents; ++j)
	{	
		forComma = numberOfTakenLecture[j];
		fprintf(outputFile,"%d ",student[j].id );
		fprintf(outputFile,"%s %s ",student[j].name, student[j].surname );
		for (i = 0; i < numberOfStudents; ++i)
		{	
			for (k = 0; k <numberOfLecture; ++k)
			{	
				if(schedule[k].codeOfLecture == lectureArray[j][i])
				{

						fprintf(outputFile,"%s", schedule[k].day );

						if (forComma-1>0)
						{
							fprintf(outputFile, ",");
							forComma--;
						}
				}

			}
			
		}

		fprintf(outputFile,"\n");
		
	}

	fprintf(outputFile, "\n\n");



	/*close input and output files*/
	fclose(inputFile);
	fclose(outputFile);

	return result;
}

/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/
