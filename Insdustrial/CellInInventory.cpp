#include "CellInInventory.h"

CellInInventory::CellInInventory(std::shared_ptr<sf::RenderWindow> _rw,
	sf::Vector2f position, bool _put, bool _take,
	std::vector<sf::Texture*>& _textures, std::vector<sf::Color> _colorsInventory)
{
	rw = _rw;
	functions = Functions(rw);

	itemsSprites = StaticSprites(_textures);

	colorsInventory = _colorsInventory;

	put = _put;
	take = _take;

	item = Item(0, 0);
	
	button = OldButton(position, sf::Vector2f(64, 64), L"",
		colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
		sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25);
}

CellInInventory::CellInInventory(std::shared_ptr<sf::RenderWindow> _rw,
	sf::Vector2f position, bool _put,
	std::vector<sf::Texture*>& _textures, std::vector<sf::Color> _colorsInventory)
{
	rw = _rw;
	functions = Functions(rw);

	itemsSprites = StaticSprites(_textures);

	put = _put;
	take = true;

	colorsInventory = _colorsInventory;

	item = Item(0, 0);

	button = OldButton(position, sf::Vector2f(64, 64), L"",
		colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
		sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25);
}

void CellInInventory::DrawCell()
{
	button.Draw(*rw);
	sf::Vector2f positionInventory = button.coords;
	if (item.number != ItemEnum::empty)
	{
		itemsSprites.DrawItemSprite(rw.get(), item.number, positionInventory, 64);
		// Написать колличество
		functions.PrintText(std::to_string(item.quantity),
			sf::Vector2f(positionInventory.x + 35, positionInventory.y + 35),
			25, sf::Color(250, 250, 250));
	}

}

void CellInInventory::DrawName()
{
	// Отрисовка названия
	if (item.number != ItemEnum::empty && button.Aim(*rw))
	{
		sf::Vector2f positionInventory = button.coords;
		sf::String name = item.name;
		int sizeSimbol = 20;
		functions.DrawRectangle(sf::Vector2f(positionInventory.x + 65, positionInventory.y),
			sf::Vector2f(sizeSimbol * name.getSize() / 1.8f + 10, 35), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 2);
		functions.PrintText(name, sf::Vector2f(positionInventory.x + 70, positionInventory.y), sizeSimbol, sf::Color(250, 250, 250));
	}
}

bool CellInInventory::Take(Item& mouseItem)
{
	//  Взять предмет левой кнопкой мыши
	if (button.CheckLeft(*rw))
	{
		if ((mouseItem.number == ItemEnum::empty || item.number == mouseItem.number) && item.number != ItemEnum::empty)
		{
			//mouseItem = item;
			mouseItem.NumberUpdate(item.number);
			mouseItem.quantity += item.quantity;
			item.NumberUpdate(ItemEnum::empty);
			return true;
		}
	}
	return false;
}

void CellInInventory::WhileOpen(Item& mouseItem)
{
	// Нажатие левой кнопки мыши
	if (button.CheckLeft(*rw))
	{
		// Если и в мыши и в ячейке есть предмет
		if (item.number != ItemEnum::empty && mouseItem.number != ItemEnum::empty)
		{
			if (put)
			{
				// Если предметы одинаковые - сложить
				if (item.number == mouseItem.number)
				{
					item.quantity += mouseItem.quantity;
					mouseItem.NumberUpdate(ItemEnum::empty);
				}
				// Если разные - поменять
				else
				{
					Item intermediateItem = mouseItem;
					mouseItem = item;
					item = intermediateItem;
				}
			}
		}
		// Если в ячейке есть предмет, а в мышке нету
		else if (item.number != ItemEnum::empty)
		{
			mouseItem = item;
			item.NumberUpdate(ItemEnum::empty);
		}
		// Если предмет есть в мыши, но нету в ячейке
		else if (mouseItem.number != ItemEnum::empty && put)
		{
			item = mouseItem;
			mouseItem.NumberUpdate(ItemEnum::empty);
		}
	}
	// Нажатие правой кнопки мыши
	if (button.CheckRight(*rw))
	{
		// Если в мыши есть предмет, а в ячейке нету
		if (mouseItem.number != ItemEnum::empty && put)
		{
			if (item.number == mouseItem.number)
			{
				item.quantity += 1;
				mouseItem.quantity -= 1;
			}
			else if (item.number == ItemEnum::empty)
			{
				item.NumberUpdate(mouseItem.number);
				item.quantity = 1;
				mouseItem.quantity -= 1;
			}
		}
		// Если в мыши нет предмета, а в ячейке есть
		if (mouseItem.number == ItemEnum::empty && item.number != ItemEnum::empty)
		{
			mouseItem.NumberUpdate(item.number);
			if (item.quantity == 1)
			{
				mouseItem.quantity = 1;
				item.NumberUpdate(ItemEnum::empty);
			}
			else
			{
				mouseItem.quantity = item.quantity / 2;
				item.quantity = item.quantity - mouseItem.quantity;
			}
		}
	}

	if (item.number == ItemEnum::empty)
	{
		item.quantity = 0;
	}

	// Если колличество 0 - сделать пустой
	if (item.quantity == 0)
	{
		item.NumberUpdate(ItemEnum::empty);
	}
	if (mouseItem.quantity == 0)
	{
		mouseItem.NumberUpdate(ItemEnum::empty);
	}
}
