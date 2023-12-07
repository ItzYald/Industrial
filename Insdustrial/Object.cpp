#include "Object.h"

Object::Object(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	texture = new sf::Texture();
	texture->loadFromFile(imageFileName);
	sprite.setTexture(*texture);
	position = _position;

	sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}
}
