#pragma once
#include "Point.h"
#include"Board.h"
#include"Utils.h"
class Board;

class ball
{
	Point upL = { 39, 9, 'O' };
	Point upR = { 40, 9, 'O' };
	Point mid1 = { 38, 10, 'O' };
	Point mid2 = { 39, 10, 'O' };
	Point mid3= { 40, 10, 'O' };
	Point mid4 = { 41, 10, 'O' };
	Point downL = { 39, 11, 'O' };
	Point downR = { 40, 11, 'O' };
	int dir_x = 0;
	int dir_y = 0;
	int mode=REG;
	int countMode = 0;//becoming a bomb to bomb and bomb to regular
	int countModeL = 4;//check if the left board can click on bomb key
	int countModeR = 4;//check if the right board can click on bomb key




	enum {REG=1,BECOMING=2,BOMB=3 };
	enum { MAX_X = 79, MAX_Y = 24 };
	enum { MIN_X = 1, MIN_Y = 4 };

public:
	friend class Board;
	
	void move();

	void startDir();

	bool isHitTheBoard( Board& playerL , Board &playerR);

	void moveAfterHit();

	bool isMissedLeft(Board &playerL, int LeftDeadArea[16][25]);

	bool isMissedRight(Board& playerR, int rightDeadArea[20][25]);

	void draw()
	{
		//draw all the points of the ball
		if (getMode() == REG)
		{
			setColor(COLOR::BLUE_TEXT);
			upL.draw();
			setColor(COLOR::BLUE_TEXT);
			upR.draw();
			setColor(COLOR::BLUE_TEXT);
			mid1.draw();
			setColor(COLOR::BLUE_TEXT);
			mid2.draw();
			setColor(COLOR::BLUE_TEXT);
			mid3.draw();
			setColor(COLOR::BLUE_TEXT);
			mid4.draw();
			setColor(COLOR::BLUE_TEXT);
			downL.draw();
			setColor(COLOR::BLUE_TEXT);
			downR.draw();
		}
		if (getMode() == BECOMING)
		{
			setColor(COLOR::YELLOW_TEXT);
			upL.draw();
			setColor(COLOR::YELLOW_TEXT);
			upR.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid1.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid2.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid3.draw();
			setColor(COLOR::YELLOW_TEXT);
			mid4.draw();
			setColor(COLOR::YELLOW_TEXT);
			downL.draw();
			setColor(COLOR::YELLOW_TEXT);
			downR.draw();
		}
		if (getMode() == BOMB)
		{
			setColor(COLOR::RED_TEXT);
			upL.draw();
			setColor(COLOR::RED_TEXT);
			upR.draw();
			setColor(COLOR::RED_TEXT);
			mid1.draw();
			setColor(COLOR::RED_TEXT);
			mid2.draw();
			setColor(COLOR::RED_TEXT);
			mid3.draw();
			setColor(COLOR::RED_TEXT);
			mid4.draw();
			setColor(COLOR::RED_TEXT);
			downL.draw();
			setColor(COLOR::RED_TEXT);
			downR.draw();
		}
		
	}

	void replace()
	{
		countMode = 0;
		mode = REG;
		//erase the ball
		upL.draw(' ');
		upR.draw(' ');
		mid1.draw(' ');
		mid2.draw(' ');
		mid3.draw(' ');
		mid4.draw(' ');
		downL.draw(' ');
		downR.draw(' ');
		//restart the ball to new game

		upL = { 39, 9, 'O' };
		upR = { 40, 9, 'O' };
		mid1 = { 38, 10, 'O' };
		mid2 = { 39, 10, 'O' };
		mid3 = { 40, 10, 'O' };
		mid4 = { 41, 10, 'O' };
		downL = { 39, 11, 'O' };
		downR = { 40, 11, 'O' };
		
	}

	int getYup()const
	{
		return upL.getY();
	}

	int getYdown()const
	{
		return downL.getY();
	}

	int getXleft()const {
		return mid1.getX();
	}

	int getXright()const {
		return mid4.getX();
	}
	
	int getMode()const
	{
		return mode;
	}
	
	void setMode(int newMode)
	{
		this->mode = newMode;
	}

	int getcount()
	{
		return countMode;
	}

	void setCount(int x)
	{
		this->countMode = x;
	}

	void setDirX()
	{
		
		dir_x = dir_x * -1;
	}
	
	int getCountModeL()
	{
		return countModeL;
	}

	void setCountModeL(int x)
	{
		countModeL = x;
	}

	int getCountModeR()
	{
		return countModeR;
	}

	void setCountModeR(int x)
	{
		countModeR = x;
	}


 };