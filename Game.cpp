#include "game.h"


bool start(int(& rightDeadArea)[20][25], int(& LeftDeadArea)[16][25], Board &playerLeft, Board &playerRight,ball& b, KeyboardManager kbManager)
{
	Screen screen;
	screen.drawScreen();
	bool exit = false;


	drawDeadAreas(LeftDeadArea, rightDeadArea);
	playerLeft.draw();
	playerRight.draw();
	b.draw();
	b.startDir();
	b.setCountModeL(4);
	b.setCountModeR(4);
	
	//continue until the player click on space
	while (!exit) 
	{
		exit=kbManager.handleKeyboard();
		playerLeft.move(b);
		playerRight.move(b);
		//count the iteration in the same mode
		if (b.getcount() == 8 && b.getMode() == BECOMING)
		{
			b.setMode(BOMB);
			b.setCount(0);
		}
		else if (b.getcount() == 4 && b.getMode() == BOMB && b.getXright()<playerRight.getX() && b.getXleft()>playerLeft.getX())
		{
			b.setMode(REG);
			b.setCount(0);
		}
		else
		b.setCount(b.getcount()+1);

		if ((b.getXleft() == 40) && (b.getMode() == REG))
		{
			b.setCountModeL(b.getCountModeL() + 1);
			b.setCountModeR(b.getCountModeR() + 1);
		}

		b.move();
		if (b.isHitTheBoard(playerLeft,playerRight))
		{
			if (b.getcount() == 8 && b.getMode() == BECOMING)
			{
				b.setMode(BOMB);
				b.setCount(0);
			}
			else if (b.getcount() == 4 && b.getMode() == BOMB &&b.getXright()<playerRight.getX() &&b.getXleft()>playerLeft.getX())
			{
				b.setMode(REG);
				b.setCount(0);
			}
			else
				b.setCount(b.getcount() + 1);
			b.moveAfterHit();
		}
		b.draw();
		 if (b.isMissedLeft(playerLeft,LeftDeadArea))
		{
			 //start tetris in the left side
			if (playerLeft.getX() < 20)
			{
				playerLeft.theBoardFallingLeft(playerLeft, LeftDeadArea);
				if (!isFullLineLeft(LeftDeadArea, screen))
				{

					playerLeft.draw(' ');
					playerLeft.replaceLeft(playerLeft.getX() + 1);

				}
				else
				{
					playerLeft.draw(' ');
					playerLeft.replaceLeft(playerLeft.getX() - 5);

				}
				if (b.getMode() == REG||b.getMode()==BECOMING)
				{
					b.replace();
					b.draw();
					playerLeft.draw();
					playerRight.draw(' ');
					playerRight.replaceRight(playerRight.getX());
					playerRight.draw();
					b.startDir();
				}
				else if (b.getMode() == BOMB)
				{
					b.replace();
					b.draw();
					playerLeft.draw(' ');
					playerRight.draw(' ');
					playerLeft.replaceLeft(playerLeft.getX()+2);
					playerRight.replaceRight(playerRight.getX() );
					playerRight.draw();
					playerLeft.draw();
					b.setDirX();
				}

			}
			else
			{
				gotoxy(40, 10);
				std::cout << "GAME OVER!" << '\n';
				gotoxy(40, 11);
				std::cout << "player right win" << '\n';
				gotoxy(40, 12);
				std::cout << "Thanks for playing our game" << '\n';
				Sleep(1000);
				return false;
			}
		}
		 if (b.isMissedRight(playerRight, rightDeadArea))
		{
			 //start tetris in the right side
			if (playerRight.getX() > 60)
			{
				playerRight.theBoardFallingRight(playerRight, rightDeadArea);
				if (!isFullLineRight(rightDeadArea, screen))
				{

					playerRight.draw(' ');
					playerRight.replaceRight(playerRight.getX() - 1);

				}
				else
				{
					playerRight.draw(' ');
					playerRight.replaceRight(playerRight.getX() + 5);

				}
				if (b.getMode() == REG|| b.getMode() ==BECOMING)
				{
					b.replace();
					b.draw();
					playerLeft.draw(' ');
					playerLeft.replaceLeft(playerLeft.getX());
					playerLeft.draw();
					playerRight.draw();
					b.startDir();
				}
				if (b.getMode() == BOMB)
				{
					b.replace();
					b.draw();
					playerLeft.draw(' ');
					playerLeft.replaceLeft(playerLeft.getX());
					playerRight.replaceRight(playerRight.getX()-2);
					playerLeft.draw();
					playerRight.draw();
					b.setDirX();
				}
			}
			else
			{
				gotoxy(40, 10);
				std::cout << "GAME OVER!" << '\n';
				gotoxy(40, 11);
				std::cout << "player left win" << '\n';
				gotoxy(40, 12);
				std::cout << "Thanks for playing our game" << '\n';
				Sleep(1000);
				return false;
			
			}

		}
		Sleep(30);
	}

	
	return true;
	
}

bool isFullLineLeft (int(& LeftDeadArea)[16][25], Screen& screen)
{
	//check in the left array if have full line with 1
	int i = 1, j = 4;
	bool full = false;

	while(j < 25 )
		{
			if (LeftDeadArea[i][j] == 0)
			{
				j = 4;
				i++;
			}
			else
			{
				j++;
			}
			if (j == 25)
			{
				for (int k = 0; k < 25; k++)
				{
					LeftDeadArea[i][k] = 0;
				}
				screen.cleanLine(i);
				return true;
			}
			if (i == 16)
			{
				return false;
			}
	}
	return false;
}

bool isFullLineRight(int(&RightDeadArea)[20][25], Screen& screen)
{
	int i = 19, j = 4;
	bool full = false;
	//check in the right dead array if have full line with 1
	while (j < 25)
	{
		if (RightDeadArea[i][j] == 0)
		{
			j = 4;
			i--;
		}
		else
		{
			j++;
		}
		if (j == 25)//there are line
		{
			for (int k = 0; k < 25; k++)
			{
				RightDeadArea[i][k] = 0;
			}
			screen.cleanLine(i+60);
			return true;
		}
		if (i == 0)//there are no line
		{
			return false;
		}
	}
	return false;
}

void drawDeadAreas(int(&LeftDeadArea)[16][25], int(&RightDeadArea)[20][25])
{
	//print the dead boards in the left side 
	int i = 1, j = 4;
	while (i < 16)
	{
		while (j < 25)
		{
			if (LeftDeadArea[i][j] == 1)
			{
				setColor(COLOR::WHITE_TEXT);
				gotoxy(i, j);
				cout << "#";
				
			}
			j++;

		}
	i++;
	j = 4;
	}
	//print the dead boards in the left side 
	i = 1;
	j = 4;
	while (i < 20)
	{
		while (j < 25)
		{
			if (RightDeadArea[i][j] == 1)
			{
				setColor(COLOR::WHITE_TEXT);
				gotoxy(i+60, j);
				cout << "#";
				
			}
			j++;

		}
		i++;
		j = 4;
	}


}

void clearDeadAreas(int(&LeftDeadArea)[16][25], int(&RightDeadArea)[20][25])
{
	//clear the array from 1
	int i = 1, j = 4;
	while (i < 16)
	{
		while (j < 25)
		{
			if (LeftDeadArea[i][j] == 1)
			{
				LeftDeadArea[i][j] = 0;
			}
			j++;

		}
		i++;
		j = 4;
	}
	//clear the array from 1
	j = 4;
	i = 0;
	while (i < 20)
	{
		while (j < 25)
		{
			if (RightDeadArea[i][j] == 1)
			{
				RightDeadArea[i][j] = 0;
			}
			j++;

		}
		i++;
		j = 4;
	}


}
