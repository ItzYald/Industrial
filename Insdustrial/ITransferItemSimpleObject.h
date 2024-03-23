#pragma once
#include "Object.h"
#include "TransferItemObject.h"
#include "INotTransferItemSimpleObject.h"

class ITransferItemSimpleObject : public INotTransferItemSimpleObject, public TransferItemObject
{
public:

	virtual void PlayUpdate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

