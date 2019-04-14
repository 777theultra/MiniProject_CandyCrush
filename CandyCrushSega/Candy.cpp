#include <cstdlib>
#include "Candy.h"

Candy::Candy() {
	Color = CandyColor(std::rand() % 6);
}

Candy::Candy(CandyColor newColor, CandySpecial newSpecial) {
	Color = newColor;
	Special = newSpecial;
}

Candy::~Candy() {}

int Candy::GetColor() {
	return static_cast<int>(Color);
}

int Candy::GetSpecial() {
	return static_cast<int>(Special);
}

Candy* Candy::GetNext(Direction dir) {
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
}

void Candy::SetNext(Candy* candy, Direction dir) {
	switch (dir) {
	case Up:
		NextUp = candy;
		break;
	case Down:
		NextDown = candy;
		break;
	case Left:
		NextLeft = candy;
		break;
	case Right:
		NextRight = candy;
		break;
	}
}