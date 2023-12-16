#include "WorbenchInventory.h"

WorbenchInventory::WorbenchInventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	// ����
	rw = _rw;
	functions = Functions(rw);

	// �������� � ���� ��� ������
	items = std::vector<std::vector<ItemStruct>>();
	for (int i = 0; i < 3; i++)
	{
		items.push_back(std::vector<ItemStruct>());
		for (int j = 0; j < 3; j++)
		{
			items[i].push_back(ItemStruct());
		}
	}
	// ��������� �������
	madeItem = ItemStruct();
	
	itemsSprites = StaticSprites();
	// ����� ���� ������
	collectionCraft = std::vector<std::vector<std::vector<int>>>();
	collectionResult = std::vector<int>();

	// ���������� ������ �������
	for (int i = 0; i < 5; i++)
	{
		// ��������� ������
		std::vector<std::vector<int>> mas = std::vector<std::vector<int>>();
		for (int j = 0; j < 3; j++)
		{
			// ������ ��������� ������
			std::vector<int> mas2 = std::vector<int>();
			for (int k = 0; k < 3; k++)
			{
				mas2.push_back(0);
			}
			mas.push_back(mas2);
		}
		collectionCraft.push_back(mas);
		collectionResult.push_back(0);
	}

	AddCraft(0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6);

}

void WorbenchInventory::AddCraft(int number,
	int craft1, int craft2, int craft3, int craft4, int craft5, int craft6, int craft7, int craft8, int craft9,
	int result)
{
	collectionCraft[number][0][0] = craft1;
	collectionCraft[number][0][1] = craft2;
	collectionCraft[number][0][2] = craft3;
	collectionCraft[number][1][0] = craft4;
	collectionCraft[number][1][1] = craft5;
	collectionCraft[number][1][2] = craft6;
	collectionCraft[number][2][0] = craft7;
	collectionCraft[number][2][1] = craft8;
	collectionCraft[number][2][2] = craft9;
	collectionResult[number] = result;
}

void WorbenchInventory::Craft()
{
	for (int i = 0; i < collectionCraft.size(); i++)
	{
		// ���� ����� ����� ���� 
		if (collectionResult[i] != 0)
		{
			// ������� ������ ������ �������, ���� 9 - ��������, ����� - ���
			int isCraft = 0;
			// �������� ������ ������ ������
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (collectionCraft[i][j][k] == items[j][k].number)
					{
						isCraft += 1;
					}
				}
			}
			// ���� ����� ������
			if (isCraft == 9)
			{
				if (madeItem.number == 0)
				{
					madeItem.number = collectionResult[i];
					madeItem.quantity = 1;
				}
				//else if (madeItem.number == collectionResult[i])
				//{
				//	madeItem.quantity += 1;
				//}
			}
		}
		else
		{
			break;
		}
	}

	// ���� ��� ������ - ������� ����������� 0
	if (madeItem.number == 0)
	{
		madeItem.quantity == 0;
	}
	// ���� ����������� 0 - ������� ��� ������
	if (madeItem.quantity == 0)
	{
		madeItem.number = 0;
	}

}

void WorbenchInventory::Draw(Inventory& playerInventory)
{
	if (buttons.size() < 1)
	{
		for (int i = 0; i < items.size(); i++)
		{
			for (int j = 0; j < items[0].size(); j++)
			{
				buttons.push_back(Button(sf::Vector2f(350 + 8 + i * 66, 130 + 8 + j * 66), sf::Vector2f(64, 64), L"",
					sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(100, 100, 100), sf::Color::Transparent,
					sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
			}
		}
		buttons.push_back(Button(sf::Vector2f(700, 130 + 8 + 1 * 66), sf::Vector2f(64, 64), L"",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(100, 100, 100), sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
	}

	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.Rectangle(rw.get(), sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// ��� ����� �� ����������� ���� ��� ������
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{

			int numberButton = i * items[0].size() + j;
			// ������� ����� ������ ����
			if (buttons[numberButton].CheckLeft(*rw))
			{
				// ���� � � ���� � � ������ ���� �������
				if (items[i][j].number != 0 && playerInventory.mouseItem.number != 0)
				{
					// ���� �������� ���������� - �������
					if (items[i][j].number == playerInventory.mouseItem.number)
					{
						items[i][j].quantity += playerInventory.mouseItem.quantity;
						playerInventory.mouseItem.number = 0;
						playerInventory.mouseItem.quantity = 0;
					}
					// ���� ������ - ��������
					else
					{
						ItemStruct intermediateItem = playerInventory.mouseItem;
						playerInventory.mouseItem = items[i][j];
						items[i][j] = intermediateItem;
					}
				}
				// ���� � ������ ���� �������, � � ���� ����
				else if (items[i][j].number != 0)
				{
					playerInventory.mouseItem = items[i][j];
					items[i][j].number = 0;
					items[i][j].quantity = 0;
				}
				// ���� ������� ���� � ����, �� ���� � ������
				else if (playerInventory.mouseItem.number != 0)
				{

					items[i][j] = playerInventory.mouseItem;
					playerInventory.mouseItem.number = 0;
					playerInventory.mouseItem.quantity = 0;
				}
			}
			// ������� ������ ������ ����
			if (buttons[numberButton].CheckRight(*rw))
			{
				// ���� � ���� ���� �������, � � ������ ����
				if (playerInventory.mouseItem.number != 0 && items[i][j].number == 0)
				{
					items[i][j].number = playerInventory.mouseItem.number;
					items[i][j].quantity = 1;
					playerInventory.mouseItem.quantity -= 1;
					if (playerInventory.mouseItem.quantity == 0)
					{
						playerInventory.mouseItem.number = 0;
					}
				}
				// ���� � ���� ��� ��������, � � ������ ����
				if (playerInventory.mouseItem.number == 0 && items[i][j].number != 0)
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

			// ���������
			sf::Vector2f positionInventory = buttons[numberButton].coords;
			if (items[i][j].number != 0)
			{
				itemsSprites.DrawItemSprite(rw.get(), items[i][j].number, positionInventory, sf::Vector2f(4, 4));
				functions.PrintText(std::to_string(items[i][j].quantity), sf::Vector2f(positionInventory.x + 40, positionInventory.y + 40), 20, sf::Color(250, 250, 250));
			}

			buttons[numberButton].Draw(*rw);
		}
	}
	// ���������� ��������� ������
	buttons[9].Draw(*rw);
	sf::Vector2f positionInventory = buttons[9].coords;
	itemsSprites.DrawItemSprite(rw.get(), madeItem.number, positionInventory, sf::Vector2f(4, 4));
	functions.PrintText(std::to_string(madeItem.quantity), sf::Vector2f(positionInventory.x + 40, positionInventory.y + 40), 20, sf::Color(250, 250, 250));

	Craft();

	// ������� ��������� ������
	if (buttons[9].CheckLeft(*rw) && madeItem.number != 0)
	{
		playerInventory.mouseItem = madeItem;
		madeItem.number = 0;
		madeItem.quantity = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				items[i][j].quantity -= 1;
				if (items[i][j].quantity == 0)
				{
					items[i][j].number = 0;
				}
			}
		}
	}
	playerInventory.Draw();
}

