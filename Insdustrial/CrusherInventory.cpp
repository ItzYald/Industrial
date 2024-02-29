#include "CrusherInventory.h"

CrusherInventory::CrusherInventory(
	std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
	int _maxEnergy, std::vector<sf::Texture*>& _textures)
	: EnergyObjectInventory(_rw, _colorsInventory, _maxEnergy)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;
	itemsSprites = StaticSprites(_textures);

	progress = ProgressInventory(_rw, _textures, cells);
}

void CrusherInventory::PlayUpdate()
{
	progress.Progress(energy, cells, cells[0].item.whatCrush.x, cells[0].item.whatCrush.y);
}

void CrusherInventory::Draw()
{
	progress.Draw();
	AllDraw();
	DrawCommon(cells);

}

void CrusherInventory::WhileOpen(Inventory& playerInventory)
{
	for (auto& thisCell : cells)
	{
		thisCell.WhileOpen(playerInventory.mouseItem);
	}

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.WhileOpen();

}
