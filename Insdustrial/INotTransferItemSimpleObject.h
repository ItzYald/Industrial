#pragma once
#include "Object.h"
#include "ObjectInventory.h"

class INotTransferItemSimpleObject : public Object
{
public:
	// ��������� (������ ��� ������)
	ObjectInventory* inventory;

	virtual void PlayUpdate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

