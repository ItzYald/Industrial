#pragma once
#include "EnergyStorageInventory.h"

class EnergyCoalGeneratorInventory : public EnergyStorageInventory
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
		int _maxEnergy, int _power, std::vector<sf::Texture>& _textures);

	// Всегда
	void Next();
	// Отроисовка отнвентаря
	void Draw();
	// Когда зашел в инвентарь
	void Update(Inventory& playerInventory);

};

