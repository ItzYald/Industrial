#pragma once
#include "Object.h"
#include "EnergyObjectInventory.h"

class INotTransferItemEnergyObject : public Object
{
public:
	// ��������� (������ ��� ������)
	EnergyObjectInventory* inventory;

	virtual void PlayUpdate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

