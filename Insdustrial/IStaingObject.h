#pragma once
#include "Object.h"
#include "ObjectInventory.h"

class IStaingObject : public Object
{
public:
	// ��������� (������ ��� ������)
	ObjectInventory* inventory;

	virtual bool NearPlayer(sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void PlayUpdate() = 0;
	virtual void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

