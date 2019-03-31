#pragma once
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
	Candy** Board;
	short SizeX = 1;
	short SizeY = 1;
};

