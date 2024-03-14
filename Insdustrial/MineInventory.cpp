#include "MineInventory.h"

MineInventory::MineInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	// Окно
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	cells = std::vector<CellInInventory>();
	for (int i = 0; i < 4; i++)
	{
		cells.push_back(CellInInventory(
			_rw, sf::Vector2f((float)500 + 8 + 66 * i, 200.f), false, _textures, colorsInventory));
	}

	maxEnergy = 100;
	energy = 0;

	itemsSprites = StaticSprites(_textures);
}

void MineInventory::PlayUpdate()
{
	if (energy > 0)
	{
		energy -= 1;
		if (rand() % 600 == 1)
		{
			int randomItem = rand() % 4;
			int item = 0;
			switch (randomItem)
			{
			case 0:
				item = 1;
				break;
			case 1:
				item = 3;
				break;
			case 2:
				item = 21;
				break;
			case 3:
				item = 22;
				break;
			}
			for (size_t i = 0; i < 5; i++)
			{
				if (cells[i].item.number == item)
				{
					cells[i].item.quantity += 1;
					break;
				}
				else if (cells[i].item.number == ItemEnum::empty)
				{
					cells[i].item.NumberUpdate(item);
					cells[i].item.quantity += 1;
					break;
				}
			}
		}
	}

	AllNext();
}

void MineInventory::Draw()
{
	AllDraw();
	DrawCommon(cells);
}

void MineInventory::WhileOpen(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	AllNext();

	// Два цикла по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].WhileOpen(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.WhileOpen();
}
