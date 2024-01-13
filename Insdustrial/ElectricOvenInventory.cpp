#include "ElectricOvenInventory.h"

#include "CoalOvenInventory.h"

ElectricOvenInventory::ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	rw = _rw;
	functions = Functions(rw);
	LoadColorInventoryFromFile();

	// 3 ячейки в инвентаре
	cells = std::vector<CellInInventory>();
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 130), true));
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 306), true));
	cells.push_back(CellInInventory(rw, sf::Vector2f(670, 218), false));

	fuel = 10;
	whatBurn = 120;
	maxFuel = 500;

	itemsSprites = StaticSprites();
}

void ElectricOvenInventory::Burn()
{
	if (cells[1].item.number == 10 && fuel < maxFuel)
	{
		fuel += 4;
		cells[1].item.quantity -= 1;
		if (fuel > maxFuel)
		{
			fuel = maxFuel;
		}
	}

	AllBurn();
}

void ElectricOvenInventory::Draw()
{
	AllDraw();
	// Топливо печки
	functions.DrawRectangle(sf::Vector2f(400, 180), sf::Vector2f(30, 140), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxFuel != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(400, 320), sf::Vector2f(30, ((fuel / (float)maxFuel)) * -140), sf::Color::Red, sf::Color(255, 200, 1));
	}

}

void ElectricOvenInventory::Update(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Два цикла по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].Update(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.Update();
}
