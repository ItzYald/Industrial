#include "EnergyStorageInventory.h"


EnergyStorageInventory::EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}

	energy = 0;
	maxEnergy = 10000;
}

void EnergyStorageInventory::Draw()
{
	functions.DrawRectangle(sf::Vector2f(400, 180), sf::Vector2f(30, 140), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxEnergy != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(400, 320), sf::Vector2f(30, ((energy / (float)maxEnergy)) * -200), sf::Color::Red, sf::Color(255, 200, 0));
	}
}

void EnergyStorageInventory::Update(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	if (energy > maxEnergy)
	{
		energy = maxEnergy;
	}
	if (energy < 0)
	{
		energy = 0;
	}

	Draw();
	playerInventory.Update();
}
