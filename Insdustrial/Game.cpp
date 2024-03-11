#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "ЭкранЗагрузкиПриложения";
	for (size_t i = 0; i < 20; i++)
	{
		lastFpsS.push_back(0);
	}
}
// Загрузка приложения
void Game::LoadingApp()
{
	playUpdatables = std::vector<IPlayUpdatable*>();
	drawables = std::vector<sf::Drawable*>();

	assets = Assets();

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
// Загрузка геймплея
void Game::LoadingPlay()
{
	oldButtons.clear();
	drawables.clear();
	// Загрузка цветов интерфейса
	LoadColorInventoryFromFile();

	assets.LoadingPlay();

	field = Field(rw, cameraPosition, sf::Vector2i(200, 200), 48,
		sizeW, assets.textures["Grass"], assets, player, drawables);
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

	screen = "Игра";
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
// Отрисовка игры
void Game::DrawPlay()
{
	// Белый экран
	functions.DrawRectangle(sf::Vector2f(0, 0), sf::Vector2f(sizeW.x, sizeW.y), sf::Color(255, 255, 255));
	// Отрисовка поля
	AllDraw();
	rw->draw(player);
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
			field.energyObjects[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 2:
			field.simpleObjects[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		}
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
	player.GamePlayUpdate();
	// Инвентарь снизу
	player.inventory.DrawNear(mouseWheel);
	// Поставить объект на землю
	if (field.ObjectHere(mousePositionGrid, player.inventory.cells[player.inventory.choseCell][3].item))
	{
		//PutObject((sf::Vector2f)mousePositionGrid);
		field.PutObject((sf::Vector2f)mousePositionGrid,
			player.inventory.cells[player.inventory.choseCell][3].item.number, colorsInventory);
	}

	for (size_t i = 0; i < field.objects.size(); i++)
	{
		field.objects[i]->Update(mousePositionGrid, player.position, player.angle);
	}

	field.GamePlayUpdate();

	// Смещение камеры
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
// Игра
void Game::Play()
{
	if (oldButtons.size() < 4)
	{
		// Кнопка выйти
		oldButtons.push_back(OldButton(sf::Vector2f(1000, 608), sf::Vector2f(128, 64), L"Выйти",
			colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
			sf::Color(255, 255, 255), sf::Color::Transparent, sf::Vector2f(128 / 2 - 35, 12), 4, 25));
	}
	// Отрисовать игру
	DrawPlay();

	field.PlayUpdate();

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

	// Кнопка выйти
	if (oldButtons[0].DrawCheckLeft(*rw))
	{
		screen = "ВыгрузочныйЭкранМеню";
		oldButtons.clear();
		return;
	}

}
// Меню
void Game::Menu()
{
	if (oldButtons.size() < 1)
	{
		oldButtons.push_back(OldButton(sf::Vector2f(sizeW.x / 2 - 75, 300), sf::Vector2f(150, 40), L"Начать",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
		oldButtons.push_back(OldButton(sf::Vector2f(sizeW.x / 2 - 75, 500), sf::Vector2f(150, 40), L"Выйти",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 30));
	}

	functions.DrawRectangle(sf::Vector2f(200, 100), sf::Vector2f(980, 520), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 4);
	functions.PrintText(L"Industrial", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

	AllDraw();

	if (oldButtons[0].DrawCheckLeft(*rw))
	{
		screen = "ЗагрузочныЭкранГеймплея";
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
	mouseWheel = 0;

	// Вычислить и показать FPS
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
// Событие мыши
void Game::Mouse(sf::Event& e, sf::RenderWindow& rw)
{
	mousePosition = sf::Mouse::getPosition(rw);
}

void Game::MouseWheelScrolled(int _mouseWheel)
{
	mouseWheel = _mouseWheel;
}
