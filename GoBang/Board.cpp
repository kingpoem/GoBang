#include "Board.h"
#include "coordinate.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include<windows.h>

using namespace std;
Board::Board() : board(15, vector<int>(15, -1))
{
	//cout << "Board Chess创建成功" << endl;
	//构造函数初始化棋盘为-1，表示空；0表示玩家1黑子，1表示玩家2白子，2表示机器
}
void Board::color(int a)//改变颜色的函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void Board::show()
{
	extern Board Chess;
	system("cls");
	system("color 70");
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (Chess.board[i][j] == '0')
			{
				color(0x70);
				cout << " ●";
			}
			else if (Chess.board[i][j] == '1' || Chess.board[i][j] == '2')
			{
				color(0x7f);
				cout << " ●";
			}
			else
			{
				color(0x76);
				cout << " ■";
			}
		}
		color(0x70);
		cout << i;
		cout << endl;
	}
	color(0x70);
	cout << " 0 1 2 3 4 5 6 7 8 9 1011121314" << endl;
	color(0x70);
}


bool Board::judgewinner1(char a, coordinate temp)//判断横排
{
	extern Board Chess;
	coordinate begin, end;
	begin.x = end.x = temp.x;
	if (temp.y <= 5)begin.y = 0;
	else begin.y = temp.y - 4;
	if (temp.y >= N - 5)end.y = N - 1;
	else end.y = temp.y + 4;
	for (int i = begin.x, j = begin.y; j <= end.y - 4; ++j)
	{
		if (Chess.board[i][j] == a
			&& Chess.board[i][j] == Chess.board[i][j + 1]
			&& Chess.board[i][j + 1] == Chess.board[i][j + 2]
			&& Chess.board[i][j + 2] == Chess.board[i][j + 3]
			&& Chess.board[i][j + 3] == Chess.board[i][j + 4])
			return 1;
	}
	return 0;
}
bool Board::judgewinner2(char a, coordinate temp)//判断竖排
{
	extern Board Chess;
	coordinate begin, end;
	begin.y = end.y = temp.y;
	if (temp.x <= 5)begin.x = 0;
	else begin.x = temp.x - 4;
	if (temp.x >= N - 5)end.x = N - 1;
	else end.x = temp.x + 4;
	for (int i = begin.x, j = begin.y; i <= end.x - 4; ++i)
	{
		if (Chess.board[i][j] == a
			&& Chess.board[i][j] == Chess.board[i + 1][j]
			&& Chess.board[i + 1][j] == Chess.board[i + 2][j]
			&& Chess.board[i + 2][j] == Chess.board[i + 3][j]
			&& Chess.board[i + 3][j] == Chess.board[i + 4][j])
			return 1;
	}
	return 0;
}
bool Board::judgewinner3(char a, coordinate temp)//判断主对角线
{
	extern Board Chess;
	coordinate begin, end;
	if (temp.x <= 5)begin.x = 0;
	else begin.x = temp.x - 4;
	if (temp.y <= 5)begin.y = 0;
	else begin.y = temp.y - 4;
	if (temp.x >= N - 5)end.x = N - 1;
	else end.x = temp.x + 4;
	if (temp.y >= N - 5)end.y = N - 1;
	else end.y = temp.y + 4;
	for (int i = begin.x, j = begin.y; i <= end.x - 4 && j <= end.y - 4; ++i, ++j)
	{
		if (Chess.board[i][j] == a && Chess.board[i][j] == Chess.board[i + 1][j + 1]
			&& Chess.board[i + 1][j + 1] == Chess.board[i + 2][j + 2]
			&& Chess.board[i + 2][j + 2] == Chess.board[i + 3][j + 3]
			&& Chess.board[i + 3][j + 3] == Chess.board[i + 4][j + 4])
			return 1;
	}
	return 0;
}
bool Board::judgewinner4(char a, coordinate temp)//判断负对角线
{
	extern Board Chess;
	coordinate begin, end;
	if (temp.x <= 5)begin.x = 0;
	else begin.x = temp.x - 4;
	if (temp.y >= N - 5)begin.y = N - 1;
	else begin.y = temp.y + 4;
	if (temp.x >= N - 5)end.x = N - 1;
	else end.x = temp.x + 4;
	if (temp.y <= 5)end.y = 0;
	else end.y = temp.y - 4;
	for (int i = begin.x, j = begin.y; i <= end.x - 4 && j >= end.y - 4; ++i, --j)
	{
		if (Chess.board[i][j] == a
			&& Chess.board[i][j] == Chess.board[i + 1][j - 1]
			&& Chess.board[i + 1][j - 1] == Chess.board[i + 2][j - 2]
			&& Chess.board[i + 2][j - 2] == Chess.board[i + 3][j - 3]
			&& Chess.board[i + 3][j - 3] == Chess.board[i + 4][j - 4])
			return 1;
	}
	return 0;
}
