#include "AllInventory.h"


void AllInventory::LoadColorInventoryFromFile()
{
	std::cout << "lol" << std::endl;
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

void AllInventory::DrawCommon(std::vector<std::vector<CellInInventory>> cells)
{
	// Отрисовка спрайтов предметов
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].button.Draw(*rw);
			cells[i][j].DrawCell();
		}
	}

	// Отрисовка описания предметов
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].DrawName();
		}
	}

}

void AllInventory::DrawCommon(std::vector<CellInInventory> cells)
{
	// Отрисовка описания предметов
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].button.Draw(*rw);
		cells[i].DrawCell();
	}

}

