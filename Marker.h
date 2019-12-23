#pragma once

#include"Utils.h"


class Marker
{
	line mark;
	char  kbChars[3];
public:
	Marker(line mark1, const char& kbCharsUp, const char& kbCharsDown, const char& kbCharsEnter) :mark(mark1), kbChars{ kbCharsUp,kbCharsDown,kbCharsEnter } {}
	
	const char* getKbChars() {
		return kbChars;
	}
	
	bool handleKeyMenu(char c)
	{

		if (c == kbChars[0]) 
		{
			if (mark.y!=10)
			{
				this->earse();
				this->setY(mark.y-2);
				this->draw();
			}
		}
		else if (c == kbChars[1])
		{
			if (mark.y != 16)
			{
				this->earse();
				this->setY(mark.y + 2);
				this->draw();
			}
		
		}
	}

	int getY()const {
		return mark.y;
	}

	void setY(int y) {
		mark.y = y;
	}

	void draw()
	{
		gotoxy(mark.x, mark.y);
		std::cout<<mark.command;
	}

	void earse()
	{
		gotoxy(mark.x, mark.y);
		std::cout << " ";
	}
};