#include <iostream>
#include <cstdlib>
#include "CandyCrush.h"

CandyCrush::CandyCrush() {}

CandyCrush::CandyCrush(int x, int y) {
	if (x < 1 || y < 1) {
		std::cout << "Board size out of bounds." << std::endl;
		return;
	}
	SizeX = x;
	SizeY = y;
	Initialized = true;
}

CandyCrush::~CandyCrush() {
	delete[] Board;
}

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

void CandyCrush::Initialize() {
	delete[] Board;
	Board = new Candy * [SizeY];
	for (int y = 0; y < SizeY; y++) {
		Board[y] = new Candy[SizeX];
		for (int x = 0; x < SizeX; x++) {
			Board[y][x] = Candy();
		}
	}
	Initialized = true;
}

bool CandyCrush::IsInitialized() {
	return Initialized;
}
