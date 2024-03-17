#pragma once
#include "EnergyTransferItemObjectInventory.h"

class MineInventory : public EnergyTransferItemObjectInventory
{
private:
	std::vector<CellInInventory> cells;

public:
	MineInventory(){}
	MineInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	void PlayUpdate() override;
	void Draw() override;
	// Работа с ячейками
	void WhileOpen(Inventory& playerInventory) override;

};

