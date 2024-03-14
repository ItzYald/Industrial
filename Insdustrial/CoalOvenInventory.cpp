#include "CoalOvenInventory.h"

CoalOvenInventory::CoalOvenInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;
	itemsSprites = StaticSprites(_textures);

	progress = ProgressInventory(_rw, _textures, cells, colorsInventory);

	transferItem = &cells[2].item;

	energy = 0;
	maxEnergy = 0;

}

void CoalOvenInventory::Burn()
{
	if (cells[1].item.whatFuel && cells[0].item.whatBurn
		&& (cells[0].item.whatBurn == cells[2].item.number
			|| cells[2].item.number == ItemEnum::empty))
	{
		if (energy <= 0)
		{
			maxEnergy = cells[1].item.whatFuel * 60;
			energy = maxEnergy;
			cells[1].item.quantity -= 1;
		}
		if (progress.whatProgress <= 0)
		{
			progress.whatProgress = 120;
		}
	}

	progress.Progress(energy, cells, cells[0].item.whatBurn, 1);
	
	energy -= 1;
}

void CoalOvenInventory::PlayUpdate()
{
	Burn();
}

void CoalOvenInventory::Draw()
{
	progress.Draw();
	DrawCommon(cells);
	// Топливо печки
	functions.DrawRectangle(sf::Vector2f(480, 220), sf::Vector2f(30, 60), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxEnergy != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(480, 280), sf::Vector2f(30, ((energy / (float)maxEnergy)) * -60), sf::Color::Red, sf::Color(255, 200, 0), 0);
	}

}

void CoalOvenInventory::WhileOpen(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Два цикла по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].WhileOpen(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.WhileOpen();
}
