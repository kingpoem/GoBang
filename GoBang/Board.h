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
	Board();//构造函数原型声明
	bool judgewinner1(char a, coordinate temp);//判断横排
	bool judgewinner2(char a, coordinate temp);//判断竖排
	bool judgewinner3(char a, coordinate temp);//判断主对角线
	bool judgewinner4(char a, coordinate temp);//判断副对角线
	void show();//打印棋盘状态
	void color(int a);
};