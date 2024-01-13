#pragma once
#include "OvenInventory.h"

class ElectricOvenInventory : public OvenInventory

{
public:
	ElectricOvenInventory(){ }
	ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw);

	void Burn();
	void Draw();
	void Update(Inventory& playerInventory);

};

