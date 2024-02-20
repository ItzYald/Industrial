#include "Player.h"

Player::Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
	std::string imageFileName, sf::Vector2f _position,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	texture = new sf::Texture();
	texture->loadFromFile(imageFileName);
	sprite.setTexture(*texture);
	position = _position;
	functions = Functions(rw);

	isOpenInventory = false;
	whatTypeInventoryOpen = 0;
	whatNumberInventoryOpen = 0;
	
	// �������� ����
	run = 0;

	inventory = Inventory(rw, _colorsInventory, _textures);

	sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

	angle = 0.06f;

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

bool Player::PutObject(sf::Vector2i mousePositionGrid, std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>& ovens,
	std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>& electricOvens,
	std::vector<std::shared_ptr<StaingObject<CrusherInventory>>>& crushers,
	std::vector<std::shared_ptr<StaingObject<CompressorInventory>>>& compressors,
	std::vector<std::shared_ptr<StaingObject<ChestInventory>>>& chests, 
	std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>& workbenches,
	std::vector<std::shared_ptr<Wire>>& wires, 
	std::vector<std::shared_ptr<StaingObject<EnergyStorageInventory>>>& energyStorages,
	std::vector<std::shared_ptr<StaingObject<EnergyHandGeneratorInventory>>>& energyHandGenerators,
	std::vector<std::shared_ptr<StaingObject<EnergyCoalGeneratorInventory>>>& energyCoalGenerators)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return false;
	}
	int chooseNumber = inventory.cells[inventory.choseCell][3].item.number;
	if ((chooseNumber == 2 || chooseNumber == 5 || chooseNumber == 8 ||
		chooseNumber == 11 || chooseNumber == 12 || chooseNumber == 13 ||
		chooseNumber == 15 || chooseNumber == 16 || chooseNumber == 17 || 
		chooseNumber == 20 || chooseNumber == 24 || chooseNumber == 28) &&
		inventory.cells[inventory.choseCell][3].item.quantity > 0)
	{
		bool isNear = false;
		for (auto& thisObject : ovens)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);

		}
		for (auto& thisObject : electricOvens)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : crushers)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : compressors)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : chests)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : workbenches)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : wires)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : energyStorages)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : energyHandGenerators)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}
		for (auto& thisObject : energyCoalGenerators)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)thisObject->position);
		}

		if (!isNear)
		{
			inventory.cells[inventory.choseCell][3].item.quantity -= 1;
			return true;
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

//void Player::Draw(sf::Vector2f cameraPosition)
//{
//	if (angle == 0)
//	{
//		sprite2.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
//		sprite2.setPosition(sprite2.getPosition().x - fieldSizeOne / 2, sprite2.getPosition().y - fieldSizeOne / 2);
//
//		(*rw).draw(sprite2);
//	}
//	else
//	{
//		sprite1.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
//		sprite1.setPosition(sprite1.getPosition().x - fieldSizeOne / 2, sprite1.getPosition().y - fieldSizeOne / 2);
//
//		(*rw).draw(sprite1);
//	}
//}



