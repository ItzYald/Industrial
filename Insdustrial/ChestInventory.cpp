#include "ChestInventory.h"

ChestInventory::ChestInventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	rw = _rw;
	functions = Functions(rw);
	LoadColorInventoryFromFile();

	items = std::vector<std::vector<ItemStruct>>();

	for (int i = 0; i < 10; i++)
	{
		items.push_back(std::vector<ItemStruct>());
		for (int j = 0; j < 4; j++)
		{
			items[i].push_back(ItemStruct());
		}
	}

	itemsSprites = StaticSprites();
}

void ChestInventory::Draw(Inventory& playerInventory)
{
	DrawCommon(items);
}

void ChestInventory::Update(Inventory& playerInventory)
{
	if (buttons.size() < 1)
	{
		for (int i = 0; i < items.size(); i++)
		{
			for (int j = 0; j < items[0].size(); j++)
			{
				buttons.push_back(Button(sf::Vector2f(300 + 8 + i * 66, 110 + 8 + j * 66), sf::Vector2f(64, 64), L"",
					colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
					sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
			}
		}
	}

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			int numberButton = i * items[0].size() + j;
			if (buttons[numberButton].CheckLeft(*rw))
			{
				if (items[i][j].number != 0 && playerInventory.mouseItem.number != 0)
				{
					if (items[i][j].number == playerInventory.mouseItem.number)
					{
						items[i][j].quantity += playerInventory.mouseItem.quantity;
						playerInventory.mouseItem.number = 0;
						playerInventory.mouseItem.quantity = 0;
					}
					else
					{
						ItemStruct intermediateItem = playerInventory.mouseItem;
						playerInventory.mouseItem = items[i][j];
						items[i][j] = intermediateItem;
					}
				}
				else if (items[i][j].number != 0)
				{
					playerInventory.mouseItem = items[i][j];
					items[i][j].number = 0;
					items[i][j].quantity = 0;
				}
				else if (playerInventory.mouseItem.number != 0)
				{
					items[i][j] = playerInventory.mouseItem;
					playerInventory.mouseItem.number = 0;
					playerInventory.mouseItem.quantity = 0;
				}
			}

			if (buttons[numberButton].CheckRight(*rw))
			{
				// Если в мыши есть предмет, а в ячейке нету
				if (playerInventory.mouseItem.number != 0)
				{
					if (items[i][j].number == playerInventory.mouseItem.number)
					{
						items[i][j].quantity += 1;
						playerInventory.mouseItem.quantity -= 1;
					}
					else if (items[i][j].number == 0)
					{
						items[i][j].number = playerInventory.mouseItem.number;
						items[i][j].quantity = 1;
						playerInventory.mouseItem.quantity -= 1;
					}
				}
				// Если в мыши нет предмета, а в ячейке есть
				else if (items[i][j].number != 0)
				{
					playerInventory.mouseItem.number = items[i][j].number;
					if (items[i][j].quantity == 1)
					{
						playerInventory.mouseItem.quantity = 1;
						items[i][j].number = 0;
						items[i][j].quantity = 0;
					}
					else
					{
						playerInventory.mouseItem.quantity = items[i][j].quantity / 2;
						items[i][j].quantity = items[i][j].quantity - playerInventory.mouseItem.quantity;
					}
				}

			}

		}
	}

	Draw(playerInventory);

	playerInventory.Update();
}

void ChestInventory::Update2(Inventory& playerInventory)
{

}
