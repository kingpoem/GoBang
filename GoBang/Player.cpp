#include "Player.h"
#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;
extern Board Chess;
coordinate Player::playchess1()  //玩家一下棋
{
	cout << "请玩家一输入坐标(坐标为整数):" << endl;
	double x1,z1;
	while (cin >> x1 >> z1)
	{
		if (x1 > N - 1 || z1 > N - 1 || x1 < 0 || z1 < 0)
		{
			cout << "输入超界，请从新输入" << endl;
			continue;
		}
		if (Chess.board[x1][z1] == -1) {
			Chess.board[x1][z1] = '0';//0表示玩家1黑子
			break;
		}
		else
		{
			cout << "输入错误,请重新输入";
		}
	}
	coordinate temp;
	temp.x = x1;
	temp.y = z1;
	return temp;
}
coordinate Player::playchess2()  //玩家二下棋
{

	cout << "请玩家二输入坐标(坐标为整数):" << endl;
	double x2, z2;
	while (cin >> x2 >> z2)
	{
		if (Chess.board[x2][z2] == -1) {
			Chess.board[x2][z2] = '1';//1表示玩家2白子
			break;
		}
		else
		{
			cout << "输入错误,请重新输入";
		}
	}
	coordinate temp;
	temp.x = x2;
	temp.y = z2;
	return temp;
}