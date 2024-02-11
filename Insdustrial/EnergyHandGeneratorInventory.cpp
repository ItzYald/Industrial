#include "EnergyHandGeneratorInventory.h"

void EnergyHandGeneratorInventory::Draw()
{
	functions.DrawRectangle(sf::Vector2f(400, 150), sf::Vector2f(30, 200), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	buttons[0].Draw(*rw);
	if (maxEnergy != 0)
	{
		// Отрисовка количества энергии
		functions.DrawRectangleGradient(
			sf::Vector2f(400, 350), sf::Vector2f(30, (energy / (float)maxEnergy) * -200),
			sf::Color::Red, sf::Color(255, 200, 0));
		functions.PrintText(std::to_string((int)energy) + " / " + std::to_string(maxEnergy) + " en",
			sf::Vector2f(450, 330), 20, sf::Color(colorsInventory[0]));
	}
	
}

void EnergyHandGeneratorInventory::Update(Inventory& playerInventory)
{
	if (buttons.size() < 1)
	{
		buttons.push_back(Button(sf::Vector2f(550, 160), sf::Vector2f(128, 128), L"",
			colorsInventory[0], colorsInventory[1], sf::Color::Red,
			colorsInventory[2], sf::Color::Transparent, sf::Color::Transparent,
			sf::Color(255, 255, 255), sf::Color::Transparent, sf::Color::Transparent,
			sf::Vector2f(0, 0), 4, 25));
	}

	if (buttons[0].CheckDown(*rw))
	{
		energy += 1;
	}

	if (energy > maxEnergy)
		energy = maxEnergy;

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.Update();

}

