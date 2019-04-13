#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "Game.h"
#include "CandyCrush.h"

static CandyCrush game;

void Initialize() {
	std::srand(time(0));
	Restart();
}

void Restart() {
	game = CandyCrush();
	game.RenderBoard();
}

void CandyMove(int x, int y, int dir) {
	Direction direction;
	switch (dir) {
	case 1:
		direction = Up;
		break;
	case 2:
		direction = Down;
		break;
	case 3:
		direction = Left;
		break;
	case 4:
		direction = Right;
		break;
	default:
		std::cout << "Invalid dir value" << std::endl;
		break;
	}
	game.CandyMove(x, y, direction);
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