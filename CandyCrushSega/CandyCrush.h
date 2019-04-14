#pragma once
#include "Game.h"
#include "Candy.h"

class CandyContainer {
public:
	void SetCandy(Candy);
	Candy* GetCandy();
	void Update();

	CandyContainer* GetNext(Direction);
	void SetNext(CandyContainer*, Direction);

	void SetEmpty(bool);
	bool GetEmpty();
	int X, Y;
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
	int GetCandyColor(int, int);
	int GetCandySpecial(int, int);
private:
	CandyContainer** Board = nullptr;
	int** RawValues = nullptr;
	short SizeX = 6;
	short SizeY = 6;
};

static CandyCrush game;