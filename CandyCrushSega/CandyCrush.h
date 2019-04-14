#pragma once
#include "Candy.h"

class CandyContainer {
public:
	CandyContainer();
	~CandyContainer();
	void SetCandy(Candy);
	Candy GetCandy();
	CandyContainer* GetNext(Direction);
	void SetNext(CandyContainer*, Direction);
private:
	Candy CandyObject;
	CandyContainer* NextUp = nullptr;
	CandyContainer* NextDown = nullptr;
	CandyContainer* NextLeft = nullptr;
	CandyContainer* NextRight = nullptr;
};

class CandyCrush {
public:
	CandyCrush();
	~CandyCrush();
	void RenderBoard();
	void CandyScan(CandyContainer);
	void CandySwap(CandyContainer*, CandyContainer*);
	void CandyMove(int, int, Direction);
	CandyContainer* GetCandyContainer(int, int);
	int GetCandyColor(int, int);
	int GetCandySpecial(int, int);
private:
	CandyContainer** Board = nullptr;
	int** RawValues = nullptr;
	short SizeX = 6;
	short SizeY = 6;
};

