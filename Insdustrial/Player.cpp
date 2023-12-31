#include "Player.h"

Player::Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	texture = new sf::Texture();
	texture->loadFromFile(imageFileName);
	sprite.setTexture(*texture);
	position = _position;

	isOpenInventory = false;
	whatTypeInventoryOpen = 0;
	whatNumberInventoryOpen = 0;

	run = 0;

	inventory = Inventory(rw);
	functions = Functions(rw);

	sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

	angle = 0.06f;

	buttons = std::vector<Button>();

	inventory.cells[0][3].item.number = 1;
	inventory.cells[0][3].item.quantity = 15;
	inventory.cells[1][3].item.number = 2;
	inventory.cells[1][3].item.quantity = 20;
	inventory.cells[2][3].item.number = 3;
	inventory.cells[2][3].item.quantity = 10;
	inventory.cells[3][3].item.number = 5;
	inventory.cells[3][3].item.quantity = 2;
	inventory.cells[4][3].item.number = 4;
	inventory.cells[4][3].item.quantity = 10;
	inventory.cells[5][3].item.number = 8;
	inventory.cells[5][3].item.quantity = 10;
	inventory.cells[6][3].item.number = 7;
	inventory.cells[6][3].item.quantity = 10;
	inventory.cells[7][3].item.number = 9;
	inventory.cells[7][3].item.quantity = 10;

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}

}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) &&
		position.x < fieldSizeOne * 1000)
	{
		position.x += run;
		angle = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) &&
		position.x > 0)
	{
		position.x -= run;
		angle = 3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) &&
		position.y < fieldSizeOne * 1000)
	{
		position.y += run;
		angle = 2;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) &&
		position.y > 0)
	{
		position.y -= run;
		angle = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl))
	{
		run = 0.1f;
	}
	else
	{
		run = 0.06f;
	}
}
// ��, ��� ����� ������ ������ ����
void Player::Update()
{
	if (!isOpenInventory)
	{
		Move();
	}
	if (ch[0].Check(sf::Keyboard::Key::E))
	{
		isOpenInventory = true;
		whatTypeInventoryOpen = 0;
	}
}
// ��������� ������� ������� ����� �������
bool Player::PutObject(std::vector<std::shared_ptr<StaingObject<OvenInventory>>>& ovens,
	std::vector<std::shared_ptr<StaingObject<ChestInventory>>>& chests, 
	std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>& workbenches)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	{
		if ((inventory.cells[inventory.choseCell][3].item.number == 2 ||
			inventory.cells[inventory.choseCell][3].item.number == 5 || 
			inventory.cells[inventory.choseCell][3].item.number == 8) &&
			inventory.cells[inventory.choseCell][3].item.quantity > 0)
		{
			bool isNear = false;
			for (std::shared_ptr<StaingObject<OvenInventory>>& thisObject : ovens)
			{
				isNear = thisObject->NearPlayer(position, angle);
			}
			for (std::shared_ptr<StaingObject<ChestInventory>>& thisObject : chests)
			{
				if (!isNear)
					isNear = thisObject->NearPlayer(position, angle);
			}
			for (std::shared_ptr<StaingObject<WorkbenchInventory>>& thisObject : workbenches)
			{
				if (!isNear)
					isNear = thisObject->NearPlayer(position, angle);
			}

			if (!isNear)
			{
				inventory.cells[inventory.choseCell][3].item.quantity -= 1;
				return true;
			}
		}
	}
	return false;
}

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

