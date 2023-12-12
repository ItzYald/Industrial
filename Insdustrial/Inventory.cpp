#include "Inventory.h"

Inventory::Inventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	// Узнать координаты мыши
	mousePosition = sf::Vector2i();
	items = std::vector<std::vector<ItemStruct>>();
	mouseItem = ItemStruct();
	itemsSprites = StaticSprites();
	rw = _rw;
	functions = Functions(rw);
	// Выбранная ячейка
	choseCell = 0;

	for (int i = 0; i < 10; i++)
	{
		items.push_back(std::vector<ItemStruct>());
		for (int j = 0; j < 4; j++)
		{
			items[i].push_back(ItemStruct());
		}
	}

	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

}

void Inventory::Draw()
{
	// Задание кнопок
	if (buttons.size() < 1)
	{
		for (int i = 0; i < items.size(); i++)
		{
			for (int j = 0; j < items[0].size(); j++)
			{
				buttons.push_back(Button(sf::Vector2f(300 + 8 + i * 66, 400 + 8 + j * 66), sf::Vector2f(64, 64), L"",
					sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(100, 100, 100), sf::Color::Transparent,
					sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
			}
		}
	}

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.Rectangle(rw.get(), sf::Vector2f(302, 400), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			if (buttons[i * items[0].size() + j].CheckLeft(*rw))
			{
				if (items[i][j].number != 0 && mouseItem.number != 0)
				{
					if (items[i][j].number == mouseItem.number)
					{
						items[i][j].quantity += mouseItem.quantity;
						mouseItem.number = 0;
						mouseItem.quantity = 0;
					}
					else
					{
						ItemStruct intermediateItem = mouseItem;
						mouseItem = items[i][j];
						items[i][j] = intermediateItem;
					}
				}
				else if (items[i][j].number != 0)
				{
					mouseItem = items[i][j];
					items[i][j].number = 0;
					items[i][j].quantity = 0;
				}
				else if (mouseItem.number != 0)
				{
					items[i][j] = mouseItem;
					mouseItem.number = 0;
					mouseItem.quantity = 0;
				}
			}

			if (buttons[i * 4 + j].CheckRight(*rw) && mouseItem.number == 0 && items[i][j].number != 0)
			{
				mouseItem.number = items[i][j].number;
				if (items[i][j].quantity == 1)
				{
					mouseItem.quantity = 1;
					items[i][j].number = 0;
					items[i][j].quantity = 0;
				}
				else
				{
					mouseItem.quantity = items[i][j].quantity / 2;
					items[i][j].quantity = items[i][j].quantity - mouseItem.quantity;
				}
			}

			sf::Vector2f positionInventory = sf::Vector2f(300 + 8 + i * 66, 400 + 8 + j * 66);
			if (items[i][j].number != 0)
			{
				itemsSprites.DrawItemSprite(rw.get(), items[i][j].number, positionInventory, sf::Vector2f(4, 4));
				functions.PrintText(std::to_string(items[i][j].quantity), sf::Vector2f(positionInventory.x + 40, positionInventory.y + 40), 20, sf::Color(250, 250, 250));
			}

			buttons[i * 4 + j].Draw(*rw);
		}
	}

	if (mouseItem.number != 0)
	{
		itemsSprites.DrawItemSprite(rw.get(), mouseItem.number, sf::Vector2f(mousePosition.x, mousePosition.y), sf::Vector2f(4, 4));
		functions.PrintText(std::to_string(mouseItem.quantity), sf::Vector2f(mousePosition.x + 40, mousePosition.y + 40), 20, sf::Color(250, 250, 250));
	}

}

void Inventory::DrawNear(int mouseWheel)
{

	functions.Rectangle(rw.get(), sf::Vector2f(302, 598), sf::Vector2f(676, 82), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	for (int i = 0; i < items.size(); i++)
	{
		functions.DrawRectangle(sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66), sf::Vector2f(64, 64), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
		sf::Vector2f positionInventory = sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66);
		if (items[i][3].number != 0)
		{
			itemsSprites.DrawItemSprite(rw.get(), items[i][3].number, positionInventory, sf::Vector2f(4, 4));
			functions.PrintText(std::to_string(items[i][3].quantity), sf::Vector2f(positionInventory.x + 40, positionInventory.y + 40), 20, sf::Color(250, 250, 250));
		}

	}

	functions.DrawRectangle(sf::Vector2f(300 + 8 + choseCell * 66, 400 + 8 + 3 * 66), sf::Vector2f(64, 64), sf::Color::Transparent, sf::Color(100, 100, 100), 4);

	if (mouseWheel < 0)
	{
		if (choseCell < items.size() - 1)
		{
			choseCell += 1;
		}
		else
		{
			choseCell = 0;
		}
	}
	else if (mouseWheel > 0)
	{
		if (choseCell > 0)
		{
			choseCell -= 1;
		}
		else
		{
			choseCell = items.size() - 1;
		}
	}

}
