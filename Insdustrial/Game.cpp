#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "�����������������������";
	for (size_t i = 0; i < 20; i++)
	{
		lastFpsS.push_back(0);
	}
}
// �������� ����������
void Game::LoadingApp()
{
	playUpdatables = std::vector<IPlayUpdatable*>();

	assets = Assets();

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

void Game::LoadingForPlay()
{
	player.LoadingForPlay();
	field.LoadingForPlay(colorsInventory);
}

void Game::LoadingForDev()
{
	player.LoadingForDev();
	field.LoadingForDev(colorsInventory);
}
// �������� ��������
void Game::LoadingPlay()
{
	oldButtons.clear();
	drawables.clear();
	// �������� ������ ����������
	LoadColorInventoryFromFile();

	assets.LoadingPlay();

	field = Field(rw, cameraPosition, sf::Vector2i(200, 200), 48, sizeW, assets.textures["Grass"], assets, player);
	drawables.push_back(&field);
	player = Player(rw, cameraPosition, field.sizeOne, assets.textures["Player"], sf::Vector2f(20, 20), colorsInventory, assets.itemTextures);

#if defined(_DEBUG)
	LoadingForDev();
#else
	LoadingForPlay();
#endif;

	field.LoadingPlay();

	playUpdatables.push_back(&field);

	for (size_t i = 0; i < field.objects.size(); i++)
	{
		drawables.push_back(field.objects[i]);
	}

	screen = "����";
}

void Game::UnloadingPlay(std::string nextScreen)
{
	assets.UnloadingPlay();

	drawables.clear();
	oldButtons.clear();
	field.objects.clear();

	field.UnloadingPlay();

	screen = nextScreen;
}
// ��������� ����
void Game::DrawPlay()
{
	// ����� �����
	functions.DrawRectangle(sf::Vector2f(0, 0), sf::Vector2f(sizeW.x, sizeW.y), sf::Color(255, 255, 255));
	// ��������� ����
	AllDraw();
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

		switch (player.whatTypeInventoryOpen)
		{
		case 1:
			field.energyObjects[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 2:
			field.simpleObjects[player.whatNumberInventoryOpen]->isOpenInventory = false;
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
		field.simpleObjects.push_back(new StaingObject<CoalOvenInventory >(
			rw, cameraPosition, field.sizeOne, assets.textures["Oven"], assets.itemTextures, position, colorsInventory));
		field.objects.push_back(field.simpleObjects[field.simpleObjects.size() - 1]);
		break;
	// ������������
	case 11:
		field.energyObjects.push_back(new EnergyObject<ElectricOvenInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["ElectricOven"], assets.itemTextures, position, colorsInventory));
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	// ���������
	case 24:
		field.energyObjects.push_back(new EnergyObject<CrusherInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["Crusher"], assets.itemTextures, position, colorsInventory, 1000));
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	// ����������
	case 28:
		field.energyObjects.push_back(new EnergyObject<CompressorInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["Compressor"], assets.itemTextures, position, colorsInventory, 1000));
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
		// ����������
	case 32:
		field.energyObjects.push_back(new EnergyObject<MineInventory >(
			rw, cameraPosition, field.sizeOne, assets.textures["Mine"], assets.itemTextures, position, colorsInventory));
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	// ������
	case 5:
		field.simpleObjects.push_back(new StaingObject<ChestInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["Chest"], assets.itemTextures, position, colorsInventory));
		field.objects.push_back(field.simpleObjects[field.simpleObjects.size() - 1]);
		break;
	// �������
	case 8:
		field.simpleObjects.push_back(new StaingObject<WorkbenchInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["Workbench"], assets.itemTextures, position, colorsInventory));
		field.objects.push_back(field.simpleObjects[field.simpleObjects.size() - 1]);
		break;
	// ���������������
	case 13:
		field.energyObjects.push_back(new EnergyObject<EnergyStorageInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["EnergyStorage"], assets.itemTextures, position, colorsInventory, 1000, 10));
		field.transEnergyObjects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	// ������ ���������������
	case 16:
		field.energyObjects.push_back(new EnergyObject<EnergyHandGeneratorInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["EnergyHandGenerator"],
			assets.itemTextures, position, colorsInventory, 100, 10, assets.texturesInInventory));
		field.transEnergyObjects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	// �������� ���������������
	case 17:
		field.energyObjects.push_back(new EnergyObject<EnergyCoalGeneratorInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["EnergyCoalGenerator"], assets.itemTextures, position, colorsInventory, 100, 10));
		field.transEnergyObjects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
	// ������ ������
	case 12:
		field.energyObjects.push_back(new EnergyObject<WireInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["CopperWireOn"], assets.itemTextures, position, colorsInventory, 10, 10));
		field.transEnergyObjects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	// �������� ������
	case 15:
		field.energyObjects.push_back(new EnergyObject<WireInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["IronWireOn"], assets.itemTextures, position, colorsInventory, 100, 100));
		field.transEnergyObjects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	// �������� ������
	case 20:
		field.energyObjects.push_back(new EnergyObject<WireInventory > (
			rw, cameraPosition, field.sizeOne, assets.textures["TinWireOn"], assets.itemTextures, position, colorsInventory, 1000, 1000));
		field.transEnergyObjects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		field.objects.push_back(field.energyObjects[field.energyObjects.size() - 1]);
		break;
	}

	drawables.push_back(field.objects[field.objects.size() - 1]);
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
	player.GamePlayUpdate();
	// ��������� �����
	player.inventory.DrawNear(mouseWheel);
	// ��������� ������ �� �����
	if (field.ObjectHere(mousePositionGrid, player.inventory.cells[player.inventory.choseCell][3].item))
	{
		PutObject((sf::Vector2f)mousePositionGrid);
	}

	for (size_t i = 0; i < field.objects.size(); i++)
	{
		field.objects[i]->Update(mousePositionGrid, player.position, player.angle);
	}

	field.GamePlayUpdate();

	// �������� ������
	//cameraPosition -= (cameraPosition - sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2))) * 0.04f;
	cameraPosition = sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2));
}

void Game::WhatInventory()
{
	switch (player.whatTypeInventoryOpen)
	{
	case 0:
		player.inventory.DrawMiniWorkbench();
		player.inventory.WhileOpen();
		break;
	case 1:
		field.energyObjects[player.whatNumberInventoryOpen]->inventory->WhileOpen(player.inventory);
		break;
	case 2:
		field.simpleObjects[player.whatNumberInventoryOpen]->inventory->WhileOpen(player.inventory);
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

	//field.PlayUpdate();

	for (size_t i = 0; i < playUpdatables.size(); i++)
	{
		playUpdatables[i]->PlayUpdate();
	}

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
	}

	functions.DrawRectangle(sf::Vector2f(200, 100), sf::Vector2f(980, 520), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 4);
	functions.PrintText(L"Industrial", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

	AllDraw();

	if (oldButtons[0].DrawCheckLeft(*rw))
	{
		screen = "�����������������������";
		oldButtons.clear();
		return;
	}


	if (oldButtons[1].DrawCheckLeft(*rw) || ch[0].Check(sf::Keyboard::Escape))
	{
		rw->close();
		oldButtons.clear();
		return;
	}

}

void Game::AllDraw()
{
	for (int i = 0; i < drawables.size(); i++)
	{
		rw->draw(*drawables[i]);
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
	mouseWheel = 0;

	// ��������� � �������� FPS
	fps = clock.getElapsedTime();
	lastFpsS[whatNumberFps] = 1 / fps.asSeconds();
	whatNumberFps += 1;
	if (whatNumberFps >= lastFpsS.size() - 1)
	{
		avarageFps = 0;
		for (size_t i = 0; i < lastFpsS.size(); i++)
		{
			avarageFps += lastFpsS[i] / (float)lastFpsS.size();
		}
		whatNumberFps = 0;
	}
	functions.PrintText(std::to_string((int)(1 / fps.asSeconds())), sf::Vector2f(sizeW.x - 15, 10), 25, sf::Color::Red, 0);
	functions.PrintText(std::to_string((int)(avarageFps)), sf::Vector2f(sizeW.x - 15, 80), 25, sf::Color::Red, 0);
	clock.restart();
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
