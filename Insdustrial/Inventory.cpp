#include "Inventory.h"

Inventory::Inventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	// ������ ���������� ����
	mousePosition = sf::Vector2i();
	items = std::vector<std::vector<ItemStruct>>();
	// ������� ��������������� ������
	mouseItem = ItemStruct();
	itemsSprites = StaticSprites();
	rw = _rw;
	functions = Functions(rw);
	// ��������� ������
	choseCell = 0;

	// �������� ������
	for (int i = 0; i < 10; i++)
	{
		items.push_back(std::vector<ItemStruct>());
		for (int j = 0; j < 4; j++)
		{
			items[i].push_back(ItemStruct());
		}
	}

	// ���������
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
				sf::Color(150, 150, 150), sf::Color(200, 200, 200), sf::Color(250, 250, 250), sf::Color::Transparent,
				sf::Color::Transparent, sf::Color::Transparent, 1, 4, 25));
		}
	}
	if (miniWorkbench)
	{
		for (int i = 0; i < itemsMiniWorkbench.size(); i++)
		{
			for (int j = 0; j < itemsMiniWorkbench[0].size(); j++)
			{
				buttons.push_back(Button(sf::Vector2f(600 + 8 + i * 66, 130 + 8 + j * 66), sf::Vector2f(64, 64), L"",
					sf::Color(150, 150, 150), sf::Color(200, 200, 200), sf::Color(250, 250, 250), sf::Color::Transparent,
					sf::Color::Transparent, sf::Color::Transparent, 1, 4, 25));
			}
		}
	}
}

void Inventory::Draw()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].Draw(*rw);
	}

	// ��������� �������� ���������
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			int numberButton = i * items[0].size() + j;
			sf::Vector2f positionInventory = buttons[numberButton].coords;
			if (items[i][j].number != 0)
			{
				itemsSprites.DrawItemSprite(rw.get(), items[i][j].number, positionInventory, sf::Vector2f(4, 4));
				// �������� �����������
				functions.PrintText(std::to_string(items[i][j].quantity),
					sf::Vector2f(positionInventory.x + 35, positionInventory.y + 35),
					25, sf::Color(250, 250, 250));
			}
		}
	}

	// ��������� �������� ���������
	//for (int i = 0; i < items.size(); i++)
	//{
	//	for (int j = 0; j < items[0].size(); j++)
	//	{
	//		int numberButton = i * items[0].size() + j;
	//		if (items[i][j].number != 0 && buttons[numberButton].Aim(*rw))
	//		{
	//			sf::Vector2f positionInventory = buttons[numberButton].coords;
	//			sf::String name = itemsSprites.GetName(items[i][j].number);
	//			int sizeSimbol = 20;
	//			functions.DrawRectangle(sf::Vector2f(positionInventory.x + 65, positionInventory.y),
	//				sf::Vector2f(sizeSimbol * name.getSize() / 1.8 + 10, 35), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 2);
	//			functions.PrintText(name, sf::Vector2f(positionInventory.x + 70, positionInventory.y), sizeSimbol, sf::Color(250, 250, 250));
	//		}
	//	}
	//}

	DrawItemName(items);

	// ��������� �������� � �����
	if (mouseItem.number != 0)
	{
		itemsSprites.DrawItemSprite(rw.get(), mouseItem.number, sf::Vector2f(mousePosition.x, mousePosition.y), sf::Vector2f(4, 4));
		functions.PrintText(std::to_string(mouseItem.quantity), sf::Vector2f(mousePosition.x + 40, mousePosition.y + 40), 20, sf::Color(250, 250, 250));
	}
}

void Inventory::Update()
{
	// ������� ������
	if (buttons.size() < 1)
	{
		AddButtons(false);
	}

	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.Rectangle(rw.get(), sf::Vector2f(302, 400), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// ��� ����� �� ����������� ���������
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			// ����� ������ (����� ������ ��� �� ������� ������)
			int numberButton = i * items[0].size() + j;
			// ������� ����� ������ ����
			if (buttons[numberButton].CheckLeft(*rw))
			{
				// ���� � � ���� � � ������ ���� �������
				if (items[i][j].number != 0 && mouseItem.number != 0)
				{
					// ���� �������� ���������� - �������
					if (items[i][j].number == mouseItem.number)
					{
						items[i][j].quantity += mouseItem.quantity;
						mouseItem.number = 0;
						mouseItem.quantity = 0;
					}
					// ���� ������ - ��������
					else
					{
						ItemStruct intermediateItem = mouseItem;
						mouseItem = items[i][j];
						items[i][j] = intermediateItem;
					}
				}
				// ���� � ������ ���� �������, � � ���� ����
				else if (items[i][j].number != 0)
				{
					mouseItem = items[i][j];
					items[i][j].number = 0;
					items[i][j].quantity = 0;
				}
				// ���� ������� ���� � ����, �� ���� � ������
				else if (mouseItem.number != 0)
				{
					items[i][j] = mouseItem;
					mouseItem.number = 0;
					mouseItem.quantity = 0;
				}
			}
			// ������� ������ ������ ����
			if (buttons[numberButton].CheckRight(*rw))
			{
				// ���� � ���� ���� �������, � � ������ ����
				if (mouseItem.number != 0 && items[i][j].number == 0)
				{
					items[i][j].number = mouseItem.number;
					items[i][j].quantity = 1;
					mouseItem.quantity -= 1;
					if (mouseItem.quantity == 0)
					{
						mouseItem.number = 0;
					}
				}
				// ���� � ���� ��� ��������, � � ������ ����
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

			// ���� ����������� 0 - ������� ������
			if (items[i][j].quantity == 0)
			{
				items[i][j].number = 0;
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

	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.Rectangle(rw.get(), sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	
	// ��� ����� �� ����������� ���������
	for (int i = 0; i < itemsMiniWorkbench.size(); i++)
	{
		for (int j = 0; j < itemsMiniWorkbench[0].size(); j++)
		{
			int numberButton = i * itemsMiniWorkbench.size() + (items[0].size() * items.size()) + j;
			// ������� ����� ������ ����
			if (buttons[numberButton].CheckLeft(*rw))
			{
				// ���� � � ���� � � ������ ���� �������
				if (itemsMiniWorkbench[i][j].number != 0 && mouseItem.number != 0)
				{
					// ���� �������� ���������� - �������
					if (itemsMiniWorkbench[i][j].number == mouseItem.number)
					{
						itemsMiniWorkbench[i][j].quantity += mouseItem.quantity;
						mouseItem.number = 0;
						mouseItem.quantity = 0;
					}
					// ���� ������ - ��������
					else
					{
						ItemStruct intermediateItem = mouseItem;
						mouseItem = itemsMiniWorkbench[i][j];
						itemsMiniWorkbench[i][j] = intermediateItem;
					}
				}
				// ���� � ������ ���� �������, � � ���� ����
				else if (itemsMiniWorkbench[i][j].number != 0)
				{
					mouseItem = itemsMiniWorkbench[i][j];
					itemsMiniWorkbench[i][j].number = 0;
					itemsMiniWorkbench[i][j].quantity = 0;
				}
				// ���� ������� ���� � ����, �� ���� � ������
				else if (mouseItem.number != 0)
				{
					itemsMiniWorkbench[i][j] = mouseItem;
					mouseItem.number = 0;
					mouseItem.quantity = 0;
				}
			}
			// ������� ������ ������ ����
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

			// ���������
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
// ��������� ������ ����� ��������� (�� ����� ��������)
void Inventory::DrawNear(int mouseWheel)
{
	functions.Rectangle(rw.get(), sf::Vector2f(302, 598), sf::Vector2f(676, 82), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	
	for (int i = 0; i < items.size(); i++)
	{
		// ���� 0 - ������� ������
		if (items[i][3].quantity == 0)
		{
			items[i][3].number = 0;
		}

		// ���������
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
