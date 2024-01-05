#include "OvenInventory.h"

OvenInventory::OvenInventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	rw = _rw;
	functions = Functions(rw);
	LoadColorInventoryFromFile();

	// 3 ������ � ���������
	items = std::vector<ItemStruct>();
	items.push_back(ItemStruct());
	items.push_back(ItemStruct());
	items.push_back(ItemStruct());

	fuel = 0;
	whatBurn = 120;
	maxFuel = 0;

	itemsSprites = StaticSprites();

}

void OvenInventory::AllBurn()
{
	if (fuel > 0)
	{
		fuel -= 1;
		if (itemsSprites.IsBurn(items[0].number))
		{
			whatBurn -= 1;
			if (whatBurn == 0)
			{
				whatBurn = 120;
				if (items[2].number == itemsSprites.IsBurn(items[0].number) && items[2].number != 0)
				{
					items[2].quantity += 1;
				}
				else
				{
					items[2].number = itemsSprites.IsBurn(items[0].number);
					items[2].quantity = 1;
				}

				items[0].quantity -= 1;
				if (items[0].quantity == 0)
				{
					items[0].number = 0;
				}
			}
		}
		else
		{
			whatBurn = 120;
		}
	}
	else
	{
		if (whatBurn < 120)
		{
			whatBurn += 1;
		}
	}
}

void OvenInventory::Burn()
{
	if (previousItemBurn != items[0].number)
	{
		whatBurn = 120;
	}
	previousItemBurn = items[0].number;

	if (items[2].number == 0 || items[2].number == itemsSprites.IsBurn(items[0].number))
	{
		if (fuel == 0)
			maxFuel = 0;

		if (itemsSprites.IsFuel(items[1].number) && itemsSprites.IsBurn(items[0].number))
		{
			if (fuel <= 0)
			{
				maxFuel = itemsSprites.IsFuel(items[1].number) * 60;
				fuel = maxFuel;
				items[1].quantity -= 1;
			}
			if (whatBurn <= 0)
			{
				whatBurn = 120;
			}
		}
		AllBurn();
	}
	else
	{
		fuel -= 1;
	}

	if (fuel < 0)
	{
		fuel = 0;
	}
}

void OvenInventory::Draw(Inventory& playerInventory)
{
	DrawCommon(items);
}

void OvenInventory::Update(Inventory& playerInventory)
{
	if (buttons.size() < 1)
	{
		// ���� ��� ����, ��� �����
		buttons.push_back(Button(sf::Vector2f(460, 130), sf::Vector2f(64, 64), L"",
			colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));

		// ���� ��� ����
		buttons.push_back(Button(sf::Vector2f(460, 306), sf::Vector2f(64, 64), L"",
			colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));

		// ���� ��� ����, ��� ����������
		buttons.push_back(Button(sf::Vector2f(670, 218), sf::Vector2f(64, 64), L"",
			colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
	}

	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	// ����������� �����
	functions.DrawRectangle(sf::Vector2f(550, 240), sf::Vector2f(90, 20), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	functions.DrawRectangleGradient(sf::Vector2f(550, 240), sf::Vector2f((120 - whatBurn) * 0.75f, 20), sf::Color::Red, sf::Color(255, 200, 0));
	// ������� �����
	functions.DrawRectangle(sf::Vector2f(480, 220), sf::Vector2f(30, 60), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxFuel != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(480, 280), sf::Vector2f(30, ((fuel / (float)maxFuel)) * -60), sf::Color::Red, sf::Color(255, 200, 1));
	}

	// ������ ������� ���� �� ����� ��� ������ �������� ����������
	if (buttons[2].CheckRight(*rw) && playerInventory.mouseItem.number == 0 && items[2].number != 0)
	{
		playerInventory.mouseItem.number = items[2].number;
		if (items[2].quantity == 1)
		{
			playerInventory.mouseItem.quantity = 1;
			items[2].number = 0;
			items[2].quantity = 0;
		}
		else
		{
			playerInventory.mouseItem.quantity = items[2].quantity / 2;
			items[2].quantity = items[2].quantity - playerInventory.mouseItem.quantity;
		}
	}
	
	// ���� ��� ������� � ���� ��� ��������
	for (int i = 0; i < 2; i++)
	{
		// ����� ������� ���� �� �����
		if (buttons[i].CheckLeft(*rw))
		{
			if (playerInventory.mouseItem.number != 0 && items[i].number != 0)
			{
				if (items[i].number == playerInventory.mouseItem.number)
				{
					items[i].quantity += playerInventory.mouseItem.quantity;
					playerInventory.mouseItem.number = 0;
					playerInventory.mouseItem.quantity = 0;
				}
				else
				{
					ItemStruct intermediateItem = playerInventory.mouseItem;
					playerInventory.mouseItem = items[i];
					items[i] = intermediateItem;
				}
			}
			else if (playerInventory.mouseItem.number != 0)
			{
				items[i] = playerInventory.mouseItem;
				playerInventory.mouseItem.number = 0;
				playerInventory.mouseItem.quantity = 0;
			}
			else if (items[i].number != 0)
			{
				playerInventory.mouseItem = items[i];
				items[i].number = 0;
				items[i].quantity = 0;
			}
		}
		// ������ ������� ���� �� �����
		if (buttons[i].CheckRight(*rw))
		{

			// ���� � ���� ���� �������, � � ������ ����
			if (playerInventory.mouseItem.number != 0)
			{
				if (items[i].number == playerInventory.mouseItem.number)
				{
					items[i].quantity += 1;
				}
				if (items[i].number == 0)
				{
					items[i].number = playerInventory.mouseItem.number;
					items[i].quantity = 1;
				}
				playerInventory.mouseItem.quantity -= 1;
			}
			// ���� � ���� ��� ��������, � � ������ ����
			if (playerInventory.mouseItem.number == 0 && items[i].number != 0)
			{
				playerInventory.mouseItem.number = items[i].number;
				if (items[i].quantity == 1)
				{
					playerInventory.mouseItem.quantity = 1;
					items[i].number = 0;
					items[i].quantity = 0;
				}
				else
				{
					playerInventory.mouseItem.quantity = items[i].quantity / 2;
					items[i].quantity = items[i].quantity - playerInventory.mouseItem.quantity;
				}
			}
		}
	}
	// ������� ������������� ��������
	if (buttons[2].CheckLeft(*rw))
	{
		if (items[2].number != 0 && playerInventory.mouseItem.number == 0)
		{
			playerInventory.mouseItem = items[2];
			items[2].number = 0;
			items[2].quantity = 0;
		}
	}

	if (items[1].quantity == 0)
	{
		items[1].number = 0;
	}

	Draw(playerInventory);
	playerInventory.Update();
}
