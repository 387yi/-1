#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#include"game.h"

void IntBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; i++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//1.��ӡһ������
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
			//��ӡ�ָ���
		if (i < row - 1) 
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void Xiaqi(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����£���");
	while (1)
	{
		printf("��ѡ��Ҫ�µ��к���");
		printf("��:  ��:");
		scanf("%d ,%d", &x, &y);
		if (x <= row && y<=col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else {
				printf("����ռ��");
			}
		}
		else
		{
			printf("�Ƿ���������������");
		}
	}
	DisplayBoard(board, ROW, COL);
}
void Dxiaqi(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����£���\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y]==' ')
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
		}
	}
	DisplayBoard(board, ROW, COL);
}
char shengfu(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] != ' ')
			return board[i][1];
		else if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[1][i] != ' ')
			return board[1][i];
		else if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
			return board[1][1];
		else if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
			return board[1][1];
		for (j = 0; j <= col; j++)
		{
			if (board[i][j]==' ')
			{
				return 'j';
			}
		}
	}

}