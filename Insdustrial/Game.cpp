#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "�����������������������";
	font.loadFromFile("Font/Undertale-Font.ttf");

	coalOvens = std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>();
	electricOvens = std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>();

	chests = std::vector<std::shared_ptr<StaingObject<ChestInventory>>>();
	workbenches = std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>();

	energyHandGenerators = std::vector<std::shared_ptr<EnergySprite<EnergyHandGeneratorInventory>>>();
	energyCoalGenerators = std::vector<std::shared_ptr<EnergySprite<EnergyCoalGeneratorInventory>>>();

	wires = std::vector<std::shared_ptr<Wire>>();
}
// �������� ����������
void Game::LoadingApp()
{
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
// �������� ��������
void Game::LoadingPlay()
{
	// �������� ������ ����������
	LoadColorInventoryFromFile();
	/// ��������:
	// �����
	textures["Oven"] = sf::Texture();
	textures["Oven"].loadFromFile("Images/Objects/Oven.png");
	// ������������
	textures["ElectricOven"] = sf::Texture();
	textures["ElectricOven"].loadFromFile("Images/Objects/ElectricOven.png");
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
	textures["CooperWire"] = sf::Texture();
	textures["CooperWire"].loadFromFile("Images/Wires/CooperWireOn.png");
	// ��������
	textures["IronWire"] = sf::Texture();
	textures["IronWire"].loadFromFile("Images/Wires/IronWireOn.png");
	/// ������ � ���������
	// ������ ������ ��������� �������
	texturesInInventory["HandGenerate"] = sf::Texture();
	texturesInInventory["HandGenerate"].loadFromFile(
		"Images/IconsInInventory/IconEnergyHandGenerator.png");


	// �������� ���������
	for (int i = 0; i < 19; i++)
	{
		itemTextures.push_back(sf::Texture());
	}

	// ������ ����
	itemTextures[0].loadFromFile("Images/Empty.png");
	// �������� ����
	itemTextures[1].loadFromFile("Images/IronOre.png");
	// �����
	itemTextures[2].loadFromFile("Images/Objects/Oven.png");
	// �����
	itemTextures[3].loadFromFile("Images/Coal.png");
	// �������� ������
	itemTextures[4].loadFromFile("Images/IronIngot.png");
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
	// ��������
	itemTextures[10].loadFromFile("Images/Redstone.png");
	// ����������
	itemTextures[11].loadFromFile("Images/Objects/ElectricOven.png");
	// ������ ������
	itemTextures[12].loadFromFile("Images/Wires/CooperWireOn.png");
	// ���������������
	itemTextures[13].loadFromFile("Images/Objects/EnergyStorage.png");
	// ������ ������
	itemTextures[14].loadFromFile("Images/CooperIngot.png");
	// �������� ������
	itemTextures[15].loadFromFile("Images/Wires/IronWireOn.png");
	// ������ ���������������
	itemTextures[16].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// �������� ���������������
	itemTextures[17].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	// ������ ����������
	itemTextures[18].loadFromFile("Images/Objects/MechanismBody.png");


	field = Field(rw, sf::Vector2i(200, 200), 48, sizeW, textures["Grass"]);
	player = Player(rw, field.sizeOne, "Images/Human.png", sf::Vector2f(20, 20), colorsInventory, itemTextures);

	coalOvens.push_back(
		std::make_shared<StaingObject<CoalOvenInventory>>(rw, field.sizeOne, textures["Oven"], itemTextures, sf::Vector2f(23, 20), colorsInventory));
	electricOvens.push_back(
		std::make_shared<StaingObject<ElectricOvenInventory>>(rw, field.sizeOne, textures["ElectricOven"], itemTextures, sf::Vector2f(23, 19), colorsInventory));
	chests.push_back(
		std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, textures["Chest"], itemTextures, sf::Vector2f(23, 21), colorsInventory));
	workbenches.push_back(
		std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, textures["Workbench"], itemTextures, sf::Vector2f(23, 22), colorsInventory));
	energyStorages.push_back(
		std::make_shared<StaingObject<EnergyStorageInventory>>(rw, field.sizeOne, textures["EnergyStorage"], itemTextures, sf::Vector2f(22, 20), colorsInventory, 10000, 10));
	energyHandGenerators.push_back(
		std::make_shared<EnergySprite<EnergyHandGeneratorInventory>>(rw, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, sf::Vector2f(22, 19), colorsInventory, 100, 10, texturesInInventory));
	energyCoalGenerators.push_back(
		std::make_shared<EnergySprite<EnergyCoalGeneratorInventory>>(rw, field.sizeOne, textures["EnergyCoalGenerator"], itemTextures, sf::Vector2f(21, 18), colorsInventory, 100, 10));

	screen = "����";
}

void Game::UnloadingPlay(std::string nextScreen)
{
	textures.clear();
	itemTextures.clear();
	texturesInInventory.clear();

	coalOvens.clear();
	electricOvens.clear();
	chests.clear();
	workbenches.clear();
	wires.clear();
	energyStorages.clear();
	energyHandGenerators.clear();
	energyCoalGenerators.clear();

	screen = nextScreen;
}
// ��������� ����
void Game::DrawPlay()
{
	// ����� �����
	functions.DrawRectangle(sf::Vector2f(0, 0), sf::Vector2f(sizeW.x, sizeW.y), sf::Color(255, 255, 255));
	// ��������� ����
	field.Draw(cameraPosition);
	// ��������� �������� �����
	for (std::shared_ptr<StaingObject<CoalOvenInventory>> oven : coalOvens)
	{
		oven->Draw(cameraPosition);
	}
	// ��������� ������������� �����
	for (std::shared_ptr<StaingObject<ElectricOvenInventory>> oven : electricOvens)
	{
		oven->Draw(cameraPosition);
	}
	// ��������� ��������
	for (std::shared_ptr<StaingObject<ChestInventory>> chest : chests)
	{
		chest->Draw(cameraPosition);
	}
	// ��������� ���������
	for (std::shared_ptr<StaingObject<WorkbenchInventory>> worbench : workbenches)
	{
		worbench->Draw(cameraPosition);
	}
	// ��������� ������� �������
	for (std::shared_ptr<StaingObject<EnergyStorageInventory>> energyStorage : energyStorages)
	{
		energyStorage->Draw(cameraPosition);
	}
	// ��������� ������ �����������������
	for (std::shared_ptr<StaingObject<EnergyHandGeneratorInventory>> energyHandGenerator : energyHandGenerators)
	{
		energyHandGenerator->Draw(cameraPosition);
	}
	// ��������� �������� �����������������
	for (std::shared_ptr<StaingObject<EnergyCoalGeneratorInventory>> energyCoalGenerator : energyCoalGenerators)
	{
		energyCoalGenerator->Draw(cameraPosition);
	}
	// ��������� ��������
	for (std::shared_ptr<Wire> wire : wires)
	{
		wire->Draw(cameraPosition);
	}
	// ��������� ������
	player.Draw(cameraPosition);
}

void Game::DrawDrive()
{
	// ��������� ������, ��������� �����
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

		switch (player.whatTypeInventoryOpen)
		{
		case 1:
			coalOvens[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 2:
			electricOvens[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 3:
			chests[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 4:
			workbenches[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 5:
			energyStorages[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 6:
			energyHandGenerators[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 7:
			energyCoalGenerators[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		}
		//player.inventory.DeleteButtons();
	}
}
// ��������� ������ �� ������������ �����������
void Game::PutObject(sf::Vector2f position)
{
	// ��������� �����
	if (player.inventory.cells[player.inventory.choseCell][3].item.number == 2)
	{
		coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(rw, field.sizeOne, textures["Oven"], itemTextures, position, colorsInventory));
	}
	// ��������� �������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 11)
	{
		electricOvens.push_back(std::make_shared<StaingObject<ElectricOvenInventory>>(rw, field.sizeOne, textures["ElectricOven"], itemTextures, position, colorsInventory));
	}
	// ��������� ������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 5)
	{
		chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, textures["Chest"], itemTextures, position, colorsInventory));
	}
	// ��������� �������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 8)
	{
		workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, textures["Workbench"], itemTextures, position, colorsInventory));
	}
	// ��������� ���������������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 13)
	{
		energyStorages.push_back(std::make_shared<StaingObject<EnergyStorageInventory>>(rw, field.sizeOne, textures["EnergyStorage"], itemTextures, position, colorsInventory, 1000, 10));
	}
	// ��������� ������ ���������������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 16)
	{
		energyHandGenerators.push_back(std::make_shared<EnergySprite<EnergyHandGeneratorInventory>>(rw, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, position, colorsInventory, 100, 10));
	}
	// ��������� ������ ���������������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 17)
	{
		energyCoalGenerators.push_back(std::make_shared<EnergySprite<EnergyCoalGeneratorInventory>>(rw, field.sizeOne, textures["EnergyCoalGenerator"], itemTextures, position, colorsInventory, 100, 10));
	}
	// ��������� ������ ������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 12)
	{
		wires.push_back(std::make_shared<Wire>(rw, field.sizeOne, textures["CooperWire"], position, 0));
	}
	// ��������� �������� ������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 15)
	{
		wires.push_back(std::make_shared<Wire>(rw, field.sizeOne, textures["IronWire"], position, 1));
	}
}
// ��������
void Game::Drive()
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

	DrawDrive();

	// ��, ��� ������ ����� ������ ����
	player.Update();
	// ��������� �����
	player.inventory.DrawNear(mouseWheel);
	// ��������� ������ �� �����
	bool nearObject = player.PutObject(mousePositionGrid,
		coalOvens, electricOvens, chests, workbenches, wires, energyStorages, energyHandGenerators, energyCoalGenerators);
	if (nearObject)
	{
		PutObject((sf::Vector2f)mousePositionGrid);
	}

	// ������ �������� �����
	for (int i = 0; i < coalOvens.size(); i++)
	{
		coalOvens[i]->Update(mousePositionGrid, player.position, player.angle);
		if (coalOvens[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 1;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ������������� �����
	for (int i = 0; i < electricOvens.size(); i++)
	{
		// ���������� ������� � ��������� ������ ������������ � ������� �� �����������
		field.electricOvens[electricOvens[i]->position.x][electricOvens[i]->position.y] = i;
		// ���������� ������������
		electricOvens[i]->Update(mousePositionGrid, player.position, player.angle);
		// ���� ��������� ������
		if (electricOvens[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 2;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ��������
	for (int i = 0; i < chests.size(); i++)
	{
		chests[i]->Update(mousePositionGrid, player.position, player.angle);
		if (chests[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 3;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ���������
	for (int i = 0; i < workbenches.size(); i++)
	{
		workbenches[i]->Update(mousePositionGrid, player.position, player.angle);
		if (workbenches[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 4;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ �������� �������
	for (int i = 0; i < energyStorages.size(); i++)
	{
		// ���������� ������� � ��������� ������ �������� � ������� �� �����������
		field.energyStorages[energyStorages[i]->position.x][energyStorages[i]->position.y] = i;
		energyStorages[i]->Update(mousePositionGrid, player.position, player.angle);
		if (energyStorages[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 5;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ������ �����������������
	for (int i = 0; i < energyHandGenerators.size(); i++)
	{
		// ���������� ������� � ��������� ������ �������� � ������� �� �����������
		field.energyHandGenerators[energyHandGenerators[i]->position.x][energyHandGenerators[i]->position.y] = i;
		energyHandGenerators[i]->Update(mousePositionGrid, player.position, player.angle);
		if (energyHandGenerators[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 6;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ �������� �����������������
	for (int i = 0; i < energyCoalGenerators.size(); i++)
	{
		// ���������� ������� � ��������� ������ �������� � ������� �� �����������
		field.energyCoalGenerators[energyCoalGenerators[i]->position.x][energyCoalGenerators[i]->position.y] = i;
		energyCoalGenerators[i]->Update(mousePositionGrid, player.position, player.angle);
		if (energyCoalGenerators[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 7;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ��������
	for (int i = 0; i < wires.size(); i++)
	{
		// ���������� ������� � ��������� ������ �������� � ������� �� �����������
		field.wires[wires[i]->position.x][wires[i]->position.y] = i;
		wires[i]->Update(player.position, player.angle);
	}
	// �������� ������
	//cameraPosition -= (cameraPosition - sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2))) * 0.04f;
	cameraPosition = sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2));
}

void Game::TransEnergy(float& originalEnergy, int power, float& nextEnergy, int nextMaxEnergy)
{
	if (originalEnergy - power < 0)
	{
		if (nextEnergy + power > nextMaxEnergy)
		{
			originalEnergy -= nextMaxEnergy - nextEnergy;
			nextEnergy = nextMaxEnergy;
		}
		else
		{
			nextEnergy += power;
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
	// ���� �� ����� ����� ������
	if (field.wires[nextPosition.x][nextPosition.y] != -1)
	{
		std::shared_ptr<Wire> thisWire = wires[field.wires[nextPosition.x][nextPosition.y]];
		TransEnergy(energy, power, thisWire->energy, thisWire->maxEnergy);
	}
	// ���� �� ����� ����� ������������
	else if (field.electricOvens[nextPosition.x][nextPosition.y] != -1)
	{
		ElectricOvenInventory& thisOvenInventory = electricOvens[field.electricOvens[nextPosition.x][nextPosition.y]]->inventory;
		TransEnergy(energy, power, thisOvenInventory.fuel, thisOvenInventory.maxFuel);
	}
	// ���� �� ����� ����� ���������������
	else if (field.energyStorages[nextPosition.x][nextPosition.y] != -1)
	{
		EnergyStorageInventory& thisEnergyStorage = energyStorages[field.energyStorages[nextPosition.x][nextPosition.y]]->inventory;
		TransEnergy(energy, power, thisEnergyStorage.energy, thisEnergyStorage.maxEnergy);
	}
}

void Game::CheckTypeTrans(sf::Vector2i originalPosition, sf::Vector2i nextPosition, int typeObject)
{
	if (typeObject == 0)
	{
		if (field.wires[originalPosition.x][originalPosition.y] == -1)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, wires[field.wires[originalPosition.x][originalPosition.y]]->energy,
			wires[field.wires[originalPosition.x][originalPosition.y]]->power);
	}
	else if (typeObject == 1)
	{
		if (field.energyStorages[originalPosition.x][originalPosition.y] == -1)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, energyStorages[field.energyStorages[originalPosition.x][originalPosition.y]]->inventory.energy,
			energyStorages[field.energyStorages[originalPosition.x][originalPosition.y]]->inventory.power);
	}
	else if (typeObject == 2)
	{
		if (field.energyHandGenerators[originalPosition.x][originalPosition.y] == -1)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, energyHandGenerators[field.energyHandGenerators[originalPosition.x][originalPosition.y]]->inventory.energy,
			energyHandGenerators[field.energyHandGenerators[originalPosition.x][originalPosition.y]]->inventory.power);
	}
	else if (typeObject == 3)
	{
		if (field.energyCoalGenerators[originalPosition.x][originalPosition.y] == -1)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, energyCoalGenerators[field.energyCoalGenerators[originalPosition.x][originalPosition.y]]->inventory.energy,
			energyCoalGenerators[field.energyCoalGenerators[originalPosition.x][originalPosition.y]]->inventory.power);
	}
	else
	{
		return;
	}
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
			// ���� �� ����������� ������
			if (field.wires[i][j] != -1)
			{
				if (wires[field.wires[i][j]]->energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(wires[field.wires[i][j]]->turn);
					typeObject = 0;
				}
			}
			// ���� �� ����������� ��������������
			if (field.energyStorages[i][j] != -1)
			{
				if (energyStorages[field.energyStorages[i][j]]->inventory.energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(energyStorages[field.energyStorages[i][j]]->turn);
					typeObject = 1;
				}
			}
			// ���� �� ����������� ������ ���������������
			if (field.energyHandGenerators[i][j] != -1)
			{
				if (energyHandGenerators[field.energyHandGenerators[i][j]]->inventory.energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(energyHandGenerators[field.energyHandGenerators[i][j]]->turn);
					typeObject = 2;
				}
			}
			// ���� �� ����������� �������� ���������������
			if (field.energyCoalGenerators[i][j] != -1)
			{
				if (energyCoalGenerators[field.energyCoalGenerators[i][j]]->inventory.energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(energyCoalGenerators[field.energyCoalGenerators[i][j]]->turn);
					typeObject = 3;
				}
			}
			if (typeObject != -1)
				CheckTypeTrans(sf::Vector2i(i, j), sf::Vector2i(i + shift.x, j + shift.y), typeObject);
		}
	}

}
// ����
void Game::Play()
{
	// ���������� ����
	DrawPlay();

	// ������ �����
	for (auto coalOven : coalOvens)
	{
		coalOven->inventory.Burn();
	}
	// ������ ������������
	for (auto electricOven : electricOvens)
	{
		electricOven->inventory.Burn();
	}
	// ������ ��������������� ����������
	for (auto energyStorage : energyStorages)
	{
		energyStorage->inventory.Next();
	}
	// ������ ��������� ���������������� ����������
	for (auto energyCoalGenerator : energyCoalGenerators)
	{
		energyCoalGenerator->inventory.Next();
	}

	WhatObjectTransEnergy();

	if (buttons.size() < 4)
	{
		// ������ �����
		buttons.push_back(Button(sf::Vector2f(1000, 608), sf::Vector2f(128, 64), L"�����",
			colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
			sf::Color(255, 255, 255), sf::Color::Transparent, sf::Vector2f(128 / 2 - 35, 12), 4, 25));
	}

	if (!player.isOpenInventory)
	{
		// ��������
		Drive();
	}
	else
	{
		switch (player.whatTypeInventoryOpen)
		{
		// ��������� ������
		case 0:
			player.inventory.DrawMiniWorkbench();
			player.inventory.Update();
			break;
		// ��������� �������� �����
		case 1:
			coalOvens[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			break;
		// ��������� ������������
		case 2:
			electricOvens[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			break;
		// ��������� �������
		case 3:
			chests[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			break;
		// �������� ��������
		case 4:
			workbenches[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			break;
		// ��������� ��������������� ���������
		case 5:
			energyStorages[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			break;
		// ��������� ������� ����������������
		case 6:
			energyHandGenerators[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			break;
		// ��������� ��������� ����������������
		case 7:
			energyCoalGenerators[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			break;
		}
		CloseInventory();
	}

	// ������ �����
	if (buttons[0].DrawCheckLeft(*rw))
	{
		screen = "��������������������";
		buttons.clear();
		return;
	}

}
// ����
void Game::Menu()
{
	if (buttons.size() < 1)
	{
		buttons.push_back(Button(sf::Vector2f(sizeW.x / 2 - 75, 300), sf::Vector2f(150, 40), L"������",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
		buttons.push_back(Button(sf::Vector2f(sizeW.x / 2 - 75, 500), sf::Vector2f(150, 40), L"�����",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
	}

	functions.DrawRectangle(sf::Vector2f(200, 100), sf::Vector2f(980, 520), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 4);
	functions.PrintText(L"Industrial", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

	if (buttons[0].DrawCheckLeft(*rw))
	{
		screen = "�����������������������";
		buttons.clear();
		return;
	}

	if (buttons[1].DrawCheckLeft(*rw) || ch[0].Check(sf::Keyboard::Escape))
	{
		rw->close();
		buttons.clear();
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
