#include "EnergyHandGeneratorInventory.h"

void EnergyHandGeneratorInventory::Draw()
{
	buttons[0].Draw(*rw);
	functions.DrawRectangle(sf::Vector2f(400, 150), sf::Vector2f(30, 200), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxEnergy != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(400, 350), sf::Vector2f(30, ((energy / (float)maxEnergy)) * -200), sf::Color::Red, sf::Color(255, 200, 0));
		functions.PrintText(std::to_string(energy) + " / " + std::to_string(maxEnergy) + " en", sf::Vector2f(600, 200), 25, sf::Color(colorsInventory[0]));
	}
	
}

void EnergyHandGeneratorInventory::Update(Inventory& playerInventory)
{
	if (buttons.size() < 1)
	{
		buttons.push_back(Button(sf::Vector2f(100, 608), sf::Vector2f(128, 64), L"F",
			colorsInventory[0], colorsInventory[1], sf::Color::Red,
			colorsInventory[2], sf::Color::Transparent, sf::Color::Transparent,
			sf::Color(255, 255, 255), sf::Color::Transparent, sf::Color::Transparent,
			sf::Vector2f(128 / 2 - 35, 12), 4, 25));
	}

	if (buttons[0].CheckDown(*rw))
	{
		energy += 1;
	}

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.Update();

}

