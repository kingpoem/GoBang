#include "Player.h"
#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;
extern Board Chess;
coordinate Player::playchess1()  //���һ����
{
	cout << "�����һ��������(����Ϊ����):" << endl;
	double x1,z1;
	while (cin >> x1 >> z1)
	{
		if (x1 > N - 1 || z1 > N - 1 || x1 < 0 || z1 < 0)
		{
			cout << "���볬�磬���������" << endl;
			continue;
		}
		if (Chess.board[x1][z1] == -1) {
			Chess.board[x1][z1] = '0';//0��ʾ���1����
			break;
		}
		else
		{
			cout << "�������,����������";
		}
	}
	coordinate temp;
	temp.x = x1;
	temp.y = z1;
	return temp;
}
coordinate Player::playchess2()  //��Ҷ�����
{

	cout << "����Ҷ���������(����Ϊ����):" << endl;
	double x2, z2;
	while (cin >> x2 >> z2)
	{
		if (Chess.board[x2][z2] == -1) {
			Chess.board[x2][z2] = '1';//1��ʾ���2����
			break;
		}
		else
		{
			cout << "�������,����������";
		}
	}
	coordinate temp;
	temp.x = x2;
	temp.y = z2;
	return temp;
}