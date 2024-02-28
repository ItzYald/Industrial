#include "MineInventory.h"

MineInventory::MineInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	// ����
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	// ������ � ���������� (����� 10 x 4)
	cells = std::vector<CellInInventory>();
	for (int i = 0; i < 10; i++)
	{
		cells.push_back(CellInInventory(_rw, sf::Vector2f(300, 200 + 68 * i), false, _textures));
	}

	itemsSprites = StaticSprites(_textures);
}

void MineInventory::Next()
{

}

void MineInventory::Draw()
{
	DrawCommon(cells);
}

void MineInventory::Update(Inventory& playerInventory)
{
	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// ��� ����� �� ����������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].Update(playerInventory.mouseItem);
	}

	playerInventory.Update();
}
