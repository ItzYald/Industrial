#include "CoalOvenInventory.h"

CoalOvenInventory::CoalOvenInventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	rw = _rw;
	functions = Functions(rw);
	LoadColorInventoryFromFile();

	// 3 ячейки в инвентаре
	cells = std::vector<CellInInventory>();
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 130), true, true));
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 306), true, true));
	cells.push_back(CellInInventory(rw, sf::Vector2f(670, 218), false, true));

	fuel = 0;
	whatBurn = 120;
	maxFuel = 0;

	itemsSprites = StaticSprites();
}

void CoalOvenInventory::Burn()
{
	if (itemsSprites.IsFuel(cells[1].item.number) && itemsSprites.IsBurn(cells[0].item.number))
	{
		if (fuel <= 0)
		{
			maxFuel = itemsSprites.IsFuel(cells[1].item.number) * 60;
			fuel = maxFuel;
			cells[1].item.quantity -= 1;
		}
		if (whatBurn <= 0)
		{
			whatBurn = 120;
		}
	}

	AllBurn();
}

void CoalOvenInventory::Draw()
{
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	// Прогрессбар печки
	functions.DrawRectangle(sf::Vector2f(550, 240), sf::Vector2f(90, 20), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	functions.DrawRectangleGradient(sf::Vector2f(550, 240), sf::Vector2f((120 - whatBurn) * 0.75f, 20), sf::Color::Red, sf::Color(255, 200, 0));
	// Топливо печки
	functions.DrawRectangle(sf::Vector2f(480, 220), sf::Vector2f(30, 60), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxFuel != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(480, 280), sf::Vector2f(30, ((fuel / (float)maxFuel)) * -60), sf::Color::Red, sf::Color(255, 200, 1));
	}
	DrawCommon(cells);

}

void CoalOvenInventory::Update(Inventory& playerInventory)
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
