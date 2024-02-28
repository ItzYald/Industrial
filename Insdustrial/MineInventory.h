#pragma once
#include "EnergyObjectInventory.h"

class MineInventory : public EnergyObjectInventory
{
private:
	std::vector<CellInInventory> cells;

public:
	MineInventory(){}
	MineInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	void Next() override;
	void Draw() override;
	// Работа с ячейками
	void Update(Inventory& playerInventory) override;

};

