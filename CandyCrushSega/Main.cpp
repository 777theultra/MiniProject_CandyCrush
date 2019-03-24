#include <iostream>
#include <cstdlib>
#include <time.h>

#include "CandyCrush.h"

/*
	Note: Set project as start up project inorder to run exe.
	Usage:
		Input: SizeX SizeY
		Generates a board with a width of SizeX and height of SizeY;
*/
int main() {
	std::srand(time(0));

	int sizeX, sizeY;
	std::cin >> sizeX >> sizeY;

	CandyCrush game = CandyCrush(sizeX, sizeY);
	game.Initialize();
	game.RenderBoard();

	std::cin.get();
	return 0;
}