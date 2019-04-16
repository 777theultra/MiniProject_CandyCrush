#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "Game.h"
#include "CandyCrush.h"

int MoveCounter = 0;
bool GameReady = false;

void Initialize() {
	std::srand(time(0));
	Restart();
}

void Restart() {
	MoveCounter = 0;
	GameReady = false;
	game = CandyCrush();
	GameReady = true;
}

void ConnectRenderer(void (*f)()) {
	RenderApplication = f;
}

void ConnectAwardPoints(void (*f)(int)) {
	AwardPoints = f;
}

void ConnectObjectiveComplete(void (*f)(int)) {
	ObjectiveComplete = f;
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
		if (GameReady) {
			AwardPoints(points);
		}
	} else {
		std::cout << "Connection: Failed to award points." << std::endl;
	}
}

void AppSetObjectiveCompleted(int id) {
	if (AppSetObjectiveCompleted != NULL) {
		ObjectiveComplete(id);
	} else {
		std::cout << "Connection: Failed to set complete for objective " << id <<"." << std::endl;
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

int GetCandy(int x, int y) {
	return game.GetRawCandy(x, y);
}

int GetObjectiveBColor() {
	return game.ObjectiveBColor;
}

int GetObjectiveBAmount() {
	return game.GetObjectiveBAmount();
}

int GetObjectiveDCombo() {
	return game.ObjectiveDCombo;
}

int GetObjectiveDAmount() {
	return game.GetObjectiveDAmount();
}

void DebugBoard() {
	game.RenderBoard();
}