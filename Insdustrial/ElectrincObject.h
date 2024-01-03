#pragma once
#include "StaingObject.h"
#include "Wire.h"


template<class InventoryTypeF>
class ElectrincObject : public StaingObject<InventoryTypeF>
{
	InventoryTypeF a;

	ElectrincObject(){ }
	ElectrincObject(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, sf::Texture& _texture, sf::Vector2f _position){ }

	void NearWire(std::vector<Wire> wires){}
};

