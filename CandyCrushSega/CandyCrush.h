#pragma once
#include <vector>
#include "Candy.h"

class CandyCrush {
public:
	CandyCrush();
	CandyCrush(int, int);
	~CandyCrush();
	void RenderBoard();
	void Initialize();
	bool IsInitialized();
private:
	bool Initialized = false;
	std::vector<std::vector<Candy>> Board;
	short SizeX = 1;
	short SizeY = 1;
};

