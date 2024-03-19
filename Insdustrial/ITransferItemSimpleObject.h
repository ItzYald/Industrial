#pragma once
#include "Object.h"
#include "TransferItemSimpleObjectInventory.h"
#include "INotTransferItemSimpleObject.h"

class ITransferItemSimpleObject : public INotTransferItemSimpleObject
{
public:
	// Инвентарь (каждый раз разный)
	TransferItemSimpleObjectInventory* transferInventory;

	virtual bool NearPlayer(sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void PlayUpdate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

