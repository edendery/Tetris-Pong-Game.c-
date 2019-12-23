#include "Screen.h"

void Screen:: drawScreen()
{
	//draw the limits
	Point down = { MIN_X, MIN_Y, '_' };
	Point up = { MIN_X, MAX_Y, '_' };
	Point left = { MIN_X, MIN_Y, '|' };
	Point right = { MAX_X, MIN_Y, '|' };

	
	for (int i = MIN_X -1; i <= MAX_X; i++)
	{
		up.set(i+1, MIN_Y-2, '_');
		setColor(COLOR::BLUE_TEXT);
		up.draw();
		down.set(i, MAX_Y+1, '_');
		setColor(COLOR::BLUE_TEXT);
		down.draw();
	}
	
	
	for (int i = MIN_Y - 1; i <= MAX_Y+1; i++)
	{
		left.set(MIN_X-1, i, '|');
		left.draw();
		right.set(MAX_X+1, i, '|');
		right.draw();
	}
}

void Screen::cleanLine(int x)
{
	//clear the screen
	int y = MIN_Y;
	Point clean = { x,y,' ' };
	while(y<=MAX_Y)
	{
		clean.draw();
		clean.set(x, y + 1, ' ');
		y++;
	}
}


