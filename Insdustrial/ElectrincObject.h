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
		//rw = _rw;
		//fieldSizeOne = _fieldSizeOne;
		//sprite.setTexture(_texture);
		//position = _position;
		//
		//functions = Functions(rw);
		//
		//isOpenInventory = false;
		//
		//inventory = InventoryType(rw);
		//
		//sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);
		//
		//for (int i = 0; i < 30; i++)
		//{
		//	ch.push_back(Checks());
		//}
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

