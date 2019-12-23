#pragma once
#include "Utils.h"
#include "Screen.h"

class Point {
	int x, y;
	char ch;
	enum { MAX_X = 79, MAX_Y = 24 };
	enum { MIN_X = 1, MIN_Y = 4 };

public:
	friend class ball;
	friend class screen;
	Point(int x1, int y1, char c) : x(x1), y(y1), ch(c) {}

	void set(int x1, int y1, char c)
	{
		x = x1;
		y = y1;
		ch = c;
	}

	void move(int dir_x, int dir_y)
	{
		if (MAX_Y >= y + dir_y)
		{
			y += dir_y;
			x += dir_x;
		}
	}

	bool isMax()
	{
		if (this->y == MAX_Y)
		{
			return true;
		}
		return false;
	}

	bool isMin()
	{
		if (this->y == MIN_Y )
		{
			return true;
		}
		return false;
	}

	void draw(char c)
	{
		gotoxy(x, y);
		std::cout << c;
	}

	void draw() {
		draw(ch);
	}

	void erase() {
		draw(' ');
	}

	int getX()const {
		return x;
	}

	int getY()const {
		return y;
	}

	bool operator!=(const Point& other) const {
		return x != other.x || y != other.y;
	}
};
