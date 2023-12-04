#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Functions.h"
#include "Button.h"
#include "Checks.h"

//#include "Sprite.h"
#include "Wire.h"
#include "Field.h"
#include "Player.h"
#include "Oven.h"
#include "Inventory.h"


class Game
{
private:
	//// Обязательные
	std::shared_ptr<sf::RenderWindow> rw;
	// Круг
	sf::CircleShape circle;
	// Какой экран
	sf::String screen;
	// Размер дисплея
	sf::Vector2u sizeW;
	// Текст
	sf::Text text;
	// Шрифт
	sf::Font font;
	// Позиция мыши
	sf::Vector2i mousePosition;
	// Колесико мыши
	int mouseWheel;
	//
	std::vector<Checks> ch;
	// Функции
	Functions functions;
	// Список кнопок
	std::vector<Button> buttons;
	// Часы
	sf::Clock clock;

	// Позиция камеры
	sf::Vector2f cameraPosition;

	// Игрок
	Player player;

	// Список печек
	std::vector<Oven> ovens;
	// Поле
	Field field;

public:
	Game(sf::RenderWindow& _rw);
	void LoadingApp1();
	void LoadingImg();
	void LoadingApp();
	// Отрисовка игрового поля
	void DrawPlay();
	// Интерфейс Печки
	void OvenInventory();
	// Геймплей
	void Drive();
	// Отрисовка
	void Draw();
	// Игра
	void Play();
	// Меню
	void Menu();
	// Следуюущий кадр
	void Next();
	// Нарисовать круг
	void Circle(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	// Текст
	void Mouse(sf::Event& e, sf::RenderWindow& rw);

	void MouseWheelScrolled(int _mouseWheel);

	void EndProgramm(){}
};

