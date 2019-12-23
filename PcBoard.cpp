#include "PcBoard.h"

void PcBoard:: changeDir( ball& b)
{
	//in this function we move pc board to the right place
	int x = 0;
	int boardY = up.getY() - 1;
	int ballY = b.getYup() + 1;
	if (b.getXright() + 1 == getX()|| b.getXleft() - 1 == getX())
	{
		x = rand() % (level * 10 +1);	
	}
	if (x != 1)
	{
		if (boardY > ballY)
		{
			if (!up.isMax())
			{
				up.erase();
				down.move(0, -1);
				up.move(0, -1);
				setColor(COLOR::WHITE_TEXT);
				down.draw();
			}
		}
		if (boardY < ballY)
		{
			if (!down.isMin())
			{
				down.erase();
				up.move(0, 1);
				down.move(0, 1);
				setColor(COLOR::WHITE_TEXT);
				up.draw();
			}
		}
	}
	else
	{
		if (boardY > ballY)
		{
			if (!down.isMin())
			{
				down.erase();
				up.move(0, 1);
				down.move(0, 1);
				setColor(COLOR::WHITE_TEXT);
				up.draw();
			}
			if (!down.isMin())
			{
				down.erase();
				up.move(0, 1);
				down.move(0, 1);
				setColor(COLOR::WHITE_TEXT);
				up.draw();
			}
		}
		if (boardY < ballY)
		{
			if (!up.isMax())
			{
				up.erase();
				down.move(0, -1);
				up.move(0, -1);
				setColor(COLOR::WHITE_TEXT);
				down.draw();
			}
			if (!up.isMax())
			{
				up.erase();
				down.move(0, -1);
				up.move(0, -1);
				setColor(COLOR::WHITE_TEXT);
				down.draw();
			}
		}

	}

}

