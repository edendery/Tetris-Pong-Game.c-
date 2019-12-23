#include "ball.h"

void ball::startDir()
{
	srand(time(0));
	//in this function we restart the direction of the ball in new game
	unsigned int dir = rand();
	dir = dir % 4;

	if (dir == 0)
	{
		dir_x = 1;
		dir_y = 1;
	}
	if (dir == 1)
	{
		dir_x = 1;
		dir_y =-1;
	}
	if (dir == 2)
	{
		dir_x =-1;
		dir_y = 1;
	}
	if (dir == 3)
	{
		dir_x =-1;
		dir_y =-1;
	}
}

void ball::move()
{	

	//erase
	upL.draw(' ');
	upR.draw(' ');
	mid1.draw(' ');
	mid2.draw(' ');
	mid3.draw(' ');
	mid4.draw(' ');
	downL.draw(' ');
	downR.draw(' ');
	//check if the ball is in the limit's game
	if (mid4.x + dir_x == MAX_X || mid1.x + dir_x == MIN_X) {
		dir_x = -dir_x;
	}
	if (downL.y + dir_y == MAX_Y || upL.y + dir_y == MIN_Y) {
		dir_y = -dir_y;
	}
	//change the position
	upL.x += dir_x;
	upR.x += dir_x;
	mid1.x += dir_x;
	mid2.x += dir_x;
	mid3.x += dir_x;
	mid4.x += dir_x;
	downL.x += dir_x;
	downR.x += dir_x;

	upL.y += dir_y;
	upR.y += dir_y;
	mid1.y += dir_y;
	mid2.y += dir_y;
	mid3.y += dir_y;
	mid4.y += dir_y;
	downL.y += dir_y;
	downR.y += dir_y;
	
}

void ball::moveAfterHit()
{

	//change the position of the ball after hit the boards
	dir_x = -dir_x;
	//check if the move will not posible

	if (downL.y + dir_y == MAX_Y || upL.y + dir_y == MIN_Y) {
		dir_y = -dir_y;
	}



	upL.x += dir_x;
	upR.x += dir_x;
	mid1.x += dir_x;
	mid2.x += dir_x;
	mid3.x += dir_x;
	mid4.x += dir_x;
	downL.x += dir_x;
	downR.x += dir_x;

	upL.y += dir_y;
	upR.y += dir_y;
	mid1.y += dir_y;
	mid2.y += dir_y;
	mid3.y += dir_y;
	mid4.y += dir_y;
	downL.y += dir_y;
	downR.y += dir_y;
	
}

bool ball:: isHitTheBoard( Board& playerL,  Board& playerR)
{
	//check if the ball hit the  left board
	if (this->getXleft() == playerL.getX())
	{
		if (this->getYup() <= playerL.getUpY() && this->getYdown() >= (playerL.getDownY()))
		{
			if (mode == BECOMING)
			{
				setMode(REG);
				setCount(0);
			}
			if (mode == BOMB)
			{

				return false;
			}
			return true;
		}
			
	}
	//check if the ball hit the  right board
	if (this->getXright() == playerR.getX())
	{
		if (this->getYup() <= playerR.getUpY() && this->getYdown() >= (playerR.getDownY()))
		{
			if (mode == BECOMING)
			{
				setMode(REG);
				setCount(0);
			}
			if (mode == BOMB)
			{
			
				return false;
			}
			return true;
		}
	}
	//the ball isnt hit the boards
	return false;

}

bool ball:: isMissedLeft( Board &playerL, int LeftDeadArea[16][25])
{
	//check if the left board miss the ball
	if (this->getXleft() == playerL.getX())
	{
		if (this->getYup() > playerL.getUpY() || this->getYdown() < playerL.getDownY())
		{

			if (mode == REG)
				return true;
		}
		else if(mode==BOMB)
		{
			return true;
		}
	}
	if (this->getXleft() < playerL.getX())
	{

		int yUp = getYup();
		int yMid= getYup()+1;
		int yDown = getYdown();
		if (LeftDeadArea[getXleft() - 1][yUp] == 1 || LeftDeadArea[getXleft() - 1][yMid] == 1 || LeftDeadArea[getXleft() - 1][yDown] == 1 || getXleft() - 1 == MIN_X)
		{		
			if (mode == BECOMING || mode == REG)
			{
				return true;
			}
			if (mode == BOMB && getXleft() - 1 != MIN_X)
				//clean line and restart line in array
			{
				playerL.draw(' ');
				//clear the line screen
				int y = MIN_Y;
				Point clean = { getXleft() - 1,y,' ' };
				while (y <= MAX_Y)
				{
					clean.draw();
					clean.set(getXleft() - 1, y + 1, ' ');
					y++;
				}
				//restart the line in the array
				for (int k = 0; k < 25; k++)
				{
					LeftDeadArea[getXleft() - 1][k] = 0;
				}
				playerL.draw(' ');
				playerL.setX(playerL.getX() - 4);
				return true;


			}
			else
			{
				playerL.draw(' ');
				if (playerL.getX() - 3>MIN_X)

				playerL.setX(playerL.getX() - 3);
				return true;
			}
		}
	}
	return false;
}

bool ball:: isMissedRight(Board& playerR, int rightDeadArea[20][25])
{
	//check if the right board miss the ball
	if (this->getXright() == playerR.getX())
	{
		if (this->getYup() > playerR.getUpY() || this->getYdown() < playerR.getDownY())
		{

			if (mode == REG)
				return true;
		}
		else if (mode == BOMB)
		{
			return true;
		}
	}
	if (this->getXright() > playerR.getX())
	{
		int yUp = getYup();
		int yMid = getYup() + 1;
		int yDown = getYdown();

		if (rightDeadArea[getXright() - 60 + 1][yUp] == 1 || rightDeadArea[getXright() - 60 + 1][yMid] == 1 || rightDeadArea[getXright() - 60 + 1][yDown] == 1 || getXright() + 1 == MAX_X)
		{
			if (mode == BECOMING || mode == REG)
			{
				return true;
			}
			if (mode == BOMB && getXright()+1 != MAX_X)//clean line and restart line in array
			{
				//clear the line screen
				playerR.draw(' ');
				int y = MIN_Y;
				Point clean = { getXright() + 1,y,' ' };
				while (y <= MAX_Y)
				{
					clean.draw();
					clean.set(getXright() + 1, y + 1, ' ');
					y++;
				}
				//restart the line in the array
				for (int k = 0; k < 25; k++)
				{
					rightDeadArea[getXright() - 60 + 1][k] = 0;
				}
				playerR.setX(playerR.getX() + 4);
				return true;
			}
			else//if we here we in bomb mode and in the limit screen
			{
				playerR.draw(' ');
				if (playerR.getX()+3<MAX_X)
					playerR.setX(playerR.getX() + 3);
				return true;
			}
		}
	}
	return false;
}