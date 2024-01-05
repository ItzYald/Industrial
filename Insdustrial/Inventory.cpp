#include "Inventory.h"

Inventory::Inventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	// Узнать координаты мыши
	mousePosition = sf::Vector2i();
	items = std::vector<std::vector<ItemStruct>>();
	// Предмет перетаскиваемый мышкой
	mouseItem = ItemStruct();
	itemsSprites = StaticSprites();
	rw = _rw;
	functions = Functions(rw);
	// Выбранная ячейка
	choseCell = 0;

	LoadColorInventoryFromFile();

	// Ивентарь игрока
	for (int i = 0; i < 10; i++)
	{
		items.push_back(std::vector<ItemStruct>());
		for (int j = 0; j < 4; j++)
		{
			items[i].push_back(ItemStruct());
		}
	}

	// Инвертарь
	for (int i = 0; i < 2; i++)
	{
		itemsMiniWorkbench.push_back(std::vector<ItemStruct>());
		for (int j = 0; j < 2; j++)
		{
			itemsMiniWorkbench[i].push_back(ItemStruct());
		}
	}

	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

}

void Inventory::DeleteButtons()
{
	buttons.clear();
}

void Inventory::AddButtons(bool miniWorkbench)
{
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			buttons.push_back(Button(sf::Vector2f(300 + 8 + i * 66, 400 + 8 + j * 66), sf::Vector2f(64, 64), L"",
				colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
				sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
		}
	}
	if (miniWorkbench)
	{
		for (int i = 0; i < itemsMiniWorkbench.size(); i++)
		{
			for (int j = 0; j < itemsMiniWorkbench[0].size(); j++)
			{
				buttons.push_back(Button(sf::Vector2f(600 + 8 + i * 66, 130 + 8 + j * 66), sf::Vector2f(64, 64), L"",
					colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
					sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
			}
		}
	}
}

void Inventory::Draw()
{
	DrawCommon(items);

	// Отрисовка предмета в мышке
	if (mouseItem.number != 0)
	{
		itemsSprites.DrawItemSprite(rw.get(), mouseItem.number, sf::Vector2f(mousePosition.x, mousePosition.y), sf::Vector2f(4, 4));
		functions.PrintText(std::to_string(mouseItem.quantity), sf::Vector2f(mousePosition.x + 35, mousePosition.y + 35), 25, sf::Color(250, 250, 250));
	}
}

void Inventory::Update()
{
	// Задание кнопок
	if (buttons.size() < 1)
	{
		AddButtons(false);
	}

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 400), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Два цикла по координатам инвентаря
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			// Номер кнопки (чтобы каждый раз не считать заново)
			int numberButton = i * items[0].size() + j;
			// Нажатие левой кнопки мыши
			if (buttons[numberButton].CheckLeft(*rw))
			{
				// Если и в мыши и в ячейке есть предмет
				if (items[i][j].number != 0 && mouseItem.number != 0)
				{
					// Если предметы одинаковые - сложить
					if (items[i][j].number == mouseItem.number)
					{
						items[i][j].quantity += mouseItem.quantity;
						mouseItem.number = 0;
						mouseItem.quantity = 0;
					}
					// Если разные - поменять
					else
					{
						ItemStruct intermediateItem = mouseItem;
						mouseItem = items[i][j];
						items[i][j] = intermediateItem;
					}
				}
				// Если в ячейке есть предмет, а в мыше нету
				else if (items[i][j].number != 0)
				{
					mouseItem = items[i][j];
					items[i][j].number = 0;
					items[i][j].quantity = 0;
				}
				// Если предмет есть в мыши, но нету в ячейке
				else if (mouseItem.number != 0)
				{
					items[i][j] = mouseItem;
					mouseItem.number = 0;
					mouseItem.quantity = 0;
				}
			}
			// Нажатие правой кнопки мыши
			if (buttons[numberButton].CheckRight(*rw))
			{
				// Если в мыши есть предмет, а в ячейке нету
				if (mouseItem.number != 0)
				{
					if (items[i][j].number == mouseItem.number)
					{
						items[i][j].quantity += 1;
					}
					if (items[i][j].number == 0)
					{
						items[i][j].number = mouseItem.number;
						items[i][j].quantity = 1;
					}
					mouseItem.quantity -= 1;
				}
				// Если в мыши нет предмета, а в ячейке есть
				if (mouseItem.number == 0 && items[i][j].number != 0)
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
			}

			// Если колличество 0 - сделать пустой
			if (items[i][j].quantity == 0)
			{
				items[i][j].number = 0;
			}
			if (mouseItem.quantity == 0)
			{
				mouseItem.number = 0;
			}
		}
	}

	Draw();
}

void Inventory::DrawMiniWorkbench()
{
	if (buttons.size() < 4 * 10 + 3)
	{
		AddButtons(true);
	}

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	
	// Два цикла по координатам инвентаря
	for (int i = 0; i < itemsMiniWorkbench.size(); i++)
	{
		for (int j = 0; j < itemsMiniWorkbench[0].size(); j++)
		{
			int numberButton = i * itemsMiniWorkbench.size() + (items[0].size() * items.size()) + j;
			// Нажатие левой кнопки мыши
			if (buttons[numberButton].CheckLeft(*rw))
			{
				// Если и в мыши и в ячейке есть предмет
				if (itemsMiniWorkbench[i][j].number != 0 && mouseItem.number != 0)
				{
					// Если предметы одинаковые - сложить
					if (itemsMiniWorkbench[i][j].number == mouseItem.number)
					{
						itemsMiniWorkbench[i][j].quantity += mouseItem.quantity;
						mouseItem.number = 0;
						mouseItem.quantity = 0;
					}
					// Если разные - поменять
					else
					{
						ItemStruct intermediateItem = mouseItem;
						mouseItem = itemsMiniWorkbench[i][j];
						itemsMiniWorkbench[i][j] = intermediateItem;
					}
				}
				// Если в ячейке есть предмет, а в мыше нету
				else if (itemsMiniWorkbench[i][j].number != 0)
				{
					mouseItem = itemsMiniWorkbench[i][j];
					itemsMiniWorkbench[i][j].number = 0;
					itemsMiniWorkbench[i][j].quantity = 0;
				}
				// Если предмет есть в мыши, но нету в ячейке
				else if (mouseItem.number != 0)
				{
					itemsMiniWorkbench[i][j] = mouseItem;
					mouseItem.number = 0;
					mouseItem.quantity = 0;
				}
			}
			// Нажатие правой кнопки мыши
			if (buttons[numberButton].CheckRight(*rw) && mouseItem.number == 0 && itemsMiniWorkbench[i][j].number != 0)
			{
				mouseItem.number = itemsMiniWorkbench[i][j].number;
				if (itemsMiniWorkbench[i][j].quantity == 1)
				{
					mouseItem.quantity = 1;
					itemsMiniWorkbench[i][j].number = 0;
					itemsMiniWorkbench[i][j].quantity = 0;
				}
				else
				{
					mouseItem.quantity = itemsMiniWorkbench[i][j].quantity / 2;
					itemsMiniWorkbench[i][j].quantity = itemsMiniWorkbench[i][j].quantity - mouseItem.quantity;
				}
			}

			// Отрисовка
			// sf::Vector2f positionInventory = sf::Vector2f(600 + 8 + i * 66, 130 + 8 + j * 66);
			sf::Vector2f positionInventory = buttons[numberButton].coords;
			if (itemsMiniWorkbench[i][j].number != 0)
			{
				itemsSprites.DrawItemSprite(rw.get(), itemsMiniWorkbench[i][j].number, positionInventory, sf::Vector2f(4, 4));
				functions.PrintText(std::to_string(itemsMiniWorkbench[i][j].quantity), sf::Vector2f(positionInventory.x + 40, positionInventory.y + 40), 20, sf::Color(250, 250, 250));
			}

			buttons[numberButton].Draw(*rw);
		}
	}


}
// Отрисовка нижней части инвентаря (во время геймплея)
void Inventory::DrawNear(int mouseWheel)
{
	functions.DrawRectangle(sf::Vector2f(302, 598), sf::Vector2f(676, 82), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	
	for (int i = 0; i < items.size(); i++)
	{
		// Если 0 - сделать пустым
		if (items[i][3].quantity == 0)
		{
			items[i][3].number = 0;
		}

		// Отрисовка
		functions.DrawRectangle(sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66), sf::Vector2f(64, 64), sf::Color(150, 150, 150), sf::Color(100, 100, 100), 2);
		sf::Vector2f positionInventory = sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66);
		if (items[i][3].number != 0)
		{
			itemsSprites.DrawItemSprite(rw.get(), items[i][3].number, positionInventory, sf::Vector2f(4, 4));
			// Колличество
			functions.PrintText(std::to_string(items[i][3].quantity), sf::Vector2f(positionInventory.x + 35, positionInventory.y + 35), 25, sf::Color(250, 250, 250));
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
