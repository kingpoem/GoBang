#pragma once
using namespace std;
class GameManager
{
public:
	int mode;//��սģʽ,0Ϊ�˻���ս��1Ϊ˫�˶�ս
	int& m = mode;
	void select_mode();//����ģʽ��ѡ��ȷ��m
	void play_game(int& m);//��ѭ��
};