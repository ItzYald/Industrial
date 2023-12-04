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

void Object::NearPlayer(sf::Vector2f playerPosition, int playerAngle)
{
	//if (ch[0].Check(sf::Keyboard::Key::Q))
	//{
	//	if ((playerPosition.x == position.x && playerPosition.y == position.y + 1 && playerAngle == 2) ||
	//		(playerPosition.x == position.x && playerPosition.y == position.y - 1 && playerAngle == 0) ||
	//		(playerPosition.x == position.x + 1 && playerPosition.y == position.y && playerAngle == 1) ||
	//		(playerPosition.x == position.x - 1 && playerPosition.y == position.y && playerAngle == 3))
	//	{
	//		//std::cout << "lol";
	//	}
	//}
}

void Object::Update(sf::Vector2f playerPosition, int playerAngle)
{

}

