#pragma once
#include <string>

enum CandyColor : unsigned short {Red, Orange, Yellow, Green, Blue, Purple };
enum CandySpecial : unsigned short {None, Striped, Wrapped };
enum Direction : unsigned short { Up, Down, Left, Right };

class Candy {
public:
	Candy();
	Candy(CandyColor, CandySpecial);
	~Candy();
	int GetColor();
	int GetSpecial();
private:
	Candy* NextUp = nullptr;
	Candy* NextDown = nullptr;
	Candy* NextLeft = nullptr;
	Candy* NextRight = nullptr;
	CandyColor Color = Red;
	CandySpecial Special = None;
};

