#pragma once
using namespace std;
class GameManager
{
public:
	int mode;//对战模式,0为人机对战，1为双人对战
	int& m = mode;
	void select_mode();//进行模式的选择，确定m
	void play_game(int& m);//主循环
};