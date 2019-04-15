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

void Candy::SetSpecial(CandySpecial special) {
	Special = special;
}