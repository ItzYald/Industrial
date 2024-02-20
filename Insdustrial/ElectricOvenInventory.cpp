#include "ElectricOvenInventory.h"

ElectricOvenInventory::ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	progress = ProgressInventory(_rw);

	// 3 ячейки в инвентаре
	cells = std::vector<CellInInventory>();
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 130), true, _textures));
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 306), true, _textures));
	cells.push_back(CellInInventory(rw, sf::Vector2f(670, 218), false, _textures));

	energy = 0;
	maxEnergy = 1000;

	itemsSprites = StaticSprites(_textures);
}

void ElectricOvenInventory::Burn()
{
	// Раньше был редстоун, но его больше нет
	//if (cells[1].item.number == 10 && fuel < maxFuel)
	//{
	//	fuel += 10;
	//	cells[1].item.quantity -= 1;
	//	if (fuel > maxFuel)
	//	{
	//		fuel = maxFuel;
	//	}
	//}

	progress.Progress(energy, cells, cells[0].item.whatBurn, 1);
	if (cells[0].item.whatBurn && energy > 0)
	{
		energy -= 1;
	}

	if (energy > maxEnergy)
	{
		energy = maxEnergy;
	}

}

void ElectricOvenInventory::Draw()
{
	//AllDraw();
	progress.Draw();
	DrawCommon(cells);
	// Топливо печки
	functions.DrawRectangle(sf::Vector2f(400, 180), sf::Vector2f(30, 140), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxEnergy != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(400, 320), sf::Vector2f(30, ((energy / (float)maxEnergy)) * -140), sf::Color::Red, sf::Color(255, 200, 0));
	}

}

void ElectricOvenInventory::Update(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Цикл по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].Update(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.Update();
}
