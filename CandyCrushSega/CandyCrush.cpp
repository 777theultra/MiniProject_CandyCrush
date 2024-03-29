#include <iostream>
#include <cstdlib>
#include "CandyCrush.h"

void BlowUpSurrounding(CandyContainer* center) {
	int points = 0;
	if (center->GetNext(Up) != nullptr) {
		if (!center->GetNext(Up)->GetEmpty()) { points++; }
		center->GetNext(Up)->SetEmpty(true);
		if (center->GetNext(Up)->GetNext(Left) != nullptr) {
			if (!center->GetNext(Up)->GetNext(Left)->GetEmpty()) { points++; }
			center->GetNext(Up)->GetNext(Left)->SetEmpty(true);
		}
		if (center->GetNext(Up)->GetNext(Right) != nullptr) {
			if (!center->GetNext(Up)->GetNext(Right)->GetEmpty()) { points++; }
			center->GetNext(Up)->GetNext(Right)->SetEmpty(true);
		}
	}
	if (center->GetNext(Down) != nullptr) {
		if (!center->GetNext(Down)->GetEmpty()) { points++; }
		center->GetNext(Down)->SetEmpty(true);
		if (center->GetNext(Down)->GetNext(Left) != nullptr) {
			if (!center->GetNext(Down)->GetNext(Left)->GetEmpty()) { points++; }
			center->GetNext(Down)->GetNext(Left)->SetEmpty(true);
		}
		if (center->GetNext(Down)->GetNext(Right) != nullptr) {
			if (!center->GetNext(Down)->GetNext(Right)->GetEmpty()) { points++; }
			center->GetNext(Down)->GetNext(Right)->SetEmpty(true);
		}
	}
	if (center->GetNext(Left) != nullptr) {
		if (!center->GetNext(Left)->GetEmpty()) { points++; }
		center->GetNext(Left)->SetEmpty(true);
	}
	if (center->GetNext(Right) != nullptr) {
		if (!center->GetNext(Right)->GetEmpty()) { points++; }
		center->GetNext(Right)->SetEmpty(true);
	}
	if (!center->GetEmpty()) { points++; };
	AppAwardPoints(points);
	center->SetEmpty(true);
}

//-- CandyContainer;

void CandyContainer::SetCandy(Candy candy) {
	CandyObject = candy;
}

Candy* CandyContainer::GetCandy() {
	return &CandyObject;
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

//-- CandyCrush;

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

	bool changed;
	do {
		changed = false;
		for (int x = 0; x < SizeX; x++) {
			CandyContainer* column = &Board[5][x];
			do {
				column->ApplyGravity();
				column = column->GetNext(Up);
			} while (column != nullptr);
		}
		for (int y = 0; y < SizeY; y++) {
			for (int x = 0; x < SizeX; x++) {
				if (!Board[y][x].GetEmpty()) {
					CandyScan(&Board[y][x]);
				}
			}
		}
		bool foundUnwrapped = false;
		for (int y = 0; y < SizeY; y++) {
			for (int x = 0; x < SizeX; x++) {
				if (Board[y][x].GetCandy()->GetSpecial() == Unwrapped) {
					BlowUpSurrounding(&Board[y][x]);
					foundUnwrapped = true;
					changed = true;
				}
			}
		}
		if (foundUnwrapped) {
			AppRenderApplication();
			for (int x = 0; x < SizeX; x++) {
				CandyContainer* column = &Board[5][x];
				do {
					column->ApplyGravity();
					column = column->GetNext(Up);
				} while (column != nullptr);
			}
		}
		for (int y = 0; y < SizeY; y++) {
			for (int x = 0; x < SizeX; x++) {
				if (Board[y][x].GetEmpty()) {
					changed = true;
				}
			}
		}
	} while (changed == true);

	ObjectiveBColor = (std::rand() % 6);
	ObjectiveDCombo = (std::rand() % 3);

	ObjectiveBAmount = 6 + (std::rand() % 6);
	ObjectiveDAmount = 2;
}

CandyCrush::~CandyCrush() { /*Destructor*/ }

void CandyCrush::MinusObjectiveB() {
	std::cout << "Decreasing ObjectiveB ";
	ObjectiveBAmount--;
	std::cout << " -> " << ObjectiveBAmount << std::endl;
}

int CandyCrush::GetObjectiveBAmount() {
	return ObjectiveBAmount;
}

void CandyCrush::MinusObjectiveD() {
	ObjectiveDAmount--;
}

int CandyCrush::GetObjectiveDAmount() {
	return ObjectiveDAmount;
}

void CandyCrush::RenderBoard() { //Disabled
	//if (true) { return; }
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
		if (!c->GetEmpty() && c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
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
		if (!c->GetEmpty() && c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
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
		if (!c->GetEmpty() && c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
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
		if (!c->GetEmpty() && c->GetCandy()->GetColor() == subject->GetCandy()->GetColor()) {
			//std::cout << " [" << c->GetCandy()->GetColor() << "]";
			hContainers[h] = c;
			h++;
		} else {
			break;
		}
		c = c->GetNext(Right);
	};
	//std::cout << std::endl;

	int points = 0;

	if (h > 2) {
		std::cout << "Horizontal chain found: " << h << std::endl;
		for (int x = 0; x < h; x++) {
			if (hContainers[x] != NULL) {

				if (!hContainers[x]->GetEmpty() && hContainers[x]->GetCandy()->GetSpecial() != Bomb && hContainers[x]->GetCandy()->GetColor() == ObjectiveBColor) {
					MinusObjectiveB();
				}
				hContainers[x]->SetEmpty(true);

				if (hContainers[x]->GetCandy()->GetSpecial() == Striped) {
					for (int a = 0; a < SizeX; a++) {
						if (!Board[hContainers[x]->Y][a].GetEmpty()) {
							points++;
							if (Board[hContainers[x]->Y][a].GetCandy()->GetSpecial() == Wrapped) {
								BlowUpSurrounding(hContainers[x]);
								hContainers[x]->SetEmpty(false);
								hContainers[x]->GetCandy()->SetSpecial(Unwrapped);
								std::cout << "Combo R wiping surrounding" << std::endl;
							}
						}
						Board[hContainers[x]->Y][a].SetEmpty(true);
					}
					std::cout << "Combo P wiping row: " << hContainers[x]->Y << std::endl;
				} else if (hContainers[x]->GetCandy()->GetSpecial() == Wrapped) {
					BlowUpSurrounding(hContainers[x]);
					hContainers[x]->SetEmpty(false);
					hContainers[x]->GetCandy()->SetSpecial(Unwrapped);
					std::cout << "Combo R wiping surrounding" << std::endl;
				}
			}
		}
		if (h == 4) {
			std::cout << "Combo P found" << std::endl;
			subject->SetEmpty(false);
			subject->GetCandy()->SetSpecial(Striped);
			if (ObjectiveDCombo == 0) {
				MinusObjectiveD();
			}
		} else if (h == 5) {
			std::cout << "Combo S found" << std::endl;
			subject->SetEmpty(false);
			subject->GetCandy()->SetSpecial(Bomb);
			if (ObjectiveDCombo == 2) {
				MinusObjectiveD();
			}
		}
		points += (h - 2);
	}
	if (v > 2) {
		std::cout << "Vertical chain found: " << h << std::endl;
		for (int y = 0; y < v; y++) {
			if (vContainers[y] != NULL) {

				if (!vContainers[y]->GetEmpty() && vContainers[y]->GetCandy()->GetSpecial() != Bomb && vContainers[y]->GetCandy()->GetColor() == ObjectiveBColor) {
					MinusObjectiveB();
				}
				vContainers[y]->SetEmpty(true);
				if (vContainers[y]->GetCandy()->GetSpecial() == Striped) {
					for (int a = 0; a < SizeX; a++) {
						if (!Board[vContainers[y]->Y][a].GetEmpty()) {
							points++;
							if (Board[vContainers[y]->Y][a].GetCandy()->GetSpecial() == Wrapped) {
								BlowUpSurrounding(vContainers[y]);
								vContainers[y]->SetEmpty(false);
								vContainers[y]->GetCandy()->SetSpecial(Unwrapped);
								std::cout << "Combo R wiping surrounding" << std::endl;
							}
						}
						Board[vContainers[y]->Y][a].SetEmpty(true);
					}
					std::cout << "Combo P wiping row: " << vContainers[y]->Y << std::endl;
				} else if (vContainers[y]->GetCandy()->GetSpecial() == Wrapped) {
					BlowUpSurrounding(vContainers[y]);
					vContainers[y]->SetEmpty(false);
					vContainers[y]->GetCandy()->SetSpecial(Unwrapped);
					std::cout << "Combo R wiping surrounding" << std::endl;
				}
			}
		}
		if (v == 4) {
			std::cout << "Combo P found" << std::endl;
			subject->SetEmpty(false);
			subject->GetCandy()->SetSpecial(Striped);
			if (ObjectiveDCombo == 0) {
				MinusObjectiveD();
			}
		} else if (v == 5) {
			std::cout << "Combo S found" << std::endl;
			subject->SetEmpty(false);
			subject->GetCandy()->SetSpecial(Bomb);
			if (ObjectiveDCombo == 2) {
				MinusObjectiveD();
			}
		}
		points += (v - 2);
	}
	/* T, L Alignments
		### #    #    #
		 #  ###  #  ###
		 #  #   ###   #

		 #     # ### ###
		 #     # #     #
		 ### ### #     #
	*/
	if (h >= 3 && v >= 3) {
		std::cout << "Combo R found" << std::endl;
		subject->SetEmpty(false);
		subject->GetCandy()->SetSpecial(Wrapped);
		if (ObjectiveDCombo == 1) {
			MinusObjectiveD();
		}
	}
	AppAwardPoints(points);
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
			if (target->GetCandy()->GetSpecial() == Bomb) {
				std::cout << "Combo S bombing all color " << selection->GetCandy()->GetColor() << std::endl;

				if (!target->GetEmpty() && target->GetCandy()->GetSpecial() != Bomb && target->GetCandy()->GetColor() == ObjectiveBColor) {
					MinusObjectiveB();
				}
				target->SetEmpty(true);
				for (int y = 0; y < SizeY; y++) {
					for (int x = 0; x < SizeX; x++) {
						if (Board[y][x].GetCandy()->GetColor() == selection->GetCandy()->GetColor()) {

							if (!Board[y][x].GetEmpty() && Board[y][x].GetCandy()->GetSpecial() != Bomb && Board[y][x].GetCandy()->GetColor() == ObjectiveBColor) {
								MinusObjectiveB();
							}
							Board[y][x].SetEmpty(true);
							AppAwardPoints(1);
						}
					}
				}
			} else {
				CandyScan(selection);
			}
		}
		if (!target->GetEmpty()) {
			CandyScan(target);
		}
		bool changed;
		do {
			changed = false;
			AppRenderApplication();
			for (int x = 0; x < SizeX; x++) {
				CandyContainer* column = &Board[5][x];
				do {
					column->ApplyGravity();
					column = column->GetNext(Up);
				} while (column != nullptr);
			}
			for (int y = 0; y < SizeY; y++) {
				for (int x = 0; x < SizeX; x++) {
					if (!Board[y][x].GetEmpty()) {
						CandyScan(&Board[y][x]);
					}
				}
			}
			bool foundUnwrapped = false;
			for (int y = 0; y < SizeY; y++) {
				for (int x = 0; x < SizeX; x++) {
					if (Board[y][x].GetCandy()->GetSpecial() == Unwrapped) {
						BlowUpSurrounding(&Board[y][x]);
						foundUnwrapped = true;
						changed = true;
					}
				}
			}
			if (foundUnwrapped) {
				AppRenderApplication();
				for (int x = 0; x < SizeX; x++) {
					CandyContainer* column = &Board[5][x];
					do {
						column->ApplyGravity();
						column = column->GetNext(Up);
					} while (column != nullptr);
				}
			}
			for (int y = 0; y < SizeY; y++) {
				for (int x = 0; x < SizeX; x++) {
					if (Board[y][x].GetEmpty()) {
						changed = true;
					}
				}
			}
		} while (changed == true);
	}
	std::cout << "Objectives B Color:" << ObjectiveBColor << " B Amout:" << ObjectiveBAmount << " D Combo:" << ObjectiveDAmount << std::endl;
	if (ObjectiveDAmount <= 0) {
		AppSetObjectiveCompleted(2);
	}
	if (ObjectiveBAmount <= 0) {
		AppSetObjectiveCompleted(1);
	}
}

CandyContainer* CandyCrush::GetCandyContainer(int x, int y) {
	return &Board[y][x];
}

int CandyCrush::GetRawCandy(int x, int y) {
	return Board[y][x].GetEmpty() ? -1 :
		(Board[y][x].GetCandy()->GetSpecial() == Bomb) ? static_cast<int>(Bomb) :
		(Board[y][x].GetCandy()->GetSpecial() == Unwrapped) ? Board[y][x].GetCandy()->GetColor() :
		(Board[y][x].GetCandy()->GetSpecial() == None) ? Board[y][x].GetCandy()->GetColor() :
		Board[y][x].GetCandy()->GetSpecial() + Board[y][x].GetCandy()->GetColor();
}

