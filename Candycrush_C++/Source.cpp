#include <algorithm>
using std::swap;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <string>
using std::string;

#include <iomanip> 
using std::setw;

//Sync test ~ K
class candycrush
{
public:
	int candy[6][6];
	void initialize()
	{
		for (int y = 0; y <= 5; y++)
		{
			for (int x = 0; x <= 5; x++)
			{
				candy[y][x] = 1 + rand() % 6;
			}
		}
	}
	void print_field()
	{
		for (int y = 0; y <= 5; y++)
		{
			for (int x = 0; x <= 5; x++)
			{
				cout << setw(7) << candy[y][x];
			}
			cout << endl;
		}
	}
	int exchange(int exchange[2], string exchangedir)
	{
		if (exchangedir == "up" && exchange[0] > 0)
		{
			swap(candy[exchange[0]][exchange[1]], candy[exchange[0] - 1][exchange[1]]);
			if (check() == 1)
			{
				return check();
			}
			else
			{
				swap(candy[exchange[0]][exchange[1]], candy[exchange[0] - 1][exchange[1]]);
			}
		}
		else if (exchangedir == "down" && exchange[0] < 5)
		{
			swap(candy[exchange[0]][exchange[1]], candy[exchange[0] + 1][exchange[1]]);
			if (check() == 1)
			{
				return check();
			}
			else
			{
				swap(candy[exchange[0]][exchange[1]], candy[exchange[0] + 1][exchange[1]]);
			}
		}
		else if (exchangedir == "right" && exchange[1] < 5)
		{
			swap(candy[exchange[0]][exchange[1]], candy[exchange[0]][exchange[1] + 1]);
			if (check() == 1)
			{
				return check();
			}
			else
			{
				swap(candy[exchange[0]][exchange[1]], candy[exchange[0]][exchange[1] + 1]);
			}
		}
		else if (exchangedir == "left" && exchange[1] > 0)
		{
			swap(candy[exchange[0]][exchange[1]], candy[exchange[0]][exchange[1] - 1]);
			if (check() == 1)
			{
				return check();
			}
			else
			{
				swap(candy[exchange[0]][exchange[1]], candy[exchange[0]][exchange[1] - 1]);
			}
		}
	}
	int check()
	{
		int match = 0;
		for (int y = 0; y <= 5; y++)
		{
			for (int x = 0; x <= 3; x++)
			{
				if (candy[y][x] == candy[y][x + 1] && candy[y][x] == candy[y][x + 2])
				{
					match = 1;
				}
			}
		}
		for (int x = 0; x <= 5; x++)
		{
			for (int y = 0; y <= 3; y++)
			{
				if (candy[y][x] == candy[y + 1][x] && candy[y][x] == candy[y + 2][x])
				{
					match = 1;
				}
			}
		}
		return match;
	}
	void destory()
	{
		int match = 0;
		for (int y = 0; y <= 5; y++)
		{
			for (int x = 0; x <= 3; x++)
			{
				if (candy[y][x] == candy[y][x + 1] && candy[y][x] == candy[y][x + 2])
				{
					for (int z = 3; x + z < 5; z++)
					{
						if (candy[y][x] == candy[y][x + z])
						{
							candy[y][x + z] = 0;
						}
					}
					candy[y][x] = 0;
					candy[y][x + 1] = 0;
					candy[y][x + 2] = 0;
					match = 1;
				}
			}
		}
		for (int x = 0; x <= 5; x++)
		{
			for (int y = 0; y <= 3; y++)
			{
				if (candy[y][x] == candy[y + 1][x] && candy[y][x] == candy[y + 2][x])
				{
					for (int z = 3; y + z < 5; z++)
					{
						if (candy[y][x] == candy[y + z][x])
						{
							candy[y + z][x] = 0;
						}
					}
					candy[y][x] = 0;
					candy[y + 1][x] = 0;
					candy[y + 2][x] = 0;
					match = 1;
				}
			}
		}
	}
	void gravity()
	{
		for (int layers = 1; layers <= 5; layers++)
		{
			for (int y = 4; y >= 0; y--)
			{
				for (int x = 0; x <= 5; x++)
				{
					if (candy[y + 1][x] == 0)
					{
						swap(candy[y][x], candy[y + 1][x]);
					}
				}
			}
		}
	}
	void fill()
	{
		for (int y = 5; y >= 0; y--)
		{
			for (int x = 0; x <= 5; x++)
			{
				if (candy[y][x] == 0)
				{
					candy[y][x] = 1 + rand() % 6;
				}
			}
		}
	}
};

int main()
{
	candycrush game;
	int match = 1;
	int exchange[2];
	string exchangedir;
	srand(time(0));
	while (match != 0)
	{
		game.initialize();
		match = game.check();
	}
	game.print_field();
	int temp = 1;
	for (;;)
	{
		//x axis first, then y axis
		cin >> exchange[0];
		cin >> exchange[1];
		cin >> exchangedir;
		match = game.exchange(exchange, exchangedir);
		while (match == 1)
		{
			game.destory();
			game.gravity();
			game.fill();
			match = game.check();
		}
		game.print_field();

	}
	return 0;
}