#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "�����������������������";
	coalOvens = std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>();
	electricOvens = std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>();

	chests = std::vector<std::shared_ptr<StaingObject<ChestInventory>>>();
	workbenches = std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>();

	energyHandGenerators = std::vector<std::shared_ptr<EnergySprite<EnergyHandGeneratorInventory>>>();

	wires = std::vector<std::shared_ptr<Wire>>();
	font.loadFromFile("Font/Undertale-Font.ttf");
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
	/// ��������� ��������
	// ������
	textures["CooperWire"] = sf::Texture();
	textures["CooperWire"].loadFromFile("Images/Wires/CooperWireOn.png");
	// ��������
	textures["IronWire"] = sf::Texture();
	textures["IronWire"].loadFromFile("Images/Wires/IronWireOn.png");

	// �������� ���������
	for (int i = 0; i < 16; i++)
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


	field = Field(rw, sf::Vector2i(200, 200), 48, sizeW, textures["Grass"]);
	player = Player(rw, field.sizeOne, "Images/Human.png", sf::Vector2f(20, 20), colorsInventory, itemTextures);

	coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(rw, field.sizeOne, textures["Oven"], itemTextures, sf::Vector2f(23, 20), colorsInventory));
	electricOvens.push_back(std::make_shared<StaingObject<ElectricOvenInventory>>(rw, field.sizeOne, textures["ElectricOven"], itemTextures, sf::Vector2f(23, 19), colorsInventory));
	chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, textures["Chest"], itemTextures, sf::Vector2f(23, 21), colorsInventory));
	workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, textures["Workbench"], itemTextures, sf::Vector2f(23, 22), colorsInventory));
	energyStorages.push_back(std::make_shared<EnergySprite<EnergyStorageInventory>>(rw, field.sizeOne, textures["EnergyStorage"], itemTextures, sf::Vector2f(22, 20), colorsInventory, 10000, 10));
	energyHandGenerators.push_back(std::make_shared<EnergySprite<EnergyHandGeneratorInventory>>(rw, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, sf::Vector2f(22, 19), colorsInventory, 100, 10));

	screen = "����";
}

void Game::UnloadingPlay(std::string nextScreen)
{
	textures.clear();
	itemTextures.clear();

	coalOvens.clear();
	electricOvens.clear();
	chests.clear();
	workbenches.clear();
	wires.clear();
	energyStorages.clear();

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
	// ��������� ������ �����������
	for (std::shared_ptr<StaingObject<EnergyHandGeneratorInventory>> energyHandGenerator : energyHandGenerators)
	{
		energyHandGenerator->Draw(cameraPosition);
	}
	// ��������� ��������
	for (std::shared_ptr<Wire> wire : wires)
	{
		wire->Draw(cameraPosition);
	}
	// ��������� ������
	player.Draw(cameraPosition);
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
		}
		player.inventory.DeleteButtons();
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
		energyStorages.push_back(std::make_shared<EnergySprite<EnergyStorageInventory>>(rw, field.sizeOne, textures["EnergyStorage"], itemTextures, position, colorsInventory, 1000, 10));
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
	// ��, ��� ������ ����� ������ ����
	player.Update();
	// ��������� �����
	player.inventory.DrawNear(mouseWheel);
	// ��������� ������ �� �����
	bool nearObject = player.PutObject(coalOvens, electricOvens, chests, workbenches, wires, energyStorages);
	if (nearObject)
	{
		switch (player.angle)
		{
		case 0:
			PutObject(sf::Vector2f((int)player.position.x, (int)player.position.y - 1));
			break;
		case 1:
			PutObject(sf::Vector2f((int)player.position.x + 1, (int)player.position.y));
			break;
		case 2:
			PutObject(sf::Vector2f((int)player.position.x, (int)player.position.y + 1));
			break;
		case 3:
			PutObject(sf::Vector2f((int)player.position.x - 1, (int)player.position.y));
			break;
		}
	}
	// ������ �������� �����
	for (int i = 0; i < coalOvens.size(); i++)
	{
		coalOvens[i]->Update(player.position, player.angle);
		if (coalOvens[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
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
		electricOvens[i]->Update(player.position, player.angle);
		// ���� ��������� ������
		if (electricOvens[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 2;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ��������
	for (int i = 0; i < chests.size(); i++)
	{
		chests[i]->Update(player.position, player.angle);
		if (chests[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 3;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ���������
	for (int i = 0; i < workbenches.size(); i++)
	{
		workbenches[i]->Update(player.position, player.angle);
		if (workbenches[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
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
		energyStorages[i]->Update(player.position, player.angle);
		if (energyStorages[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 5;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ �������� �������
	for (int i = 0; i < energyHandGenerators.size(); i++)
	{
		// ���������� ������� � ��������� ������ �������� � ������� �� �����������
		field.energyHandGenerators[energyHandGenerators[i]->position.x][energyHandGenerators[i]->position.y] = i;
		energyHandGenerators[i]->Update(player.position, player.angle);
		if (energyHandGenerators[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 6;
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
	cameraPosition -= (cameraPosition - sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2))) * 0.04f;
}

void Game::TransEnergy(int& originalEnergy, int power, int& nextEnergy, int nextMaxEnergy)
{
	if (originalEnergy - power < 0)
	{
		if (nextEnergy + power > nextMaxEnergy)
			nextEnergy = nextMaxEnergy;
		else
			nextEnergy += power;
		originalEnergy = 0;
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

void Game::CheckNextEnergyObject(sf::Vector2i nextPosition, int& energy, int power)
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
			if (typeObject != -1)
				CheckTypeTrans(sf::Vector2i(i, j), sf::Vector2i(i + shift.x, j + shift.y), typeObject);
		}
	}

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
		// ��������� ������� ����������
		case 6:
			energyHandGenerators[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
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
	functions.PrintText(L"Few Colors", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

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
