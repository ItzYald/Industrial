#pragma once
#include "EnergyObjectInventory.h"
#include "ProgressInventory.h"

class CrusherInventory : public EnergyObjectInventory
{
public:
	ProgressInventory progress;

	std::vector<CellInInventory> cells;

	CrusherInventory(){ }
	CrusherInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, std::vector<sf::Texture>& _textures);

	void Crush();
	// Всегда
	void Next();
	// Отроисовка отнвентаря
	void Draw();
	// Когда зашел в инвентарь
	void Update(Inventory& playerInventory);
};

