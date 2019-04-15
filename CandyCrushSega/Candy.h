#pragma once
#include <string>

enum CandyColor : short { Empty = -1, Red, Orange, Yellow, Green, Blue, Purple };
enum CandySpecial : unsigned short {None = 0, Striped = 10, Wrapped = 20};
enum Direction : unsigned short { Up, Down, Left, Right };

class Candy {
public:
	Candy();
	Candy(CandyColor, CandySpecial);
	~Candy();
	int GetColor();
	int GetSpecial();
	void SetSpecial(CandySpecial);
private:
	CandyColor Color = Red;
	CandySpecial Special = None;
};

