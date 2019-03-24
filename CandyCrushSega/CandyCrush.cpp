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
	std::vector<std::vector<Candy>> empty;
	Board.swap(empty);
}

void CandyCrush::RenderBoard() {
	std::cout << std::endl;
	for (int y = 0; y < Board.size(); y++) {
		for (int x = 0; x < Board[y].size(); x++) {
			Candy& candy = Board[y][x];
			std::cout << candy.GetColor() << (candy.GetSpecial() == 0 ? "" : "*") << "\t";
		}
		std::cout << std::endl;
	}
}

void CandyCrush::Initialize() {
	for (int y = 0; y < SizeY; y++) {
		Board.push_back(std::vector<Candy>());
		for (int x = 0; x < SizeX; x++) {
			Board[y].push_back(Candy());
		}
	}
	Initialized = true;
}

bool CandyCrush::IsInitialized() {
	return Initialized;
}
