#pragma once
#include "ProgressInventory.h"
#include "TransferItemObjectInventory.h"
#include "EnergyObjectInventory.h"

class ElectricOvenInventory : public EnergyObjectInventory, public TransferItemObjectInventory

{
	// Ячейки с предметами
	std::vector<CellInInventory> cells;

	ProgressInventory progress;
public:
	ElectricOvenInventory(){ }
	ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	void Burn();
	// Каждый кадр (даже пока игрок не открыл этот инвентарь)
	void PlayUpdate() override;
	// Отрисовка
	void Draw() override;
	// Когда инвентарь открыт
	void WhileOpen(Inventory& playerInventory) override;

};

