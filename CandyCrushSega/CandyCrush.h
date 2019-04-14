#pragma once
#include "Candy.h"

class CandyCrush {
public:
	CandyCrush();
	~CandyCrush();
	void RenderBoard();
	void CandySwap(Candy*, Candy*);
	void CandyMove(int, int, Direction);
	Candy* GetCandy(int, int);
	int GetCandyColor(int, int);
	int GetCandySpecial(int, int);
private:
	Candy** Board = nullptr;
	int** RawValues = nullptr;
	short SizeX = 6;
	short SizeY = 6;
};

