#pragma once
#include "Object.h"
#include "EnergyObjectInventory.h"

class INotTransferItemEnergyObject : public Object
{
public:
	// Инвентарь (каждый раз разный)
	EnergyObjectInventory* inventory;

	virtual bool NearPlayer(sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void PlayUpdate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

