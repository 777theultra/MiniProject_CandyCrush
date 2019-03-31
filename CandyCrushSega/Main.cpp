#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "CandyCrush.h"

/*
	Note: Set project as start up project in order to run exe.
	Usage:
		Input: cmd inputX inputY

	Commands:
		"quit" - exit app.
		""
*/
int main() {
	std::srand(time(0));

	CandyCrush game = CandyCrush(6, 6);
	game.Initialize();

	std::string cmd;
	int inputX, inputY;

	do {
		game.RenderBoard();
		std::cin >> cmd;
		if (cmd == "quit") { break; }
		std::cin >> inputX >> inputY;
		if (!std::cin.fail()) {
			
		} else {
			std::cin.clear();
			std::cin.ignore();
		}
	} while (true);

	std::cin.get();
	return 0;
}