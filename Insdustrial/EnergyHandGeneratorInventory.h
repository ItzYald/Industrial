#pragma once
#include "EnergyStorageInventory.h"

class EnergyHandGeneratorInventory : public EnergyStorageInventory
{
public:
	EnergyHandGeneratorInventory(){ }

	EnergyHandGeneratorInventory(
		std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture>& _textures)
		: EnergyStorageInventory(_rw, _colorsInventory, _maxEnergy, _power, _textures)
	{
	}

	void Draw();
	void Update(Inventory& playerInventory);

};

