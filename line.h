#pragma once
#include "Point.h"
#include "Board.h"
#include"Utils.h"

class menu
{
	line startGame = { 10,10,"start new game" };
	line returnGame = { 10,15,"return to the game" };
	line rulesGame = { 10,10,"game rules" };
	line exitGame = { 10,10,"exit" };
	Board marker({ 6,10,'>' }, { 7,10,'>' }, 'p', 'l');
};
	bool inGame = false;
};