#include "WireInventory.h"

WireInventory::WireInventory(
	std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
	int _maxEnergy, int _power, std::vector<sf::Texture>& _itemTextures)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;
	power = _power;

	maxEnergy = _maxEnergy;

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}
	energy = 0;
}

void WireInventory::Update(Inventory& playerInventory)
{
	AllUpdate(playerInventory);
}

void WireInventory::Next()
{
	AllNext();
}

void WireInventory::Draw()
{
	AllDraw();
}

