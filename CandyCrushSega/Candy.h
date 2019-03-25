#pragma once
#include <string>

enum CandyColor : unsigned short {Red, Orange, Yellow, Green, Blue, Purple };
enum CandySpecial : unsigned short {None, Striped, Wrapped };

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

