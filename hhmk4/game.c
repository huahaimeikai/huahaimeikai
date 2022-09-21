
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set; 
		}
	}
}



void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}



void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}




int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + 
		mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] + 
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';

}



void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{      
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入排查雷的坐标:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入！\n");

		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
	}
}















//void kz(char mine[ROWS][COLS], int x, int y)//用递归的扩展功能未成功！！！
//{
//	int k = 0;
//	int z = 0;
//	int m = 1;
//	
//	{
//		switch (m)
//		{
//		case 1:
//			mine[k][z] = mine[x - 1][y];
//		case 2:
//			mine[k][z] = mine[x - 1][y - 1];
//		case 3:
//			mine[k][z] = mine[x][y - 1];
//		case 4:
//			mine[k][z] = mine[x + 1][y - 1];
//		case 5:
//			mine[k][z] = mine[x + 1][y];
//		case 6:
//			mine[k][z] = mine[x + 1][y + 1];
//		case 7:
//			mine[k][z] = mine[x][y + 1];
//		case 8:
//			mine[k][z] = mine[x - 1][y + 1];
//		}
//
//	}
//
//
//
//
//
//
//
//	void mk(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//	{
//		int x = 0;
//		int y = 0;
//		int k = 0;
//		int z = 0;
//		while (mine[k][z] == '1' || mine[x][y] == '1')
//		{
//			if (mine[x][y] != '1' && mine[k][z] != '1')
//			{
//				int count = get_mine_count(mine, x, y);
//				show[x][y] = count + '0';
//				show[k][z] = count + '0';
//				DisplayBoard(show, row, col);
//			}
//			else
//			{
//				break;
//			}
//		}
//	}