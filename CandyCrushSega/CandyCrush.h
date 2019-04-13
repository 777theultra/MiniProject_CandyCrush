#pragma once
#include "Candy.h"

enum Direction : unsigned short { Up, Down, Left, Right };

class CandyCrush {
public:
	CandyCrush();
	~CandyCrush();
	void RenderBoard();
	void CandySwap(Candy*, Candy*);
	void CandyMove(int, int, Direction);
	int GetCandyColor(int, int);
	int GetCandySpecial(int, int);
private:
	Candy** Board = nullptr;
	int** RawValues = nullptr;
	short SizeX = 6;
	short SizeY = 6;
};

