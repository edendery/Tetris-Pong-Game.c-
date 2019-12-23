#pragma once
#include "Board.h"
#include "UserBoard.h"
#include "PcBoard.h"
#include "KeyboardManager.h"
#include "ball.h"
#include"Screen.h"

#include <list>
#include <array>

bool start(int (&rightDeadArea)[20][25], int (&LeftDeadArea)[16][25], Board &playerLeft, Board &playerRight, ball& b, KeyboardManager kbManager);
bool isFullLineLeft(int(&LeftDeadArea)[16][25], Screen& screen);
bool isFullLineRight(int(&RightDeadArea)[20][25], Screen& screen);
void drawDeadAreas(int(&LeftDeadArea)[16][25], int(&RightDeadArea)[20][25]);
void clearDeadAreas(int (&LeftDeadArea)[16][25], int (&RightDeadArea)[20][25]);