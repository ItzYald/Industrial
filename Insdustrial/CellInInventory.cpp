#include "CellInInventory.h"

CellInInventory::CellInInventory(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f position, bool _put, bool _take)
{
	rw = _rw;
	functions = Functions(rw);

	put = _put;
	take = _take;

	item.number = 0;
	item.quantity = 0;

	LoadColorInventoryFromFile();
	button = Button(position, sf::Vector2f(64, 64), L"",
		colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
		sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25);
}

void CellInInventory::LoadColorInventoryFromFile()
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

void CellInInventory::Update(ItemStruct& mouseItem)
{
	// Нажатие левой кнопки мыши
	if (button.CheckLeft(*rw))
	{
		// Если и в мыши и в ячейке есть предмет
		if (item.number != 0 && mouseItem.number != 0)
		{
			// Если предметы одинаковые - сложить
			if (item.number == mouseItem.number)
			{
				item.quantity += mouseItem.quantity;
				mouseItem.number = 0;
				mouseItem.quantity = 0;
			}
			// Если разные - поменять
			else
			{
				ItemStruct intermediateItem = mouseItem;
				mouseItem = item;
				item = intermediateItem;
			}
		}
		// Если в ячейке есть предмет, а в мыше нету
		else if (item.number != 0)
		{
			mouseItem = item;
			item.number = 0;
			item.quantity = 0;
		}
		// Если предмет есть в мыши, но нету в ячейке
		else if (mouseItem.number != 0)
		{
			item = mouseItem;
			mouseItem.number = 0;
			mouseItem.quantity = 0;
		}
	}
	// Нажатие правой кнопки мыши
	if (button.CheckRight(*rw))
	{
		// Если в мыши есть предмет, а в ячейке нету
		if (mouseItem.number != 0)
		{
			if (item.number == mouseItem.number)
			{
				item.quantity += 1;
				mouseItem.quantity -= 1;
			}
			else if (item.number == 0)
			{
				item.number = mouseItem.number;
				item.quantity = 1;
				mouseItem.quantity -= 1;
			}
		}
		// Если в мыши нет предмета, а в ячейке есть
		if (mouseItem.number == 0 && item.number != 0)
		{
			mouseItem.number = item.number;
			if (item.quantity == 1)
			{
				mouseItem.quantity = 1;
				item.number = 0;
				item.quantity = 0;
			}
			else
			{
				mouseItem.quantity = item.quantity / 2;
				item.quantity = item.quantity - mouseItem.quantity;
			}
		}
	}

	// Если колличество 0 - сделать пустой
	if (item.quantity == 0)
	{
		item.number = 0;
	}
	if (mouseItem.quantity == 0)
	{
		mouseItem.number = 0;
	}
}
