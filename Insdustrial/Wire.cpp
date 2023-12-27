#include "Wire.h"

Wire::Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
	sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3, sf::Texture& texture4,
	sf::Vector2f _position)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	sprites = std::vector<sf::Sprite>();
	for (int i = 0; i < 5; i++)
	{
		sprites.push_back(sf::Sprite());
	}
	sprites[0].setTexture(texture1);
	sprites[1].setTexture(texture1);
	sprites[2].setTexture(texture1);
	sprites[3].setTexture(texture1);
	position = _position;

	numberSprite = 0;

	sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}
}

bool Wire::NearPlayer(sf::Vector2f playerPosition, int playerAngle)
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	//{
	//	if ((playerPosition.x == position.x && playerPosition.y == position.y + 1 && playerAngle == 2) ||
	//		(playerPosition.x == position.x && playerPosition.y == position.y - 1 && playerAngle == 0) ||
	//		(playerPosition.x == position.x + 1 && playerPosition.y == position.y && playerAngle == 1) ||
	//		(playerPosition.x == position.x - 1 && playerPosition.y == position.y && playerAngle == 3))
	//	{
	//		
	//	}
	//}
	return false;
}

void Wire::Update(sf::Vector2f playerPosition, int playerAngle)
{

}

void Wire::Draw(sf::Vector2f cameraPosition)
{
	// Все 4 связи
	if (connections[0] && connections[1] && connections[2] && connections[3])
	{
		numberSprite = 3;
	}
	// Связь сверху, справа и снизу
	else if (connections[0] && connections[1] && connections[2])
	{
		numberSprite = 2;
		sprites[numberSprite].setRotation(90);
	}
	// Связь справа, снизу и слева
	else if (connections[1] && connections[2] && connections[3])
	{
		numberSprite = 2;
		sprites[numberSprite].setRotation(180);
	}
	// Связь снизу, слева и сверху
	else if (connections[2] && connections[3] && connections[0])
	{
		numberSprite = 2;
		sprites[numberSprite].setRotation(270);
	}
	// Связь слева, сверху и справа
	else if (connections[3] && connections[0] && connections[1])
	{
		numberSprite = 2;
		sprites[numberSprite].setRotation(0);
	}
	// Связь сверху и слева
	else if (connections[3] && connections[0] && connections[1])
	{
		numberSprite = 2;
		sprites[numberSprite].setRotation(0);
	}


	sprites[numberSprite].setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
	rw->draw(sprites[numberSprite]);
}
