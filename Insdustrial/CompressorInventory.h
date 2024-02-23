#pragma once
#include "EnergyObjectInventory.h"
#include "ProgressInventory.h"

class CompressorInventory : public EnergyObjectInventory
{
public:
	ProgressInventory progress;

	std::vector<CellInInventory> cells;

	CompressorInventory()
	{
	}
	CompressorInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, std::vector<sf::Texture>& _textures);

	// Всегда
	void Next() override;
	// Отроисовка отнвентаря
	void Draw() override;
	// Когда зашел в инвентарь
	void Update(Inventory& playerInventory) override;
};

