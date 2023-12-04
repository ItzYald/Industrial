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
	
	ovens = std::vector<Oven>();
	ovens.push_back(Oven(rw, field.sizeOne, "Images/Oven.png", sf::Vector2f(25, 20)));
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

	for (Oven oven : ovens)
	{
		oven.Draw(cameraPosition);
	}
	player.Draw(cameraPosition);
}
// Отрисовка всего
void Game::Draw()
{
	DrawPlay();
}
// Интерфейс печки
void Game::OvenInventory()
{
	ovens[player.whatNumberInventoryOpen].inventory.Draw(player.inventory);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		player.isOpenInterface = false;
		ovens[player.whatNumberInventoryOpen].isOpenInterface = false;
		player.buttons.clear();
	}
}
// Геймплей
void Game::Drive()
{
	// Все что делает игрок каждый кадр
	player.Update();
	// Инвентарь снизу
	player.inventory.DrawNear(mouseWheel);
	// Поставить объект на землю
	player.PutObject(ovens);

	for (int i = 0; i < ovens.size(); i++)
	{
		ovens[i].Update(player.position, player.angle);
		if (ovens[i].isOpenInterface)
		{
			player.isOpenInterface = true;
			player.whatTypeInventoryOpen = 1;
			player.whatNumberInventoryOpen = i;
			break;
		}
	}
	cameraPosition = sf::Vector2f(player.position.x - (sizeW.x / field.sizeOne / 2), player.position.y - (sizeW.y / field.sizeOne / 2));
}
// Игра
void Game::Play()
{
	DrawPlay();

	// Работа печек
	for (int i = 0; i < ovens.size(); i++)
	{
		ovens[i].inventory.Burn(player.inventory);
	}

	if (buttons.size() < 4)
	{
		// Цвета
		buttons.push_back(Button(sf::Vector2f(1000, 600), sf::Vector2f(90, 60), L"Выйти",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(0, 255, 0), sf::Color::Transparent,
			sf::Color(0, 255, 0), sf::Color::Transparent, 1, 2, 25));
	}

	if (!player.isOpenInterface)
	{
		// Геймплей
		Drive();
	}
	else
	{
		if (player.whatTypeInventoryOpen == 0)
		{
			player.inventory.Draw();
			if (ch[2].Check(sf::Keyboard::Key::Escape) || ch[3].Check(sf::Keyboard::Key::E))
			{
				player.isOpenInterface = false;
			}
		}
		else if (player.whatTypeInventoryOpen == 1)
		{
			OvenInventory();
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
		buttons.push_back(Button(sf::Vector2f(sizeW.x / 2 - 75, 300), sf::Vector2f(150, 40), L"Играть",
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
	//std::cout << mouseWheel << " ";
}
