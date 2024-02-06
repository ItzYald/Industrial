#include "EnergyStorageInventory.h"


EnergyStorageInventory::EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, int type)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}

	if (type == 0)
	{
		maxEnergy = 10000;
	}
	else if (type == 1)
	{
		maxEnergy = 100000;
	}

	energy = 0;
}

void EnergyStorageInventory::Draw()
{
	functions.DrawRectangle(sf::Vector2f(400, 150), sf::Vector2f(30, 200), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxEnergy != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(400, 350), sf::Vector2f(30, ((energy / (float)maxEnergy)) * -200), sf::Color::Red, sf::Color(255, 200, 0));
		functions.PrintText(std::to_string(energy) + " / " + std::to_string(maxEnergy) + " en", sf::Vector2f(600, 200), 25, sf::Color(colorsInventory[0]));
	}
}

void EnergyStorageInventory::Next()
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

void EnergyStorageInventory::Update(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.Update();
}
