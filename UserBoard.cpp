#include "utils.h"
#include "UserBoard.h"
#include "Ball.h"



void UserBoard::handleKey(char c)
{
	x = c;
}

void UserBoard::changeDir(ball& b)
{
	//in this function we move the user board 
	if (x == 0)
		return;

	if (x == kbChars[0]||x-'A'+'a'==kbChars[0]) 
	{
		if (!up.isMax())
		{
			down.erase();
			down.move(0, 1);
			up.move(0, 1);
			setColor(COLOR::WHITE_TEXT);
			up.draw();
		}
	}
	else if (x == kbChars[1] || x - 'A' + 'a' == kbChars[1])
	{
		if (!down.isMin())
		{
			up.erase();
			up.move(0, -1);
			down.move(0, -1);
			setColor(COLOR::WHITE_TEXT);
			down.draw();
		}
	}
	else if (x == kbChars[2] || x - 'A' + 'a' == kbChars[2])
	{
		if (b.getMode() == REG)
		{ 
			if ((x == 's' || x == 'S') && (b.getCountModeL() >= 4))
			{
				b.setMode(BECOMING);
				b.setCount(0);
				b.setCountModeL(0);
			}
			if ((x == 'k' || x == 'K') && (b.getCountModeR() >= 4))
			{
				b.setMode(BECOMING);
				b.setCount(0);
				b.setCountModeR(0);
			}
		}
	}

	x = 0;

}

