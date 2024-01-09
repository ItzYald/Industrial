#include "ObjectInventory.h"

void ObjectInventory::LoadColorInventoryFromFile()
{
	colorsInventory.clear();
	// Файл с цветами
	std::fstream colorFile("Files/ColorInventory.txt");
	// Построчное чтение
	std::string line;
	std::string line2;
	line2 = "";
	while (std::getline(colorFile, line))
	{
		sf::Color color = sf::Color(0, 0, 0);
		// Красный
		line2.push_back(line[0]);
		line2.push_back(line[1]);
		line2.push_back(line[2]);
		color.r = std::stoi(line2);
		line2.clear();
		// Зеленый
		line2.push_back(line[4]);
		line2.push_back(line[5]);
		line2.push_back(line[6]);
		color.g = std::stoi(line2);
		line2.clear();
		// Синий
		line2.push_back(line[8]);
		line2.push_back(line[9]);
		line2.push_back(line[10]);
		color.b = std::stoi(line2);
		colorsInventory.push_back(color);
		//std::cout << line2 << std::endl;
		line2.clear();
	}

}

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
			functions.PrintText(std::to_string(items[i].quantity), sf::Vector2f(buttons[i].coords.x + 35, buttons[i].coords.y + 35), 25, sf::Color(250, 250, 250));
		}
		// Отрисовка названия предмета
		if (items[i].number != 0 && buttons[i].Aim(*rw))
		{
			sf::Vector2f positionInventory = buttons[i].coords;
			sf::String name = itemsSprites.GetName(items[i].number);
			int sizeSimbol = 20;
			functions.DrawRectangle(sf::Vector2f(positionInventory.x + 65, positionInventory.y),
				sf::Vector2f(sizeSimbol * name.getSize() / 1.8 + 10, 35), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 2);
			functions.PrintText(name, sf::Vector2f(positionInventory.x + 65, positionInventory.y), sizeSimbol, sf::Color(250, 250, 250));
		}
	}

}

void ObjectInventory::DrawCommon(std::vector<std::vector<CellInInventory>> cells)
{
	// Отрисовка спрайтов предметов
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].button.Draw(*rw);
			sf::Vector2f positionInventory = cells[i][j].button.coords;
			if (cells[i][j].item.number != 0)
			{
				itemsSprites.DrawItemSprite(rw.get(), cells[i][j].item.number, positionInventory, sf::Vector2f(4, 4));
				// Написать колличество
				functions.PrintText(std::to_string(cells[i][j].item.quantity),
					sf::Vector2f(positionInventory.x + 35, positionInventory.y + 35),
					25, sf::Color(250, 250, 250));
			}
		}
	}

	// Отрисовка описания предметов
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			if (cells[i][j].item.number != 0 && cells[i][j].button.Aim(*rw))
			{
				sf::Vector2f positionInventory = cells[i][j].button.coords;
				sf::String name = itemsSprites.GetName(cells[i][j].item.number);
				int sizeSimbol = 20;
				functions.DrawRectangle(sf::Vector2f(positionInventory.x + 65, positionInventory.y),
					sf::Vector2f(sizeSimbol * name.getSize() / 1.8 + 10, 35), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 2);
				functions.PrintText(name, sf::Vector2f(positionInventory.x + 70, positionInventory.y), sizeSimbol, sf::Color(250, 250, 250));
			}
		}
	}

}
