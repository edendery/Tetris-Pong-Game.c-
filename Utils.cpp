
#include "utils.h"

void hideConsoleCursor(bool hideFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = !hideFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setColor(COLOR color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// pick the colorattribute
	SetConsoleTextAttribute(hConsole, (int)color);
}