/*--------------------------------------------------------------------------*/
/*																			*/
/* HW05_121044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 04/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* CHESS simulator.															*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>

void initBoard(char *board);
void getPosition(char *col, int *row);
int isValidCell(char col , int row);
void printBoard(char *board);
int isPieceMovable(char *board);

int isKnightMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow);

int isRookMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow);

int isPawnMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow);

int isBishopMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow); 

int isKingMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow);

int isQueenMovable(char *board, char sourceCol, int sourceRow,
				   char targetCol, int targetRow);

int isRookMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow);
				  
/*finds the index based on the entered value */
int findIndex(int row , char column);


void emptyBuffer()
{
	while ( getchar() != '\n' );
}


/*initialize board*/
void initBoard(char *board)
{
	int i=0;

	*board=0;
	/*initializing board*/
	board[0]='r';  board[7]='r';
	board[56]='R'; board[63]='R';
	board[1] ='n'; board[6]='n';
	board[57]='N'; board[62]='N';
	board[2]='b';  board[5]='b';
	board[58]='B'; board[61]='B';
	board[3]='q';  board[4]='k';
	board[59]='Q'; board[60]='K';

	for (i = 8; i < 16; ++i)
	{
		board[i] = 'p';
	}

	for ( i = 16; i < 48; ++i)
	{
		board[i]=' ';
	}

	for (i = 48; i < 56; ++i)
	{
		board[i] = 'P';
	}

}

/*prints board with border*/
void printBoard(char *board)
{
	
	int i=0, j=0, k=0;

	/*print column*/
	printf("  ");
	for (i = 97; i <= 104; ++i)
	{
		printf("%c ", i );
	}
	printf("\n");

	/*print --------*/
	printf("  ");
	for (i = 0; i < 8; ++i)
	{
		printf("- ");
	}
	printf("\n");

	/*print rows and characters*/
	for (i = 8; i>= 1; --i)
	{
		printf("%d|",i);
		for (j = 0; j <=7; ++j)
		{	
			
			printf("%c", board[k]);
			if (j==7)
			{
				printf("|");
			}
			else{printf(" ");}
			
			k+=1;
		}
		printf("\n");
	}

	/*print --------*/
	printf("  ");
	for (i = 0; i < 8; ++i)
	{
		printf("- ");
	}
	printf("\n");

}

/*gets column and row by user*/
void getPosition(char *col, int *row)
{
	*col=0;
	*row=0;

	scanf(" %c%d", col, row);

}


/*checks whether piece can move*/
int isPieceMovable(char *board)
{ 

	char sourceCol, targetCol;
	int targetRow, sourceRow;
	int targetIndex;

	/*gets source column and row by user*/	
	getPosition(&sourceCol, &sourceRow);
	/*gets target column and row by user*/
    getPosition(&targetCol, &targetRow);

    /*checks whether the move is valid*/
    if (!isValidCell(sourceCol , sourceRow))
	{
		return 0;
	}
    if (!isValidCell(targetCol , targetRow))
	{
		return 0;
	}

	/*finds target index in board using target row and column*/
    targetIndex = findIndex(targetRow, targetCol);

    /*checks target index is empty and */
    /*checks whether the stone belongs to the opponent*/
    if (board[targetIndex]==' '|| 
    	((sourceCol>=65 && sourceCol<=90) && (targetCol>=97&& targetCol<=122))||
    	((targetCol>=65 && targetCol<=90) && (sourceCol>=97&& sourceCol<=122)))
    {

    	/*calls functions*/
		if( 
			isPawnMovable(board, sourceCol, sourceRow,targetCol, targetRow)  ||
			isRookMovable(board, sourceCol, sourceRow,targetCol, targetRow)  ||
			isKnightMovable(board, sourceCol, sourceRow,targetCol, targetRow)||
			isBishopMovable(board, sourceCol, sourceRow,targetCol, targetRow)||
			isQueenMovable(board, sourceCol, sourceRow,targetCol, targetRow) ||
			isQueenMovable(board, sourceCol, sourceRow,targetCol, targetRow)
		  )
	
		return 1;
	}
			
	return 0;

}


/*checks whether the move is valid*/
int isValidCell(char col , int row)
{

	if ((row<1 || row>8) ||  (col<97 || col>104))
	{
		
		return 0;
	}

	return 1;
}


/*checks pawn's move*/
int isPawnMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow)
{

	int sourceIndex=0;
	int targetIndex=0;
	

	sourceIndex = findIndex(sourceRow, sourceCol);
	targetIndex = findIndex(targetRow, targetCol);



	if (	
		(board[sourceIndex]=='p'  && board[targetIndex]==' ' 
		&&(targetIndex == sourceIndex+8))
		|| ((board[sourceIndex]=='P') &&  board[targetIndex]==' ' 
		&& (targetIndex == sourceIndex-8))
		||(targetIndex == sourceIndex+8+1)
		|| (targetIndex == sourceIndex+8-1)
		||(targetIndex==(sourceIndex-8)+1)
		||(targetIndex== sourceIndex-8-1)
		)

		{return 1;}

	if (
		  (board[targetIndex]==' ' && (targetIndex== sourceIndex-8+1))
	 	||(board[targetIndex]== ' '&& (targetIndex == sourceIndex+8-1))
	    ||(board[targetIndex]==' ' && (targetIndex == sourceIndex+8+1))
		||(board[targetIndex]==' ' && (targetIndex == sourceIndex-8-1))
		
	   )
		
		{
		return 0;
		}

		

	return 0;
		
}

/*checks knight's move*/
int isKnightMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow)

{

	int sourceIndex=0;
	int targetIndex=0;

	sourceIndex = findIndex(sourceRow, sourceCol);
	targetIndex = findIndex(targetRow, targetCol);

	if (
		
	    /*horizontal, vertical, inverted , flat L status*/
		(targetIndex == (sourceIndex+16)-1) ||
		(targetIndex == (sourceIndex+16)+1) ||
		(targetIndex == (sourceIndex-16)-1) ||
		(targetIndex == (sourceIndex-16)+1) ||
		(targetIndex == (sourceIndex+2)-8)  ||
		(targetIndex == (sourceIndex+2)+8)  ||
		(targetIndex == (sourceIndex-2)-8)  ||
		(targetIndex == (sourceIndex-2)+8)   )
	{
		return 1;
	}

	return 0;


}

/*checks bishop's move*/
int isBishopMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow)

{
	int sourceIndex=0;
	int targetIndex=0;
	int differenceOfRow=0;
	int differenceOfCol=0;

	differenceOfRow = sourceRow-targetRow;
	differenceOfCol = (int)sourceCol- (int)targetCol;

	sourceIndex = findIndex(sourceRow, sourceCol);
	targetIndex = findIndex(targetRow, targetCol);

	if (
		/*checks the cross in the upper right */
		targetIndex == (sourceIndex-(8*(differenceOfCol))+(differenceOfRow)) ||
		/*checks the cross in the lower left */
		targetIndex == (sourceIndex+(8*(differenceOfCol))-(differenceOfRow)) ||
		/*checks the cross in the lower right */
		targetIndex == (sourceIndex+(8*(differenceOfCol))+(differenceOfRow)) ||
		/*checks the cross in the upper left */
		targetIndex == (sourceIndex-(8*(differenceOfCol))-(differenceOfRow))  )
	
	{
		return 1;
	}


	return 0;

}
/*checks king's move*/
int isKingMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow)
{
	
	int sourceIndex=0;
	int targetIndex=0;

	sourceIndex = findIndex(sourceRow, sourceCol);
	targetIndex = findIndex(targetRow, targetCol);

	if (
		/*checks the cross in the lower left */
		(targetIndex == (sourceIndex+8)-1) ||
		/*checks the cross in the lower right*/
		(targetIndex == (sourceIndex+8)+1) ||
		/*checks the cross in the upper left*/
		(targetIndex == (sourceIndex-8)-1) ||
		/*checks the cross in the upper right*/
		(targetIndex == (sourceIndex-8)+1) ||
		/*checks the upper*/
		(targetIndex ==  sourceIndex+8)    ||
		/*checks the lower*/
		(targetIndex ==  sourceIndex-8)    ||
		/*chacks the right*/
		(targetIndex ==  sourceIndex+1)    ||
		/*chacks the left*/
		(targetIndex ==  sourceIndex-1)    )
	{
		return 1;
	}

	return 0;

}

/*checks queen's move*/
int isQueenMovable(char *board, char sourceCol, int sourceRow,
				   char targetCol, int targetRow)
{
	return 1;
}

/*checks rook's move*/
int isRookMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow)
{
	int sourceIndex=0;
	int targetIndex=0;
	int differenceOfRow=0;
	int differenceOfCol=0;

	/*source index on board*/
	sourceIndex = findIndex(sourceRow, sourceCol);
	/*target index on board*/
	targetIndex = findIndex(targetRow, targetCol);

	differenceOfRow = sourceRow-targetRow;
	differenceOfCol = (int)sourceCol- (int)targetCol;


	if (targetIndex == sourceIndex + differenceOfCol 	 ||
		targetIndex == sourceIndex + (differenceOfRow*8) ||
		targetIndex == sourceIndex - differenceOfCol 	 ||
		targetIndex == sourceIndex - (differenceOfRow*8)
	   )
	{
		return 1;
	}

	

	return 0;


}

/*finds the index based on the entered value */
int findIndex(int row , char column)
{

	int index;

	switch(column)
	{
		case 'a':	index = 8*(row-1)+7;	break;
		case 'b':	index = 8*(row-1)+6; 	break;
		case 'c':	index = 8*(row-1)+5; 	break;
		case 'd':	index = 8*(row-1)+4; 	break;
		case 'e':	index = 8*(row-1)+3; 	break;
		case 'f':	index = 8*(row-1)+2; 	break;
		case 'g':	index = 8*(row-1)+1; 	break;
		case 'h':	index = 8*(row-1); 		break;

	}

	return index;

}

/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/

