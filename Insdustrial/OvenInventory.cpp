#include "OvenInventory.h"

void OvenInventory::AllBurn()
{
	progress.Progress(fuel, cells, cells[0].item.whatBurn, 1);
}

void OvenInventory::AllDraw()
{
	//// Отрисовать окно интерфейса
	//functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	//// Прогрессбар печки
	//functions.DrawRectangle(sf::Vector2f(550, 240), sf::Vector2f(90, 20), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	//functions.DrawRectangleGradient(sf::Vector2f(550, 240), sf::Vector2f((120 - progress.whatProgress) * 0.75f, 20), sf::Color::Red, sf::Color(255, 200, 1));
	progress.Draw();
	DrawCommon(cells);
}
