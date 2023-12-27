#include "ObjectInventory.h"

void ObjectInventory::DrawItemName(std::vector<std::vector<ItemStruct>> items)
{

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
