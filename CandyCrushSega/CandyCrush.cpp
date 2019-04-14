#include <iostream>
#include <cstdlib>
#include "CandyCrush.h"

void CandyContainer::SetCandy(Candy candy) {
	CandyObject = candy;
}

Candy* CandyContainer::GetCandy() {
	return &CandyObject;
}

void CandyContainer::Update() {
	game.RenderBoard();
	if (IsEmpty) {
		if (NextUp != nullptr && !NextUp->IsEmpty) {
			game.CandySwap(this, NextUp);
		} else {
			CandyObject = Candy();
			IsEmpty = false;
		}
	} else {
		if (NextDown != nullptr && NextDown->IsEmpty) {
			game.CandySwap(this, NextDown);
		}
	}
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

void CandyContainer::SetEmpty(bool empty) {
	IsEmpty = empty;
}

bool CandyContainer::GetEmpty() {
	return IsEmpty;
}

CandyCrush::CandyCrush() {
	Board = new CandyContainer * [SizeY];
	for (int y = 0; y < SizeY; y++) {
		Board[y] = new CandyContainer[SizeX];
		for (int x = 0; x < SizeX; x++) {
			Board[y][x] = CandyContainer();
			Board[y][x].Y = y;
			Board[y][x].X = x;
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
			if (Board[y][x].GetEmpty()) {
				std::cout << "X" << "\t";
			} else {
				Candy* candy = Board[y][x].GetCandy();
				std::cout << candy->GetColor() << (candy->GetSpecial() == 0 ? "" : "*") << "\t";
			}
		}
		std::cout << std::endl;
	}
}

void CandyCrush::CandyScan(CandyContainer* subject) {
	CandyContainer* c = subject;
	CandyContainer* vContainers[6] = {};
	CandyContainer* hContainers[6] = {};
	int h = 0, v = 0;

	//std::cout << "[Up]:  ";
	do {
		if (c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
			//std::cout << " [" << c->GetCandy()->GetColor() << "]";
			vContainers[v] = c;
			v++;
		} else {
			break;
		}
		c = c->GetNext(Up);
	} while (c != nullptr);

	c = subject->GetNext(Down);
	//std::cout << " [Down]: ";
	while (c != nullptr) {
		if (c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
			//std::cout << " [" << c->GetCandy()->GetColor() << "]";
			vContainers[v] = c;
			v++;
		} else {
			break;
		}
		c = c->GetNext(Down);
	};
	//std::cout << std::endl;

	c = subject;
	//std::cout << "[Left]:  ";
	do {
		if (c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
			//std::cout << " [" << c->GetCandy()->GetColor() << "]";
			hContainers[h] = c;
			h++;
		} else {
			break;
		}
		c = c->GetNext(Left);
	} while (c != nullptr);

	c = subject->GetNext(Right);
	//std::cout << " [Right]: ";
	while (c != nullptr) {
		if (c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
			//std::cout << " [" << c->GetCandy()->GetColor() << "]";
			hContainers[h] = c;
			h++;
		} else {
			break;
		}
		c = c->GetNext(Right);
	};
	//std::cout << std::endl;

	if (h > 2) {
		std::cout << "Horizontal chain found: " << h << std::endl;
		for (int x = 0; x < h; x++) {
			if (hContainers[x] != NULL) {
				hContainers[x]->SetEmpty(true);
				hContainers[x]->Update();
			}
		}
		if (AwardPoints != NULL) {
			AwardPoints(1 * (h - 2));
			std::cout << "Successfully to awarded points." << std::endl;
		} else {
			std::cout << "Failed to award points." << std::endl;
		}
	}
	if (v > 2) {
		std::cout << "Vertical chain found: " << h << std::endl;
		for (int y = 0; y < v; y++) {
			if (vContainers[y] != NULL) {
				vContainers[y]->SetEmpty(true);
				vContainers[y]->Update();
			}
		}
		if (AwardPoints != NULL) {
			AwardPoints(1 * (v - 2));
			std::cout << "Successfully to awarded points." << std::endl;
		} else {
			std::cout << "Failed to award points." << std::endl;
		}
	}
}

void CandyCrush::CandySwap(CandyContainer* a, CandyContainer* b) {
	Candy tempA = *(a->GetCandy());
	bool tempBool = a->GetEmpty();
	a->SetCandy(*(b->GetCandy()));
	a->SetEmpty(b->GetEmpty());
	b->SetCandy(tempA);
	b->SetEmpty(tempBool);
	
	if (!b->GetEmpty()) {
		CandyScan(b);
	} else {
		b->Update();
	}
	if (!a->GetEmpty()) {
		CandyScan(a);
	} else {
		a->Update();
	}
}

void CandyCrush::CandyMove(int x, int y, Direction dir) {
	if (x < 0 || y < 0 || x > SizeX || y > SizeY) {
		std::cout << "Input corrdinates out of bounds." << std::endl;
		return;
	}
	CandyContainer* selection = &Board[y][x];
	CandyContainer* target = nullptr;

	std::cout << "Moving Selection's Candy (" << selection->GetCandy()->GetColor() << ")";

	switch (dir) {
	case Up:
		if (y - 1 >= 0) {
			target = &Board[y - 1][x];
			std::cout << " Target (" << x << "," << y - 1 << ") (" << target->GetCandy()->GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved up." << std::endl;
		}
		break;
	case Down:
		if (y + 1 < SizeY) {
			target = &Board[y + 1][x];
			std::cout << " Target (" << x << "," << y + 1 << ") (" << target->GetCandy()->GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved down." << std::endl;
		}
		break;
	case Left:
		if (x - 1 >= 0) {
			target = &Board[y][x - 1];
			std::cout << " Target (" << x - 1 << "," << y << ") (" << target->GetCandy()->GetColor() << ")" << std::endl;
		} else {
			std::cout << " Candy can not be moved left." << std::endl;
		}
		break;
	case Right:
		if (x + 1 < SizeX) {
			target = &Board[y][x + 1];
			std::cout << " Target (" << x + 1 << "," << y << ") (" << target->GetCandy()->GetColor() << ")" << std::endl;
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
	return Board[y][x].GetCandy()->GetColor();
}

int CandyCrush::GetCandySpecial(int x, int y) {
	return Board[y][x].GetCandy()->GetSpecial();
}

