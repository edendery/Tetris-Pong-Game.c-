#pragma once

#include "Board.h"
#include "Point.h"
#include"ball.h"
#include"KeyboardEventListener.h"
enum { REG = 1, BECOMING = 2, BOMB = 3 };
class ball;
class UserBoard : public Board ,public KeyboardEventListener {
	char x=0;
	char kbChars[3];
public:
	friend class ball;

	UserBoard(Point up, Point down, const char& kbCharsUp, const char& kbCharsDown,const char & kbCharsBomb) :Board(up, down),kbChars{ kbCharsDown,kbCharsUp,kbCharsBomb}{}
	
	
	void handleKey(char c);

	const char* getKbChars() 
	{
		return kbChars;
	}
	
	void changeDir ( ball& b);

};