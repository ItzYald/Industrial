#include "Sprite.h"

// Sprite::Sprite(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position)
// {
// 	rw = _rw;
// 	fieldSizeOne = _fieldSizeOne;
// 	texture = new sf::Texture();
// 	texture->loadFromFile(imageFileName);
// 	sprite.setTexture(*texture);
// 	position = _position;
// }
// 
void Sprite::Draw(sf::Vector2f cameraPosition)
{
	sprite.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
	(*rw).draw(sprite);
}

