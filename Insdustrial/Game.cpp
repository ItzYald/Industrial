#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "�����������������������";
	font.loadFromFile("Font/Undertale-Font.ttf");
}
// �������� ����������
void Game::LoadingApp()
{
	objects = std::vector<Object*>();
	transEnergyObjects = std::vector<IEnergyObject*>();
	simpleObjects = std::vector<IStaingObject*>();


	mouseWheel = 0;
	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

	srand(time(NULL));

	screen = "����";
	cameraPosition = sf::Vector2f(20, 20);
}
// �������� ������������� ��������
void Game::LoadingScreen(std::string nextScreen)
{
	functions.PrintText(L"��������...", sf::Vector2f(sizeW.x / 2 - 100, 300), 25, sf::Color::Green);
	screen = nextScreen;
}
// �������� �������� ����� ���������� �� �����
void Game::LoadColorInventoryFromFile()
{
	colorsInventory.clear();
	// ���� � �������
	std::fstream colorFile("Files/ColorInventory.txt");
	// ���������� ������
	std::string line;
	std::string line2;
	line2 = "";
	while (std::getline(colorFile, line))
	{
		sf::Color color = sf::Color(0, 0, 0);
		// �������
		line2.push_back(line[0]);
		line2.push_back(line[1]);
		line2.push_back(line[2]);
		color.r = std::stoi(line2);
		line2.clear();
		// �������
		line2.push_back(line[4]);
		line2.push_back(line[5]);
		line2.push_back(line[6]);
		color.g = std::stoi(line2);
		line2.clear();
		// �����
		line2.push_back(line[8]);
		line2.push_back(line[9]);
		line2.push_back(line[10]);
		color.b = std::stoi(line2);
		colorsInventory.push_back(color);
		//std::cout << line2 << std::endl;
		line2.clear();
	}
}
// �������� �������� ��� ����
void Game::LoadingImagesPlay()
{
	/// ��������:
	textures["Player"] = sf::Texture();
	textures["Player"].loadFromFile("Images/Human.png");
	// �����
	textures["Oven"] = sf::Texture();
	textures["Oven"].loadFromFile("Images/Objects/Oven.png");
	// ������������
	textures["ElectricOven"] = sf::Texture();
	textures["ElectricOven"].loadFromFile("Images/Objects/ElectricOven.png");
	// ���������
	textures["Crusher"] = sf::Texture();
	textures["Crusher"].loadFromFile("Images/Objects/Crusher.png");
	// ���������
	textures["Compressor"] = sf::Texture();
	textures["Compressor"].loadFromFile("Images/Objects/Compressor.png");
	// ������
	textures["Chest"] = sf::Texture();
	textures["Chest"].loadFromFile("Images/Objects/Chest.png");
	// �������
	textures["Workbench"] = sf::Texture();
	textures["Workbench"].loadFromFile("Images/Objects/Workbench.png");
	// �����
	textures["Grass"] = sf::Texture();
	textures["Grass"].loadFromFile("Images/Grass.png");
	// ��������� �������
	textures["EnergyStorage"] = sf::Texture();
	textures["EnergyStorage"].loadFromFile("Images/Objects/EnergyStorage.png");
	// ������ ���������������
	textures["EnergyHandGenerator"] = sf::Texture();
	textures["EnergyHandGenerator"].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// �������� ���������������
	textures["EnergyCoalGenerator"] = sf::Texture();
	textures["EnergyCoalGenerator"].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	/// ��������� ��������
	// ������
	textures["CopperWireOn"] = sf::Texture();
	textures["CopperWireOn"].loadFromFile("Images/Wires/CopperWireOn.png");
	textures["CopperWireOff"] = sf::Texture();
	textures["CopperWireOff"].loadFromFile("Images/Wires/CopperWireOff.png");
	// ��������
	textures["IronWireOn"] = sf::Texture();
	textures["IronWireOn"].loadFromFile("Images/Wires/IronWireOn.png");
	textures["IronWireOff"] = sf::Texture();
	textures["IronWireOff"].loadFromFile("Images/Wires/IronWireOff.png");
	// ���������
	textures["TinWireOn"] = sf::Texture();
	textures["TinWireOn"].loadFromFile("Images/Wires/TinWireOn.png");
	textures["TinWireOff"] = sf::Texture();
	textures["TinWireOff"].loadFromFile("Images/Wires/TinWireOff.png");
	/// ������ � ���������
	// ������ ������ ��������� �������
	texturesInInventory["HandGenerate"] = sf::Texture();
	texturesInInventory["HandGenerate"].loadFromFile(
		"Images/IconsInInventory/IconEnergyHandGenerator.png");

	// �������� ���������
	for (int i = 0; i < 32; i++)
	{
		itemTextures.push_back(sf::Texture());
	}

	// ������ ����
	itemTextures[0].loadFromFile("Images/Empty.png");
	// �������� ����
	itemTextures[1].loadFromFile("Images/Metals/IronOre.png");
	// �����
	itemTextures[2].loadFromFile("Images/Objects/Oven.png");
	// �����
	itemTextures[3].loadFromFile("Images/Coal.png");
	// �������� ������
	itemTextures[4].loadFromFile("Images/Metals/IronIngot.png");
	// ������
	itemTextures[5].loadFromFile("Images/Objects/Chest.png");
	// �������� ����
	itemTextures[6].loadFromFile("Images/IronBlock.png");
	// ���������
	itemTextures[7].loadFromFile("Images/Wood.png");
	// �������
	itemTextures[8].loadFromFile("Images/Objects/WorkBench.png");
	// �����
	itemTextures[9].loadFromFile("Images/Planks.png");
	// ������ ����������
	itemTextures[10].loadFromFile("Images/Accumulator.png");
	// ����������
	itemTextures[11].loadFromFile("Images/Objects/ElectricOven.png");
	// ������ ������
	itemTextures[12].loadFromFile("Images/Wires/CopperWireOn.png");
	// ���������������
	itemTextures[13].loadFromFile("Images/Objects/EnergyStorage.png");
	// ������ ������
	itemTextures[14].loadFromFile("Images/Metals/CopperIngot.png");
	// �������� ������
	itemTextures[15].loadFromFile("Images/Wires/IronWireOn.png");
	// ������ ���������������
	itemTextures[16].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// �������� ���������������
	itemTextures[17].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	// ������ ����������
	itemTextures[18].loadFromFile("Images/Objects/MechanismBody.png");
	// �������� ������
	itemTextures[19].loadFromFile("Images/Metals/TinIngot.png");
	// �������� ������
	itemTextures[20].loadFromFile("Images/Wires/TinWireOn.png");
	// �������� ������
	itemTextures[21].loadFromFile("Images/Metals/CopperOre.png");
	// �������� ������
	itemTextures[22].loadFromFile("Images/Metals/TinOre.png");
	// ������������ �������� ����
	itemTextures[23].loadFromFile("Images/Metals/CrushedIronOre.png");
	// ����������
	itemTextures[24].loadFromFile("Images/Objects/Crusher.png");
	// �������� ��������
	itemTextures[25].loadFromFile("Images/Metals/IronPlate.png");
	// ����������
	itemTextures[26].loadFromFile("Images/Metals/CopperPlate.png");
	// ����������
	itemTextures[27].loadFromFile("Images/Metals/TinPlate.png");
	// ����������
	itemTextures[28].loadFromFile("Images/Objects/Compressor.png");
	// ����������
	itemTextures[29].loadFromFile("Images/Chip.png");
	// �����
	itemTextures[30].loadFromFile("Images/Stick.png");
	// �����
	itemTextures[31].loadFromFile("Images/Hammer.png");

}
// �������� ��������
void Game::LoadingPlay()
{
	drawables.clear();
	// �������� ������ ����������
	LoadColorInventoryFromFile();

	LoadingImagesPlay();

	field = Field(rw, cameraPosition, sf::Vector2i(200, 200), 48, sizeW, textures["Grass"], objects);
	player = Player(rw, cameraPosition, field.sizeOne, textures["Player"], sf::Vector2f(20, 20), colorsInventory, itemTextures);

	energyObjects.push_back(new EnergyObject<ElectricOvenInventory > (
		rw, cameraPosition, field.sizeOne, textures["ElectricOven"], itemTextures, sf::Vector2f(23, 19), colorsInventory));
	energyObjects.push_back(new EnergyObject<CrusherInventory > (
		rw, cameraPosition, field.sizeOne, textures["Crusher"], itemTextures, sf::Vector2f(19, 17), colorsInventory, 1000));
	energyObjects.push_back(new EnergyObject<CompressorInventory > (
		rw, cameraPosition, field.sizeOne, textures["Compressor"], itemTextures, sf::Vector2f(19, 16), colorsInventory, 1000));
	energyObjects.push_back(new EnergyObject<EnergyStorageInventory> (
		rw, cameraPosition, field.sizeOne, textures["EnergyStorage"], itemTextures, sf::Vector2f(22, 20), colorsInventory, 10000, 10));
	transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new EnergyObject<EnergyHandGeneratorInventory> (
		rw, cameraPosition, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, sf::Vector2f(22, 19), colorsInventory, 100, 10, texturesInInventory));
	transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
	energyObjects.push_back(new EnergyObject<EnergyCoalGeneratorInventory > (
		rw, cameraPosition, field.sizeOne, textures["EnergyCoalGenerator"], itemTextures, sf::Vector2f(20, 19), colorsInventory, 100, 10));
	transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);

	simpleObjects.push_back(new StaingObject<CoalOvenInventory>(
		rw, cameraPosition, field.sizeOne, textures["Oven"], itemTextures, sf::Vector2f(23, 20), colorsInventory));
	simpleObjects.push_back(new StaingObject<ChestInventory> (
		rw, cameraPosition, field.sizeOne, textures["Chest"], itemTextures, sf::Vector2f(23, 21), colorsInventory));
	simpleObjects.push_back(new StaingObject<WorkbenchInventory > (
		rw, cameraPosition, field.sizeOne, textures["Workbench"], itemTextures, sf::Vector2f(23, 22), colorsInventory));

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
		drawables.push_back(objects[i]);
	}

	screen = "����";
}

void Game::UnloadingPlay(std::string nextScreen)
{
	textures.clear();
	itemTextures.clear();
	texturesInInventory.clear();

	drawables.clear();
	buttons.clear();
	objects.clear();
	simpleObjects.clear();
	energyObjects.clear();
	transEnergyObjects.clear();

	screen = nextScreen;
}
// ��������� ����
void Game::DrawPlay()
{
	// ����� �����
	functions.DrawRectangle(sf::Vector2f(0, 0), sf::Vector2f(sizeW.x, sizeW.y), sf::Color(255, 255, 255));
	// ��������� ����
	field.Draw();
	// ��������� ��������
	for (int i = drawables.size() - 1; i >= 0; i--)
	{
		rw->draw(*drawables[i]);
	}
	rw->draw(player);
}

void Game::DrawGameplay()
{
	// ��������� ������, �� ������� �����
	functions.DrawRectangle(sf::Vector2f(
		field.sizeOne * (mousePositionGrid.x - cameraPosition.x),
		field.sizeOne * (mousePositionGrid.y - cameraPosition.y)),
		sf::Vector2f(field.sizeOne, field.sizeOne), sf::Color(200, 200, 200, 100), sf::Color(150, 150, 150), 2);
}
// ������� ���������
void Game::CloseInventory()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		player.isOpenInventory = false;

		switch (player.newWhatTypeInventoryOpen)
		{
		case 1:
			energyObjects[player.newWhatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 2:
			simpleObjects[player.newWhatNumberInventoryOpen]->isOpenInventory = false;
			break;
		}
	}
}
// ��������� ������ �� ������������ �����������
void Game::PutObject(sf::Vector2f position)
{
	// ���������:
	switch (player.inventory.cells[player.inventory.choseCell][3].item.number)
	{
	// �����
	case 2:
		simpleObjects.push_back(new StaingObject<CoalOvenInventory >(
			rw, cameraPosition, field.sizeOne, textures["Oven"], itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
	// ������������
	case 11:
		energyObjects.push_back(new EnergyObject<ElectricOvenInventory > (
			rw, cameraPosition, field.sizeOne, textures["ElectricOven"], itemTextures, position, colorsInventory));
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ���������
	case 24:
		energyObjects.push_back(new EnergyObject<CrusherInventory > (
			rw, cameraPosition, field.sizeOne, textures["Crusher"], itemTextures, position, colorsInventory, 1000));
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ����������
	case 28:
		energyObjects.push_back(new EnergyObject<CompressorInventory > (
			rw, cameraPosition, field.sizeOne, textures["Compressor"], itemTextures, position, colorsInventory, 1000));
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ������
	case 5:
		simpleObjects.push_back(new StaingObject<ChestInventory > (
			rw, cameraPosition, field.sizeOne, textures["Chest"], itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
	// �������
	case 8:
		simpleObjects.push_back(new StaingObject<WorkbenchInventory > (
			rw, cameraPosition, field.sizeOne, textures["Workbench"], itemTextures, position, colorsInventory));
		objects.push_back(simpleObjects[simpleObjects.size() - 1]);
		break;
	// ���������������
	case 13:
		energyObjects.push_back(new EnergyObject<EnergyStorageInventory > (
			rw, cameraPosition, field.sizeOne, textures["EnergyStorage"], itemTextures, position, colorsInventory, 1000, 10));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// ������ ���������������
	case 16:
		energyObjects.push_back(new EnergyObject<EnergyHandGeneratorInventory > (
			rw, cameraPosition, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, position, colorsInventory, 100, 10));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// �������� ���������������
	case 17:
		energyObjects.push_back(new EnergyObject<EnergyCoalGeneratorInventory > (
			rw, cameraPosition, field.sizeOne, textures["EnergyCoalGenerator"], itemTextures, position, colorsInventory, 100, 10));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
	// ������ ������
	case 12:
		energyObjects.push_back(new EnergyObject<WireInventory > (
			rw, cameraPosition, field.sizeOne, textures["CopperWireOn"], itemTextures, position, colorsInventory, 10, 10));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// �������� ������
	case 15:
		energyObjects.push_back(new EnergyObject<WireInventory > (
			rw, cameraPosition, field.sizeOne, textures["IronWireOn"], itemTextures, position, colorsInventory, 100, 100));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	// �������� ������
	case 20:
		energyObjects.push_back(new EnergyObject<WireInventory > (
			rw, cameraPosition, field.sizeOne, textures["TinWireOn"], itemTextures, position, colorsInventory, 1000, 1000));
		transEnergyObjects.push_back(energyObjects[energyObjects.size() - 1]);
		objects.push_back(energyObjects[energyObjects.size() - 1]);
		break;
	}
}
// ��������
void Game::Gameplay()
{
	// ��������� ���������� ��� �������� ���������� �� ������
	sf::Vector2i m = sf::Vector2i(
		mousePosition.x / (float)field.sizeOne + cameraPosition.x,
		mousePosition.y / (float)field.sizeOne + cameraPosition.y);

	float mouseDistance = std::sqrt((m.x - player.position.x) * (m.x - player.position.x) +
		(m.y - player.position.y) * (m.y - player.position.y));

	if (mouseDistance > maxMouseDistance)
	{
		mousePositionGrid = sf::Vector2i(
			(player.position.x + (m.x - player.position.x) / (mouseDistance / maxMouseDistance)),
			(player.position.y + (m.y - player.position.y) / (mouseDistance / maxMouseDistance)));
	}
	else
	{
		mousePositionGrid = m;
	}

	DrawGameplay();

	// ��, ��� ������ ����� ������ ����
	player.Update();
	// ��������� �����
	player.inventory.DrawNear(mouseWheel);
	// ��������� ������ �� �����
	if (field.PutObject(mousePositionGrid, objects, player.inventory.cells[player.inventory.choseCell][3].item))
	{
		PutObject((sf::Vector2f)mousePositionGrid);
	}

	for (size_t i = 0; i < energyObjects.size(); i++)
	{
		field.newEnergyObjectsNumbers[energyObjects[i]->position.x][energyObjects[i]->position.y] = i;
		energyObjects[i]->Update(mousePositionGrid, player.position, player.angle);
		if (energyObjects[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.newWhatTypeInventoryOpen = 1;
			player.newWhatNumberInventoryOpen = i;
			break;
		}
	}

	for (size_t i = 0; i < simpleObjects.size(); i++)
	{
		simpleObjects[i]->Update(mousePositionGrid, player.position, player.angle);
		if (simpleObjects[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.newWhatTypeInventoryOpen = 2;
			player.newWhatNumberInventoryOpen = i;
			break;
		}
	}

	for (size_t i = 0; i < transEnergyObjects.size(); i++)
	{
		field.transEnergyObjectsNumbers[transEnergyObjects[i]->position.x][transEnergyObjects[i]->position.y] = i;
	}

	// �������� ������
	//cameraPosition -= (cameraPosition - sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2))) * 0.04f;
	cameraPosition = sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2));
}

void Game::TransEnergy(float& originalEnergy, int power, float& nextEnergy, int nextMaxEnergy)
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

void Game::CheckNextEnergyObject(sf::Vector2i nextPosition, float& energy, int power)
{
	EnergyObjectInventory* thisObjectInventory;

	if (field.newEnergyObjectsNumbers[nextPosition.x][nextPosition.y] == -1)
	{
		return;
	}

	thisObjectInventory = energyObjects[field.newEnergyObjectsNumbers[nextPosition.x][nextPosition.y]]->inventory;
	TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
}

sf::Vector2i Game::CheckTurnEnergy(int turn)
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

void Game::WhatObjectTransEnergy()
{
	// �������� �������
	for (int i = 0; i < field.size.x; i++)
	{
		for (int j = 0; j < field.size.y; j++)
		{
			sf::Vector2i shift;
			int typeObject = -1;

			if (field.transEnergyObjectsNumbers[i][j] == -1)
			{
				continue;
			}
			if (transEnergyObjects[field.transEnergyObjectsNumbers[i][j]]->inventory->energy == 0)
			{
				continue;
			}

			shift = CheckTurnEnergy(transEnergyObjects[field.transEnergyObjectsNumbers[i][j]]->turn);
			if (field.newEnergyObjectsNumbers[i][j] == -1)
			{
				continue;
			}
			CheckNextEnergyObject(sf::Vector2i(i + shift.x, j + shift.y),
				transEnergyObjects[field.transEnergyObjectsNumbers[i][j]]->inventory->energy,
				transEnergyObjects[field.transEnergyObjectsNumbers[i][j]]->inventory->power);
		}
	}

}

void Game::WhatInventory()
{
	switch (player.newWhatTypeInventoryOpen)
	{
	case 0:
		player.inventory.DrawMiniWorkbench();
		player.inventory.Update();
		break;
	case 1:
		energyObjects[player.newWhatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
	case 2:
		simpleObjects[player.newWhatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
	}
	
	CloseInventory();
}
// ����
void Game::Play()
{
	if (oldButtons.size() < 4)
	{
		// ������ �����
		oldButtons.push_back(OldButton(sf::Vector2f(1000, 608), sf::Vector2f(128, 64), L"�����",
			colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
			sf::Color(255, 255, 255), sf::Color::Transparent, sf::Vector2f(128 / 2 - 35, 12), 4, 25));
	}
	// ���������� ����
	DrawPlay();

	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->Next();
	}

	WhatObjectTransEnergy();

	if (!player.isOpenInventory)
	{
		Gameplay();
	}
	else
	{
		WhatInventory();
	}

	// ������ �����
	if (oldButtons[0].DrawCheckLeft(*rw))
	{
		screen = "��������������������";
		oldButtons.clear();
		return;
	}

}
// ����
void Game::Menu()
{
	if (oldButtons.size() < 1)
	{
		oldButtons.push_back(OldButton(sf::Vector2f(sizeW.x / 2 - 75, 300), sf::Vector2f(150, 40), L"������",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
		oldButtons.push_back(OldButton(sf::Vector2f(sizeW.x / 2 - 75, 500), sf::Vector2f(150, 40), L"�����",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
		buttons.push_back(new BaseButton(mousePosition, sf::Vector2f(100, 100), sf::Vector2f(100, 50),
			buttonColors(sf::Color(255, 255, 255), sf::Color(200, 200, 200)),
			buttonColors(sf::Color(0, 255, 0), sf::Color::Transparent),
			buttonColors(sf::Color(255, 0, 0), sf::Color::Transparent),
			buttonColors(sf::Color(0, 0, 255), sf::Color::Transparent)));
		for (size_t i = 0; i < buttons.size(); i++)
		{
			drawables.push_back(buttons[i]);
		}
	}

	functions.DrawRectangle(sf::Vector2f(200, 100), sf::Vector2f(980, 520), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 4);
	functions.PrintText(L"Industrial", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

	if (oldButtons[0].DrawCheckLeft(*rw))
	{
		screen = "�����������������������";
		oldButtons.clear();
		return;
	}

	for (size_t i = 0; i < drawables.size(); i++)
	{
		rw->draw(*drawables[i]);
	}

	buttons[0]->Update();

	if (oldButtons[1].DrawCheckLeft(*rw) || ch[0].Check(sf::Keyboard::Escape))
	{
		rw->close();
		oldButtons.clear();
		return;
	}

}
// ���������� ���� (����� ������)
void Game::Next()
{
	mousePosition = sf::Mouse::getPosition(*rw);

	if (screen == "����")
	{
		Play();
	}
	else if (screen == "�����������������������")
	{
		LoadingScreen("������������������");
	}
	else if (screen == "������������������")
	{
		LoadingApp();
	}
	else if (screen == "�����������������������")
	{
		LoadingScreen("����������������");
	}
	else if (screen == "�����������������������������")
	{
		LoadingScreen("����");
	}
	else if (screen == "��������������������")
	{
		UnloadingPlay("����");
	}
	else if (screen == "����������������")
	{
		LoadingPlay();
	}
	else if (screen == "����")
	{
		Menu();
	}
	// ��������� � �������� FPS
	sf::Time FPS = clock.getElapsedTime();
	functions.PrintText(std::to_string((int)(1 / FPS.asSeconds())), sf::Vector2f(sizeW.x - 15, 10), 25, sf::Color::Red, 0);
	clock.restart();
	mouseWheel = 0;
}
// ������� ����
void Game::Mouse(sf::Event& e, sf::RenderWindow& rw)
{
	mousePosition = sf::Mouse::getPosition(rw);
}

void Game::MouseWheelScrolled(int _mouseWheel)
{
	mouseWheel = _mouseWheel;
}
