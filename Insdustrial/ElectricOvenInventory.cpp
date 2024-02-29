#include "ElectricOvenInventory.h"

ElectricOvenInventory::ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	progress = ProgressInventory(_rw, _textures, cells);

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

	if (energy > maxEnergy)
	{
		energy = maxEnergy;
	}

}

void ElectricOvenInventory::PlayUpdate()
{
	Burn();
}

void ElectricOvenInventory::Draw()
{
	progress.Draw();
	DrawCommon(cells);
	AllDraw();
}

void ElectricOvenInventory::WhileOpen(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Цикл по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].WhileOpen(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.WhileOpen();
}
