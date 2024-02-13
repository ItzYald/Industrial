#pragma once
#include "StaingObject.h"
#include "EnergyStorageInventory.h"

// Используется для объектов передающих энергию
template<class T>
class EnergySprite : public StaingObject<T>
{
	
public:

	EnergySprite(){ }
	
	EnergySprite(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _textures, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, int _maxFuel, int _power)
	{
		StaingObject<T>::rw = _rw;
		StaingObject<T>::fieldSizeOne = _fieldSizeOne;
		StaingObject<T>::sprite.setTexture(_texture);
		StaingObject<T>::position = _position;

		StaingObject<T>::functions = Functions(StaingObject<T>::rw);

		StaingObject<T>::isOpenInventory = false;

		StaingObject<T>::inventory = T(StaingObject<T>::rw, _colorsInventory, _maxFuel, _power, _textures);

		StaingObject<T>::sprite.setScale(
			StaingObject<T>::fieldSizeOne / (float)StaingObject<T>::sprite.getTexture()->getSize().x,
			StaingObject<T>::fieldSizeOne / (float)StaingObject<T>::sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			StaingObject<T>::ch.push_back(Checks());
		}
		StaingObject<T>::turn = 0;
	}

	EnergySprite(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, int _maxFuel, int _power,
		std::map<std::string, sf::Texture>& _texturesInInventory)
	{
		StaingObject<T>::rw = _rw;
		StaingObject<T>::fieldSizeOne = _fieldSizeOne;
		StaingObject<T>::sprite.setTexture(_texture);
		StaingObject<T>::position = _position;

		StaingObject<T>::functions = Functions(StaingObject<T>::rw);

		StaingObject<T>::isOpenInventory = false;


		StaingObject<T>::turn = 0;

		StaingObject<T>::inventory =
			T(StaingObject<T>::rw, _colorsInventory, _maxFuel, _power, _itemTextures, _texturesInInventory);

		//StaingObject<T>::inventory =
		//	T(StaingObject<T>::rw, _colorsInventory, _maxFuel, _power, _itemTextures);

		StaingObject<T>::sprite.setScale(
			StaingObject<T>::fieldSizeOne / (float)StaingObject<T>::sprite.getTexture()->getSize().x,
			StaingObject<T>::fieldSizeOne / (float)StaingObject<T>::sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			StaingObject<T>::ch.push_back(Checks());
		}
	}
};

