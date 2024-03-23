#pragma once
#include "TransferItemObjectInventory.h"
#include "EnergyObjectInventory.h"

class MineInventory : public EnergyObjectInventory, public TransferItemObjectInventory
{
private:
	std::vector<CellInInventory> cells;

public:
	MineInventory(){}
	MineInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	void PlayUpdate() override;
	void Draw() override;
	// ������ � ��������
	void WhileOpen(Inventory& playerInventory) override;

};

