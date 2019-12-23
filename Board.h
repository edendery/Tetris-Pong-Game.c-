#pragma once
#include "Point.h"
#include "ball.h"
#include <list>
#include <array>
class ball;

class Board
{
protected:
	Point up, down;
	

public:
	friend class ball;
	enum { MAX_X = 79, MAX_Y = 24 };
	enum { MIN_X = 1, MIN_Y = 4 };
	
	Board(const Point up1, const Point down1) : up(up1), down(down1) {}

	void draw();
	
	void draw(char ch);

	void move(ball &b);

	void theBoardFallingLeft(Board PlayerLeft, int LefttDeadArea[16][25]);

	void theBoardFallingRight(Board playerRight, int rightDeadArea[20][25]);
	
	void set(Point up1, Point down1)
	{
		this->up = up1;
		this->down = down1;
	}

	int getX()const {
		return up.getX();
	}

	int getUpY()const {
		return up.getY();
	}

	int getDownY()const {
		return down.getY();
	}

	void setX(int x) {
		up.set(x, up.getY(), '#');
		down.set(x, down.getY(), '#');
	}

	void replaceLeft(int x)
	{
		up.set(x, 12, '#');
		down.set(x, 10, '#');
	}

	void replaceRight(int x)
	{
		up.set(x, 13, '#');
		down.set(x, 11, '#');
	}

	virtual void changeDir( ball& b);

	
};