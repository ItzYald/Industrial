#include "CrusherInventory.h"

CrusherInventory::CrusherInventory(
	std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
	int _maxEnergy, std::vector<sf::Texture*>& _textures)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;
	itemsSprites = StaticSprites(_textures);

	maxEnergy = _maxEnergy;
	energy = 0;

	progress = ProgressInventory(_rw, _textures, cells, colorsInventory);
	transferItem = &cells[2].item;
	acceptItem = &cells[0].item;
}

void CrusherInventory::PlayUpdate()
{
	progress.Progress(energy, cells, cells[0].item.whatCrush.x, cells[0].item.whatCrush.y);
}

void CrusherInventory::Draw()
{
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
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

	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);

	Draw();
	playerInventory.WhileOpen();

}
