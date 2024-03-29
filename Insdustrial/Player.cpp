#include "Player.h"

Player::Player(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
	sf::Texture* _texture, sf::Vector2f _position,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _itemTextures)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	sprite.setTexture(*_texture);
	position = _position;
	functions = Functions(rw);

	cameraPosition = &_cameraPosition;

	isOpenInventory = false;
	whatTypeInventoryOpen = 0;
	whatNumberInventoryOpen = 0;

	// �������� ����
	run = 0;

	inventory = Inventory(rw, _colorsInventory, _itemTextures);

	sprite.setScale(fieldSizeOne / (float)sprite.getTexture()->getSize().x, fieldSizeOne / (float)sprite.getTexture()->getSize().y);

	angle = 0.06f;


	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}

}

void Player::LoadingForDev()
{
	inventory.cells[0][0].item.NumberUpdate(1);
	inventory.cells[0][0].item.quantity = 15;
	inventory.cells[1][0].item.NumberUpdate(2);
	inventory.cells[1][0].item.quantity = 20;
	inventory.cells[2][0].item.NumberUpdate(3);
	inventory.cells[2][0].item.quantity = 10;
	inventory.cells[3][0].item.NumberUpdate(5);
	inventory.cells[3][0].item.quantity = 2;
	inventory.cells[4][0].item.NumberUpdate(4);
	inventory.cells[4][0].item.quantity = 10;
	inventory.cells[5][0].item.NumberUpdate(8);
	inventory.cells[5][0].item.quantity = 10;
	inventory.cells[6][0].item.NumberUpdate(7);
	inventory.cells[6][0].item.quantity = 10;
	inventory.cells[7][0].item.NumberUpdate(9);
	inventory.cells[7][0].item.quantity = 10;
	inventory.cells[8][0].item.NumberUpdate(10);
	inventory.cells[8][0].item.quantity = 60;
	inventory.cells[9][0].item.NumberUpdate(11);
	inventory.cells[9][0].item.quantity = 14;
	inventory.cells[0][1].item.NumberUpdate(12);
	inventory.cells[0][1].item.quantity = 14;
	inventory.cells[1][1].item.NumberUpdate(13);
	inventory.cells[1][1].item.quantity = 20;
	inventory.cells[2][1].item.NumberUpdate(14);
	inventory.cells[2][1].item.quantity = 20;
	inventory.cells[3][1].item.NumberUpdate(17);
	inventory.cells[3][1].item.quantity = 20;
	inventory.cells[4][1].item.NumberUpdate(19);
	inventory.cells[4][1].item.quantity = 20;
	inventory.cells[5][1].item.NumberUpdate(21);
	inventory.cells[5][1].item.quantity = 20;
	inventory.cells[6][1].item.NumberUpdate(22);
	inventory.cells[6][1].item.quantity = 20;
	inventory.cells[7][1].item.NumberUpdate(24);
	inventory.cells[7][1].item.quantity = 10;
	inventory.cells[8][1].item.NumberUpdate(28);
	inventory.cells[8][1].item.quantity = 10;
	inventory.cells[9][1].item.NumberUpdate(29);
	inventory.cells[9][1].item.quantity = 10;
	inventory.cells[0][2].item.NumberUpdate(32);
	inventory.cells[0][2].item.quantity = 10;
	inventory.cells[1][2].item.NumberUpdate(ItemEnum::stone);
	inventory.cells[1][2].item.quantity = 10;
	inventory.cells[2][2].item.NumberUpdate(ItemEnum::pipe);
	inventory.cells[2][2].item.quantity = 10;
}

void Player::LoadingForPlay()
{
	inventory.cells[0][0].item.NumberUpdate(9);
	inventory.cells[0][0].item.quantity = 6;
	inventory.cells[0][1].item.NumberUpdate(4);
	inventory.cells[0][1].item.quantity = 1;
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

void Player::GamePlayUpdate()
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

	sprite.setPosition(fieldSizeOne * (position.x - (*cameraPosition).x), fieldSizeOne * (position.y - (*cameraPosition).y));
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
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}

