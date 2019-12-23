#pragma once

#include "Board.h"
#include "Point.h"
#include "ball.h"
class ball;

class PcBoard : public Board {
	int level=0;
enum { BEST = 0, GOOD = 4, NOVICE = 1 }; 
public:
	friend class ball;
	PcBoard(Point up, Point down) :Board(up, down) {}

	int getLevel()
	{
		return level;
	}

	void setLevel(int newLevel)
	{
		level = newLevel;
	}

	void  changeDir( ball& b);
};