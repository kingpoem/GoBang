#include<iostream>
#include "GameManager.h"
#include "Board.h"
#include "Player.h"

using namespace std;
const int N = 15;
Board Chess;

int main() {
	GameManager game;
	game.select_mode();
	Chess.show();
	game.play_game(game.m);
	return 0;
}
