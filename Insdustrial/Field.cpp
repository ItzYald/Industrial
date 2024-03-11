#include "Field.h"

Field::Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition,
	sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW,
	Assets& _assets, Player& _player, std::vector<sf::Drawable*>& _drawables)
	: rw(_rw), size(_size), sizeOne(_sizeOne), sizeW(_sizeW)
{
	functions = Functions(rw);
	assets = &_assets;

	sprite = sf::Sprite(*assets->textures["Grass"]);
	cameraPosition = &_cameraPosition;

	objects = std::vector<Object*>();
	transEnergyObjects = std::vector<IEnergyObject*>();
	simpleObjects = std::vector<IStaingObject*>();

	drawables = &_drawables;

	playUpdatables = std::vector<IPlayUpdatable*>();

	player = &_player;


	sprite.setScale(_sizeOne / (float)sprite.getTexture()->getSize().x, _sizeOne / (float)sprite.getTexture()->getSize().y);
	
	sprites = std::vector<std::vector<sf::Sprite>>();
	for (size_t i = 0; i < size.x; i++)
	{
		sprites.push_back(std::vector<sf::Sprite>());
		for (size_t j = 0;  j < size.y;  j++)
		{
			sprites[i].push_back(sprite);
		}
	}

	for (size_t i = 0; i < size.x; i++)
	{
		for (size_t j = 0; j < size.y; j++)
		{
			sprites[i][j].setPosition(
				sf::Vector2f(sizeOne * (i - cameraPosition->x), sizeOne * (j - cameraPosition->y)));
		}
	}

	objects = std::vector<Object*>();

	newEnergyObjectsNumbers = std::vector<std::vector<int>>();
	transEnergyObjectsNumbers = std::vector<std::vector<int>>();

	for (int i = 0; i < size.x; i++)
	{
		newEnergyObjectsNumbers.push_back(std::vector <int>());
		transEnergyObjectsNumbers.push_back(std::vector <int>());
		for (int j = 0; j < size.y; j++)
		{
			newEnergyObjectsNumbers[i].push_back(-1);
			transEnergyObjectsNumbers[i].push_back(-1);
		}
	}

}

void Field::LoadingForDev(std::vector<sf::Color>& colorsInventory)
{
	energyObjects.push_back(new EnergyObject<ElectricOvenInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["ElectricOven"], assets->itemTextures, sf::Vector2f(23, 19), colorsInventory));
	energyObjects.push_back(new EnergyObject<CrusherInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Crusher"], assets->itemTextures, sf::Vector2f(19, 17), colorsInventory, 1000));
	energyObjects.push_back(new EnergyObject<CompressorInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Compressor"], assets->itemTextures, sf::Vector2f(19, 16), colorsInventory, 1000));
	energyObjects.push_back(new EnergyObject<EnergyStorageInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["EnergyStorage"], assets->itemTextures, sf::Vector2f(22, 20), colorsInventory, 10000, 10));
	transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new EnergyObject<EnergyHandGeneratorInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["EnergyHandGenerator"], assets->itemTextures, sf::Vector2f(22, 19), colorsInventory, 100, 10, assets->texturesInInventory));
	transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new EnergyObject<EnergyCoalGeneratorInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["EnergyCoalGenerator"], assets->itemTextures, sf::Vector2f(20, 19), colorsInventory, 100, 10));
	transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new EnergyObject<MineInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Mine"], assets->itemTextures, sf::Vector2f(15, 16), colorsInventory));

	simpleObjects.push_back(new StaingObject<CoalOvenInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["Oven"], assets->itemTextures, sf::Vector2f(23, 20), colorsInventory));
	simpleObjects.push_back(new StaingObject<ChestInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["Chest"], assets->itemTextures, sf::Vector2f(23, 21), colorsInventory));
	simpleObjects.push_back(new StaingObject<WorkbenchInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Workbench"], assets->itemTextures, sf::Vector2f(23, 22), colorsInventory));
}

void Field::LoadingForPlay(std::vector<sf::Color>& colorsInventory)
{
	simpleObjects.push_back(new StaingObject<WorkbenchInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Workbench"], assets->itemTextures, sf::Vector2f(23, 22), colorsInventory));
	energyObjects.push_back(new EnergyObject<MineInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Mine"], assets->itemTextures, sf::Vector2f(22, 22), colorsInventory));
}

void Field::LoadingPlay()
{
	for (size_t i = 0; i < simpleObjects.size(); i++)
	{
		objects.push_back(simpleObjects[i]);
	}
	for (size_t i = 0; i < energyObjects.size(); i++)
	{
		objects.push_back(energyObjects[i]);
	}
	for (size_t i = 0; i < objects.size(); i++)
	{
		playUpdatables.push_back(objects[i]);
	}
}

void Field::UnloadingPlay()
{
	simpleObjects.clear();
	energyObjects.clear();
	transEnergyObjects.clear();
}

void Field::Draw()
{
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			sprite.setPosition(sf::Vector2f(sizeOne * (i - cameraPosition->x), sizeOne * (j - cameraPosition->y)));
			if (sprite.getPosition().x < sizeW.x && sprite.getPosition().y < sizeW.y &&
				sprite.getPosition().x + sizeOne > 0 && sprite.getPosition().y + sizeOne > 0)
			{
				rw->draw(sprite);
			}
		}
	}
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			if (sprites[i][j].getPosition().x < sizeW.x && sprites[i][j].getPosition().y < sizeW.y &&
				sprites[i][j].getPosition().x + sizeOne > 0 && sprites[i][j].getPosition().y + sizeOne > 0)
			{
				target.draw(sprites[i][j]);
			}
		}
	}
}
// Поставить объект по определенным координатам
void Field::PutObject(sf::Vector2f position, int playerCell, std::vector<sf::Color>& colorsInventory)
{
	// Поставить:
	switch (playerCell)
	{
		// Печку
	case ItemEnum::oven:
		simpleObjects.push_back(new StaingObject<CoalOvenInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Oven"], assets->itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
		// Электропечку
	case ItemEnum::energyOven:
		energyObjects.push_back(new EnergyObject<ElectricOvenInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["ElectricOven"], assets->itemTextures, position, colorsInventory));
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Дробитель
	case ItemEnum::crusher:
		energyObjects.push_back(new EnergyObject<CrusherInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Crusher"], assets->itemTextures, position, colorsInventory, 1000));
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Компрессор
	case ItemEnum::compressor:
		energyObjects.push_back(new EnergyObject<CompressorInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Compressor"], assets->itemTextures, position, colorsInventory, 1000));
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Шахту
	case ItemEnum::mine:
		energyObjects.push_back(new EnergyObject<MineInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Mine"], assets->itemTextures, position, colorsInventory));
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Сундук
	case ItemEnum::chest:
		simpleObjects.push_back(new StaingObject<ChestInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Chest"], assets->itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
		// Верстак
	case ItemEnum::workbench:
		simpleObjects.push_back(new StaingObject<WorkbenchInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Workbench"], assets->itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
		// Энергохранилище
	case ItemEnum::energyStorage:
		energyObjects.push_back(new EnergyObject<EnergyStorageInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["EnergyStorage"], assets->itemTextures, position, colorsInventory, 1000, 10));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Ручной энергогенератор
	case ItemEnum::handEnergyGenerator:
		energyObjects.push_back(new EnergyObject<EnergyHandGeneratorInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["EnergyHandGenerator"],
			assets->itemTextures, position, colorsInventory, 100, 10, assets->texturesInInventory));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Угольный энергогенератор
	case ItemEnum::coalEnergyGenerator:
		energyObjects.push_back(new EnergyObject<EnergyCoalGeneratorInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["EnergyCoalGenerator"], assets->itemTextures, position, colorsInventory, 100, 10));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		// Медный провод
	case ItemEnum::copperWire:
		energyObjects.push_back(new EnergyObject<WireInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["CopperWireOn"], assets->itemTextures, position, colorsInventory, 10, 10));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Железный провод
	case ItemEnum::ironWire:
		energyObjects.push_back(new EnergyObject<WireInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["IronWireOn"], assets->itemTextures, position, colorsInventory, 100, 100));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// Оловяный провод
	case ItemEnum::tinWire:
		energyObjects.push_back(new EnergyObject<WireInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["TinWireOn"], assets->itemTextures, position, colorsInventory, 1000, 1000));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	}

	drawables->push_back(objects[objects.size() - 1]);
	playUpdatables.push_back(objects[objects.size() - 1]);
	playUpdatables[playUpdatables.size() - 1]->PlayUpdate();
}

void Field::GamePlayUpdate()
{
	for (size_t i = 0; i < energyObjects.size(); i++)
	{
		newEnergyObjectsNumbers[energyObjects[i]->position.x][energyObjects[i]->position.y] = i;
		if (energyObjects[i]->isOpenInventory)
		{
			player->isOpenInventory = true;
			player->whatTypeInventoryOpen = 1;
			player->whatNumberInventoryOpen = i;
			break;
		}
	}

	for (size_t i = 0; i < simpleObjects.size(); i++)
	{
		if (simpleObjects[i]->isOpenInventory)
		{
			player->isOpenInventory = true;
			player->whatTypeInventoryOpen = 2;
			player->whatNumberInventoryOpen = i;
			break;
		}
	}

	for (size_t i = 0; i < transEnergyObjects.size(); i++)
	{
		transEnergyObjectsNumbers[transEnergyObjects[i]->position.x][transEnergyObjects[i]->position.y] = i;
	}
}

void Field::TransEnergy(float& originalEnergy, int power, float& nextEnergy, int nextMaxEnergy)
{
	if (originalEnergy - power < 0)
	{
		if (nextEnergy + originalEnergy > nextMaxEnergy)
		{
			originalEnergy -= nextMaxEnergy - nextEnergy;
			nextEnergy = nextMaxEnergy;
		}
		else
		{
			nextEnergy += originalEnergy;
			originalEnergy = 0;
		}
	}
	else
	{
		if (nextEnergy + power > nextMaxEnergy)
		{
			originalEnergy -= nextMaxEnergy - nextEnergy;
			nextEnergy = nextMaxEnergy;
		}
		else
		{
			nextEnergy += power;
			originalEnergy -= power;
		}
	}
}

void Field::CheckNextEnergyObject(sf::Vector2i nextPosition, float& energy, int power)
{
	EnergyObjectInventory* thisObjectInventory;

	if (newEnergyObjectsNumbers[nextPosition.x][nextPosition.y] == -1)
	{
		return;
	}

	thisObjectInventory = energyObjects[newEnergyObjectsNumbers[nextPosition.x][nextPosition.y]]->inventory;
	TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
}

sf::Vector2i Field::CheckTurnEnergy(int turn)
{
	switch (turn)
	{
	case 0:
		return sf::Vector2i(0, -1);
		break;
	case 1:
		return sf::Vector2i(1, 0);;
		break;
	case 2:
		return sf::Vector2i(0, 1);
		break;
	case 3:
		return sf::Vector2i(-1, 0);
		break;
	}
}

void Field::WhatObjectTransEnergy()
{
	// Передача энергии
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			sf::Vector2i shift;
			int typeObject = -1;

			if (transEnergyObjectsNumbers[i][j] == -1) continue;
			if (transEnergyObjects[transEnergyObjectsNumbers[i][j]]->inventory->energy == 0) continue;

			shift = CheckTurnEnergy(transEnergyObjects[transEnergyObjectsNumbers[i][j]]->turn);

			if (newEnergyObjectsNumbers[i][j] == -1) continue;

			CheckNextEnergyObject(sf::Vector2i(i + shift.x, j + shift.y),
				transEnergyObjects[transEnergyObjectsNumbers[i][j]]->inventory->energy,
				transEnergyObjects[transEnergyObjectsNumbers[i][j]]->inventory->power);
		}
	}
}

void Field::PlayUpdate()
{
	for (size_t i = 0; i < playUpdatables.size(); i++)
	{
		playUpdatables[i]->PlayUpdate();
	}

	WhatObjectTransEnergy();

	for (size_t i = 0; i < size.x; i++)
	{
		for (size_t j = 0; j < size.y; j++)
		{
			sprites[i][j].setPosition(
				sf::Vector2f(sizeOne * (i - cameraPosition->x), sizeOne * (j - cameraPosition->y)));
		}
	}

}

bool Field::ObjectHere(sf::Vector2i mousePositionGrid, Item& chooseItem)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return false;
	}
	int chooseNumber = chooseItem.number;
	if ((chooseNumber == 2 || chooseNumber == 5 || chooseNumber == 8 ||
		chooseNumber == 11 || chooseNumber == 12 || chooseNumber == 13 ||
		chooseNumber == 15 || chooseNumber == 16 || chooseNumber == 17 ||
		chooseNumber == 20 || chooseNumber == 24 || chooseNumber == 28 ||
		chooseNumber == 32) &&
		chooseItem.quantity > 0)
	{
		bool isNear = false;

		for (size_t i = 0; i < objects.size(); i++)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)objects[i]->position);
		}

		if (!isNear)
		{
			chooseItem.quantity -= 1;
			return true;
		}
	}
	return false;
}

sf::Vector2i Field::WhatActive(sf::Vector2i mousePosition)
{
	return sf::Vector2i(0, 0);
}
