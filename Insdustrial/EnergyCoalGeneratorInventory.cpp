#include "EnergyCoalGeneratorInventory.h"

EnergyCoalGeneratorInventory::EnergyCoalGeneratorInventory(
	std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
	int _maxEnergy, int _power, std::vector<sf::Texture>& _textures)
	: EnergyStorageInventory(_rw, _colorsInventory, _maxEnergy, _power, _textures)
{
	coalCell = CellInInventory(rw, sf::Vector2f(460, 350 - 64), true, _textures);
	burn = 0;
	maxBurn = 0;
}

void EnergyCoalGeneratorInventory::Next()
{
	if (coalCell.item.whatFuel)
	{
		if (burn <= 0)
		{
			maxBurn = coalCell.item.whatFuel * 60;
			burn = maxBurn;
			coalCell.item.quantity -= 1;
		}
	}

	if (burn > 0)
	{
		burn -= 1;
		energy += 0.05f;
	}
	if (energy > maxEnergy)
	{
		energy = maxEnergy;
	}
	else if (energy < 0)
	{
		energy = 0;
	}
}

void EnergyCoalGeneratorInventory::Draw()
{
	functions.DrawRectangle(sf::Vector2f(400, 150), sf::Vector2f(30, 200), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxEnergy != 0)
	{
		// Отрисовка количества энергии
		functions.DrawRectangleGradient(
			sf::Vector2f(400, 350), sf::Vector2f(30, (energy / (float)maxEnergy) * -200),
			sf::Color::Red, sf::Color(255, 200, 0));
		functions.PrintText(std::to_string((int)energy) + " / " + std::to_string(maxEnergy) + " en",
			sf::Vector2f(450, 355), 20, sf::Color(colorsInventory[0]));
	}
	// Топливо печки
	functions.DrawRectangle(sf::Vector2f(480, 220), sf::Vector2f(30, 60), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxBurn != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(480, 280), sf::Vector2f(30, ((burn / (float)maxBurn)) * -60), sf::Color::Red, sf::Color(255, 200, 0), 0);
	}
	coalCell.DrawCell();

}

void EnergyCoalGeneratorInventory::Update(Inventory& playerInventory)
{
	coalCell.Update(playerInventory.mouseItem);

	//if (energy > maxEnergy)
	//	energy = maxEnergy;

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.Update();

}

