#pragma once
#include "Point.h"

class Screen {
	int i;
public:
	enum { MAX_X = 79, MAX_Y = 24 };
	enum { MIN_X = 1, MIN_Y = 4 };
	void drawScreen();
	void cleanLine(int x);
	
};