#include "Wire.h"

Wire::Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
	sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3, sf::Texture& texture4, sf::Texture& texture5,
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
	sprites[1].setTexture(texture2);
	sprites[2].setTexture(texture3);
	sprites[3].setTexture(texture4);
	sprites[4].setTexture(texture5);
	position = _position;

	numberSprite = 1;
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i].setScale(fieldSizeOne / sprites[i].getTexture()->getSize().x, fieldSizeOne / sprites[i].getTexture()->getSize().y);
	}

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}
}

bool Wire::NearPlayer(sf::Vector2f playerPosition, int playerAngle)
{
	if (((int)playerPosition.x == position.x && (int)playerPosition.y == position.y + 1 && playerAngle == 0) ||
		((int)playerPosition.x == position.x && (int)playerPosition.y == position.y - 1 && playerAngle == 2) ||
		((int)playerPosition.x == position.x + 1 && (int)playerPosition.y == position.y && playerAngle == 3) ||
		((int)playerPosition.x == position.x - 1 && (int)playerPosition.y == position.y && playerAngle == 1))
	{
		return true;
	}
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
		numberSprite = 4;
	}
	// Связь сверху, справа и снизу
	else if (connections[0] && connections[1] && connections[2])
	{
		numberSprite = 3;
		sprites[numberSprite].setRotation(90);
	}
	// Связь справа, снизу и слева
	else if (connections[1] && connections[2] && connections[3])
	{
		numberSprite = 3;
		sprites[numberSprite].setRotation(180);
	}
	// Связь снизу, слева и сверху
	else if (connections[2] && connections[3] && connections[0])
	{
		numberSprite = 3;
		sprites[numberSprite].setRotation(270);
	}
	// Связь слева, сверху и справа
	else if (connections[3] && connections[0] && connections[1])
	{
		numberSprite = 3;
		sprites[numberSprite].setRotation(0);
	}
	// Связь сверху и справа
	else if (connections[0] && connections[1])
	{
		numberSprite = 1;
		sprites[numberSprite].setRotation(0);
	}
	// Связь справа и снизу
	else if (connections[0] && connections[1])
	{
		numberSprite = 1;
		sprites[numberSprite].setRotation(90);
	}


	sprites[numberSprite].setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
	rw->draw(sprites[numberSprite]);
}
