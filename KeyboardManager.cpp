#include <conio.h>
#include "KeyboardManager.h"

void KeyboardManager::registerKbListener(KeyboardEventListener * pKbListener)
{
	const char * chars = pKbListener->getKbChars();
	size_t numCharToRegister = strlen(chars);
	for (size_t i = 0; i < numCharToRegister; ++i) {
		int index = getIndex(chars[i]);
		if (index != -1) {
			kbListeners[index].push_back(pKbListener);
		}
	}
}

bool KeyboardManager::handleKeyboard()
{
	bool exit = false;
	if (_kbhit()) {
		char k = (_getch());
		if (k != 27)
		{
			int index = getIndex(k);
			if (index != -1)
			{
				for (auto pKbListener : kbListeners[index])
				{
					pKbListener->handleKey(k);
				}
			}
		}
		else
			exit = true;
	}
	return exit;
}