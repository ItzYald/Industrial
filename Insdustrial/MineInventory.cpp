#include "MineInventory.h"

MineInventory::MineInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	// ����
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	cells = std::vector<CellInInventory>();
	for (int i = 0; i < 4; i++)
	{
		cells.push_back(CellInInventory(
			_rw, sf::Vector2f((float)500 + 8 + 66 * i, 200.f), false, _textures, colorsInventory));
	}

	transferItem = &cells[0].item;

	maxEnergy = 100;
	energy = 0;

	itemsSprites = StaticSprites(_textures);
}

void MineInventory::PlayUpdate()
{
	if (energy > 0)
	{
		energy -= 1;
		if (rand() % 250 == 1)
		{
			int randomItem = rand() % 4;
			int item = 0;
			switch (randomItem)
			{
			case 0:
				item = ItemEnum::ironOre;
				break;
			case 1:
				item = ItemEnum::coal;
				break;
			case 2:
				item = ItemEnum::copperOre;
				break;
			case 3:
				item = ItemEnum::tinOre;
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

	AllPlayUpdate();
}

void MineInventory::Draw()
{
	AllDraw();
	DrawCommon(cells);
}

void MineInventory::WhileOpen(Inventory& playerInventory)
{
	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	AllPlayUpdate();

	// ��� ����� �� ����������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].WhileOpen(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.WhileOpen();
}
