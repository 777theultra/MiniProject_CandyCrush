#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "CandyCrush.h"

using namespace std::chrono_literals;

void CandyContainer::SetCandy(Candy candy) {
	CandyObject = candy;
}

Candy* CandyContainer::GetCandy() {
	return &CandyObject;
}

void CandyContainer::Update() {
	if (NextDown != nullptr) {
		if (NextDown->IsEmpty) {
			game.CandySwap(this, NextDown);
			if (IsEmpty && NextUp == nullptr) {
				CandyObject = Candy();
				IsEmpty = false;
			}
			NextDown->Update();
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

void CandyContainer::ApplyGravity() {
	if (IsEmpty) {
		CandyContainer* nextNonEmpty = NextUp;
		if (nextNonEmpty != nullptr) {
			do {
				if (nextNonEmpty->IsEmpty) {
					if (nextNonEmpty->NextUp != nullptr) {
						nextNonEmpty = nextNonEmpty->NextUp;
					} else {
						nextNonEmpty->SetCandy(Candy());
						nextNonEmpty->SetEmpty(false);
					}
				}
			} while (nextNonEmpty->IsEmpty);
			game.CandySwap(this, nextNonEmpty);
		} else {
			CandyObject = Candy();
			IsEmpty = false;
		}
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
				std::cout << game.GetRawCandy(x, y) << "\t";
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
				if (hContainers[x]->GetCandy()->GetSpecial() == Striped) {
					for (int a = 0; a < SizeX; a++) {
						Board[hContainers[x]->Y][a].SetEmpty(true);
					}
					std::cout << "Combo P wiping row " << hContainers[x]->Y << std::endl;
				}
			}
		}
		if (h == 4) {
			std::cout << "Combo P found: " << h << std::endl;
			subject->SetEmpty(false);
			subject->GetCandy()->SetSpecial(Striped);
		}
		AppAwardPoints(1 * (h - 2));
	}
	if (v > 2) {
		std::cout << "Vertical chain found: " << h << std::endl;
		for (int y = 0; y < v; y++) {
			if (vContainers[y] != NULL) {
				vContainers[y]->SetEmpty(true);
				if (vContainers[y]->GetCandy()->GetSpecial() == Striped) {
					for (int a = 0; a < SizeX; a++) {
						Board[vContainers[y]->Y][a].SetEmpty(true);
					}
					std::cout << "Combo P wiping row " << vContainers[y]->Y << std::endl;
				}
			}
		}
		if (v == 4) {
			std::cout << "Combo P found: " << v << std::endl;
			subject->SetEmpty(false);
			subject->GetCandy()->SetSpecial(Striped);
		}
		AppAwardPoints(1 * (v - 2));
	}
}

void CandyCrush::CandySwap(CandyContainer* a, CandyContainer* b) {
	Candy tempA = *(a->GetCandy());
	bool tempBool = a->GetEmpty();
	a->SetCandy(*(b->GetCandy()));
	a->SetEmpty(b->GetEmpty());
	b->SetCandy(tempA);
	b->SetEmpty(tempBool);
}

void CandyCrush::CandyMove(int x, int y, Direction dir) {
	if (x < 0 || y < 0 || x > SizeX || y > SizeY) {
		std::cout << "Input corrdinates out of bounds." << std::endl;
		return;
	}
	CandyContainer* selection = &Board[y][x];
	CandyContainer* target = nullptr;

	std::cout << "Moving Candy (" << x << "," << y << ") [" << selection->GetCandy()->GetColor() << "]";

	switch (dir) {
	case Up:
		if (y - 1 >= 0) {
			target = &Board[y - 1][x];
			std::cout << " to (" << x << "," << y - 1 << ") [" << target->GetCandy()->GetColor() << "]" << std::endl;
		} else {
			std::cout << " Candy can not be moved up." << std::endl;
		}
		break;
	case Down:
		if (y + 1 < SizeY) {
			target = &Board[y + 1][x];
			std::cout << " to (" << x << "," << y + 1 << ") [" << target->GetCandy()->GetColor() << "]" << std::endl;
		} else {
			std::cout << " Candy can not be moved down." << std::endl;
		}
		break;
	case Left:
		if (x - 1 >= 0) {
			target = &Board[y][x - 1];
			std::cout << " to (" << x - 1 << "," << y << ") [" << target->GetCandy()->GetColor() << "]" << std::endl;
		} else {
			std::cout << " Candy can not be moved left." << std::endl;
		}
		break;
	case Right:
		if (x + 1 < SizeX) {
			target = &Board[y][x + 1];
			std::cout << " to (" << x + 1 << "," << y << ") [" << target->GetCandy()->GetColor() << "]" << std::endl;
		} else {
			std::cout << " Candy can not be moved right." << std::endl;
		}
		break;
	}
	if (selection != nullptr && target != nullptr) {
		CandySwap(selection, target);

		if (!selection->GetEmpty()) {
			CandyScan(selection);
		}
		if (!target->GetEmpty()) {
			CandyScan(target);
		}
		AppRenderApplication();
		for (int x = 0; x < SizeX; x++) {
			CandyContainer* column = &Board[5][x];
			do {
				column->ApplyGravity();
				column = column->GetNext(Up);
			} while (column != nullptr);
		}
	}
}

CandyContainer* CandyCrush::GetCandyContainer(int x, int y) {
	return &Board[y][x];
}

int CandyCrush::GetRawCandy(int x, int y) {
	return Board[y][x].GetEmpty() ? -1 :
		(Board[y][x].GetCandy()->GetSpecial() == 0) ? Board[y][x].GetCandy()->GetColor() :
		Board[y][x].GetCandy()->GetSpecial() + Board[y][x].GetCandy()->GetColor();
}

