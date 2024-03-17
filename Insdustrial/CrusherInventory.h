#pragma once
#include "EnergyObjectInventory.h"
#include "ProgressInventory.h"
#include "TransferObject.h"
#include "AcceptItemObject.h"

class CrusherInventory : public EnergyObjectInventory, public TransferObject, public AcceptItemObject
{
public:
	ProgressInventory progress;

	std::vector<CellInInventory> cells;

	CrusherInventory(){ }
	CrusherInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, std::vector<sf::Texture*>& _textures);

	// Всегда
	void PlayUpdate() override;
	// Отроисовка отнвентаря
	void Draw() override;
	// Когда зашел в инвентарь
	void WhileOpen(Inventory& playerInventory) override;
};

