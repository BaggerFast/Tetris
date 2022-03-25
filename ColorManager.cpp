#include "ColorManager.h"

void ColorManager::getRandom()
{
	previous = current;
	current = 1 + rand() % 15;
}
