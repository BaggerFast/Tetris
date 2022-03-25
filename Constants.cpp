#include "Constants.h"

bool Keyboard::parseKeys(std::vector<int> keys, int key)
{
	return find(keys.begin(), keys.end(), key) != keys.end();
}
