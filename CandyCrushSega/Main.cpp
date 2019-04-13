#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "CandyCrush.h"

/*
	Note: Set project as exe and start up project in order to run exe.
	Usage:
		Input: cmd inputX inputY

	Commands:
		"quit" - exit app.
		"move X Y [w, a, s, d]" - moves candy in a direction. e.g "move 1 2 w"
		"restart" - regenerate board.
*/

int main() {
	std::srand(time(0));

	CandyCrush game = CandyCrush();

	std::string cmd;
	int inputX, inputY;
	std::string dir;

	do {
		game.RenderBoard();
		std::cin >> cmd;
		if (cmd == "quit") { break; }
		if (cmd != "restart") {
			std::cin >> inputX >> inputY;
			if (!std::cin.fail()) {
				if (cmd == "move") {
					std::cin >> dir;
					if (dir == "w") {
						game.CandyMove(inputX, inputY, Up);
					} else if (dir == "a") {
						game.CandyMove(inputX, inputY, Left);
					} else if (dir == "s") {
						game.CandyMove(inputX, inputY, Down);
					} else if (dir == "d") {
						game.CandyMove(inputX, inputY, Right);
					}
				}
			} else {
				std::cin.clear();
				std::cin.ignore();
			}
		} else {
			std::cout << "Restarting game.." << std::endl;
			game = CandyCrush();
		}
	} while (true);

	return 0;
}