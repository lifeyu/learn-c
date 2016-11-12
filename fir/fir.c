#include "fir.h"

void main()
{
	initGame();

	destroy();
}

void initGame(void)
{
	clearScreen();
	
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("*  Welcome to FIR (Five In A Row)  *\n");
		printf("*                                  *\n");
		printf("*                                  *\n");
		printf("* [1]  start            [2]  help  *\n");
		printf("*                                  *\n");
		printf("*                                  *\n");
		printf("* [0]  quit                        *\n");
		printf("*                                  *\n");
		printf("*                                  *\n");
		printf("************************************\n");
		printf("请选择:>");
		scanf("%d", &select);

		if (select == 0) break;

		switch (select)
		{
		case 1:
			clearScreen();
			printChessboard();
			playChess();
			break;	
		case 2:
			break;
		default:
			printf("对不起, 您输入的选择错误, 请重新输入.");
			break;
		}
	}
}

void printChessboard(void)
{
	for (int row = 0; row <= N; row++)
	{
		for (int col = 0; col <= N; col++)
		{
			if (0 == row) 
				printf("%3d", col);	
			else if (0 == col)
				printf("%3d", row);
			else if (1 == chessboard[row][col])
				printf("  ●");
			else if (2 == chessboard[row][col])
				printf("  ○");
			else
				printf("  *");
		}	

		printf("\n");
	}
}

void playChess()
{
	while (1)
	{
	
		whoseTurn++;	// 实现玩家轮流落子

		int row;
		int col;

		// 玩家1落子
		if (1 == whoseTurn % 2)
		{
			checkMove(&row, &col, 1);
		}
		// 玩家2落子
		else
		{
			checkMove(&row, &col, 2);
		}

		clearScreen();
		printChessboard();

		if (judge(row, col))
		{
			if (1 == whoseTurn % 2)
				printf("玩家1胜.\n");	
			else
				printf("玩家2胜.\n");	

			printf("please enter Y/y (restart game) / N/n (exit game) : ");
			char enter;
			scanf("%s", &enter);

			if (enter == 'Y' || enter == 'y')
			{
				clearGame();
				break;
			}
			else
			{
				exit(0);
			}
		}

	}
}

void checkMove(int * row, int * col, int chessPieces)
{
	while (1)
	{
		int tempRow;
		int tempCol;

		printf("当前落子玩家：玩家%d, 请输入落子的位置, 格式为 行号 + 空格 + 列号:", chessPieces);
		scanf("%d %d", &tempRow, &tempCol);

		if (tempRow >= 1 && tempRow <= N + 1
			&& tempCol >= 1 && tempCol <= N + 1)
		{

			// 判断对应位置是否已经落子
			if (chessboard[tempRow][tempCol] != 0)
			{
				clearScreen();
				printChessboard();
				printf("对不起, 您输入的行号, 列号对应的位置已经落过子, 请重新输入.\n");
			}
			else
			{
				*row = tempRow;
				*col = tempCol;
				break;
			}

		}
		else
		{
			clearScreen();
			printChessboard();
			printf("对不起, 您输入的行号, 列号有错误, 请重新输入.\n");
		}
	}

	chessboard[*row][*col] = chessPieces;
}

int judge(int row, int col)
{
	int rule = 4;
	int t = 2 - whoseTurn % 2;

	// 判断横向
	for (int i = row - rule, j = col; i <= row; i++)
	{
		if (i >= 1 && i <= N - rule 
			&& t == chessboard[i][j]
			&& t == chessboard[i + 1][j]
			&& t == chessboard[i + 2][j]
			&& t == chessboard[i + 3][j]
			&& t == chessboard[i + 4][j])
			return 1;	
	}


	// 判断纵向
	for (int i = row, j = col - rule; j <= col; j++)
	{
		if (j >= 1 && j <= N - rule
			&& t == chessboard[i][j]
			&& t == chessboard[i][j + 1]
			&& t == chessboard[i][j + 2]
			&& t == chessboard[i][j + 3]
			&& t == chessboard[i][j + 4])	
			return 1;
	}

	// 判断左斜向
	for (int i = row - rule, j = col - rule; i <= row, j <= col; i++, j++)
	{
		if (i >= 1 && i <= N - rule && j >= 1 && j <= N - rule
			&& t == chessboard[i][j]
			&& t == chessboard[i + 1][j + 1]
			&& t == chessboard[i + 2][j + 2]
			&& t == chessboard[i + 3][j + 3]
			&& t == chessboard[i + 4][j + 4])	
			return 1;
	}

	// 判断右斜向
	for (int i = row + rule, j = col - rule; i >= 1, j <= col; i--, j++)
	{
		if (i >= 1 && i <= N - rule && j >= 1 && j <= N - rule
			&& t == chessboard[i][j]
			&& t == chessboard[i - 1][j + 1]
			&& t == chessboard[i - 2][j + 2]
			&& t == chessboard[i - 3][j + 3]
			&& t == chessboard[i - 4][j + 4])	
			return 1;
	}

	return 0;
}

void clearGame()
{
	// 清空数组
	memset(chessboard, 0, sizeof(chessboard));
	// 重置落子方判断标识
	whoseTurn = 0;
	// 清除游戏棋盘
	clearScreen();
}

void destroy()
{

}

void clearScreen()
{
	system("clear");
}
