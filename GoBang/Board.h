#pragma once
#include <vector>
#include "coordinate.h"
using namespace std;
extern const int N;
class Board
{
public:
	Board* p;
	vector<vector<int>> board;
	Board();//���캯��ԭ������
	bool judgewinner1(char a, coordinate temp);//�жϺ���
	bool judgewinner2(char a, coordinate temp);//�ж�����
	bool judgewinner3(char a, coordinate temp);//�ж����Խ���
	bool judgewinner4(char a, coordinate temp);//�жϸ��Խ���
	void show();//��ӡ����״̬
	void color(int a);
};