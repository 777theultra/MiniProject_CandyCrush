#include <iostream>
#include <cstdlib>
#include "CandyCrush.h"
#include "Game.h"

CandyContainer::CandyContainer() {}

CandyContainer::~CandyContainer() {}

void CandyContainer::SetCandy(Candy candy) {
	CandyObject = candy;
}

Candy CandyContainer::GetCandy() {
	return CandyObject;
}

CandyContainer* CandyContainer::GetNext(Direction dir) {
	switch (dir) {
	case Up:
		return NextUp;
	case Down:
		return NextDown;
	case Left:
		return NextLeft;
	case Right:
		return NextRight;
	}
	return nullptr;
}

void CandyContainer::SetNext(CandyContainer* container, Direction dir) {
	switch (dir) {
	case Up:
		NextUp = container;
		break;
	case Down:
		NextDown = container;
		break;
	case Left:
		NextLeft = container;
		break;
	case Right:
		NextRight = container;
		break;
	}
}

CandyCrush::CandyCrush() {
	Board = new CandyContainer * [SizeY];
	for (int y = 0; y < SizeY; y++) {
		Board[y] = new CandyContainer[SizeX];
		for (int x = 0; x < SizeX; x++) {
			Board[y][x] = CandyContainer();
			Board[y][x].SetCandy(Candy());
			if (x - 1 >= 0) {
				CandyContainer* c = &Board[y][x - 1];
				Board[y][x].SetNext(c, Left);
				c->SetNext(&Board[y][x], Right);
			}
			if (y - 1 >= 0) {
				CandyContainer* c = &Board[y - 1][x];
				Board[y][x].SetNext(c, Up);
				c->SetNext(&Board[y][x], Down);
			}
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
			Candy* candy = &Board[y][x].GetCandy();
			std::cout << candy->GetColor() << (candy->GetSpecial() == 0 ? "" : "*") << "\t";
		}
		std::cout << std::endl;
	}
}

void CandyCrush::CandyScan(CandyContainer subject) {
	CandyContainer* c = &subject;

	std::cout << "[UP]";
	while (c != nullptr) {
		std::cout << "[" << c->GetCandy().GetColor() << "]";
		c = c->GetNext(Up);
		if (c != nullptr) { std::cout << "->"; }
	};
	std::cout << std::endl;
	std::cout << "[Down]";
	while (c != nullptr) {
		std::cout << "[" << c->GetCandy().GetColor() << "]";
		c = c->GetNext(Down);
		if (c != nullptr) { std::cout << "->"; }
	};
	std::cout << std::endl;
	std::cout << "[Left]";
	while (c != nullptr) {
		std::cout << "[" << c->GetCandy().GetColor() << "]";
		c = c->GetNext(Left);
		if (c != nullptr) { std::cout << "->"; }
	};
	std::cout << std::endl;
	std::cout << "[Right]";
	while (c != nullptr) {
		std::cout << "[" << c->GetCandy().GetColor() << "]";
		c = c->GetNext(Right);
		if (c != nullptr) { std::cout << "->"; }
	};
	std::cout << std::endl;
}

void CandyCrush::CandySwap(CandyContainer* a, CandyContainer* b) {
	std::cout << "A: " << a->GetNext(Up) << "," << a->GetNext(Down) << "," << a->GetNext(Left) << "," << a->GetNext(Right) << "," << std::endl;
	std::cout << "B: " << b->GetNext(Up) << "," << b->GetNext(Down) << "," << b->GetNext(Left) << "," << b->GetNext(Right) << "," << std::endl;

	Candy tempA = a->GetCandy();
	a->SetCandy(b->GetCandy());
	b->SetCandy(tempA);

	std::cout << "A: " << a->GetNext(Up) << "," << a->GetNext(Down) << "," << a->GetNext(Left) << "," << a->GetNext(Right) << "," << std::endl;
	std::cout << "B: " << b->GetNext(Up) << "," << b->GetNext(Down) << "," << b->GetNext(Left) << "," << b->GetNext(Right) << "," << std::endl;

	if (RenderApplication != NULL) {
		RenderApplication();
	} else {
		std::cout << "Render application failed." << std::endl;
	}
}

void CandyCrush::CandyMove(int x, int y, Direction dir) {
	if (x < 0 || y < 0 || x > SizeX || y > SizeY) {
		std::cout << "Input corrdinates out of bounds." << std::endl;
		return;
	}
	CandyContainer* selection = &Board[y][x];
	CandyContainer* target = nullptr;

	std::cout << "Moving Selection's Candy (" << selection->GetCandy().GetColor() << ")";

	switch (dir) {
	case Up:
		if (y - 1 >= 0) {
			target = &Board[y - 1][x];
			std::cout << " Target (" << x << "," << y - 1 << ") (" << target->GetCandy().GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved up." << std::endl;
		}
		break;
	case Down:
		if (y + 1 < SizeY) {
			target = &Board[y + 1][x];
			std::cout << " Target (" << x << "," << y + 1 << ") (" << target->GetCandy().GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved down." << std::endl;
		}
		break;
	case Left:
		if (x - 1 >= 0) {
			target = &Board[y][x - 1];
			std::cout << " Target (" << x - 1 << "," << y << ") (" << target->GetCandy().GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved left." << std::endl;
		}
		break;
	case Right:
		if (x + 1 < SizeX) {
			target = &Board[y][x + 1];
			std::cout << " Target (" << x + 1 << "," << y << ") (" << target->GetCandy().GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved right." << std::endl;
		}
		break;
	}
	if (selection != nullptr && target != nullptr) {
		CandySwap(selection, target);
	}
}

CandyContainer* CandyCrush::GetCandyContainer(int x, int y) {
	return &Board[y][x];
}

int CandyCrush::GetCandyColor(int x, int y) {
	return Board[y][x].GetCandy().GetColor();
}

int CandyCrush::GetCandySpecial(int x, int y) {
	return Board[y][x].GetCandy().GetSpecial();
}

