#include "CompressorInventory.h"

CompressorInventory::CompressorInventory(
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

void CompressorInventory::PlayUpdate()
{
	progress.Progress(energy, cells, cells[0].item.whatCompress, 1);
}

void CompressorInventory::Draw()
{
	progress.Draw();
	AllDraw();
	DrawCommon(cells);
}

void CompressorInventory::WhileOpen(Inventory& playerInventory)
{
	for (auto& thisCell : cells)
	{
		thisCell.WhileOpen(playerInventory.mouseItem);
	}

	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	Draw();
	playerInventory.WhileOpen();

}
