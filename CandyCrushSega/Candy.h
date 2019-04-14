#pragma once
#include <string>

enum CandyColor : short { Empty = -1, Red, Orange, Yellow, Green, Blue, Purple };
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
	CandyColor Color = Red;
	CandySpecial Special = None;
};

