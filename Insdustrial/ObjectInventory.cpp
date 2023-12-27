#include "ObjectInventory.h"

void ObjectInventory::DrawCommon(std::vector<std::vector<ItemStruct>> items)
{

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].Draw(*rw);
	}

	// Отрисовка спрайтов предметов
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			int numberButton = i * items[0].size() + j;
			sf::Vector2f positionInventory = buttons[numberButton].coords;
			if (items[i][j].number != 0)
			{
				itemsSprites.DrawItemSprite(rw.get(), items[i][j].number, positionInventory, sf::Vector2f(4, 4));
				// Написать колличество
				functions.PrintText(std::to_string(items[i][j].quantity),
					sf::Vector2f(positionInventory.x + 35, positionInventory.y + 35),
					25, sf::Color(250, 250, 250));
			}
		}
	}

	// Отрисовка описания предметов
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{
			int numberButton = i * items[0].size() + j;
			if (items[i][j].number != 0 && buttons[numberButton].Aim(*rw))
			{
				sf::Vector2f positionInventory = buttons[numberButton].coords;
				sf::String name = itemsSprites.GetName(items[i][j].number);
				int sizeSimbol = 20;
				functions.DrawRectangle(sf::Vector2f(positionInventory.x + 65, positionInventory.y),
					sf::Vector2f(sizeSimbol * name.getSize() / 1.8 + 10, 35), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 2);
				functions.PrintText(name, sf::Vector2f(positionInventory.x + 70, positionInventory.y), sizeSimbol, sf::Color(250, 250, 250));
			}
		}
	}

}

void ObjectInventory::DrawCommon(std::vector<ItemStruct> items)
{
	// Отрисовка описания предметов
	for (int i = 0; i < items.size(); i++)
	{
		buttons[i].Draw(*rw);

		// Отрисовка предмета в ячейке 
		if (items[i].number != 0)
		{
			itemsSprites.DrawItemSprite(rw.get(), items[i].number, buttons[i].coords, sf::Vector2f(4, 4));
			functions.PrintText(std::to_string(items[i].quantity), sf::Vector2f(buttons[i].coords.x + 40, buttons[i].coords.y + 40), 20, sf::Color(250, 250, 250));
		}

		if (items[i].number != 0 && buttons[i].Aim(*rw))
		{
			sf::Vector2f positionInventory = buttons[i].coords;
			sf::String name = itemsSprites.GetName(items[i].number);
			int sizeSimbol = 20;
			functions.DrawRectangle(sf::Vector2f(positionInventory.x + 65, positionInventory.y),
				sf::Vector2f(sizeSimbol * name.getSize() / 1.8 + 10, 35), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 2);
			functions.PrintText(name, sf::Vector2f(positionInventory.x + 70, positionInventory.y), sizeSimbol, sf::Color(250, 250, 250));
		}
	}

}
