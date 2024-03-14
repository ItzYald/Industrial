#pragma once
#include "EnergyObjectInventory.h"
#include "TransferObject.h"

class MineInventory : public EnergyObjectInventory, public TransferObject
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

