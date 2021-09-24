/*--------------------------------------------------------------------------*/
/*																			*/
/* HW08_141044063_Rumeysa_Karakavak	 										*/
/*																			*/
/* part1.c 																	*/
/* ---------																*/
/* Created on 23/04/2016 by Rumeysa_Karakavak								*/
/*																			*/  
/* Description																*/
/* -----------																*/
/* CHESS simulator.															*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

void initBoard(char *board);

void getPosition(char *col, int *row);

int isValidCell(char col , int row);

void printBoard(char *board);

int isPieceMovable(char *board, char sc, int sr, char tc, int tr);

int isInCheck(char* board);

int checkTopAndBase(char *board, char king, char character);

int checkLeftAndRight(char *board, char king, char character);

int checkCross(char *board, char king, char character);

int checkPawn(char *board, char king, char character);

int checkKnight(char *board, char king, char character);


int makeMove(char *board, char sc, int sr, char tc, int tr);

char getPlayer(char *board, char sc, int sr);

int isBlack(char currPlayer);

int isWhite(char currPlayer);


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

	for ( i = 16; i <=40; ++i)
	{
		board[i]=' ';
	}
	for (i = 41; i < 48; ++i)
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
	for (i = 0; i < BOARD_SIZE; ++i)
	{
		printf("- ");
	}
	printf("\n");

	/*print rows and characters*/
	for (i = BOARD_SIZE; i>= 1; --i)
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
	for (i = 0; i < BOARD_SIZE; ++i)
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
int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{ 

	int result=0;
	int sourceIndex;


    /*checks whether the move is valid*/
    if (!isValidCell(sc , sr))
	{
		result= 0;
	}
    if (!isValidCell(tc , tr))
	{
		result= 0;
	}

	/*finds target index in board using target row and column*/
    sourceIndex = findIndex(sr, sc);


    /*checks target index is empty and */
    /*checks whether the stone belongs to the opponent*/
  
 
/*calls functions*/
switch(board[sourceIndex])
{
	case 'p':
	case 'P':

		if(isPawnMovable(board, sc, sr,tc, tr))

			result= 1;	break;

	case 'R':
	case 'r':

		if(isRookMovable(board, sc, sr,tc, tr))

			result= 1;	break;

	case 'n':
	case 'N':

		if(isKnightMovable(board, sc, sr,tc, tr))

			result=1;	break;

	case 'B':
	case 'b':

		if(isBishopMovable(board, sc, sr,tc, tr))

			result= 1;	break;

	case 'Q':
	case 'q':

		if(isQueenMovable(board, sc, sr,tc, tr))

			result= 1;	break;

	case 'K':
	case 'k':

		if(isKingMovable(board, sc, sr,tc, tr))

			result =1;	break;
} 
	
	return result;
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
	int result =0;
	

	sourceIndex = findIndex(sourceRow, sourceCol);
	targetIndex = findIndex(targetRow, targetCol);




	if ((board[sourceIndex]=='p'  && board[targetIndex]==' ' 
		&&(targetIndex == sourceIndex+8))

		|| ((board[sourceIndex]=='P') &&  board[targetIndex]==' ' 
		&& (targetIndex == sourceIndex-8)))
	
		result =1;
	


	if (((targetIndex == sourceIndex+8+1)&&(board[sourceIndex]=='p')
		  &&((board[targetIndex]<=90) && (board[targetIndex]>=65)))

		  ||((targetIndex == sourceIndex+8-1)&&(board[sourceIndex]=='p')
		  &&((board[targetIndex]<=90) && (board[targetIndex]>=65))))
	
		result =1;
	

	if (((targetIndex == sourceIndex-8+1)&&(board[sourceIndex]=='P')
		  &&((board[targetIndex]<=122) && (board[targetIndex]>=97)))

		  ||((targetIndex == sourceIndex-8-1)&&(board[sourceIndex]=='P')
		  &&((board[targetIndex]<=122) && (board[targetIndex]>=97))))
	
		result =1;
	


	if ((board[sourceIndex]=='p'&& ((board[targetIndex]<=90) 
		 && (board[targetIndex]>=65))&&(targetIndex == sourceIndex+8)))

		result =1;


	if ((board[sourceIndex]=='P'&& ((board[targetIndex]<=122) 
		 && (board[targetIndex]>=97))&&(targetIndex == sourceIndex+8)))

		result =1;


	if (isWhite(board[sourceIndex]) && isWhite(board[targetIndex]))
	{
		result =0;
	}
	
	if (isBlack(board[sourceIndex]) && isBlack(board[targetIndex]))
	{
		result =0;
	}
	

	return result;
		
}

/*checks knight's move*/
int isKnightMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow)

{

	int sourceIndex=0;
	int targetIndex=0;
	int result=0;

	sourceIndex = findIndex(sourceRow, sourceCol);
	targetIndex = findIndex(targetRow, targetCol);

	if ((targetIndex == (sourceIndex+16)-1) ||
		(targetIndex == (sourceIndex+16)+1) ||
		(targetIndex == (sourceIndex-16)-1) ||
		(targetIndex == (sourceIndex-16)+1) ||
		(targetIndex == (sourceIndex+2)-8)  ||
		(targetIndex == (sourceIndex+2)+8)  ||
		(targetIndex == (sourceIndex-2)-8)  ||
		(targetIndex == (sourceIndex-2)+8)   )
	
		result= 1;
	

	if (isWhite(board[sourceIndex]) && isWhite(board[targetIndex]))
	{
		result =0;
	}
	
	if (isBlack(board[sourceIndex]) && isBlack(board[targetIndex]))
	{
		result =0;
	}

	return result;


}

/*checks bishop's move*/
int isBishopMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow)

{
	int sourceIndex=0;
	int targetIndex=0;
	int result =0;
	int i, j;

	sourceIndex = findIndex(sourceRow, sourceCol);
	targetIndex = findIndex(targetRow, targetCol);


	if (targetIndex==sourceIndex+7||targetIndex==sourceIndex+14
		||targetIndex==sourceIndex+21||targetIndex==sourceIndex+28
		||targetIndex==sourceIndex+35||targetIndex==sourceIndex+42
		||targetIndex==sourceIndex+49)

	{
		j=1;
		for(i=sourceIndex+8; i<targetIndex; i+=8)
		{
			
			if (board[i-j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			j+=1;
		}

		if (targetIndex==sourceIndex+7)
		{
			result =1;
		}

	}
		


	if (targetIndex==sourceIndex+9||targetIndex==sourceIndex+18
		||targetIndex==sourceIndex+27||targetIndex==sourceIndex+36
		||targetIndex==sourceIndex+45||targetIndex==sourceIndex+56
		||targetIndex==sourceIndex+63)
	{
		j =1;
		for(i=sourceIndex+8; i<targetIndex; i+=8)
		{
			
			if (board[i+j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			j+=1;
		}

		if (targetIndex==sourceIndex+9)
		{
			result =1;
		}

	}

	

	if (targetIndex==sourceIndex-9||targetIndex==sourceIndex-18
		||targetIndex==sourceIndex-27||targetIndex==sourceIndex-36
		||targetIndex==sourceIndex-45||targetIndex==sourceIndex-56
		||targetIndex==sourceIndex-63)
	{
		j=1;
	
		for(i=sourceIndex-8; i>targetIndex; i-=8)
		{
			if (board[i-j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			j+=1;
		}

		if (targetIndex==sourceIndex-9)
		{
			result =1;
		}

	}



	if (targetIndex==sourceIndex-7||targetIndex==sourceIndex-14
		||targetIndex==sourceIndex-21||targetIndex==sourceIndex-28
		||targetIndex==sourceIndex-35||targetIndex==sourceIndex-42
		||targetIndex==sourceIndex-56)
	{

		j=1;
		for(i=sourceIndex-8; i>targetIndex; i-=8)
		{
			if (board[i+j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}

			j+=1;
		}

		if (targetIndex==sourceIndex-7)
		{
			result =1;
		}

	}


	if (isWhite(board[sourceIndex]) && isWhite(board[targetIndex]))
	{
		result =0;
	}
	
	if (isBlack(board[sourceIndex]) && isBlack(board[targetIndex]))
	{
		result =0;
	}



	return result;

}

/*checks king's move*/
int isKingMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow)
{
	
	int sourceIndex=0;
	int targetIndex=0;
	int result=0;

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
		result=1;
	}


	if (isWhite(board[sourceIndex]) && isWhite(board[targetIndex]))
	{
		result =0;
	}
	
	if (isBlack(board[sourceIndex]) && isBlack(board[targetIndex]))
	{
		result =0;
	}

	return result;

}


/*checks queen's move*/
int isQueenMovable(char *board, char sourceCol, int sourceRow,
				   char targetCol, int targetRow)
{
	int result=1;
	int targetIndex ;
	int sourceIndex;
	int i;
	int j=1;

	targetIndex = findIndex(targetRow, targetCol);
	sourceIndex = findIndex(sourceRow, sourceCol);

	if (targetIndex==sourceIndex+7||targetIndex==sourceIndex+14
		||targetIndex==sourceIndex+21||targetIndex==sourceIndex+28
		||targetIndex==sourceIndex+35||targetIndex==sourceIndex+42
		||targetIndex==sourceIndex+49)
	{
		for(i=sourceIndex+8; i<targetIndex; i+=8)
		{
			
			if (board[i-j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			j+=1;
		}
	}


	if (targetIndex==sourceIndex+9||targetIndex==sourceIndex+18
		||targetIndex==sourceIndex+27||targetIndex==sourceIndex+36
		||targetIndex==sourceIndex+45||targetIndex==sourceIndex+56
		||targetIndex==sourceIndex+63)
	{
		j =1;
		for(i=sourceIndex+8; i<targetIndex; i+=8)
		{
			
			if (board[i+j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			j+=1;
		}
	}

		

	if (targetIndex==sourceIndex-9||targetIndex==sourceIndex-18
		||targetIndex==sourceIndex-27||targetIndex==sourceIndex-36
		||targetIndex==sourceIndex-45||targetIndex==sourceIndex-56
		||targetIndex==sourceIndex-63)
	{
		j=1;
		for(i=sourceIndex-8; i>targetIndex; i-=8)
		{
			if (board[i-j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			j+=1;
		}

	}

		

	if (targetIndex==sourceIndex-7||targetIndex==sourceIndex-14
		||targetIndex==sourceIndex-21||targetIndex==sourceIndex-28
		||targetIndex==sourceIndex-35||targetIndex==sourceIndex-42
		||targetIndex==sourceIndex-56)
	{
			
		j=1;
		for(i=sourceIndex-8; i>targetIndex; i-=8)
		{
			
			if (board[i+j]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			j+=1;
		}

	}
	if (targetIndex==sourceIndex-8||targetIndex==sourceIndex-16
		||targetIndex==sourceIndex-24||targetIndex==sourceIndex-32
		||targetIndex==sourceIndex-40||targetIndex==sourceIndex-48
		||targetIndex==sourceIndex-56)
	{
		for(i=sourceIndex-8; i>targetIndex; i-=8)
		{
			if (board[i]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			
		}
	}
		
	if (targetIndex==sourceIndex+8||targetIndex==sourceIndex+16||
		targetIndex==sourceIndex+24||targetIndex==sourceIndex+32
		||targetIndex==sourceIndex+40||targetIndex==sourceIndex+48
		||targetIndex==sourceIndex+56)
	{
		for(i=sourceIndex+8; i<targetIndex; i+=8)
		{
			if (board[i]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
			
		}
	}


	if (isWhite(board[sourceIndex]) && isWhite(board[targetIndex]))
	{
		result =0;
	}
	
	if (isBlack(board[sourceIndex]) && isBlack(board[targetIndex]))
	{
		result =0;
	}
		

	return result;
}


/*checks rook's move*/
int isRookMovable(char *board, char sourceCol, int sourceRow,
				  char targetCol, int targetRow)
{
	int sourceIndex=0;
	int targetIndex=0;
	int differenceOfRow=0;
	int differenceOfCol=0;
	int result =0;
	int i;

	/*source index on board*/
	sourceIndex = findIndex(sourceRow, sourceCol);
	/*target index on board*/
	targetIndex = findIndex(targetRow, targetCol);

	differenceOfRow = abs(targetRow-sourceRow);
	differenceOfCol = abs(targetCol- sourceCol);
	printf("%d\n",differenceOfRow );
	printf("%d\n",sourceIndex );
	printf("%d\n",targetIndex );


	
	if (targetIndex == sourceIndex + differenceOfCol)
	{
		for(i=sourceIndex+1; i<targetIndex; i++)
		{
			if (board[i]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
		}
	}



	if (targetIndex == sourceIndex - differenceOfCol)
	{
		for(i=sourceIndex+1; i>targetIndex; i--)
		{
			if (board[i]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
		}
	}



	if (targetIndex == sourceIndex + (differenceOfRow*8))
	{
		for(i=sourceIndex+8; i<targetIndex; i+=8)
		{
			if (board[i]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
		}
	}



	if (targetIndex == sourceIndex - (differenceOfRow*8))
	{
		for(i=sourceIndex-8; i>targetIndex; i-=8)
		{

			if (board[i]!=' ')
			{
				result = 0;
			}
			else
			{
				result =1;
			}
		}
	}


	if (isWhite(board[sourceIndex]) && isWhite(board[targetIndex]))
	{
		result =0;
	}
	
	if (isBlack(board[sourceIndex]) && isBlack(board[targetIndex]))
	{
		result =0;
	}
	
	
	
	return result;


}

/*finds the index based on the entered value */
int findIndex(int row , char column)
{

	int index;

	switch(column)
	{
		case 'a':	index = BOARD_SIZE*(BOARD_SIZE-row);	break;
		case 'b':	index = BOARD_SIZE*(BOARD_SIZE-row)+1; 	break;
		case 'c':	index = BOARD_SIZE*(BOARD_SIZE-row)+2; 	break;
		case 'd':	index = BOARD_SIZE*(BOARD_SIZE-row)+3; 	break;
		case 'e':	index = BOARD_SIZE*(BOARD_SIZE-row)+4; 	break;
		case 'f':	index = BOARD_SIZE*(BOARD_SIZE-row)+5; 	break;
		case 'g':	index = BOARD_SIZE*(BOARD_SIZE-row)+6; 	break;
		case 'h':	index = BOARD_SIZE*(BOARD_SIZE-row)+7; 	break;

	}

	return index;

}


/*returns the character to be played */
char getPlayer(char *board, char sc, int sr)
{
	int index = findIndex(sr, sc);

	char player = board[index];

	return player;
}

/*if character is white, returns 1 else 0*/
int isWhite(char currPlayer)
{
	int result=0;

	if (currPlayer>=65 && currPlayer<=90) 
		
	{
		result =1;
	}

	return result;
}

/*if character is black, returns 1 else 0*/
int isBlack(char currPlayer)
{
	int result=0;

	if (currPlayer>=97 && currPlayer<=122) 
		
	{
		result =1;
	}

	return result;
}


int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	int sourceIndex=0;
	int targetIndex=0;
	char player;
	int result=0;


	/*source index on board*/
	sourceIndex = findIndex(sr, sc);
	/*target index on board*/
	targetIndex = findIndex(tr, tc);

	player = getPlayer(board, sc, sr);

	/*if move is invalid, return 0*/
	if (!isPieceMovable(board, sc, sr, tc, tr))
	{
		result = 0;
	}

	/*if move is valid, return 2*/
	if (isPieceMovable(board, sc, sr, tc, tr))
	{
		result = 2;
		
	}

	/*king is in check return 3*/
	if (isPieceMovable(board, sc, sr, tc, tr) &&isInCheck(board)>=1)
	{

		result = 3;

	}

	/*king is in check return 1*/
	if (isInCheck(board)>= 1 && result ==3)
	{
		result = 1;
		
	}

	if (result==2)
	{
		board[sourceIndex]=' ';
		board[targetIndex]= player;
	}



	return result;
}


int isInCheck(char* board)
{
	int result=0;

	int bKingCheck1, bKingCheck2, bKingCheck3,
		bKingCheck4, bKingCheck5, bKingCheck6,
		bKingCheck7, bKingCheck8;

	int wKingCheck1, wKingCheck2, wKingCheck3,
		wKingCheck4, wKingCheck5, wKingCheck6,
		wKingCheck7, wKingCheck8;

	/*black king and white rook*/
	bKingCheck1 = checkTopAndBase(board, 'k' , 'R');

	/*black king and white rook*/
	bKingCheck2 =checkLeftAndRight(board,'k', 'R');

	/*white king and black rook*/
	wKingCheck1 = checkTopAndBase(board, 'K' , 'r');

	/*white king and black rook*/
	wKingCheck2 =checkLeftAndRight(board,'K', 'r');
	


	/*white king and black queen*/
	wKingCheck3 = checkTopAndBase(board, 'K' , 'q');

	/*white king and black queen*/
	wKingCheck4 = checkLeftAndRight(board,'K', 'q');

	/*white king and black queen*/
	wKingCheck5 = checkCross(board, 'K', 'q');



	/*black king and white queen*/
	bKingCheck3 = checkTopAndBase(board, 'k' , 'Q');

	/*black king and white queen*/
	bKingCheck4=checkLeftAndRight(board,'k', 'Q');
	
	/*black king and white queen*/
	bKingCheck5 = checkCross(board, 'k', 'Q');



	/*black king white bishop*/
	bKingCheck6 = checkCross(board, 'k', 'B');

	/*white king black bishop*/
	wKingCheck6 = checkCross(board, 'K', 'b');



	/*white king black pawn*/
	wKingCheck7 = checkPawn(board, 'K', 'p');

	/*black king white pawn*/
	bKingCheck7 = checkPawn(board, 'k', 'P');


	/*black king white knight*/
	bKingCheck8 = checkKnight(board,'k', 'N');

	/*white king black knight*/
	wKingCheck8 = checkKnight(board,'K', 'n');


	if (bKingCheck1 == 2 || bKingCheck2 == 2 || bKingCheck3 == 2 ||
		bKingCheck4 == 2 || bKingCheck5 == 2 || bKingCheck6 == 2 ||
		bKingCheck7 == 2 || bKingCheck8 == 2)
	{
		result = 2;
	}

	if (wKingCheck1 == 2 || wKingCheck2 == 2 || wKingCheck3 == 2 ||
		wKingCheck4 == 2 || wKingCheck5 == 2 || wKingCheck6 == 2 ||
		wKingCheck7 == 2 || wKingCheck8 == 2)
	{
		result = 1;
	}


	return result;
}

/*check the risks on the top and base*/
int checkTopAndBase(char *board, char king, char character)
{
	int i=0;
	int j=0;
	int k=0;
	int whereIsKing=0;
	int opponentCharacterIndex=0;
	int otherOpponentCharacterIndex=0;
	int result = 0;

	/*find king index*/
	while(board[i]!= king)
	{
		i++;
	}

	whereIsKing = i;


	/*find first character index*/
	while(board[j]!=character)
	{
		   j++;
	}

	opponentCharacterIndex = j;


	/*find second character index*/
	k = opponentCharacterIndex +1 ;

	while(board[k]!=character && k<=64)
	{
		k++;
	}

	otherOpponentCharacterIndex = k;



	/*for the first character*/
	/*if not found character dont do anything and return 0*/
	if (j!=0)
	{
		
		if (abs(whereIsKing- opponentCharacterIndex)%8 == 0)
		{
			/*if character is on top and king is base*/
			if (opponentCharacterIndex < whereIsKing )
			{
				
				for(i=whereIsKing-8; i>=opponentCharacterIndex; i-=8)
				{
					/*first found character, there is obstacle*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}
					/*first found character, there is not obstacle*/
					else
					{
						result =2;
					}
				}

			}

			/*if king is on top and character is base*/
			if (opponentCharacterIndex > whereIsKing)
			{
				for(i=whereIsKing+8 ; i<=opponentCharacterIndex; i+=8)
				{
					/*first found character, there is obstacle*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}
					/*first found character, there is not obstacle*/
					else
					{
						
						result =2;
					}
				}
			}
			
		}

	}

/*for the second character*/
/*if king is check at first character return 2 and dont do second character*/
	if(result!=2 && otherOpponentCharacterIndex<64)
	{
		if (abs(whereIsKing- otherOpponentCharacterIndex)%8 ==0)
		{

			/*if character is on top and king is down*/
			if (otherOpponentCharacterIndex< whereIsKing)
			{
				
				for(i= whereIsKing-8; i>= otherOpponentCharacterIndex; i-=8)
				{
					/*second found character, there is obstacle*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i=otherOpponentCharacterIndex+1;
					}

					/*second found character, there is not obstacle*/
					else
					{
						result =2;

					}
				}

			}

			/*if king is on top and character is down*/
			if (otherOpponentCharacterIndex > whereIsKing)
			{
				for(i= whereIsKing+8; i<= otherOpponentCharacterIndex; i+=8)
				{
					/*second found character, there is obstacle*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i=otherOpponentCharacterIndex+1;
					}
					/*second found character, there is not obstacle*/
					else
					{
						result =2;
					}
				}
			}
			
		}
	}


	return result;
}

/* check the risks on the left and right*/
int checkLeftAndRight(char *board, char king, char character)
{
	int i=0;
	int j=0;
	int k=0;
	int whereIsKing=0;
	int opponentCharacterIndex=0;
	int otherOpponentCharacterIndex=0;
	int result = 0;

	/*find king index*/
	while(board[i]!= king)
	{
		i++;
	}

	whereIsKing = i;
	

	/*find first character index*/
	while(board[j]!=character)
	{
		   j++;
	}

	opponentCharacterIndex = j;


	/*find second character index*/
	k = opponentCharacterIndex +1 ;

	while(board[k]!=character && k<=64)
	{
		k++;
	}

	otherOpponentCharacterIndex = k;



	/*for the first character*/
	/*if not found character dont do anything and return 0*/
	if (j!=0)
	{
		if (abs(whereIsKing - opponentCharacterIndex <=7 ))
		{
			if (opponentCharacterIndex > whereIsKing )
			{
				for (i = whereIsKing+1; i <= opponentCharacterIndex; ++i)
				{
					/*first found character, there is obstacle
					(character is right)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}

					/*first found character, there is not obstacle
					(character is right)*/
					else
					{
						result =2;
					}
				}
			}

			if (opponentCharacterIndex < whereIsKing )
			{
				for (i = whereIsKing-1; i >= opponentCharacterIndex; --i)
				{
					/*first found character, there is obstacle
					(character is left)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}

					/*first found character, there is not obstacle
					(character is left)*/
					else
					{
						result =2;
					}
				}
			}
		}
	}

	/*for the second character*/
	/*if king is check at first character return 2, dont do second character*/
	if (result!=2 && otherOpponentCharacterIndex<64)
	{
		if (abs(whereIsKing - otherOpponentCharacterIndex <=7 ))
		{
			if (otherOpponentCharacterIndex > whereIsKing )
			{
				for (i = whereIsKing+1; i <= otherOpponentCharacterIndex; ++i)
				{

					/*second found character, there is obstacle
					(character is right)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = otherOpponentCharacterIndex+1;
					}
					/*second found character, there is obstacle
					(character is right)*/
					else
					{
						result =2;
					}
				}
			}

			if (otherOpponentCharacterIndex < whereIsKing )
			{
				for (i = whereIsKing-1; i >= otherOpponentCharacterIndex; --i)
				{
					/*second found character, there is obstacle
					(character is left)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = otherOpponentCharacterIndex+1;
					}

					/*second found character, there is not obstacle
					(character is left)*/
					else
					{
						result =2;
					}
				}
			}
		}
	}



	return result;
}

/*check the risks on the cross*/
int checkCross(char *board, char king, char character)
{
	int i=0;
	int j=0;
	int k=0;
	int whereIsKing=0;
	int opponentCharacterIndex=0;
	int otherOpponentCharacterIndex=0;
	int result = 0;

	/*find king index*/
	while(board[i]!= king)
	{
		i++;
	}

	whereIsKing = i;
	

	/*find first character index*/
	while(board[j]!=character)
	{
		   j++;
	}

	opponentCharacterIndex = j;


	/*find second character index*/
	k = opponentCharacterIndex +1 ;

	while(board[k]!=character && k<=64)
	{
		k++;
	}

	otherOpponentCharacterIndex = k;

	/*for the first character*/
	/*if not found character dont do anything and return 0*/
	if (j!=0)
	{
		
		if (abs(whereIsKing- opponentCharacterIndex)%7 == 0)
		{
			/*if character is on top and king is down*/
			if (opponentCharacterIndex < whereIsKing )
			{
				
				for(i=whereIsKing-8+1; i>=opponentCharacterIndex; i-=7)
				{
					/*first found character, there is obstacle
					(character is top and right)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}

					/*second found character, there is not obstacle
					(character is top and right)*/
					else
					{
						result =2;
					}
				}

			}

			/*if king is on top and character is down*/
			if (opponentCharacterIndex > whereIsKing)
			{
				for(i=whereIsKing+8-1 ; i<=opponentCharacterIndex; i+=7)
				{
					/*first found character, there is obstacle
					(character is base and left)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}

					/*first found character, there is not obstacle
					(character is base and right)*/
					else
					{
						result =2;
					}
				}
			}
			
		}

		if (abs(whereIsKing- opponentCharacterIndex)%9 == 0)
		{
			
		
			/*if character is on top and king is down*/
			if (opponentCharacterIndex < whereIsKing )
			{
				
				for(i=whereIsKing-8-1; i>=opponentCharacterIndex; i-=9)
				{
					/*first found character, there is obstacle
					(character is top and left)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}

					/*first found character, there is not obstacle 
					(character is top and left)*/
					else
					{
						result =2;
					}
				}

			}

			/*if king is on top and character is down*/
			if (opponentCharacterIndex > whereIsKing)
			{
				for(i=whereIsKing+8+1 ; i<=opponentCharacterIndex; i+=9)
				{
					/*first found character, there is obstacle
					(character is base and right)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = opponentCharacterIndex+1;
					}

					/*first found character, there is not obstacle
					(character is base and right)*/
					else
					{
						result =2;
	
					}
				}
			}
		}	
		

	}

	/*for the second character*/
	/*if king is check at first character return 2, dont do second character*/
	if (result!=2 && otherOpponentCharacterIndex<64)
	{

		if (abs(whereIsKing- otherOpponentCharacterIndex)%7 == 0)
		{
			/*if character is on top and king is down*/
			if (otherOpponentCharacterIndex < whereIsKing )
			{
				
				for(i=whereIsKing-8+1; i>=otherOpponentCharacterIndex; i-=7)
				{
					/*second found character, there is obstacle
					(character is top and right)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = otherOpponentCharacterIndex+1;
					}

					/*second found character, there is not obstacle
					(character is top and right)*/
					else
					{
						result =2;
					}
				}

			}

			/*if king is on top and character is down*/
			if (otherOpponentCharacterIndex > whereIsKing)
			{
				for(i=whereIsKing+8-1 ; i<=otherOpponentCharacterIndex; i+=7)
				{
					/*second found character, there is obstacle
					(character is base and left)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = otherOpponentCharacterIndex+1;
					}

					/*second found character, there is not obstacle
					(character is base and left)*/
					else
					{
						result =2;
					}
				}
			}
			
		}

		if (abs(whereIsKing- otherOpponentCharacterIndex)%9 == 0)
		{
			
		
		/*if character is on top and king is down*/
			if (otherOpponentCharacterIndex < whereIsKing )
			{
				
				for(i=whereIsKing-8-1; i>=otherOpponentCharacterIndex; i-=9)
				{
					/*second found character, there is obstacle
					(character is top and left)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = otherOpponentCharacterIndex+1;
					}

					/*second found character, there is not obstacle
					(character is top and left)*/
					else
					{
						result =2;
					}
				}

			}

			/*if king is on top and character is down*/
			if (otherOpponentCharacterIndex > whereIsKing)
			{
				for(i=whereIsKing+8+1 ; i<=otherOpponentCharacterIndex; i+=9)
				{
					/*second found character, there is obstacle
					(character is base and right)*/
					if (board[i]!=' '&& board[i]!=character)
					{
						result = 0;
						i = otherOpponentCharacterIndex+1;
					}
					/*second found character, there is not obstacle
					(character is base and right)*/
					else
					{
						result =2;
					}
				}
			}
		}	
		

	}

	
	return result;

}
/*check the risks  which may come in pawn*/
int checkPawn(char *board, char king, char character)
{

	int result = 0;
	int i=0;
	int whereIsKing;

	while(board[i]!= king)
	{
		i++;
	}

	whereIsKing = i;
	if ((int)character == 'p')
	{

		/*black pawn white king
		right and top*/
		if (board[whereIsKing-7] == character)
		{
			result = 2;
		}

		else
		{
			result = 0;
		}

		/*black pawn white king
		left and top*/
		if (board[whereIsKing-9] == character)
		{	
			result = 2;
		}

		else
		{
			result = 0;
		}

	}

	if (character=='P')
	{

		/*white pawn black king
		left and base*/
		if (board[whereIsKing+7] == character)
		{
			result = 2;
		}

		else
		{
			result = 0;
		}


		/*white pawn black king
		right and base*/
		if (board[whereIsKing+9] == character)
		{	
			result = 2;
		}

		else
		{
			result = 0;
		}

	}

	return result;
}

/*check the risks  which may come in knight*/
int checkKnight(char *board, char king, char character)
{
	int i=0;
	int j=0;
	int k=0;
	int whereIsKing=0;
	int opponentCharacterIndex=0;
	int otherOpponentCharacterIndex=0;
	int result = 0;

	/*find king index*/
	while(board[i]!= king)
	{
		i++;
	}

	whereIsKing = i;
	

	/*find first character index*/
	while(board[j]!=character)
	{
		   j++;
	}

	opponentCharacterIndex = j;


	/*find second character index*/
	k = opponentCharacterIndex +1 ;

	while(board[k]!=character && k<=64)
	{
		k++;
	}

	otherOpponentCharacterIndex = k;


	/*for the first character*/
	/*if not found character dont do anything and return 0*/
	if (j!=0)
	{
		
		if (opponentCharacterIndex==0 ||opponentCharacterIndex==8||
			opponentCharacterIndex==16||opponentCharacterIndex==24||
			opponentCharacterIndex==32||opponentCharacterIndex==40||
			opponentCharacterIndex==48||opponentCharacterIndex==56)
		{
			/*if character is on top and king is down*/
			if (opponentCharacterIndex < whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==15 ||
					abs(opponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (opponentCharacterIndex > whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==17 ||
					abs(opponentCharacterIndex- whereIsKing)==10)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}

		if (opponentCharacterIndex==7 ||opponentCharacterIndex==15||
			opponentCharacterIndex==23||opponentCharacterIndex==31||
			opponentCharacterIndex==39||opponentCharacterIndex==47||
			opponentCharacterIndex==55||opponentCharacterIndex==63)
		{
			/*if character is on top and king is base*/
			if (opponentCharacterIndex < whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==10 ||
					abs(opponentCharacterIndex- whereIsKing)==17)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (opponentCharacterIndex > whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==15 ||
					abs(opponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}

		if (opponentCharacterIndex==1 ||opponentCharacterIndex==9||
			opponentCharacterIndex==17||opponentCharacterIndex==25||
			opponentCharacterIndex==33||opponentCharacterIndex==41||
			opponentCharacterIndex==49||opponentCharacterIndex==57)
		{
			/*if character is on top and king is base*/
			if (opponentCharacterIndex < whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (opponentCharacterIndex > whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==10)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}


		if (opponentCharacterIndex==6 ||opponentCharacterIndex==14||
			opponentCharacterIndex==22||opponentCharacterIndex==30||
			opponentCharacterIndex==38||opponentCharacterIndex==46||
			opponentCharacterIndex==54||opponentCharacterIndex==62)
		{
			/*if character is on top and king is on base*/
			if (opponentCharacterIndex < whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==10)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (opponentCharacterIndex > whereIsKing )
			{
				
				if (abs(opponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}

	}

	/*for the second character*/
	/*if king is check at first character return 2, dont do second character*/
	if (result!=2 && otherOpponentCharacterIndex<64)
	{
			if (otherOpponentCharacterIndex==0 ||otherOpponentCharacterIndex==8||
			otherOpponentCharacterIndex==16||otherOpponentCharacterIndex==24||
			otherOpponentCharacterIndex==32||otherOpponentCharacterIndex==40||
			otherOpponentCharacterIndex==48||otherOpponentCharacterIndex==56)
		{
			/*if character is on top and king is on base*/
			if (otherOpponentCharacterIndex < whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==15 ||
					abs(otherOpponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (otherOpponentCharacterIndex > whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==17 ||
					abs(otherOpponentCharacterIndex- whereIsKing)==10)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}

		if (otherOpponentCharacterIndex==7 ||otherOpponentCharacterIndex==15||
			otherOpponentCharacterIndex==23||otherOpponentCharacterIndex==31||
			otherOpponentCharacterIndex==39||otherOpponentCharacterIndex==47||
			otherOpponentCharacterIndex==55||otherOpponentCharacterIndex==63)
		{
			/*if character is on top and king is down*/
			if (otherOpponentCharacterIndex < whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==10 ||
					abs(otherOpponentCharacterIndex- whereIsKing)==17)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (otherOpponentCharacterIndex > whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==15 ||
					abs(otherOpponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}

		if (otherOpponentCharacterIndex==1 ||otherOpponentCharacterIndex==9||
			otherOpponentCharacterIndex==17||otherOpponentCharacterIndex==25||
			otherOpponentCharacterIndex==33||otherOpponentCharacterIndex==41||
			otherOpponentCharacterIndex==49||otherOpponentCharacterIndex==57)
		{
			/*if character is on top and king is down*/
			if (otherOpponentCharacterIndex < whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (otherOpponentCharacterIndex > whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==10)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}


		if (otherOpponentCharacterIndex==6 ||otherOpponentCharacterIndex==14||
			otherOpponentCharacterIndex==22||otherOpponentCharacterIndex==30||
			otherOpponentCharacterIndex==38||otherOpponentCharacterIndex==46||
			otherOpponentCharacterIndex==54||otherOpponentCharacterIndex==62)
		{
			/*if character is on top and king is down*/
			if (otherOpponentCharacterIndex < whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==10)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}

			/*if character is on base and king is top*/
			if (otherOpponentCharacterIndex > whereIsKing )
			{
				
				if (abs(otherOpponentCharacterIndex- whereIsKing)==6)
				{
					result =0;
				}
				else
				{
					result =1;
				}

			}


		}

	
	}
	return result;
}
/*---------------------------------------------------------------------------*/ 
/*								End of part1.c 								 */
/*---------------------------------------------------------------------------*/

