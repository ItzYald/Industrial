#pragma once
#include "Object.h"
#include "EnergyTransferItemObjectInventory.h"
#include "INotTransferItemEnergyObject.h"

class ITransferItemEnergyObject : public INotTransferItemEnergyObject
{
public:
	// ��������� (������ ��� ������)
	EnergyTransferItemObjectInventory* transferInventory;

	virtual bool NearPlayer(sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void PlayUpdate() = 0;
	//virtual void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

