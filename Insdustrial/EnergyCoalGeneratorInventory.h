#pragma once
#include "EnergyStorageInventory.h"
#include "AcceptItemObject.h"

class EnergyCoalGeneratorInventory : public EnergyObjectInventory, public AcceptItemObject
{
public:
	// Место для уголя (или другого горючего)
	CellInInventory coalCell;
	// Процесс горения
	int burn;
	int maxBurn;

	EnergyCoalGeneratorInventory(){ }

	EnergyCoalGeneratorInventory(
		std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture*>& _textures);

	// Всегда
	void PlayUpdate() override;
	// Отроисовка отнвентаря
	void Draw() override;
	// Когда зашел в инвентарь
	void WhileOpen(Inventory& playerInventory) override;

};

