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
	electricOvens = std::vector<std::shared_ptr<EnergyObject<ElectricOvenInventory>>>();
	compressors = std::vector<std::shared_ptr<EnergyObject<CompressorInventory>>>();

	chests = std::vector<std::shared_ptr<StaingObject<ChestInventory>>>();
	workbenches = std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>();

	energyHandGenerators = std::vector<std::shared_ptr<EnergyObject<EnergyHandGeneratorInventory>>>();
	energyCoalGenerators = std::vector<std::shared_ptr<EnergyObject<EnergyCoalGeneratorInventory>>>();

	objects = std::vector<Sprite*>();

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
	// �������� ������ ����������
	LoadColorInventoryFromFile();

	LoadingImagesPlay();

	field = Field(rw, sf::Vector2i(200, 200), 48, sizeW, textures["Grass"]);
	player = Player(rw, cameraPosition, field.sizeOne, textures["Player"], sf::Vector2f(20, 20), colorsInventory, itemTextures);

	objects.push_back(&player);

	coalOvens.push_back(
		std::make_shared<StaingObject<CoalOvenInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Oven"], itemTextures, sf::Vector2f(23, 20), colorsInventory));
	electricOvens.push_back(
		std::make_shared<EnergyObject<ElectricOvenInventory>>(
			rw, cameraPosition, field.sizeOne, textures["ElectricOven"], itemTextures, sf::Vector2f(23, 19), colorsInventory));
	crushers.push_back(
		std::make_shared<EnergyObject<CrusherInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Crusher"], itemTextures, sf::Vector2f(19, 17), colorsInventory, 1000));
	compressors.push_back(
		std::make_shared<EnergyObject<CompressorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Compressor"], itemTextures, sf::Vector2f(19, 16), colorsInventory, 1000));
	chests.push_back(
		std::make_shared<StaingObject<ChestInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Chest"], itemTextures, sf::Vector2f(23, 21), colorsInventory));
	workbenches.push_back(
		std::make_shared<StaingObject<WorkbenchInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Workbench"], itemTextures, sf::Vector2f(23, 22), colorsInventory));
	energyStorages.push_back(
		std::make_shared<EnergyObject<EnergyStorageInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyStorage"], itemTextures, sf::Vector2f(22, 20), colorsInventory, 10000, 10));
	energyHandGenerators.push_back(
		std::make_shared<EnergyObject<EnergyHandGeneratorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, sf::Vector2f(22, 19), colorsInventory, 100, 10, texturesInInventory));
	energyCoalGenerators.push_back(
		std::make_shared<EnergyObject<EnergyCoalGeneratorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyCoalGenerator"], itemTextures, sf::Vector2f(20, 19), colorsInventory, 100, 10));

	objects.push_back(coalOvens[coalOvens.size() - 1].get());
	objects.push_back(coalOvens[coalOvens.size() - 1].get());
	objects.push_back(electricOvens[electricOvens.size() - 1].get());
	objects.push_back(crushers[crushers.size() - 1].get());
	objects.push_back(compressors[compressors.size() - 1].get());
	objects.push_back(chests[chests.size() - 1].get());
	objects.push_back(workbenches[workbenches.size() - 1].get());
	objects.push_back(energyStorages[energyStorages.size() - 1].get());
	objects.push_back(energyHandGenerators[energyHandGenerators.size() - 1].get());
	objects.push_back(energyCoalGenerators[energyCoalGenerators.size() - 1].get());

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
	// ��������� ��������
	for (int i = objects.size() - 1; i >= 0; i--)
	{
		//objects[i]->Draw();
		rw->draw(*objects[i]);
	}
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
		case 8:
			crushers[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 9:
			compressors[player.whatNumberInventoryOpen]->isOpenInventory = false;
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
		coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Oven"], itemTextures, position, colorsInventory));
		objects.push_back(coalOvens[coalOvens.size() - 1].get());
		break;
	// ������������
	case 11:
		electricOvens.push_back(std::make_shared<EnergyObject<ElectricOvenInventory>>(
			rw, cameraPosition, field.sizeOne, textures["ElectricOven"], itemTextures, position, colorsInventory));
		objects.push_back(electricOvens[electricOvens.size() - 1].get());
		objects.push_back(electricOvens[electricOvens.size() - 1].get());
		break;
	// ���������
	case 24:
		crushers.push_back(std::make_shared<EnergyObject<CrusherInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Crusher"], itemTextures, position, colorsInventory, 1000));
		objects.push_back(crushers[crushers.size() - 1].get());
		objects.push_back(crushers[crushers.size() - 1].get());
		break;
	// ����������
	case 28:
		compressors.push_back(std::make_shared<EnergyObject<CompressorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Compressor"], itemTextures, position, colorsInventory, 1000));
		objects.push_back(compressors[compressors.size() - 1].get());
		objects.push_back(compressors[compressors.size() - 1].get());
		break;
	// ������
	case 5:
		chests.push_back(std::make_shared<StaingObject<ChestInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Chest"], itemTextures, position, colorsInventory));
		objects.push_back(chests[chests.size() - 1].get());
		break;
	// �������
	case 8:
		workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Workbench"], itemTextures, position, colorsInventory));
		objects.push_back(workbenches[workbenches.size() - 1].get());
		break;
	// ���������������
	case 13:
		energyStorages.push_back(std::make_shared<EnergyObject<EnergyStorageInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyStorage"], itemTextures, position, colorsInventory, 1000, 10));
		objects.push_back(energyStorages[energyStorages.size() - 1].get());
		objects.push_back(energyStorages[energyStorages.size() - 1].get());
		break;
	// ������ ���������������
	case 16:
		energyHandGenerators.push_back(std::make_shared<EnergyObject<EnergyHandGeneratorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, position, colorsInventory, 100, 10));
		objects.push_back(energyHandGenerators[energyHandGenerators.size() - 1].get());
		objects.push_back(energyHandGenerators[energyHandGenerators.size() - 1].get());
		break;
	// �������� ���������������
	case 17:
		energyCoalGenerators.push_back(std::make_shared<EnergyObject<EnergyCoalGeneratorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyCoalGenerator"], itemTextures, position, colorsInventory, 100, 10));
		objects.push_back(energyCoalGenerators[energyCoalGenerators.size() - 1].get());
		objects.push_back(energyCoalGenerators[energyCoalGenerators.size() - 1].get());
		break;
	// ������ ������
	case 12:
		wires.push_back(std::make_shared<Wire>(
			rw, cameraPosition, field.sizeOne, textures["CopperWireOn"], textures["CopperWireOff"], position, 0));
		objects.push_back(wires[wires.size() - 1].get());
		break;
	// �������� ������
	case 15:
		wires.push_back(std::make_shared<Wire>(
			rw, cameraPosition, field.sizeOne, textures["IronWireOn"], textures["IronWireOff"], position, 1));
		objects.push_back(wires[wires.size() - 1].get());
		break;
	// �������� ������
	case 20:
		wires.push_back(std::make_shared<Wire>(
			rw, cameraPosition, field.sizeOne, textures["TinWireOn"], textures["TinWireOff"], position, 2));
		objects.push_back(wires[wires.size() - 1].get());
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
	/*if (player.PutObject(mousePositionGrid,
		coalOvens, electricOvens, crushers, compressors, chests,
		workbenches, wires, energyStorages, energyHandGenerators, energyCoalGenerators))*/
	if (field.PutObject(mousePositionGrid, objects, player.inventory.cells[player.inventory.choseCell][3].item))
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
		field.energyObjectsNumbers[electricOvens[i]->position.x][electricOvens[i]->position.y] = sf::Vector2i(1, i);
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
	// ������ ����������
	for (int i = 0; i < crushers.size(); i++)
	{
		// ���������� ������� � ��������� ������ ������������ � ������� �� �����������
		field.energyObjectsNumbers[crushers[i]->position.x][crushers[i]->position.y] = sf::Vector2i(5, i);
		// ���������� ������������
		crushers[i]->Update(mousePositionGrid, player.position, player.angle);
		// ���� ��������� ������
		if (crushers[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 8;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// ������ ������������
	for (int i = 0; i < compressors.size(); i++)
	{
		// ���������� ������� � ��������� ������ ������������ � ������� �� �����������
		field.energyObjectsNumbers[compressors[i]->position.x][compressors[i]->position.y] = sf::Vector2i(6, i);
		// ���������� ������������
		compressors[i]->Update(mousePositionGrid, player.position, player.angle);
		// ���� ��������� ������
		if (compressors[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 9;
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
		field.energyObjectsNumbers[energyStorages[i]->position.x][energyStorages[i]->position.y] = sf::Vector2i(2, i);
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
		field.energyObjectsNumbers[energyHandGenerators[i]->position.x][energyHandGenerators[i]->position.y] = sf::Vector2i(3, i);
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
		field.energyObjectsNumbers[energyCoalGenerators[i]->position.x][energyCoalGenerators[i]->position.y] = sf::Vector2i(4, i);
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
		//field.wires[wires[i]->position.x][wires[i]->position.y] = i;
		field.energyObjectsNumbers[wires[i]->position.x][wires[i]->position.y] = sf::Vector2i(0, i);
		wires[i]->Update(mousePositionGrid, player.position, player.angle);
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
	// ���� �� ����� ����� ������
	if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 0)
	{
		std::shared_ptr<Wire> thisWire = wires[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y];
		TransEnergy(energy, power, thisWire->energy, thisWire->maxEnergy);
	}
	// ���� �� ����� ����� ������������
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 1)
	{
		thisObjectInventory = electricOvens[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// ���� �� ����� ����� ���������
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 5)
	{
		thisObjectInventory = crushers[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// ���� �� ����� ����� ����������
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 6)
	{
		thisObjectInventory = compressors[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// ���� �� ����� ����� ���������������
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 2)
	{
		thisObjectInventory = energyStorages[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// ���� �� ����� ����� ���������������
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 2)
	{
		thisObjectInventory = energyStorages[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
}

void Game::CheckTypeTrans(sf::Vector2i originalPosition, sf::Vector2i nextPosition, int typeObject)
{
	if (typeObject == 0)
	{
		if (field.energyObjectsNumbers[originalPosition.x][originalPosition.y].x == -1)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, wires[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->energy,
			wires[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->power);
	}
	else if (typeObject == 1)
	{
		if (field.energyObjectsNumbers[originalPosition.x][originalPosition.y].x == 0)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, energyStorages[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->inventory->energy,
			energyStorages[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->typeInventory.power);
	}
	else if (typeObject == 2)
	{
		if (field.energyObjectsNumbers[originalPosition.x][originalPosition.y].x == -1)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, energyHandGenerators[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->inventory->energy,
			energyHandGenerators[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->typeInventory.power);
	}
	else if (typeObject == 3)
	{
		if (field.energyObjectsNumbers[originalPosition.x][originalPosition.y].x == -1)
		{
			return;
		}
		CheckNextEnergyObject(nextPosition, energyCoalGenerators[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->inventory->energy,
			energyCoalGenerators[field.energyObjectsNumbers[originalPosition.x][originalPosition.y].y]->typeInventory.power);
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
			switch (field.energyObjectsNumbers[i][j].x)
			{
			// ���� �� ����������� ������
			case 0:
				if (wires[field.energyObjectsNumbers[i][j].y]->energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(wires[field.energyObjectsNumbers[i][j].y]->turn);
					typeObject = 0;
				}
				break;
			// ���� �� ����������� ���������������
			case 2:
				if (energyStorages[field.energyObjectsNumbers[i][j].y]->inventory->energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(energyStorages[field.energyObjectsNumbers[i][j].y]->turn);
					typeObject = 1;
				}
				break;
			// ���� �� ����������� ������ ���������������
			case 3:
				if (energyHandGenerators[field.energyObjectsNumbers[i][j].y]->inventory->energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(energyHandGenerators[field.energyObjectsNumbers[i][j].y]->turn);
					typeObject = 2;
				}
				break;
			// ���� �� ����������� �������� ���������������
			case 4:
				if (energyCoalGenerators[field.energyObjectsNumbers[i][j].y]->inventory->energy != 0)
				{
					// ����� ������������ ������� (���� �� ��������)
					shift = CheckTurnEnergy(energyCoalGenerators[field.energyObjectsNumbers[i][j].y]->turn);
					typeObject = 3;
				}
				break;
			}
			if (typeObject != -1)
				CheckTypeTrans(sf::Vector2i(i, j), sf::Vector2i(i + shift.x, j + shift.y), typeObject);
		}
	}

}

void Game::WhatInventory()
{
	switch(player.whatTypeInventoryOpen)
	{
		// ��������� ������
	case 0:
		player.inventory.DrawMiniWorkbench();
		player.inventory.Update();
		break;
		// ��������� �������� �����
	case 1:
		coalOvens[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// ��������� ������������
	case 2:
		electricOvens[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// ��������� �������
	case 3:
		chests[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// �������� ��������
	case 4:
		workbenches[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// ��������� ��������������� ���������
	case 5:
		energyStorages[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// ��������� ������� ����������������
	case 6:
		energyHandGenerators[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// ��������� ��������� ����������������
	case 7:
		energyCoalGenerators[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// ��������� ���������
	case 8:
		crushers[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// ��������� ������������
	case 9:
		compressors[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
	}
	CloseInventory();
}
// ����
void Game::Play()
{
	if (buttons.size() < 4)
	{
		// ������ �����
		buttons.push_back(Button(sf::Vector2f(1000, 608), sf::Vector2f(128, 64), L"�����",
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
