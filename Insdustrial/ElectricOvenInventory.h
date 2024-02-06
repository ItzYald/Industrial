#pragma once
#include "OvenInventory.h"

class ElectricOvenInventory : public OvenInventory

{
public:
	ElectricOvenInventory(){ }
	ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);

	void Burn();
	void Draw();
	void Update(Inventory& playerInventory);

};

