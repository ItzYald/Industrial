#include "ProgressInventory.h"

ProgressInventory::ProgressInventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	functions = Functions(_rw);
	whatProgress = 120;
	previousItemProgress = 0;
}

bool ProgressInventory::Progress(float& energy, std::vector<CellInInventory>& cells, int whatNext, int quantity)
{
	bool res = false;
	if (previousItemProgress != cells[0].item.number)
	{
		whatProgress = 120;
	}
	previousItemProgress = cells[0].item.number;
	if ((cells[2].item.number == 0 || cells[2].item.number == whatNext))
	{
		if (energy > 0)
		{
			if (whatNext != 0)
			{
				energy -= 1;
				whatProgress -= 1;
				if (whatProgress == 0)
				{
					whatProgress = 120;
					if (cells[2].item.number == whatNext && cells[2].item.number != 0)
					{
						cells[2].item.quantity += 1;
					}
					else
					{
						cells[2].item.NumberUpdate(whatNext);
						cells[2].item.quantity = quantity;
					}

					cells[0].item.quantity -= 1;
					if (cells[0].item.quantity == 0)
					{
						cells[0].item.NumberUpdate(0);
					}
					res = true;
				}
			}
			else
			{
				whatProgress = 120;
			}
		}
		else
		{
			if (whatProgress < 120)
			{
				whatProgress += 1;
			}
		}
	}

	if (energy < 0)
	{
		energy = 0;
	}
	return res;
}

void ProgressInventory::DrawEnergy(int energy, int maxEnergy, sf::Color color)
{
	if (maxEnergy != 0)
	{
		// Отрисовка количества энергии
		functions.DrawRectangleGradient(
			sf::Vector2f(400, 350), sf::Vector2f(30, (energy / (float)maxEnergy) * -200),
			sf::Color::Red, sf::Color(255, 200, 0));
		functions.PrintText(std::to_string((int)energy) + " / " + std::to_string(maxEnergy) + " en",
			sf::Vector2f(310, 355), 20, color);
	}
}

void ProgressInventory::Draw()
{
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	// Прогрессбар
	functions.DrawRectangle(sf::Vector2f(550, 240), sf::Vector2f(90, 20), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	functions.DrawRectangleGradient(sf::Vector2f(550, 240), sf::Vector2f((120 - whatProgress) * 0.75f, 20), sf::Color::Red, sf::Color(255, 200, 1));
}
