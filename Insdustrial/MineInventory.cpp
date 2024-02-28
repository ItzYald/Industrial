#include "MineInventory.h"

MineInventory::MineInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	// Окно
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	cells = std::vector<CellInInventory>();
	for (int i = 0; i < 4; i++)
	{
		cells.push_back(CellInInventory(_rw, sf::Vector2f(500 + 8 + 66 * i, 200), false, _textures));
	}

	maxEnergy = 100;
	energy = 0;

	itemsSprites = StaticSprites(_textures);
}

void MineInventory::Next()
{
	AllNext();
}

void MineInventory::Draw()
{
	AllDraw();
	DrawCommon(cells);
}

void MineInventory::Update(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	AllNext();

	// Два цикла по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].Update(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.Update();
}
