#include "PipeInventory.h"

PipeInventory::PipeInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;
	itemsSprites = StaticSprites(_textures);

	transferCell = CellInInventory(
		rw, sf::Vector2f(608, 200), false, false, _textures, _colorsInventory);
	transferItem = &transferCell.item;
	acceptItem = &transferCell.item;
}

void PipeInventory::PlayUpdate()
{
	
}

void PipeInventory::Draw()
{
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	transferCell.button.Draw(*rw);
	transferCell.DrawCell();

}

void PipeInventory::WhileOpen(Inventory& playerInventory)
{
	transferCell.WhileOpen(playerInventory.mouseItem);

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);

	Draw();
	playerInventory.WhileOpen();

}
