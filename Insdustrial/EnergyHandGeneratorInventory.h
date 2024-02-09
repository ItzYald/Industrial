#pragma once
#include "EnergyStorageInventory.h"

class EnergyHandGeneratorInventory : public EnergyStorageInventory
{
public:
	EnergyHandGeneratorInventory(){ }
	EnergyHandGeneratorInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int type, std::vector<sf::Texture>& _textures)
		: EnergyStorageInventory(_rw, _colorsInventory, type, _textures){}

	void Draw();
	void Update(Inventory& playerInventory);

};

