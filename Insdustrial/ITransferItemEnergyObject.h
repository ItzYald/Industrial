#pragma once
#include "Object.h"
#include "INotTransferItemEnergyObject.h"
#include "TransferItemObject.h"

class ITransferItemEnergyObject : public INotTransferItemEnergyObject, public TransferItemObject
{
public:
	virtual void PlayUpdate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

