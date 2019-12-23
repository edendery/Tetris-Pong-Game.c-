#include"main.h"

int main()
{
	setcursor(0, 0);
	int rightDeadArea[20][25] = { 0 };
	int leftDeadArea[16][25] = { 0 };
	int countUser = -1;
	KeyboardManager kbManager;
	PcBoard playerLeftP({ 4, 12, '#' }, { 4,10,'#' });
	PcBoard playerRightP({ 76,13,'#' }, { 76,11,'#' });
	UserBoard playerLeftU({ 4, 12, '#' }, { 4,10,'#' }, 'q', 'a','s');
	UserBoard playerRightU({ 76,13,'#' }, { 76,11,'#' }, 'p', 'l','k');

	ball b;
	int yMarker=10;
	bool inGame = false;

	char ch;
	drawMenu();
	drawMarker(yMarker);
	while (true)
	{
		ch = _getch();
		while (ch != ' ')
		{
			if (ch == 'l'|| ch =='L')
			{
				down(yMarker);
			}
			if (ch == 'p'|| ch == 'P')
			{
				up(yMarker);
			}
			ch = _getch();
		}
		if (yMarker == 10)//START user vs user
		{
			system("CLS");
			clearDeadAreas(leftDeadArea, rightDeadArea);
			playerLeftU.set({ 4, 12, '#' }, { 4,10,'#' });
			playerRightU.set({ 76,13,'#' }, { 76,11,'#' });
			b.replace();
			kbManager.registerKbListener(&playerLeftU);
			kbManager.registerKbListener(&playerRightU);
			countUser = 2;
			inGame = start(rightDeadArea, leftDeadArea, playerLeftU, playerRightU, b, kbManager);//if false the game is over
			if (!inGame)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				playerLeftU.set({ 4, 12, '#' }, { 4,10,'#' });
				playerRightU.set({ 76,13,'#' }, { 76,11,'#' });
				b.replace();
			}
			system("CLS");
			drawMenu();
			yMarker = 10;
			drawMarker(yMarker);

		}
		if (yMarker == 12)//START user vs pc
		{
			system("CLS");
			gotoxy(10, 10);
			cout << "chose level for Right player :";
			playerRightP.setLevel(choseLevel(15));
			system("CLS");
			

			clearDeadAreas(leftDeadArea, rightDeadArea);
			playerRightP.set({ 76,13,'#' }, { 76,11,'#' });
			playerLeftU.set({ 4, 12, '#' }, { 4,10,'#' });
			kbManager.registerKbListener(&playerLeftU);
			b.replace();
			countUser = 1;
			inGame = start(rightDeadArea, leftDeadArea, playerLeftU, playerRightP, b, kbManager);//if false the game is over
			if (!inGame)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				playerRightP.set({ 76,13,'#' }, { 76,11,'#' });
				playerLeftU.set({ 4, 12, '#' }, { 4,10,'#' });
				b.replace();
			}
			system("CLS");
			drawMenu();
			yMarker = 10;
			drawMarker(yMarker);

		}
		if (yMarker == 14)//START pc vs pc
		{
			system("CLS");
			gotoxy(10, 10);
			cout << "chose level for Right player :";
			playerRightP.setLevel(choseLevel(15));
			system("CLS");
			gotoxy(10, 10);
			cout << "chose level for Left player :";
			playerLeftP.setLevel(choseLevel(15));
			system("CLS");

			clearDeadAreas(leftDeadArea, rightDeadArea);
			playerLeftP.set({ 4, 12, '#' }, { 4,10,'#' });
			playerRightP.set({ 76,13,'#' }, { 76,11,'#' });

			b.replace();
			countUser = 0;
			inGame = start(rightDeadArea, leftDeadArea, playerLeftP, playerRightP, b, kbManager);//if false the game is over
			if (!inGame)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				playerLeftP.set({ 4, 12, '#' }, { 4,10,'#' });
				playerRightP.set({ 76,13,'#' }, { 76,11,'#' });

				b.replace();
			}
			system("CLS");
			drawMenu();
			yMarker = 10;
			drawMarker(yMarker);

		}
		if (yMarker == 16)//continue the last game
		{

			system("CLS");
			if (inGame)
			{
				if (countUser == 0)
				{
					inGame = start(rightDeadArea, leftDeadArea, playerLeftP, playerRightP, b, kbManager);//if false the game is over
				}
				if (countUser == 1)
				{
					inGame = start(rightDeadArea, leftDeadArea, playerLeftU, playerRightP, b, kbManager);//if false the game is over
				}
				if (countUser == 2)
				{
					inGame = start(rightDeadArea, leftDeadArea, playerLeftU, playerRightU, b, kbManager);//if false the game is over
				}
				
			}
			else
			{
				gotoxy(40, 12);
				cout << "there are no past game";
				Sleep(1000);
			}
			
			if (!inGame)
			{
				clearDeadAreas(leftDeadArea, rightDeadArea);
				PcBoard playerLeftP({ 4, 12, '#' }, { 4,10,'#' });
				PcBoard playerRightP({ 76,13,'#' }, { 76,11,'#' });
				UserBoard playerLeftU({ 4, 12, '#' }, { 4,10,'#' }, 'q', 'a','s');
				UserBoard playerRightU({ 76,13,'#' }, { 76,11,'#' }, 'p', 'l','k');
				b.replace();
			}
			system("CLS");
			drawMenu();
			yMarker = 10;
			drawMarker(yMarker);
		}
		if (yMarker == 18)//rules
		{
			system("CLS");
			rules();
			system("CLS");
			drawMenu();
			yMarker = 10;
			drawMarker(yMarker);
		}
		if (yMarker == 20)//exit
		{
			system("CLS");
			return 0;
		}
	}
}

void drawMenu()
{
	setColor(COLOR::BLUE_TEXT);
	gotoxy(10, 1);

	cout << "   ________         _             _                      _____";
	gotoxy(10, 2);
	cout <<"   |__   __|       | |           (_)                    |  __ \\";
	gotoxy(10, 3); 
	cout <<"	| |     ___  | |_    _ __   _   ___     ______    | |__) |  ___    _ __     __ _";
	gotoxy(10, 4);
	cout << "      | |    / _ \\ | __|  | '__| | | / __|   |______|   | ___ /  / _ \\  | '_ \\  / _` |";
	gotoxy(10, 5);
	cout << "      | |   |  __/ | |_   | |    | | \\__ \\              | |     | (_) | | | | | |(_| |";
	gotoxy(10, 6);
	cout << "	|_|   \\___ | \\__ |  |_|    |_| |___/              |_|      \\___/  |_| |_| \\__, |";
	gotoxy(10, 7);
	cout << "		                                                                   __/ |";
	gotoxy(10, 8);
	cout << "		                                                                  |___ /";
	setColor(COLOR::WHITE_TEXT);
	gotoxy(10, 10);
	std::cout << "Start a new game - Human vs Human";

	gotoxy(10, 12);
	std::cout << "Start a new game - Human vs Computer";

	gotoxy(10, 14);
	std::cout << "Start a new game - Computer vs Computer";

	gotoxy(10, 16);
	std::cout << " Continue a paused game";

	gotoxy(10, 18);
	std::cout << "Present instructions and keys";

	gotoxy(10, 20);
	std::cout << "exit";


	gotoxy(20,25);
	std::cout << "enter speace to choose, p to up and l to down in the menu";

	
	gotoxy(55, 10);
	cout << "	           O .";
	gotoxy(55, 11);
	cout << "	         _/|\\_-O ";
	gotoxy(55, 12);
	cout << "         ___|_______";
	gotoxy(55, 13);
	cout << "        /     |     \\ ";
	gotoxy(55, 14);
	cout << "       /      |      \\ ";
	gotoxy(55, 15);
	cout << "      ################# ";
	gotoxy(55, 16);
	cout << "     /   _ ( )|        \\ ";
	gotoxy(55, 17);
    cout << "    /   ( ) | |         \\ ";
	gotoxy(55, 18);
	cout << "   /   \  |_/  |          \\ ";
	gotoxy(55, 19);
    cout << "  / ____\/|____|___________\\ ";
	gotoxy(55, 20);
	cout << "     |   |             |";
	gotoxy(55, 21);
	cout << "     |  / \\            |";
	gotoxy(55, 22);
	cout << "     | /   \\           |";
	gotoxy(55, 23);
	cout << "     _/    /_";
}

void drawMarker(int y)
{
	setColor(COLOR::BLUE_TEXT);
	gotoxy(6, y);
	std::cout << ">>";
	setColor(COLOR::WHITE_TEXT);
}

void eraseMarker(int y)
{
	gotoxy(6, y);
	std::cout << "  ";
}

void down(int& y)
{
	if (y < 20)
	{

		eraseMarker(y);
		y = y + 2;
		drawMarker(y);
	}

}

void up(int& y)
{
	if (y > 10)
	{

		eraseMarker(y);
		y = y - 2;
		drawMarker(y);
	}

}

void rules()
{
	char ch;
	gotoxy(15, 5);
	cout << "The rules of the game:\n";
	cout << "\n\n\n\n";
	cout << "Keys:\n";
	cout << "Left Player : Top Q Down A Bomb S\n";
	cout << "Right Player : Top P Down L Bomb K\n";
	cout << "\n";
	cout << "the purpose of the game :\n";
	cout << "Do not let the ball pass through your board by using the keys.\n";
	cout << " please be careful from the bomb";
	cout << "If you are disqualified, a fixed tetris game begins, during which you can return 5 disqualifications.\n";
	cout << "The way to return the disqualifications is by creating a complete line.\n";
	cout << "The game ended after a loss of 16 points\n";
	
	ch = _getch();
	while (ch!=' ')
		ch = _getch();
	
	
	
}

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if (size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

int choseLevel(int y)
{ 
	//in this function the user chose the difficult level of the pc board
	gotoxy(6, y);
	std::cout << ">>";
	gotoxy(10, 15);
	cout << "a) BEST";
	gotoxy(10, 17);
	cout << "b) GOOD";
	gotoxy(10, 19);
	cout << "c) NOVICE";
	
	char ch = _getch();
	while (ch != ' ')
	{
		if (ch == 'l' || ch == 'L')
		{
			if (y < 19)
			{

				eraseMarker(y);
				y = y + 2;
				drawMarker(y);
			}
		}
		if (ch == 'p' || ch == 'P')
		{
			if (y > 15)
			{

				eraseMarker(y);
				y = y - 2;
				drawMarker(y);
			}
		}
		ch = _getch();
	}
	if (y == 15)
	{
		return BEST;
	}
	if (y == 17)
	{
		return GOOD;
	}
	if (y == 19)
	{
		return NOVICE;
	}
	return -1;
}

