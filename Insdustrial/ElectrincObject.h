#pragma once
#include "StaingObject.h"
#include "Wire.h"


template<class InventoryType>
class ElectrincObject : public StaingObject<InventoryType>
{

	ElectrincObject(){ }
	ElectrincObject(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, sf::Texture& _texture, sf::Vector2f _position)
		: StaingObject(_rw, _fieldSizeOne, _texture, _position)
	{
	}

	void NearWire(std::vector<Wire> wires)
	{
		bool res = false;
		for (int i = 0; i < wires.size(); i++)
		{
			//if ((position.x + 1 == wires[i].position.x && position.y == wires[i].position.x) ||
			//	(position.x - 1 == wires[i].position.x && position.y == wires[i].position.x) ||
			//	(position.x == wires[i].position.x && position.y + 1 == wires[i].position.x) ||
			//	(position.x == wires[i].position.x && position.y - 1 == wires[i].position.x))
			//{
			//	res = true;
			//}
		}
		return res;
	}
};

