#include "Keyboard.h"

#pragma region Public Methods

bool Keyboard::parseKeys(std::vector<int> keys, int key)
{
	return find(keys.begin(), keys.end(), key) != keys.end();
}

#pragma endregion