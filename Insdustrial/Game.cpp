#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "������������������1";
	mouseWheel = 0;
}
// ����������� �������� ����������
void Game::LoadingApp1()
{
	font.loadFromFile("Font/Undertale-Font.ttf");
	functions.PrintText(L"��������...", sf::Vector2f(sizeW.x / 2 - 100, 300), 25, sf::Color::Green);
	screen = "������������������";
}
// �������� ����������
void Game::LoadingApp()
{
	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

	srand(time(NULL));

	screen = "����";
	cameraPosition = sf::Vector2f(20, 20);

	coalOvens = std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>();
	electricOvens = std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>();

	chests = std::vector<std::shared_ptr<StaingObject<ChestInventory>>>();
	workbenches = std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>();

	wires = std::vector<std::shared_ptr<Wire>>();

	//objects = std::vector<std::shared_ptr<Object>>();

	//for (int i = 0; i < ovens.size(); i++)
	//{
	//	//objects.push_back(*ovens[i]);
	//}

}
// �������� ������������� ��������
void Game::LoadingScreen(std::string nextScreen)
{
	functions.PrintText(L"��������...", sf::Vector2f(sizeW.x / 2 - 100, 300), 25, sf::Color::Green);
	screen = nextScreen;
}
// �������� ��������
void Game::LoadingPlay()
{
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
	/// ��������� ��������
	// ������
	textures["CooperWire0"] = sf::Texture();
	textures["CooperWire0"].loadFromFile("Images/Wires/CooperWire0.png");
	textures["CooperWire1"] = sf::Texture();
	textures["CooperWire1"].loadFromFile("Images/Wires/CooperWire1.png");
	textures["CooperWire2"] = sf::Texture();
	textures["CooperWire2"].loadFromFile("Images/Wires/CooperWire2.png");
	textures["CooperWire3"] = sf::Texture();
	textures["CooperWire3"].loadFromFile("Images/Wires/CooperWire3.png");
	textures["CooperWire4"] = sf::Texture();
	textures["CooperWire4"].loadFromFile("Images/Wires/CooperWire4.png");

	textures["CooperWire"] = sf::Texture();
	textures["CooperWire"].loadFromFile("Images/Wires/CooperWire.png");

	field = Field(rw, sf::Vector2i(200, 200), 48, sizeW, textures["Grass"]);
	player = Player(rw, field.sizeOne, "Images/Human.png", sf::Vector2f(20, 20));

	coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(rw, field.sizeOne, textures["Oven"], sf::Vector2f(23, 20)));
	electricOvens.push_back(std::make_shared<StaingObject<ElectricOvenInventory>>(rw, field.sizeOne, textures["ElectricOven"], sf::Vector2f(23, 19)));
	chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, textures["Chest"], sf::Vector2f(23, 21)));
	workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, textures["Workbench"], sf::Vector2f(23, 22)));

	wires.push_back(std::make_shared<Wire>(rw, field.sizeOne, textures["CooperWire"], sf::Vector2f(15, 15)));

	screen = "����";
}
// �������� ��������
void Game::UnloadingPlay(std::string nextScreen)
{
	textures.clear();

	coalOvens.clear();
	electricOvens.clear();
	chests.clear();
	workbenches.clear();
	wires.clear();

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
		}
		player.buttons.clear();
	}
}
// ��������� ������ �� ������������ �����������
void Game::PutObject(sf::Vector2f position)
{
	// ��������� �����
	if (player.inventory.cells[player.inventory.choseCell][3].item.number == 2)
	{
		coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(rw, field.sizeOne, textures["Oven"], position));
		//objects.push_back(ovens[ovens.size() - 1]);
	}
	// ��������� �������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 11)
	{
		electricOvens.push_back(std::make_shared<StaingObject<ElectricOvenInventory>>(rw, field.sizeOne, textures["ElectricOven"], position));
		//objects.push_back(chests[ovens.size() - 1]);
	}
	// ��������� ������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 5)
	{
		chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, textures["Chest"], position));
		//objects.push_back(chests[ovens.size() - 1]);
	}
	// ��������� �������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 8)
	{
		workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, textures["Workbench"], position));
		//objects.push_back(chests[ovens.size() - 1]);
	}
	// ��������� ������ ������
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 12)
	{
		//wires.push_back(std::make_shared<Wire>(
		//	rw, field.sizeOne,
		//	textures["CooperWire0"], textures["CooperWire1"], textures["CooperWire2"], textures["CooperWire3"], textures["CooperWire4"],
		//	position));
		wires.push_back(std::make_shared<Wire>(rw, field.sizeOne, textures["CooperWire"], position));
		//objects.push_back(chests[ovens.size() - 1]);
	}
}

void Game::TransEnergy(sf::Vector2i originalPosition, sf::Vector2i nextPosition)
{
	if (field.wires[nextPosition.x][nextPosition.y] != -1)
	{
		wires[field.wires[nextPosition.x][nextPosition.y]]->energy = 1;
		wires[field.wires[originalPosition.x][originalPosition.y]]->energy = 0;
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
	bool nearObject = player.PutObject(coalOvens, electricOvens, chests, workbenches, wires);
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
		electricOvens[i]->Update(player.position, player.angle);
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
	// ������ ��������
	
	wires[0]->energy = 1;
	// ������ ��������
	for (int i = 0; i < field.wires.size(); i++)
	{
		for (int j = 0; j < field.wires[i].size(); j++)
		{
			if (field.wires[i][j] == -1)
			{
				continue;
			}
			if (wires[field.wires[i][j]]->energy == 0)
			{
				continue;
			}
			switch (wires[field.wires[i][j]]->turn)
			{
			case 0:
				TransEnergy(sf::Vector2i(i, j), sf::Vector2i(i, j - 1));
				break;
			case 1:
				TransEnergy(sf::Vector2i(i, j), sf::Vector2i(i + 1, j));
				break;
			case 2:
				TransEnergy(sf::Vector2i(i, j), sf::Vector2i(i, j + 1));
			case 3:
				TransEnergy(sf::Vector2i(i, j), sf::Vector2i(i - 1, j));
			}
		}
		
	}
	// ������ ��������
	for (int i = 0; i < wires.size(); i++)
	{
		field.wires[wires[i]->position.x][wires[i]->position.y] = i;
		wires[i]->Update(player.position, player.angle);
	}

	cameraPosition = sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2));
}
// ����
void Game::Play()
{
	// ���������� ����
	DrawPlay();

	// ������ �����
	for (int i = 0; i < coalOvens.size(); i++)
	{
		coalOvens[i]->inventory.Burn();
		//ovens[i]->inventory.fuel += 1;
	}

	// ������ ������������
	for (int i = 0; i < electricOvens.size(); i++)
	{
		electricOvens[i]->inventory.Burn();
		//ovens[i]->inventory.fuel += 1;
	}

	if (buttons.size() < 4)
	{
		// ������ �����
		buttons.push_back(Button(sf::Vector2f(1000, 600), sf::Vector2f(90, 60), L"�����",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 25));
	}

	if (!player.isOpenInventory)
	{
		// ��������
		Drive();
	}
	else
	{
		// ��������� ������
		if (player.whatTypeInventoryOpen == 0)
		{
			player.inventory.DrawMiniWorkbench();
			player.inventory.Update();
			if (ch[2].Check(sf::Keyboard::Key::Escape) || ch[3].Check(sf::Keyboard::Key::E))
			{
				player.isOpenInventory = false;
				coalOvens[player.whatNumberInventoryOpen]->isOpenInventory = false;
				chests[player.whatNumberInventoryOpen]->isOpenInventory = false;
				workbenches[player.whatNumberInventoryOpen]->isOpenInventory = false;
			}
		}
		// ��������� �����
		else if (player.whatTypeInventoryOpen == 1)
		{
			coalOvens[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			CloseInventory();
		}
		else if (player.whatTypeInventoryOpen == 2)
		{
			electricOvens[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			CloseInventory();
		}
		// ��������� �������
		else if (player.whatTypeInventoryOpen == 3)
		{
			chests[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			CloseInventory();
		}
		// ��������� ��������
		else if (player.whatTypeInventoryOpen == 4)
		{
			workbenches[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			CloseInventory();
		}
	}

	// ������ �����
	buttons[0].Draw(*rw);
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
	else if (screen == "������������������1")
	{
		LoadingApp1();
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
