#include "Checks.h"

// Проверка на отжатие клавивиши
bool Checks::Check(sf::Keyboard::Key what)
{
	bool result = false;

	if (sf::Keyboard::isKeyPressed(what))
	{
		if (!checkB)
		{
			checkB = true;
		}

	}
	else
	{
		if (checkB)
		{
			result = true;
			checkB = false;
		}
	}

	return result;
}


bool Checks::Check2(sf::Keyboard::Key what)
{
	if (sf::Keyboard::isKeyPressed(what))
	{
		if (checkB2)
		{
			checkB2 = false;
			return true;
		}
	}
	else
	{
		checkB2 = true;
	}

	return false;

}
