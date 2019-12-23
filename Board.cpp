#include "utils.h"
#include "UserBoard.h"
#include "Ball.h"


void Board::draw()
{
	//in this function we draw the board
	Point temp = up;
	setColor(COLOR::WHITE_TEXT);
	temp.draw();
	do {
		temp.move(0, -1);
		setColor(COLOR::WHITE_TEXT);
		temp.draw();
	} while (temp != down);

}

void Board::draw(char ch)
{
	Point temp = up;
	setColor(COLOR::WHITE_TEXT);
	temp.draw(ch);
	do {
		temp.move(0, -1);
		setColor(COLOR::WHITE_TEXT);
		temp.draw(ch);
	} while (temp != down);

}

void Board::move(ball& b)
{
	changeDir(b);
}

void Board::theBoardFallingLeft(Board PlayerLeft, int leftDeadArea[16][25])
{
	int x, yUp, yMid, yDown;
	bool check = true;
	Board dead = PlayerLeft;
	//check if the dead board can continue fall
	while (dead.getX() != MIN_X && check)
	{

		x = dead.getX();
		yUp = dead.getUpY();
		yMid = dead.getUpY() - 1;
		yDown = dead.getDownY();
		if (leftDeadArea[x - 1][yUp] == 1 || leftDeadArea[x - 1][yMid] == 1 || leftDeadArea[x - 1][yDown] == 1 || x - 1 == MIN_X)
		{
			//upgrade in the arr
			leftDeadArea[x][yUp] = 1;
			leftDeadArea[x][yMid] = 1;
			leftDeadArea[x][yDown] = 1;
			check = false;

		}
		else
		{
			dead.draw(' ');
			dead.setX(x - 1);
			dead.draw();
		}


	}
}

void Board::theBoardFallingRight(Board playerRight, int rightDeadArea[20][25])
{
	int x, yUp, yMid, yDown;
	bool check = true;
	Board dead = playerRight;
	//check if the dead board can continue fall
	while (dead.getX() != MAX_X && check)
	{

		x = dead.getX();
		yUp = dead.getUpY();
		yMid = dead.getUpY() - 1;
		yDown = dead.getDownY();
		if (rightDeadArea[(x - 60) + 1][yUp] == 1 || rightDeadArea[(x - 60) + 1][yMid] == 1 || rightDeadArea[(x - 60) + 1][yDown] == 1 || x + 1 == MAX_X)
		{
			//upgrade in the arr
			rightDeadArea[(x - 60)][yUp] = 1;
			rightDeadArea[(x - 60)][yMid] = 1;
			rightDeadArea[(x - 60)][yDown] = 1;
			check = false;

		}
		else
		{
			dead.draw(' ');
			dead.setX(x + 1);
			dead.draw();


		}


	}
}

void Board::changeDir(ball& b) {}
