#pragma once
#include "Game.h"
#include "Candy.h"

class CandyContainer {
public:
	void SetCandy(Candy);
	Candy* GetCandy();

	CandyContainer* GetNext(Direction);
	void SetNext(CandyContainer*, Direction);

	void ApplyGravity();

	void SetEmpty(bool);
	bool GetEmpty();
	int X = -1, Y = -1;
private:
	bool IsEmpty = false;
	Candy CandyObject = Candy();
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
	void CandyScan(CandyContainer*);
	void CandySwap(CandyContainer*, CandyContainer*);
	void CandyMove(int, int, Direction);
	CandyContainer* GetCandyContainer(int, int);
	int GetRawCandy(int, int);
private:
	CandyContainer** Board = nullptr;
	int** RawValues = nullptr;
	short SizeX = 6;
	short SizeY = 6;
};

static CandyCrush game;