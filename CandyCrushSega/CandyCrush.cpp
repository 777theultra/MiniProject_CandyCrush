#include <iostream>
#include <cstdlib>
#include "CandyCrush.h"

CandyCrush::CandyCrush() {
	Board = new Candy * [SizeY];
	for (int y = 0; y < SizeY; y++) {
		Board[y] = new Candy[SizeX];
		for (int x = 0; x < SizeX; x++) {
			Board[y][x] = Candy();
		}
	}
}

CandyCrush::~CandyCrush() { /*Destructor*/ }

void CandyCrush::RenderBoard() {
	std::cout << std::endl;
	std::cout << "[+]\t";
	for (int x = 0; x < SizeX; x++) {
		std::cout << "[" << x << "]\t";
	}
	std::cout << std::endl;
	for (int y = 0; y < SizeY; y++) {
		for (int x = 0; x < SizeX; x++) {
			if (x == 0) {
				std::cout << "[" << y << "]\t";
			}
			Candy& candy = Board[y][x];
			std::cout << candy.GetColor() << (candy.GetSpecial() == 0 ? "" : "*") << "\t";
		}
		std::cout << std::endl;
	}
}

void CandyCrush::CandySwap(Candy* a, Candy* b) {
	Candy temp = *a;
	*a = *b;
	*b = temp;
}

void CandyCrush::CandyMove(int x, int y, Direction dir) {
	if (x < 0 || y < 0 || x > SizeX || y > SizeY) {
		std::cout << "Input corrdinates out of bounds." << std::endl;
		return;
	}
	Candy* selection = &Board[y][x];
	Candy* target = nullptr;

	std::cout << "Moving Selection (" << selection->GetColor() << ")";

	switch (dir) {
	case Up:
		if (y - 1 > 0) {
			target = &Board[y - 1][x];
			std::cout << " Target (" << x << "," << y - 1 << ") (" << target->GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved up." << std::endl;
		}
		break;
	case Down:
		if (y + 1 < SizeY) {
			target = &Board[y + 1][x];
			std::cout << " Target (" << x << "," << y + 1 << ") (" << target->GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved down." << std::endl;
		}
		break;
	case Left:
		if (x - 1 > 0) {
			target = &Board[y][x - 1];
			std::cout << " Target (" << x - 1 << "," << y << ") (" << target->GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved left." << std::endl;
		}
		break;
	case Right:
		if (x + 1 < SizeX) {
			target = &Board[y][x + 1];
			std::cout << " Target (" << x + 1 << "," << y << ") (" << target->GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved right." << std::endl;
		}
		break;
	}
	if (selection != nullptr && target != nullptr) {
		CandySwap(selection, target);
	}
}

int CandyCrush::GetCandyColor(int x, int y) {
	return Board[y][x].GetColor();
}

int CandyCrush::GetCandySpecial(int x, int y) {
	return Board[y][x].GetSpecial();
}
