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

void DebugBoard() {
	game.RenderBoard();
}

int GetCandyColor(int x, int y) {
	return game.GetCandyColor(x, y);
}

int GetCandySpecial(int x, int y) {
	return game.GetCandySpecial(x, y);
}