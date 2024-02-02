#include "ChestInventory.h"

//ChestInventory::ChestInventory(std::shared_ptr<sf::RenderWindow> _rw)
//{
//	// Окно
//	rw = _rw;
//	functions = Functions(rw);
//	LoadColorInventoryFromFile();
//
//	// Ячейки с предметами (сетка 10 x 4)
//	cells = std::vector<std::vector<CellInInventory>>();
//	for (int i = 0; i < 10; i++)
//	{
//		cells.push_back(std::vector<CellInInventory>());
//		for (int j = 0; j < 4; j++)
//		{
//			cells[i].push_back(CellInInventory(rw, sf::Vector2f(300 + 8 + i * 66, 110 + 8 + j * 66), true, true));
//		}
//	}
//
//	itemsSprites = StaticSprites();
//}

ChestInventory::ChestInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory)
{
	// Окно
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	// Ячейки с предметами (сетка 10 x 4)
	cells = std::vector<std::vector<CellInInventory>>();
	for (int i = 0; i < 10; i++)
	{
		cells.push_back(std::vector<CellInInventory>());
		for (int j = 0; j < 4; j++)
		{
			cells[i].push_back(CellInInventory(rw, sf::Vector2f(300 + 8 + i * 66, 110 + 8 + j * 66), true, true));
		}
	}

	itemsSprites = StaticSprites();
}

void ChestInventory::Update(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Два цикла по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].Update(playerInventory.mouseItem);
		}
	}

	DrawCommon(cells);
	playerInventory.Update();
}
