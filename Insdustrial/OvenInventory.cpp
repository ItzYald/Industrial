#include "OvenInventory.h"

void OvenInventory::AllBurn()
{
	if (previousItemBurn2 != cells[0].item.number)
	{
		whatBurn = 120;
	}
	previousItemBurn2 = cells[0].item.number;
	if (cells[2].item.number == 0 || cells[2].item.number == cells[0].item.isBurn)
	{
		if (fuel > 0)
		{
			if (cells[0].item.isBurn)
			{
				whatBurn -= 1;
				if (whatBurn == 0)
				{
					whatBurn = 120;
					if (cells[2].item.number == cells[0].item.isBurn && cells[2].item.number != 0)
					{
						cells[2].item.quantity += 1;
					}
					else
					{
						//cells[2].item.number = cells[0].item.isBurn;
						cells[2].item.NumberUpdate(cells[0].item.isBurn);
						cells[2].item.quantity = 1;
					}

					cells[0].item.quantity -= 1;
					if (cells[0].item.quantity == 0)
					{
						//cells[0].item.number = 0;
						cells[0].item.NumberUpdate(0);
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

	if (fuel < 0)
	{
		fuel = 0;
	}
}

void OvenInventory::AllDraw()
{
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	// Прогрессбар печки
	functions.DrawRectangle(sf::Vector2f(550, 240), sf::Vector2f(90, 20), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	functions.DrawRectangleGradient(sf::Vector2f(550, 240), sf::Vector2f((120 - whatBurn) * 0.75f, 20), sf::Color::Red, sf::Color(255, 200, 0));
	DrawCommon(cells);
}
