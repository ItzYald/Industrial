#include "CrusherInventory.h"

CrusherInventory::CrusherInventory(
	std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
	int _maxEnergy, std::vector<sf::Texture>& _textures)
	: EnergyObjectInventory(_rw, _colorsInventory, _maxEnergy)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;
	itemsSprites = StaticSprites(_textures);

	progress = ProgressInventory(_rw);

	// 3 €чейки в инвентаре
	cells = std::vector<CellInInventory>();
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 130), true, _textures));
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 306), true, _textures));
	cells.push_back(CellInInventory(rw, sf::Vector2f(670, 218), false, _textures));
}

void CrusherInventory::Next()
{
	progress.Progress(energy, cells, cells[0].item.whatCrush.x, cells[0].item.whatCrush.y);
}

void CrusherInventory::Draw()
{

	progress.Draw();
	functions.DrawRectangle(sf::Vector2f(400, 150), sf::Vector2f(30, 200), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	progress.DrawEnergy(energy, maxEnergy, colorsInventory[0]);
	DrawCommon(cells);

}

void CrusherInventory::Update(Inventory& playerInventory)
{
	for (auto& thisCell : cells)
	{
		thisCell.Update(playerInventory.mouseItem);
	}

	// ”знать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// ќтрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.Update();

}
