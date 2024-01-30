#include "Wire.h"

Wire::Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
	sf::Texture& texture0, sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3, sf::Texture& texture4,
	sf::Vector2f _position)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	sprites = std::vector<sf::Sprite>();
	functions = Functions(rw);
	for (int i = 0; i < 5; i++)
	{
		sprites.push_back(sf::Sprite());
	}
	sprites[0].setTexture(texture0);
	sprites[1].setTexture(texture1);
	sprites[2].setTexture(texture2);
	sprites[3].setTexture(texture3);
	sprites[4].setTexture(texture4);
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

Wire::Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, sf::Texture& texture, sf::Vector2f _position)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	functions = Functions(rw);

	newSprite = sf::Sprite();
	newSprite.setTexture(texture);
	newSprite.setScale(fieldSizeOne / newSprite.getTexture()->getSize().x, fieldSizeOne / newSprite.getTexture()->getSize().y);

	position = _position;

	turn = 0;

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}
}

void Wire::CheckConnections(sf::Vector2f positionSeconObject) 
{
	if (position.x + 1 == positionSeconObject.x && position.y == positionSeconObject.y)
	{
		connections[1] = true;
	}
	if (position.x - 1 == positionSeconObject.x && position.y == positionSeconObject.y)
	{
		connections[3] = true;
	}
	if (position.x == positionSeconObject.x && position.y + 1 == positionSeconObject.y)
	{
		connections[2] = true;
	}
	if (position.x == positionSeconObject.x && position.y - 1 == positionSeconObject.y)
	{
		connections[0] = true;
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
	if (ch[0].Check(sf::Keyboard::Key::R))
	{
		if (NearPlayer(playerPosition, playerAngle))
		{
			if (turn < 3)
				turn += 1;
			else
				turn = 0;
		}
	}
}

//void Wire::Draw(sf::Vector2f cameraPosition)
//{
//	// Все 4 связи
//	if (connections[0] && connections[1] && connections[2] && connections[3])
//	{
//		numberSprite = 4;
//	}
//	// Связь сверху, справа и снизу
//	if (connections[0] && connections[1] && connections[2] && !connections[3])
//	{
//		numberSprite = 3;
//		sprites[numberSprite].setRotation(90);
//	}
//	// Связь справа, снизу и слева
//	if (!connections[0] && connections[1] && connections[2] && connections[3])
//	{
//		numberSprite = 3;
//		sprites[numberSprite].setRotation(180);
//	}
//	// Связь снизу, слева и сверху
//	if (connections[0] && !connections[1] && connections[2] && connections[3])
//	{
//		numberSprite = 3;
//		sprites[numberSprite].setRotation(270);
//	}
//	// Связь слева, сверху и справа
//	if (connections[0] && connections[1] && !connections[2] && connections[3])
//	{
//		numberSprite = 3;
//		sprites[numberSprite].setRotation(0);
//	}
//	// Связь сверху и справа
//	if (connections[0] && connections[1] && !connections[2] && !connections[3])
//	{
//		numberSprite = 2;
//		sprites[numberSprite].setRotation(0);
//	}
//	// Связь справа и снизу
//	if (!connections[0] && connections[1] && connections[2] && !connections[3])
//	{
//		numberSprite = 2;
//		sprites[numberSprite].setRotation(90);
//	}
//	// Связь снизу и слева
//	if (!connections[0] && !connections[1] && connections[2] && connections[3])
//	{
//		numberSprite = 2;
//		sprites[numberSprite].setRotation(180);
//	}
//	// Связь слева и сверху
//	if (connections[0] && !connections[1] && !connections[2] && connections[3])
//	{
//		numberSprite = 2;
//		sprites[numberSprite].setRotation(270);
//	}
//	// Связь сверху и снизу
//	if (connections[0] && !connections[1] && connections[2] && !connections[3])
//	{
//		numberSprite = 1;
//		sprites[numberSprite].setRotation(90);
//	}
//	// Связь справа и слева
//	if (!connections[0] && connections[1] && !connections[2] && connections[3])
//	{
//		numberSprite = 1;
//		sprites[numberSprite].setRotation(0);
//	}
//	// Связь сверху
//	if (connections[0] && !connections[1] && !connections[2] && !connections[3])
//	{
//		numberSprite = 0;
//		sprites[numberSprite].setRotation(270);
//	}
//	// Связь справа
//	if (!connections[0] && connections[1] && !connections[2] && !connections[3])
//	{
//		numberSprite = 0;
//		sprites[numberSprite].setRotation(0);
//	}
//	// Связь снизу
//	if (!connections[0] && !connections[1] && connections[2] && !connections[3])
//	{
//		numberSprite = 0;
//		sprites[numberSprite].setRotation(90);
//	}
//	// Связь слева
//	if (!connections[0] && !connections[1] && !connections[2] && connections[3])
//	{
//		numberSprite = 0;
//		sprites[numberSprite].setRotation(180);
//	}
//
//	// Задать позицию
//	sprites[numberSprite].setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
//
//	// Сдвиг для компенсации вращения
//	if (sprites[numberSprite].getRotation() == 90)
//	{
//		sprites[numberSprite].setPosition(sprites[numberSprite].getPosition().x + fieldSizeOne, sprites[numberSprite].getPosition().y);
//	}
//	else if (sprites[numberSprite].getRotation() == 180)
//	{
//		sprites[numberSprite].setPosition(sprites[numberSprite].getPosition().x + fieldSizeOne, sprites[numberSprite].getPosition().y + fieldSizeOne);
//	}
//	else if (sprites[numberSprite].getRotation() == 270)
//	{
//		sprites[numberSprite].setPosition(sprites[numberSprite].getPosition().x, sprites[numberSprite].getPosition().y + fieldSizeOne);
//	}
//
//	rw->draw(sprites[numberSprite]);
//	//sf::Vector2f realPosition = sf::Vector2f(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
//	//functions.PrintText(std::to_string((int)connections[0]), sf::Vector2f(realPosition.x + 20, realPosition.y), 15, sf::Color::Blue);
//	//functions.PrintText(std::to_string((int)connections[1]), sf::Vector2f(realPosition.x + 40, realPosition.y + 20), 15, sf::Color::Blue);
//	//functions.PrintText(std::to_string((int)connections[2]), sf::Vector2f(realPosition.x + 20, realPosition.y + 40), 15, sf::Color::Blue);
//	//functions.PrintText(std::to_string((int)connections[3]), sf::Vector2f(realPosition.x, realPosition.y + 20), 15, sf::Color::Blue);
//}

void Wire::Draw(sf::Vector2f cameraPosition)
{
	if (turn == 0)
	{
		newSprite.setRotation(0);
	}
	if (turn == 1)
	{
		newSprite.setRotation(90);
	}
	if (turn == 2)
	{
		newSprite.setRotation(180);
	}
	if (turn == 3)
	{
		newSprite.setRotation(270);
	}

	// Задать позицию
	newSprite.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));

	// Сдвиг для компенсации вращения
	if (newSprite.getRotation() == 90)
	{
		newSprite.setPosition(newSprite.getPosition().x + fieldSizeOne, newSprite.getPosition().y);
	}
	else if (newSprite.getRotation() == 180)
	{
		newSprite.setPosition(newSprite.getPosition().x + fieldSizeOne, newSprite.getPosition().y + fieldSizeOne);
	}
	else if (newSprite.getRotation() == 270)
	{
		newSprite.setPosition(newSprite.getPosition().x, newSprite.getPosition().y + fieldSizeOne);
	}

	rw->draw(newSprite);
	//sf::Vector2f realPosition = sf::Vector2f(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
	//functions.PrintText(std::to_string((int)connections[0]), sf::Vector2f(realPosition.x + 20, realPosition.y), 15, sf::Color::Blue);
	//functions.PrintText(std::to_string((int)connections[1]), sf::Vector2f(realPosition.x + 40, realPosition.y + 20), 15, sf::Color::Blue);
	//functions.PrintText(std::to_string((int)connections[2]), sf::Vector2f(realPosition.x + 20, realPosition.y + 40), 15, sf::Color::Blue);
	//functions.PrintText(std::to_string((int)connections[3]), sf::Vector2f(realPosition.x, realPosition.y + 20), 15, sf::Color::Blue);
}
