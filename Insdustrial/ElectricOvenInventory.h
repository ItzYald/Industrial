#pragma once
#include "ProgressInventory.h"
#include "EnergyObjectInventory.h"

class ElectricOvenInventory : public EnergyObjectInventory

{
	// Ячейки с предметами
	std::vector<CellInInventory> cells;

	ProgressInventory progress;
public:
	ElectricOvenInventory(){ }
	ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);

	void Burn();
	// Каждый кадр (даже пока игрок не открыл этот инвентарь)
	void Next() override;
	// Отрисовка
	void Draw() override;
	// Когда инвентарь открыт
	void Update(Inventory& playerInventory) override;

};

