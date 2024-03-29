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
	transferEnergyObjects = std::vector<INotTransferItemEnergyObject*>();
	simpleObjects = std::vector<INotTransferItemSimpleObject*>();

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

	energyObjectsNumbers = std::vector<std::vector<int>>();
	transferEnergyObjectsNumbers = std::vector<std::vector<int>>();
	transferItemObjectsNumbers = std::vector<std::vector<int>>();

	for (int i = 0; i < size.x; i++)
	{
		energyObjectsNumbers.push_back(std::vector <int>());
		transferEnergyObjectsNumbers.push_back(std::vector <int>());
		transferItemObjectsNumbers.push_back(std::vector <int>());
		for (int j = 0; j < size.y; j++)
		{
			energyObjectsNumbers[i].push_back(-1);
			transferEnergyObjectsNumbers[i].push_back(-1);
			transferItemObjectsNumbers[i].push_back(-1);
		}
	}

}

void Field::LoadingForDev(std::vector<sf::Color>& colorsInventory)
{
	energyObjects.push_back(new NotTransferItemEnergyObject<ElectricOvenInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["ElectricOven"], assets->itemTextures, sf::Vector2f(23, 19), colorsInventory));
	energyObjects.push_back(new NotTransferItemEnergyObject<CrusherInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Crusher"], assets->itemTextures, sf::Vector2f(19, 17), colorsInventory, 1000));
	energyObjects.push_back(new NotTransferItemEnergyObject<CompressorInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Compressor"], assets->itemTextures, sf::Vector2f(19, 16), colorsInventory, 1000));
	energyObjects.push_back(new NotTransferItemEnergyObject<EnergyStorageInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["EnergyStorage"], assets->itemTextures, sf::Vector2f(22, 20), colorsInventory, 10000, 10));
	transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new NotTransferItemEnergyObject<EnergyHandGeneratorInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["EnergyHandGenerator"], assets->itemTextures, sf::Vector2f(22, 19), colorsInventory, 100, 10, assets->texturesInInventory));
	transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new NotTransferItemEnergyObject<EnergyCoalGeneratorInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["EnergyCoalGenerator"], assets->itemTextures, sf::Vector2f(20, 19), colorsInventory, 1000, 10));
	transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new NotTransferItemEnergyObject<MineInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Mine"], assets->itemTextures, sf::Vector2f(15, 16), colorsInventory));


	transferItemSimpleObjects.push_back(new TransferItemSimpleObject<CoalOvenInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["Oven"], assets->itemTextures, sf::Vector2f(23, 20), colorsInventory));
	transferItemObjects.push_back(transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]);
	transferItemObjectsInventories.push_back(
		transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]->transferInventory);
	simpleObjects.push_back(transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]);

	simpleObjects.push_back(new NotTransferItemSimpleObject<ChestInventory>(
		rw, *cameraPosition, sizeOne, assets->textures["Chest"], assets->itemTextures, sf::Vector2f(23, 21), colorsInventory));

	simpleObjects.push_back(new NotTransferItemSimpleObject<WorkbenchInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Workbench"], assets->itemTextures, sf::Vector2f(23, 22), colorsInventory));
}

void Field::LoadingForPlay(std::vector<sf::Color>& colorsInventory)
{
	simpleObjects.push_back(new NotTransferItemSimpleObject<WorkbenchInventory >(
		rw, *cameraPosition, sizeOne, assets->textures["Workbench"], assets->itemTextures, sf::Vector2f(23, 22), colorsInventory));
	energyObjects.push_back(new NotTransferItemEnergyObject<MineInventory >(
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
	transferEnergyObjects.clear();
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
// ��������� ������ �� ������������ �����������
void Field::PutObject(sf::Vector2f position, Item& chooseItem, std::vector<sf::Color>& colorsInventory)
{
	if (!ObjectHere((sf::Vector2i)position, chooseItem)) return;
	// ���������:
	switch (chooseItem.number)
	{
	// �����
	case ItemEnum::oven:
		transferItemSimpleObjects.push_back(new TransferItemSimpleObject<CoalOvenInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Oven"], assets->itemTextures, position, colorsInventory));
		transferItemObjects.push_back(transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]);
		transferItemObjectsInventories.push_back(
			transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]->transferInventory);
		simpleObjects.push_back(transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]);
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
	// ������������
	case ItemEnum::energyOven:
		transferItemEnergyObjects.push_back(new TransferItemEnergyObject<ElectricOvenInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["ElectricOven"], assets->itemTextures, position, colorsInventory));
		transferItemObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		transferItemObjectsInventories.push_back(
			transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]->transferInventory);
		energyObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ���������
	case ItemEnum::crusher:
		transferItemEnergyObjects.push_back(new TransferItemEnergyObject<CrusherInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Crusher"], assets->itemTextures, position, colorsInventory, 1000));
		transferItemObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		transferItemObjectsInventories.push_back(
			transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]->transferInventory);
		energyObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ����������
	case ItemEnum::compressor:
		transferItemEnergyObjects.push_back(new TransferItemEnergyObject<CompressorInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Compressor"], assets->itemTextures, position, colorsInventory, 1000));
		transferItemObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		transferItemObjectsInventories.push_back(
			transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]->transferInventory);
		energyObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// �����
	case ItemEnum::mine:
		transferItemEnergyObjects.push_back(new TransferItemEnergyObject<MineInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Mine"], assets->itemTextures, position, colorsInventory));
		transferItemObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		transferItemObjectsInventories.push_back(
			transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]->transferInventory);
		energyObjects.push_back(transferItemEnergyObjects[transferItemEnergyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ������
	case ItemEnum::chest:
		simpleObjects.push_back(new NotTransferItemSimpleObject<ChestInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Chest"], assets->itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
	// �������
	case ItemEnum::workbench:
		simpleObjects.push_back(new NotTransferItemSimpleObject<WorkbenchInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Workbench"], assets->itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
	// �����
	case ItemEnum::pipe:
		transferItemSimpleObjects.push_back(new TransferItemSimpleObject<PipeInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["Chest"], assets->itemTextures, position, colorsInventory));
		transferItemObjects.push_back(transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]);
		transferItemObjectsInventories.push_back(
			transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]->transferInventory);
		simpleObjects.push_back(transferItemSimpleObjects[transferItemSimpleObjects.size() - 1]);
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
	// ���������������
	case ItemEnum::energyStorage:
		energyObjects.push_back(new NotTransferItemEnergyObject<EnergyStorageInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["EnergyStorage"], assets->itemTextures, position, colorsInventory, 1000, 10));
		transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ������ ���������������
	case ItemEnum::handEnergyGenerator:
		energyObjects.push_back(new NotTransferItemEnergyObject<EnergyHandGeneratorInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["EnergyHandGenerator"],
			assets->itemTextures, position, colorsInventory, 100, 10, assets->texturesInInventory));
		transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// �������� ���������������
	case ItemEnum::coalEnergyGenerator:
		energyObjects.push_back(new NotTransferItemEnergyObject<EnergyCoalGeneratorInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["EnergyCoalGenerator"],
			assets->itemTextures, position, colorsInventory, 1000, 10));
		transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// ������ ������
	case ItemEnum::copperWire:
		energyObjects.push_back(new NotTransferItemEnergyObject<WireInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["CopperWireOn"],
			assets->itemTextures, position, colorsInventory, 10, 10));
		transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// �������� ������
	case ItemEnum::ironWire:
		energyObjects.push_back(new NotTransferItemEnergyObject<WireInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["IronWireOn"],
			assets->itemTextures, position, colorsInventory, 100, 100));
		transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
		// �������� ������
	case ItemEnum::tinWire:
		energyObjects.push_back(new NotTransferItemEnergyObject<WireInventory >(
			rw, *cameraPosition, sizeOne, assets->textures["TinWireOn"],
			assets->itemTextures, position, colorsInventory, 1000, 1000));
		transferEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
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
		energyObjectsNumbers[energyObjects[i]->position.x][energyObjects[i]->position.y] = i;
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

	for (size_t i = 0; i < transferEnergyObjects.size(); i++)
	{
		transferEnergyObjectsNumbers[transferEnergyObjects[i]->position.x][transferEnergyObjects[i]->position.y] = i;
	}

	for (size_t i = 0; i < transferItemObjects.size(); i++)
	{
		transferItemObjectsNumbers[transferItemObjects[i]->position.x][transferItemObjects[i]->position.y] = i;
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
	if (energyObjectsNumbers[nextPosition.x][nextPosition.y] == -1) return;

	EnergyObjectInventory* thisObjectInventory;
	thisObjectInventory = 
		energyObjects[energyObjectsNumbers[nextPosition.x][nextPosition.y]]->inventory;
	TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
}

void Field::WhatObjectTransEnergy()
{
	// �������� �������
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			if (transferEnergyObjectsNumbers[i][j] == -1) continue;
			if (transferEnergyObjects[transferEnergyObjectsNumbers[i][j]]->inventory->energy == 0) continue;
			if (energyObjectsNumbers[i][j] == -1) continue;

			sf::Vector2i shift =
				CheckTurn(transferEnergyObjects[transferEnergyObjectsNumbers[i][j]]->turn);
			CheckNextEnergyObject(sf::Vector2i(i + shift.x, j + shift.y),
				transferEnergyObjects[transferEnergyObjectsNumbers[i][j]]->inventory->energy,
				transferEnergyObjects[transferEnergyObjectsNumbers[i][j]]->inventory->power);
		}
	}
}

void Field::TransItem(Item* transferItem, Item* acceptItem)
{
	if (transferItem->number != 0)
	{
		if (acceptItem->number == transferItem->number)
		{
			acceptItem->quantity += 1;
			transferItem->quantity -= 1;
		}
		else if (acceptItem->number == 0)
		{
			acceptItem->NumberUpdate(transferItem->number);
			acceptItem->quantity += 1;
			transferItem->quantity -= 1;
		}
	}
	if (transferItem->quantity == 0)
	{
		transferItem->NumberUpdate(ItemEnum::empty);
	}
}

void Field::CheckNextItemObject(sf::Vector2i nextPosition, Item* transferItem)
{
	if (transferItemObjectsNumbers[nextPosition.x][nextPosition.y] == -1) return;
	TransItem(transferItem,
		transferItemObjectsInventories[transferItemObjectsNumbers[nextPosition.x][nextPosition.y]]->acceptItem);
}

void Field::WhatObjectTransItem()
{
	// �������� ���������
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			if (transferItemObjectsNumbers[i][j] == -1) continue;
			if (transferItemObjectsInventories[transferItemObjectsNumbers[i][j]]->transferItem->number == ItemEnum::empty)
				continue;

			sf::Vector2i shift =
				CheckTurn(transferItemObjects[transferItemObjectsNumbers[i][j]]->turn);
			CheckNextItemObject(sf::Vector2i(i + shift.x, j + shift.y),
				transferItemObjectsInventories[transferItemObjectsNumbers[i][j]]->transferItem);
		}
	}
}

sf::Vector2i Field::CheckTurn(int turn)
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

void Field::PlayUpdate()
{
	for (size_t i = 0; i < playUpdatables.size(); i++)
	{
		playUpdatables[i]->PlayUpdate();
	}

	WhatObjectTransEnergy();
	WhatObjectTransItem();

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
		chooseNumber == 32 || chooseNumber == ItemEnum::pipe) &&
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
