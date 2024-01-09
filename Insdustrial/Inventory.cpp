#include "Inventory.h"

Inventory::Inventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	// Узнать координаты мыши
	mousePosition = sf::Vector2i();
	// Предмет перетаскиваемый мышкой
	mouseItem = ItemStruct();
	itemsSprites = StaticSprites();
	rw = _rw;
	functions = Functions(rw);
	// Выбранная ячейка
	choseCell = 0;

	LoadColorInventoryFromFile();

	// Ячейки инвентаря
	cells = std::vector< std::vector<CellInInventory>>();
	for (int i = 0; i < 10; i++)
	{
		// Временный массив
		auto cellsI = std::vector<CellInInventory>();
		for (int j = 0; j < 4; j++)
		{
			cellsI.push_back(CellInInventory(rw, sf::Vector2f(300 + 8 + i * 66, 400 + 8 + j * 66), true, true));
		}
		cells.push_back(cellsI);
	}
	// Ячейки мини верстака
	for (int i = 0; i < 2; i++)
	{
		// Временный массив
		auto cellsI = std::vector<CellInInventory>();
		for (int j = 0; j < 2; j++)
		{
			cellsI.push_back(CellInInventory(rw, sf::Vector2f(600 + 8 + i * 66, 130 + 8 + j * 66), true, true));
		}
		cellsMiniWorkbench.push_back(cellsI);
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
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
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
	DrawCommon(cells);

	// Отрисовка предмета в мышке
	if (mouseItem.number != 0)
	{
		itemsSprites.DrawItemSprite(rw.get(), mouseItem.number, sf::Vector2f(mousePosition.x, mousePosition.y), sf::Vector2f(4, 4));
		functions.PrintText(std::to_string(mouseItem.quantity), sf::Vector2f(mousePosition.x + 35, mousePosition.y + 35), 25, sf::Color(250, 250, 250));
	}
}

void Inventory::Update()
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 400), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Два цикла по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].Update(mouseItem);
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
			int numberButton = i * itemsMiniWorkbench.size() + (cells[0].size() * cells.size()) + j;
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

void Inventory::DrawMiniWorkbench2()
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	for (int i = 0; i < cellsMiniWorkbench.size(); i++)
	{
		for (int j = 0; j < cellsMiniWorkbench[0].size(); j++)
		{
			cellsMiniWorkbench[i][j].Update(mouseItem);
			DrawCommon(cellsMiniWorkbench);
		}
	}
}

// Отрисовка нижней части инвентаря (во время геймплея)
void Inventory::DrawNear(int mouseWheel)
{
	functions.DrawRectangle(sf::Vector2f(302, 598), sf::Vector2f(676, 82), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	
	for (int i = 0; i < cells.size(); i++)
	{
		// Если 0 - сделать пустым
		if (cells[i][3].item.quantity == 0)
		{
			cells[i][3].item.number = 0;
		}

		// Отрисовка
		functions.DrawRectangle(sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66), sf::Vector2f(64, 64), sf::Color(150, 150, 150), sf::Color(100, 100, 100), 2);
		sf::Vector2f positionInventory = sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66);
		if (cells[i][3].item.number != 0)
		{
			itemsSprites.DrawItemSprite(rw.get(), cells[i][3].item.number, positionInventory, sf::Vector2f(4, 4));
			// Колличество
			functions.PrintText(std::to_string(cells[i][3].item.quantity), sf::Vector2f(positionInventory.x + 35, positionInventory.y + 35), 25, sf::Color(250, 250, 250));
		}

	}

	functions.DrawRectangle(sf::Vector2f(300 + 8 + choseCell * 66, 400 + 8 + 3 * 66), sf::Vector2f(64, 64), sf::Color::Transparent, sf::Color(100, 100, 100), 4);

	if (mouseWheel < 0)
	{
		if (choseCell < cells.size() - 1)
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
			choseCell = cells.size() - 1;
		}
	}

}
