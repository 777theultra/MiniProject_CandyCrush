#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "Game.h"
#include "CandyCrush.h"

static void (*RenderBoard)();
static CandyCrush game;

void Initialize() {
	std::srand(time(0));
	Restart();
}

void Restart() {
	game = CandyCrush();
	game.RenderBoard();
}

void ConnectRenderer(void (*renderFunc)()) {
	RenderBoard = renderFunc;
}

void CandyMove(int x, int y, int dir) {
	switch (dir) {
	case 1:
		game.CandyMove(x, y, Up);
		break;
	case 2:
		game.CandyMove(x, y, Down);
		break;
	case 3:
		game.CandyMove(x, y, Left);
		break;
	case 4:
		game.CandyMove(x, y, Right);
		break;
	default:
		std::cout << "Invalid dir value" << std::endl;
		break;
	}
	RenderBoard();
}

int GetCandyColor(int x, int y) {
	return game.GetCandyColor(x, y);
}

int GetCandySpecial(int x, int y) {
	return game.GetCandySpecial(x, y);
}

void DebugBoard() {
	game.RenderBoard();
}