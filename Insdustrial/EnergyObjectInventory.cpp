#include "EnergyObjectInventory.h"

void EnergyObjectInventory::AllDraw()
{
	functions.DrawRectangle(sf::Vector2f(400, 150), sf::Vector2f(30, 200), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxEnergy != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(400, 350), sf::Vector2f(30, ((energy / (float)maxEnergy)) * -200), sf::Color::Red, sf::Color(255, 200, 0));
		functions.PrintText(std::to_string((int)energy) + " / " + std::to_string(maxEnergy) + " en",
			sf::Vector2f(400, 352), 20, sf::Color(colorsInventory[0]));
	}
}

void EnergyObjectInventory::AllNext()
{
	if (energy > maxEnergy)
	{
		energy = maxEnergy;
	}
	else if (energy < 0)
	{
		energy = 0;
	}
}

void EnergyObjectInventory::AllUpdate(Inventory& playerInventory)
{
	// Узнать координаты мыши
	//mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.WhileOpen();
}
