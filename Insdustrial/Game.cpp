#pragma once
#include "Game.h"

Game::Game(sf::RenderWindow& _rw)
{
	rw = std::shared_ptr<sf::RenderWindow>(&_rw);
	functions = Functions(rw);
	sizeW = _rw.getSize();
	screen = "ЗагрузкаПриложения1";
}
// Отображение загрузки приложения
void Game::LoadingApp1()
{
	font.loadFromFile("Font/Undertale-Font.ttf");
	functions.PrintText(L"Загрузка...", sf::Vector2f(sizeW.x / 2 - 100, 300), 25, sf::Color::Green);
	screen = "ЗагрузкаПриложения";
}
// Загрузка картинок
void Game::LoadingImg()
{
	//imgImg = sf::Image();
	//imgImg.loadFromFile("img/Andrew 1.jpg");
}
// Загрузка приложения
void Game::LoadingApp()
{
	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

	LoadingImg();

	srand(time(NULL));

	screen = "Меню";

	field = Field(rw, sf::Vector2i(200, 200), 48, sizeW);
	cameraPosition = sf::Vector2f(20, 20);

	player = Player(rw, field.sizeOne, "Images/Human.png", sf::Vector2f(20, 20));
	
	ovens = std::vector<std::shared_ptr<StaingObject<OvenInventory>>>();
	ovens.push_back(std::make_shared<StaingObject<OvenInventory>>(rw, field.sizeOne, "Images/Oven.png", sf::Vector2f(23, 20)));

	chests = std::vector<std::shared_ptr<StaingObject<ChestInventory>>>();
	chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, "Images/Chest.png", sf::Vector2f(23, 21)));

	workbenches = std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>();
	workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, "Images/Workbench.png", sf::Vector2f(23, 22)));

	// objects = std::vector<std::shared_ptr<StaingObject<OvenInventory>>>();

	// for (int i = 0; i < ovens.size(); i++)
	// {
	// 	//objects.push_back(ovens[i]);
	// }

}
// Отрисовка игры
void Game::DrawPlay()
{
	// Белый экран
	functions.Rectangle(rw.get(), sf::Vector2f(0, 0), sf::Vector2f(sizeW.x, sizeW.y), sf::Color(255, 255, 255));

	// Сетка
	for (int i = 0; i < field.size.x; i++)
		for (int j = 0; j < field.size.y; j++)
			field.Draw(cameraPosition, i, j);

	for (std::shared_ptr<StaingObject<OvenInventory>> oven : ovens)
	{
		oven->Draw(cameraPosition);
	}
	for (std::shared_ptr<StaingObject<ChestInventory>> chest : chests)
	{
		chest->Draw(cameraPosition);
	}
	for (std::shared_ptr<StaingObject<WorkbenchInventory>> worbenche : workbenches)
	{
		worbenche->Draw(cameraPosition);
	}
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
			ovens[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 2:
			chests[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		case 3:
			workbenches[player.whatNumberInventoryOpen]->isOpenInventory = false;
			break;
		}
		player.buttons.clear();
	}
}
// Интерфейс печки
void Game::OvenInventoryFun()
{
	ovens[player.whatNumberInventoryOpen]->inventory.Draw(player.inventory);
	CloseInventory();
}
// Инвентарь сундука
void Game::ChestInventoryFun()
{
	chests[player.whatNumberInventoryOpen]->inventory.Draw(player.inventory);
	CloseInventory();
}
// Инвентарь верстака
void Game::WorkbenchInventoryFunn()
{
	workbenches[player.whatNumberInventoryOpen]->inventory.Draw(player.inventory);
	CloseInventory();
}
// Поставить объект по определенным координатам
void Game::PutObject(sf::Vector2f position)
{
	// Поставить печку
	if (player.inventory.items[player.inventory.choseCell][3].number == 2)
	{
		ovens.push_back(std::make_shared<StaingObject<OvenInventory>>(rw, field.sizeOne, "Images/Oven.png", position));
		//objects.push_back(ovens[ovens.size() - 1]);
	}
	else if (player.inventory.items[player.inventory.choseCell][3].number == 5)
	{
		chests.push_back(std::make_shared<StaingObject<ChestInventory>>(rw, field.sizeOne, "Images/Chest.png", position));
		//objects.push_back(chests[ovens.size() - 1]);
	}
	else if (player.inventory.items[player.inventory.choseCell][3].number == 8)
	{
		workbenches.push_back(std::make_shared<StaingObject<WorkbenchInventory>>(rw, field.sizeOne, "Images/Workbench.png", position));
		//objects.push_back(chests[ovens.size() - 1]);
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
	bool nearObject = player.PutObject(ovens, chests, workbenches);
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

	for (int i = 0; i < ovens.size(); i++)
	{
		ovens[i]->Update(player.position, player.angle);
		if (ovens[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 1;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}

	for (int i = 0; i < chests.size(); i++)
	{
		chests[i]->Update(player.position, player.angle);
		if (chests[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 2;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}

	for (int i = 0; i < workbenches.size(); i++)
	{
		workbenches[i]->Update(player.position, player.angle);
		if (workbenches[i]->isOpenInventory)
		{
			player.inventory.DeleteButtons();
			player.isOpenInventory = true;
			player.whatTypeInventoryOpen = 3;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}

	cameraPosition = sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2));
}
// Игра
void Game::Play()
{
	// Отрисовать игру
	DrawPlay();

	// Работа печек
	for (int i = 0; i < ovens.size(); i++)
	{
		ovens[i]->inventory.Burn(player.inventory);
	}

	if (buttons.size() < 4)
	{
		// Цвета
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
				ovens[player.whatNumberInventoryOpen]->isOpenInventory = false;
				chests[player.whatNumberInventoryOpen]->isOpenInventory = false;
				workbenches[player.whatNumberInventoryOpen]->isOpenInventory = false;
			}
		}
		// Инвентарь печки
		else if (player.whatTypeInventoryOpen == 1)
		{
			OvenInventoryFun();
		}
		// Инвентарь сундука
		else if (player.whatTypeInventoryOpen == 2)
		{
			ChestInventoryFun();
		}
		// Инвентарь верстака
		else if (player.whatTypeInventoryOpen == 3)
		{
			WorkbenchInventoryFunn();
		}
	}

	// Области
	if (buttons[0].DrawCheckLeft(*rw))
	{
		screen = "Меню";
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

	functions.Rectangle(rw.get(), sf::Vector2f(200, 100), sf::Vector2f(980, 520), sf::Color(0, 40, 0), sf::Color(0, 255, 0), 4);
	functions.PrintText(L"Few Colors", sf::Vector2f(sizeW.x / 2.f, 100), 109, sf::Color(0, 255, 0), 1);

	if (buttons[0].DrawCheckLeft(*rw))
	{
		screen = "Игра";
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
// Круг
void Game::Circle(sf::Vector2f pos, sf::Vector2f size, sf::Color col)
{
	circle = sf::CircleShape(1);
	circle.setFillColor(col);
	circle.setScale(size);
	circle.setPosition(pos);
	rw->draw(circle);
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
