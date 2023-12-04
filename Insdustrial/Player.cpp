#include "Player.h"

Player::Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	texture = new sf::Texture();
	texture->loadFromFile(imageFileName);
	sprite.setTexture(*texture);
	position = _position;

	isOpenInterface = false;
	whatTypeInventoryOpen = 0;
	whatNumberInventoryOpen = 0;

	run = 0;

	inventory = Inventory(rw);
	functions = Functions(rw);

	sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

	angle = 0.06f;

	buttons = std::vector<Button>();

	inventory.items[0][3].number = 1;
	inventory.items[0][3].quantity = 15;
	inventory.items[2][2].number = 2;
	inventory.items[2][2].quantity = 20;
	inventory.items[3][3].number = 3;
	inventory.items[3][3].quantity = 10;

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}

}
// Движение
void Player::Move()
{
	// Дживение вперед 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) &&
		position.x < fieldSizeOne)
	{
		position.x += run;
		angle = 1;
	}
	// Дживение влево
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) &&
		position.x > 0)
	{
		position.x -= run;
		angle = 3;
	}
	// Дживение вниз
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) &&
		position.y < fieldSizeOne)
	{
		position.y += run;
		angle = 2;
	}
	// Дживение вправо	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) &&
		position.y > 0)
	{
		position.y -= run;
		angle = 0;
	}
	// Ускорение
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl))
	{
		run = 0.1f;
	}
	else
	{
		run = 0.06f;
	}
}
// То, что игрок делает каждый кадр
void Player::Update()
{
	if (!isOpenInterface)
	{
		Move();
	}
	if (ch[0].Check(sf::Keyboard::Key::E))
	{
		isOpenInterface = true;
		whatTypeInventoryOpen = 0;
	}
}
// Проверить если перед игроком объект
bool Player::CheckObject(std::vector<Oven>& ovens)
{
	if (angle == 0)
	{
		for (Oven thisOven : ovens)
		{
			if (thisOven.position == sf::Vector2f((int)position.x, (int)position.y - 1))
			{
				return true;
			}
		}
	}
	else if (angle == 1)
	{
		for (Oven thisOven : ovens)
		{
			if (thisOven.position == sf::Vector2f((int)position.x + 1, (int)position.y))
			{
				return true;
			}
		}
	}
	else if (angle == 2)
	{
		for (Oven thisOven : ovens)
		{
			if (thisOven.position == sf::Vector2f((int)position.x, (int)position.y + 1))
			{
				return true;
			}
		}
	}
	else if (angle == 3)
	{
		for (Oven thisOven : ovens)
		{
			if (thisOven.position == sf::Vector2f((int)position.x - 1, (int)position.y))
			{
				return true;
			}
		}
	}
	return false;
}
// Проверить наличие объекта перед игроком
void Player::PutObject(std::vector<Oven>& ovens)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	{
		if (inventory.items[inventory.choseCell][3].number == 2 &&
			inventory.items[inventory.choseCell][3].quantity > 0)
		{
			if (!CheckObject(ovens))
			{
				switch (angle)
				{
				case 0:
					ovens.push_back(Oven(rw, fieldSizeOne, "Images/Oven.png", sf::Vector2f((int)position.x, (int)position.y - 1)));
					inventory.items[inventory.choseCell][3].quantity -= 1;
					break;
				case 1:
					ovens.push_back(Oven(rw, fieldSizeOne, "Images/Oven.png", sf::Vector2f((int)position.x + 1, (int)position.y)));
					inventory.items[inventory.choseCell][3].quantity -= 1;
					break;
				case 2:
					ovens.push_back(Oven(rw, fieldSizeOne, "Images/Oven.png", sf::Vector2f((int)position.x, (int)position.y + 1)));
					inventory.items[inventory.choseCell][3].quantity -= 1;
					break;
				case 3:
					ovens.push_back(Oven(rw, fieldSizeOne, "Images/Oven.png", sf::Vector2f((int)position.x - 1, (int)position.y)));
					inventory.items[inventory.choseCell][3].quantity -= 1;
					break;
				default:
					break;
				}
			}
		}
	}
}
// Отрисовать
void Player::Draw(sf::Vector2f cameraPosition)
{
	sprite.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
	if (angle == 1)
	{
		sprite.setRotation(90);
		sprite.setPosition(sprite.getPosition().x + fieldSizeOne, sprite.getPosition().y);
	}
	else if (angle == 2)
	{
		sprite.setRotation(180);
		sprite.setPosition(sprite.getPosition().x + fieldSizeOne, sprite.getPosition().y + fieldSizeOne);
	}
	else if (angle == 3)
	{
		sprite.setRotation(270);
		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + fieldSizeOne);
	}
	else
	{
		sprite.setRotation(0);
	}

	sprite.setPosition(sprite.getPosition().x - fieldSizeOne / 2, sprite.getPosition().y - fieldSizeOne / 2);

	(*rw).draw(sprite);
}

