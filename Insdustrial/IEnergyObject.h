#pragma once
#include "Object.h"
#include "EnergyObjectInventory.h"

class IEnergyObject : public Object
{
public:
	// Инвентарь (каждый раз разный)
	EnergyObjectInventory* inventory;

	virtual bool NearPlayer(sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void Next() = 0;
	virtual void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

