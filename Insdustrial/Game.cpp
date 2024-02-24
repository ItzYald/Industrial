#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "ЭкранЗагрузкиПриложения";
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
// Загрузка приложения
void Game::LoadingApp()
{
	mouseWheel = 0;
	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

	srand(time(NULL));

	screen = "Меню";
	cameraPosition = sf::Vector2f(20, 20);
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
// Загрузка картинок для игры
void Game::LoadingImagesPlay()
{
	/// Текстуры:
	textures["Player"] = sf::Texture();
	textures["Player"].loadFromFile("Images/Human.png");
	// Печка
	textures["Oven"] = sf::Texture();
	textures["Oven"].loadFromFile("Images/Objects/Oven.png");
	// Электропечка
	textures["ElectricOven"] = sf::Texture();
	textures["ElectricOven"].loadFromFile("Images/Objects/ElectricOven.png");
	// Дробитель
	textures["Crusher"] = sf::Texture();
	textures["Crusher"].loadFromFile("Images/Objects/Crusher.png");
	// Дробитель
	textures["Compressor"] = sf::Texture();
	textures["Compressor"].loadFromFile("Images/Objects/Compressor.png");
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
	textures["EnergyStorage"].loadFromFile("Images/Objects/EnergyStorage.png");
	// Ручной энергогенератор
	textures["EnergyHandGenerator"] = sf::Texture();
	textures["EnergyHandGenerator"].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// Угольный энергогенератор
	textures["EnergyCoalGenerator"] = sf::Texture();
	textures["EnergyCoalGenerator"].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	/// Текстурки проводов
	// Медные
	textures["CopperWireOn"] = sf::Texture();
	textures["CopperWireOn"].loadFromFile("Images/Wires/CopperWireOn.png");
	textures["CopperWireOff"] = sf::Texture();
	textures["CopperWireOff"].loadFromFile("Images/Wires/CopperWireOff.png");
	// Железные
	textures["IronWireOn"] = sf::Texture();
	textures["IronWireOn"].loadFromFile("Images/Wires/IronWireOn.png");
	textures["IronWireOff"] = sf::Texture();
	textures["IronWireOff"].loadFromFile("Images/Wires/IronWireOff.png");
	// Оловяныеы
	textures["TinWireOn"] = sf::Texture();
	textures["TinWireOn"].loadFromFile("Images/Wires/TinWireOn.png");
	textures["TinWireOff"] = sf::Texture();
	textures["TinWireOff"].loadFromFile("Images/Wires/TinWireOff.png");
	/// Иконки в инвентаре
	// Иконка ручной генерации энергии
	texturesInInventory["HandGenerate"] = sf::Texture();
	texturesInInventory["HandGenerate"].loadFromFile(
		"Images/IconsInInventory/IconEnergyHandGenerator.png");

	// Текстуры предметов
	for (int i = 0; i < 32; i++)
	{
		itemTextures.push_back(sf::Texture());
	}

	// Пустой слот
	itemTextures[0].loadFromFile("Images/Empty.png");
	// Железная руда
	itemTextures[1].loadFromFile("Images/Metals/IronOre.png");
	// Печка
	itemTextures[2].loadFromFile("Images/Objects/Oven.png");
	// Уголь
	itemTextures[3].loadFromFile("Images/Coal.png");
	// Железный слиток
	itemTextures[4].loadFromFile("Images/Metals/IronIngot.png");
	// Сундук
	itemTextures[5].loadFromFile("Images/Objects/Chest.png");
	// Железный блок
	itemTextures[6].loadFromFile("Images/IronBlock.png");
	// Древесина
	itemTextures[7].loadFromFile("Images/Wood.png");
	// Верстак
	itemTextures[8].loadFromFile("Images/Objects/WorkBench.png");
	// Доски
	itemTextures[9].loadFromFile("Images/Planks.png");
	// Корпус механнизма
	itemTextures[10].loadFromFile("Images/Accumulator.png");
	// Электропеч
	itemTextures[11].loadFromFile("Images/Objects/ElectricOven.png");
	// Медный провод
	itemTextures[12].loadFromFile("Images/Wires/CopperWireOn.png");
	// Энергохранилище
	itemTextures[13].loadFromFile("Images/Objects/EnergyStorage.png");
	// Медный слиток
	itemTextures[14].loadFromFile("Images/Metals/CopperIngot.png");
	// Железный провод
	itemTextures[15].loadFromFile("Images/Wires/IronWireOn.png");
	// Ручной энергогенератор
	itemTextures[16].loadFromFile("Images/Objects/EnergyHandGenerator.png");
	// Угольный энергогенератор
	itemTextures[17].loadFromFile("Images/Objects/EnergyCoalGenerator.png");
	// Корпус механнизма
	itemTextures[18].loadFromFile("Images/Objects/MechanismBody.png");
	// Оловяный слиток
	itemTextures[19].loadFromFile("Images/Metals/TinIngot.png");
	// Оловяный провод
	itemTextures[20].loadFromFile("Images/Wires/TinWireOn.png");
	// Оловяный провод
	itemTextures[21].loadFromFile("Images/Metals/CopperOre.png");
	// Оловяный провод
	itemTextures[22].loadFromFile("Images/Metals/TinOre.png");
	// Измельченная железная руда
	itemTextures[23].loadFromFile("Images/Metals/CrushedIronOre.png");
	// Дрорбитель
	itemTextures[24].loadFromFile("Images/Objects/Crusher.png");
	// Железная пластина
	itemTextures[25].loadFromFile("Images/Metals/IronPlate.png");
	// Компрессор
	itemTextures[26].loadFromFile("Images/Metals/CopperPlate.png");
	// Компрессор
	itemTextures[27].loadFromFile("Images/Metals/TinPlate.png");
	// Компрессор
	itemTextures[28].loadFromFile("Images/Objects/Compressor.png");
	// Микросхема
	itemTextures[29].loadFromFile("Images/Chip.png");
	// Палка
	itemTextures[30].loadFromFile("Images/Stick.png");
	// Молот
	itemTextures[31].loadFromFile("Images/Hammer.png");

}
// Загрузка геймплея
void Game::LoadingPlay()
{
	// Загрузка цветов интерфейса
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

	screen = "Игра";
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
// Отрисовка игры
void Game::DrawPlay()
{
	// Белый экран
	functions.DrawRectangle(sf::Vector2f(0, 0), sf::Vector2f(sizeW.x, sizeW.y), sf::Color(255, 255, 255));
	// Отрисовка поля
	field.Draw(cameraPosition);
	// Отрисовка объектов
	for (int i = objects.size() - 1; i >= 0; i--)
	{
		//objects[i]->Draw();
		rw->draw(*objects[i]);
	}
}

void Game::DrawGameplay()
{
	// Отрисовка ячейки, на которой мышка
	functions.DrawRectangle(sf::Vector2f(
		field.sizeOne * (mousePositionGrid.x - cameraPosition.x),
		field.sizeOne * (mousePositionGrid.y - cameraPosition.y)),
		sf::Vector2f(field.sizeOne, field.sizeOne), sf::Color(200, 200, 200, 100), sf::Color(150, 150, 150), 2);
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
// Поставить объект по определенным координатам
void Game::PutObject(sf::Vector2f position)
{
	// Поставить:
	switch (player.inventory.cells[player.inventory.choseCell][3].item.number)
	{
	// Печку
	case 2:
		coalOvens.push_back(std::make_shared<StaingObject<CoalOvenInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Oven"], itemTextures, position, colorsInventory));
		objects.push_back(coalOvens[coalOvens.size() - 1].get());
		break;
	// Электропечку
	case 11:
		electricOvens.push_back(std::make_shared<EnergyObject<ElectricOvenInventory>>(
			rw, cameraPosition, field.sizeOne, textures["ElectricOven"], itemTextures, position, colorsInventory));
		objects.push_back(electricOvens[electricOvens.size() - 1].get());
		objects.push_back(electricOvens[electricOvens.size() - 1].get());
		break;
	// Дробитель
	case 24:
		crushers.push_back(std::make_shared<EnergyObject<CrusherInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Crusher"], itemTextures, position, colorsInventory, 1000));
		objects.push_back(crushers[crushers.size() - 1].get());
		objects.push_back(crushers[crushers.size() - 1].get());
		break;
	// Компрессор
	case 28:
		compressors.push_back(std::make_shared<EnergyObject<CompressorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Compressor"], itemTextures, position, colorsInventory, 1000));
		objects.push_back(compressors[compressors.size() - 1].get());
		objects.push_back(compressors[compressors.size() - 1].get());
		break;
	// Сундук
	case 5:
		chests.push_back(std::make_shared<StaingObject<ChestInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Chest"], itemTextures, position, colorsInventory));
		objects.push_back(chests[chests.size() - 1].get());
		break;
	// Верстак
	case 8:
		workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(
			rw, cameraPosition, field.sizeOne, textures["Workbench"], itemTextures, position, colorsInventory));
		objects.push_back(workbenches[workbenches.size() - 1].get());
		break;
	// Энергохранилище
	case 13:
		energyStorages.push_back(std::make_shared<EnergyObject<EnergyStorageInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyStorage"], itemTextures, position, colorsInventory, 1000, 10));
		objects.push_back(energyStorages[energyStorages.size() - 1].get());
		objects.push_back(energyStorages[energyStorages.size() - 1].get());
		break;
	// Ручной энергогенератор
	case 16:
		energyHandGenerators.push_back(std::make_shared<EnergyObject<EnergyHandGeneratorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyHandGenerator"], itemTextures, position, colorsInventory, 100, 10));
		objects.push_back(energyHandGenerators[energyHandGenerators.size() - 1].get());
		objects.push_back(energyHandGenerators[energyHandGenerators.size() - 1].get());
		break;
	// Угольный энергогенератор
	case 17:
		energyCoalGenerators.push_back(std::make_shared<EnergyObject<EnergyCoalGeneratorInventory>>(
			rw, cameraPosition, field.sizeOne, textures["EnergyCoalGenerator"], itemTextures, position, colorsInventory, 100, 10));
		objects.push_back(energyCoalGenerators[energyCoalGenerators.size() - 1].get());
		objects.push_back(energyCoalGenerators[energyCoalGenerators.size() - 1].get());
		break;
	// Медный провод
	case 12:
		wires.push_back(std::make_shared<Wire>(
			rw, cameraPosition, field.sizeOne, textures["CopperWireOn"], textures["CopperWireOff"], position, 0));
		objects.push_back(wires[wires.size() - 1].get());
		break;
	// Железный провод
	case 15:
		wires.push_back(std::make_shared<Wire>(
			rw, cameraPosition, field.sizeOne, textures["IronWireOn"], textures["IronWireOff"], position, 1));
		objects.push_back(wires[wires.size() - 1].get());
		break;
	// Оловяный провод
	case 20:
		wires.push_back(std::make_shared<Wire>(
			rw, cameraPosition, field.sizeOne, textures["TinWireOn"], textures["TinWireOff"], position, 2));
		objects.push_back(wires[wires.size() - 1].get());
		break;
	}
}
// Геймплей
void Game::Gameplay()
{
	// Временная переменная для проверки расстояния до игрока
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

	// То, что делает игрок каждый кадр
	player.Update();
	// Инвентарь снизу
	player.inventory.DrawNear(mouseWheel);
	// Поставить объект на землю
	/*if (player.PutObject(mousePositionGrid,
		coalOvens, electricOvens, crushers, compressors, chests,
		workbenches, wires, energyStorages, energyHandGenerators, energyCoalGenerators))*/
	if (field.PutObject(mousePositionGrid, objects, player.inventory.cells[player.inventory.choseCell][3].item))
	{
		PutObject((sf::Vector2f)mousePositionGrid);
	}

	// Работа угольных печей
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
	// Работа электрических печей
	for (int i = 0; i < electricOvens.size(); i++)
	{
		// Обновление массива с указанием номера электропечей в массиве по координатам
		field.energyObjectsNumbers[electricOvens[i]->position.x][electricOvens[i]->position.y] = sf::Vector2i(1, i);
		// Обновление электропечей
		electricOvens[i]->Update(mousePositionGrid, player.position, player.angle);
		// Если инвентарь открыт
		if (electricOvens[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 2;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// Работа дробителей
	for (int i = 0; i < crushers.size(); i++)
	{
		// Обновление массива с указанием номера электропечей в массиве по координатам
		field.energyObjectsNumbers[crushers[i]->position.x][crushers[i]->position.y] = sf::Vector2i(5, i);
		// Обновление электропечей
		crushers[i]->Update(mousePositionGrid, player.position, player.angle);
		// Если инвентарь открыт
		if (crushers[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 8;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// Работа компрессоров
	for (int i = 0; i < compressors.size(); i++)
	{
		// Обновление массива с указанием номера электропечей в массиве по координатам
		field.energyObjectsNumbers[compressors[i]->position.x][compressors[i]->position.y] = sf::Vector2i(6, i);
		// Обновление электропечей
		compressors[i]->Update(mousePositionGrid, player.position, player.angle);
		// Если инвентарь открыт
		if (compressors[i]->isOpenInventory)
		{
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 9;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	// Работа сундуков
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
	// Работа верстаков
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
	// Работа хранилищ энергии
	for (int i = 0; i < energyStorages.size(); i++)
	{
		// Обновление массива с указанием номера проводов в массиве по координатам
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
	// Работа ручных энергогенераторов
	for (int i = 0; i < energyHandGenerators.size(); i++)
	{
		// Обновление массива с указанием номера проводов в массиве по координатам
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
	// Работа угольных энергогенераторов
	for (int i = 0; i < energyCoalGenerators.size(); i++)
	{
		// Обновление массива с указанием номера проводов в массиве по координатам
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
	// Работа проводов
	for (int i = 0; i < wires.size(); i++)
	{
		// Обновление массива с указанием номера проводов в массиве по координатам
		//field.wires[wires[i]->position.x][wires[i]->position.y] = i;
		field.energyObjectsNumbers[wires[i]->position.x][wires[i]->position.y] = sf::Vector2i(0, i);
		wires[i]->Update(mousePositionGrid, player.position, player.angle);
	}
	// Смещение камеры
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
	// Если на месте стоит провод
	if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 0)
	{
		std::shared_ptr<Wire> thisWire = wires[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y];
		TransEnergy(energy, power, thisWire->energy, thisWire->maxEnergy);
	}
	// Если на месте стоит электропечка
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 1)
	{
		thisObjectInventory = electricOvens[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// Если на месте стоит дробитель
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 5)
	{
		thisObjectInventory = crushers[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// Если на месте стоит компрессор
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 6)
	{
		thisObjectInventory = compressors[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// Если на месте стоит энергохранилище
	else if (field.energyObjectsNumbers[nextPosition.x][nextPosition.y].x == 2)
	{
		thisObjectInventory = energyStorages[field.energyObjectsNumbers[nextPosition.x][nextPosition.y].y]->inventory;
		TransEnergy(energy, power, thisObjectInventory->energy, thisObjectInventory->maxEnergy);
	}
	// Если на месте стоит энергохранилище
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
	// Передача энергии
	for (int i = 0; i < field.size.x; i++)
	{
		for (int j = 0; j < field.size.y; j++)
		{
			sf::Vector2i shift;
			int typeObject = -1;
			switch (field.energyObjectsNumbers[i][j].x)
			{
			// Если на координатах провод
			case 0:
				if (wires[field.energyObjectsNumbers[i][j].y]->energy != 0)
				{
					// Сдвиг относительно объекта (куда он повернут)
					shift = CheckTurnEnergy(wires[field.energyObjectsNumbers[i][j].y]->turn);
					typeObject = 0;
				}
				break;
			// Если на координатах энергохранилище
			case 2:
				if (energyStorages[field.energyObjectsNumbers[i][j].y]->inventory->energy != 0)
				{
					// Сдвиг относительно объекта (куда он повернут)
					shift = CheckTurnEnergy(energyStorages[field.energyObjectsNumbers[i][j].y]->turn);
					typeObject = 1;
				}
				break;
			// Если на координатах ручной энергогенератор
			case 3:
				if (energyHandGenerators[field.energyObjectsNumbers[i][j].y]->inventory->energy != 0)
				{
					// Сдвиг относительно объекта (куда он повернут)
					shift = CheckTurnEnergy(energyHandGenerators[field.energyObjectsNumbers[i][j].y]->turn);
					typeObject = 2;
				}
				break;
			// Если на координатах угольный энергогенератор
			case 4:
				if (energyCoalGenerators[field.energyObjectsNumbers[i][j].y]->inventory->energy != 0)
				{
					// Сдвиг относительно объекта (куда он повернут)
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
		// Инвентарь игрока
	case 0:
		player.inventory.DrawMiniWorkbench();
		player.inventory.Update();
		break;
		// Инвентарь угольной печки
	case 1:
		coalOvens[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентарь электропечки
	case 2:
		electricOvens[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентарь сундука
	case 3:
		chests[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентар верстака
	case 4:
		workbenches[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентарь энергетического хранилища
	case 5:
		energyStorages[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентарь ручного энергогенератора
	case 6:
		energyHandGenerators[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентарь угольного энергогенератора
	case 7:
		energyCoalGenerators[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентарь дробителя
	case 8:
		crushers[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
		// Инвентарь коммпрессора
	case 9:
		compressors[player.whatNumberInventoryOpen]->inventory->Update(player.inventory);
		break;
	}
	CloseInventory();
}
// Игра
void Game::Play()
{
	if (buttons.size() < 4)
	{
		// Кнопка выйти
		buttons.push_back(Button(sf::Vector2f(1000, 608), sf::Vector2f(128, 64), L"Выйти",
			colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
			sf::Color(255, 255, 255), sf::Color::Transparent, sf::Vector2f(128 / 2 - 35, 12), 4, 25));
	}
	// Отрисовать игру
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

	// Кнопка выйти
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
	functions.PrintText(L"Industrial", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

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
	else if (screen == "ЭкранЗагрузкиПриложения")
	{
		LoadingScreen("ЗагрузкаПриложения");
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
