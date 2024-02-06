#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "ЗагрузкаПриложения1";
	mouseWheel = 0;
}
// Отображение загрузки приложения
void Game::LoadingApp1()
{
	font.loadFromFile("Font/Undertale-Font.ttf");
	functions.PrintText(L"Загрузка...", sf::Vector2f(sizeW.x / 2 - 100, 300), 25, sf::Color::Green);
	screen = "ЗагрузкаПриложения";
}
// Загрузка приложения
void Game::LoadingApp()
{
	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

	srand(time(NULL));

	screen = "Меню";
	cameraPosition = sf::Vector2f(20, 20);

	coalOvens = std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>();
	electricOvens = std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>();

	chests = std::vector<std::shared_ptr<StaingObject<ChestInventory>>>();
	workbenches = std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>();

	wires = std::vector<std::shared_ptr<Wire>>();

}
// Загрузка прогрессбарра геймплея
void Game::LoadingScreen(std::string nextScreen)
{
	functions.PrintText(L"Загрузка...", sf::Vector2f(sizeW.x / 2 - 100, 300), 25, sf::Color::Green);
	screen = nextScreen;
}
// Загрузка настроек цвета интерфейса из файла
void Game::LoadColorInventoryFromFile()
{
	colorsInventory.clear();
	// Файл с цветами
	std::fstream colorFile("Files/ColorInventory.txt");
	// Построчное чтение
	std::string line;
	std::string line2;
	line2 = "";
	while (std::getline(colorFile, line))
	{
		sf::Color color = sf::Color(0, 0, 0);
		// Красный
		line2.push_back(line[0]);
		line2.push_back(line[1]);
		line2.push_back(line[2]);
		color.r = std::stoi(line2);
		line2.clear();
		// Зеленый
		line2.push_back(line[4]);
		line2.push_back(line[5]);
		line2.push_back(line[6]);
		color.g = std::stoi(line2);
		line2.clear();
		// Синий
		line2.push_back(line[8]);
		line2.push_back(line[9]);
		line2.push_back(line[10]);
		color.b = std::stoi(line2);
		colorsInventory.push_back(color);
		//std::cout << line2 << std::endl;
		line2.clear();
	}
}
// Загрузка геймплея
void Game::LoadingPlay()
{
	LoadColorInventoryFromFile();
	/// Текстуры:
	// Печка
	textures["Oven"] = sf::Texture();
	textures["Oven"].loadFromFile("Images/Objects/Oven.png");
	// Электропечка
	textures["ElectricOven"] = sf::Texture();
	textures["ElectricOven"].loadFromFile("Images/Objects/ElectricOven.png");
	// Сундук
	textures["Chest"] = sf::Texture();
	textures["Chest"].loadFromFile("Images/Objects/Chest.png");
	// Верстак
	textures["Workbench"] = sf::Texture();
	textures["Workbench"].loadFromFile("Images/Objects/Workbench.png");
	// Трава
	textures["Grass"] = sf::Texture();
	textures["Grass"].loadFromFile("Images/Grass.png");
	// Хранилище энергии
	textures["EnergyStorage"] = sf::Texture();
	textures["EnergyStorage"].loadFromFile("Images/EnergyStorage.png");
	/// Текстурки проводов
	// Медные
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
	player = Player(rw, field.sizeOne, "Images/Human.png", sf::Vector2f(20, 20), colorsInventory);

	coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(rw, field.sizeOne, textures["Oven"], sf::Vector2f(23, 20), colorsInventory));
	electricOvens.push_back(std::make_shared<StaingObject<ElectricOvenInventory>>(rw, field.sizeOne, textures["ElectricOven"], sf::Vector2f(23, 19), colorsInventory));
	chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, textures["Chest"], sf::Vector2f(23, 21), colorsInventory));
	workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, textures["Workbench"], sf::Vector2f(23, 22), colorsInventory));
	energyStorages.push_back(std::make_shared<EnergyStorageSprite>(rw, field.sizeOne, textures["EnergyStorage"], sf::Vector2f(22, 20), colorsInventory, 0));

	wires.push_back(std::make_shared<Wire>(rw, field.sizeOne, textures["CooperWire"], sf::Vector2f(20, 15)));

	screen = "Игра";
}

void Game::UnloadingPlay(std::string nextScreen)
{
	textures.clear();

	coalOvens.clear();
	electricOvens.clear();
	chests.clear();
	workbenches.clear();
	wires.clear();
	energyStorages.clear();

	screen = nextScreen;
}
// Отрисовка игры
void Game::DrawPlay()
{
	// Белый экран
	functions.DrawRectangle(sf::Vector2f(0, 0), sf::Vector2f(sizeW.x, sizeW.y), sf::Color(255, 255, 255));
	// Отрисовка поля
	field.Draw(cameraPosition);
	// Отрисовка угольных печей
	for (std::shared_ptr<StaingObject<CoalOvenInventory>> oven : coalOvens)
	{
		oven->Draw(cameraPosition);
	}
	// Отрисовка электрических печей
	for (std::shared_ptr<StaingObject<ElectricOvenInventory>> oven : electricOvens)
	{
		oven->Draw(cameraPosition);
	}
	// Отрисовка сундуков
	for (std::shared_ptr<StaingObject<ChestInventory>> chest : chests)
	{
		chest->Draw(cameraPosition);
	}
	// Отрисовка верстаков
	for (std::shared_ptr<StaingObject<WorkbenchInventory>> worbench : workbenches)
	{
		worbench->Draw(cameraPosition);
	}
	// Отрисовка хранилщ энергии
	for (std::shared_ptr<StaingObject<EnergyStorageInventory>> energyStorage : energyStorages)
	{
		energyStorage->Draw(cameraPosition);
	}
	// Отрисовка проводов
	for (std::shared_ptr<Wire> wire : wires)
	{
		wire->Draw(cameraPosition);
	}
	// Отрисовка игрока
	player.Draw(cameraPosition);
}
// Закрыть инвентарь
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
		}
		player.buttons.clear();
	}
}
// Поставить объект по определенным координатам
void Game::PutObject(sf::Vector2f position)
{
	// Поставить печку
	if (player.inventory.cells[player.inventory.choseCell][3].item.number == 2)
	{
		coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(rw, field.sizeOne, textures["Oven"], position, colorsInventory));
	}
	// Поставить верстак
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 11)
	{
		electricOvens.push_back(std::make_shared<StaingObject<ElectricOvenInventory>>(rw, field.sizeOne, textures["ElectricOven"], position, colorsInventory));
	}
	// Поставить сундук
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 5)
	{
		chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, textures["Chest"], position, colorsInventory));
	}
	// Поставить верстак
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 8)
	{
		workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, textures["Workbench"], position, colorsInventory));
	}
	// Поставить энергохранилище
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 13)
	{
		energyStorages.push_back(std::make_shared<EnergyStorageSprite>(rw, field.sizeOne, textures["EnergyStorage"], position, 1));
	}
	// Поставить медный провод
	else if (player.inventory.cells[player.inventory.choseCell][3].item.number == 12)
	{
		wires.push_back(std::make_shared<Wire>(rw, field.sizeOne, textures["CooperWire"], position));
	}
}
// Геймплей
void Game::Drive()
{
	// То, что делает игрок каждый кадр
	player.Update();
	// Инвентарь снизу
	player.inventory.DrawNear(mouseWheel);
	// Поставить объект на землю
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
	// Работа угольных печей
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
	// Работа электрических печей
	for (int i = 0; i < electricOvens.size(); i++)
	{
		// Обновление массива с указанием номера электропечей в массиве по координатам
		field.electricOvens[electricOvens[i]->position.x][electricOvens[i]->position.y] = i;
		// Обновление электропечей
		electricOvens[i]->Update(player.position, player.angle);
		// Если инвентарь открыт
		if (electricOvens[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 2;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// Работа сундуков
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
	// Работа верстаков
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
	// Работа хранилищ энергии
	for (int i = 0; i < energyStorages.size(); i++)
	{
		// Обновление массива с указанием номера проводов в массиве по координатам
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
	// Работа проводов
	for (int i = 0; i < wires.size(); i++)
	{
		// Обновление массива с указанием номера проводов в массиве по координатам
		field.wires[wires[i]->position.x][wires[i]->position.y] = i;
		wires[i]->Update(player.position, player.angle);
	}
	// Смещение камеры
	cameraPosition -= (cameraPosition - sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2))) * 0.04f;
}
// Перенос энергию между проводами и устройставми
void Game::TransEnergy(sf::Vector2i originalPosition, sf::Vector2i nextPosition, int typeObject)
{
	// Ссылка на энергию объекта, который ее передает
	int* energy;
	if (typeObject == 0)
	{
		if (field.wires[originalPosition.x][originalPosition.y] == -1)
		{
			return;
		}
		energy = &wires[field.wires[originalPosition.x][originalPosition.y]]->energy;
	}
	else if (typeObject == 1)
	{
		if (field.energyStorages[originalPosition.x][originalPosition.y] == -1)
		{
			return;
		}
		energy = &energyStorages[field.energyStorages[originalPosition.x][originalPosition.y]]->inventory.energy;
	}
	else
	{
		return;
	}

	if (field.wires[nextPosition.x][nextPosition.y] != -1)
	{
		wires[field.wires[nextPosition.x][nextPosition.y]]->energy = *energy;
		*energy = 0;
	}
	else if (field.electricOvens[nextPosition.x][nextPosition.y] != -1)
	{
		electricOvens[field.electricOvens[nextPosition.x][nextPosition.y]]->inventory.fuel += *energy;
		*energy = 0;
	}
	else if (field.energyStorages[nextPosition.x][nextPosition.y] != -1)
	{
		electricOvens[field.electricOvens[nextPosition.x][nextPosition.y]]->inventory.fuel += *energy;
		*energy = 0;
	}
	energy = nullptr;
	delete energy;
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
// Игра
void Game::Play()
{
	// Отрисовать игру
	DrawPlay();

	// Работа печек
	for (auto coalOven : coalOvens)
	{
		coalOven->inventory.Burn();
	}

	// Работа электропечек
	for (auto electricOven : electricOvens)
	{
		electricOven->inventory.Burn();
	}

	// Работа энергитического хранилища
	for (auto energyStorage : energyStorages)
	{
		energyStorage->inventory.Next();
	}

	// Для теста
	energyStorages[0]->inventory.energy += 10;
	// Передача энергии проводами
	for (int i = 0; i < field.size.x; i++)
	{
		for (int j = 0; j < field.size.y; j++)
		{
			if (field.wires[i][j] != -1)
			{
				if (wires[field.wires[i][j]]->energy != 0)
				{
					// Сдвиг относительно объекта (куда он повернут)
					sf::Vector2i shift = CheckTurnEnergy(wires[field.wires[i][j]]->turn);
					TransEnergy(sf::Vector2i(i, j), sf::Vector2i(i + shift.x, j + shift.y), 0);
				}
			}
			if (field.energyStorages[i][j] != -1)
			{
				if (energyStorages[field.energyStorages[i][j]]->inventory.energy != 0)
				{
					// Сдвиг относительно объекта (куда он повернут)
					sf::Vector2i shift = CheckTurnEnergy(energyStorages[field.energyStorages[i][j]]->turn);
					TransEnergy(sf::Vector2i(i, j), sf::Vector2i(i + shift.x, j + shift.y), 1);
				}
			}
		}
	}

	if (buttons.size() < 4)
	{
		// Кнопка выйти
		buttons.push_back(Button(sf::Vector2f(1000, 600), sf::Vector2f(90, 60), L"Выйти",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 25));
	}

	if (!player.isOpenInventory)
	{
		// Геймплей
		Drive();
	}
	else
	{
		// Инвентарь игрока
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
		// Инвентарь печки
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
		// Инвентарь сундука
		else if (player.whatTypeInventoryOpen == 3)
		{
			chests[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			CloseInventory();
		}
		// Инвентарь верстака
		else if (player.whatTypeInventoryOpen == 4)
		{
			workbenches[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			CloseInventory();
		}
		// Инвентарь хранилища энергии
		else if (player.whatTypeInventoryOpen == 5)
		{
			energyStorages[player.whatNumberInventoryOpen]->inventory.Update(player.inventory);
			CloseInventory();
		}
	}

	// Кнопка выйти
	buttons[0].Draw(*rw);
	if (buttons[0].DrawCheckLeft(*rw))
	{
		screen = "ВыгрузочныйЭкранМеню";
		buttons.clear();
		return;
	}

}
// Меню
void Game::Menu()
{
	if (buttons.size() < 1)
	{
		buttons.push_back(Button(sf::Vector2f(sizeW.x / 2 - 75, 300), sf::Vector2f(150, 40), L"Начать",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
		buttons.push_back(Button(sf::Vector2f(sizeW.x / 2 - 75, 500), sf::Vector2f(150, 40), L"Выйти",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
	}

	functions.DrawRectangle(sf::Vector2f(200, 100), sf::Vector2f(980, 520), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 4);
	functions.PrintText(L"Few Colors", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

	if (buttons[0].DrawCheckLeft(*rw))
	{
		screen = "ЗагрузочныЭкранГеймплея";
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
// Следуюущий кадр (выбор экрана)
void Game::Next()
{
	mousePosition = sf::Mouse::getPosition(*rw);

	if (screen == "Игра")
	{
		Play();
	}
	else if (screen == "ЗагрузкаПриложения1")
	{
		LoadingApp1();
	}
	else if (screen == "ЗагрузкаПриложения")
	{
		LoadingApp();
	}
	else if (screen == "ЗагрузочныЭкранГеймплея")
	{
		LoadingScreen("ЗагрузкаГеймплея");
	}
	else if (screen == "ЗагрузочныйЭкранКонцаГеймплея")
	{
		LoadingScreen("Меню");
	}
	else if (screen == "ВыгрузочныйЭкранМеню")
	{
		UnloadingPlay("Меню");
	}
	else if (screen == "ЗагрузкаГеймплея")
	{
		LoadingPlay();
	}
	else if (screen == "Меню")
	{
		Menu();
	}
	// Вычислить и показать FPS
	sf::Time FPS = clock.getElapsedTime();
	functions.PrintText(std::to_string((int)(1 / FPS.asSeconds())), sf::Vector2f(sizeW.x - 15, 10), 25, sf::Color::Red, 0);
	clock.restart();
	mouseWheel = 0;
}
// Событие мыши
void Game::Mouse(sf::Event& e, sf::RenderWindow& rw)
{
	mousePosition = sf::Mouse::getPosition(rw);
}

void Game::MouseWheelScrolled(int _mouseWheel)
{
	mouseWheel = _mouseWheel;
}
