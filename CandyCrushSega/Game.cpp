#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "Game.h"
#include "CandyCrush.h"

int MoveCounter = 0;

void Initialize() {
	std::srand(time(0));
	Restart();
}

void Restart() {
	MoveCounter = 0;
	game = CandyCrush();
}

void ConnectRenderer(void (*f)()) {
	RenderApplication = f;
}

void ConnectAwardPoints(void (*f)(int)) {
	AwardPoints = f;
}

void AppRenderApplication(){
	if (AppRenderApplication != NULL) {
		RenderApplication();
		game.RenderBoard();
	} else {
		std::cout << "Connection: Failed to render." << std::endl;
	}
}

void AppAwardPoints(int points) {
	if (AppRenderApplication != NULL) {
		AwardPoints(points);
	} else {
		std::cout << "Connection: Failed to award points." << std::endl;
	}
}

void CandyMove(int x, int y, int dir) {
	MoveCounter++;
	std::cout << "Move ============ (" << MoveCounter << ") ============" << std::endl;
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
	std::cout << "End Move ============ (" << MoveCounter << ") ============" << std::endl;
	RenderApplication();
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