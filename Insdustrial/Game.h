#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"
#include "Functions/Checks.h"

#include "Functions/BaseButton.h"
#include "Functions/TextButton.h"
#include "Functions/ImageButton.h"

#include "Assets.h"

#include "Field.h"
#include "Player.h"
#include "StaingObject.h"
#include "EnergyObject.h"
// Инвентари
#include "CoalOvenInventory.h"
#include "ChestInventory.h"
#include "WorkbenchInventory.h"
#include "MineInventory.h"

#include "ElectricOvenInventory.h"
#include "CrusherInventory.h"
#include "CompressorInventory.h"
#include "EnergyStorageInventory.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"
#include "WireInventory.h"


class Game
{
private:
	//// Обязательные
	std::shared_ptr<sf::RenderWindow> rw;
	// Какой экран
	sf::String screen;
	// Размер дисплея
	sf::Vector2u sizeW;
	// Часы
	sf::Clock clock;
	// Позиция мыши
	sf::Vector2i mousePosition;
	// Колесико мыши
	int mouseWheel;
	// Кадры в секунду
	sf::Time fps;
	// Последние 10 количеств кадров в секунду
	std::vector<int> lastFpsS = std::vector<int>();
	// Средний Fps
	float avarageFps = 0;
	// Какой сейчас Fps по счету (от 0, то размера FpsS
	int whatNumberFps;

	Assets assets;
	
	std::vector<Checks> ch;
	// Функции
	Functions functions;
	// Список кнопок
	std::vector<OldButton> oldButtons;

	std::vector<Button*> buttons;

	// Позиция камеры
	sf::Vector2f cameraPosition;
	// Позиция мышки по сетке
	sf::Vector2i mousePositionGrid;
	const float maxMouseDistance = 4.2f;

	// Игрок
	Player player;

	// Стандартные цвета для приложения
	std::vector<sf::Color> colorsInventory;

	// Все на отрисовку
	std::vector<sf::Drawable*> drawables;

	// Поле
	Field field;

public:
	Game(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	Game(sf::RenderWindow& _rw);
	// Загрузка приложения
	void LoadingApp();
	// Прогрессбарр (надпись) загрузки геймплея
	void LoadingScreen(std::string nextScreen);
	// Загрузка настроек цвета интерфейса из файла
	void LoadColorInventoryFromFile();
	// Загрузка игры для разработки
	void LoadingForDev();
	// Загрузка игры для игры
	void LoadingForPlay();
	// Загрузка геймплея
	void LoadingPlay();
	/// <summary>
	/// Выгрузка геймплея из памяти
	/// (очистка массивов и обнуление картинок)
	/// </summary>
	/// <param name="nextScreen">Экран в который переходит после выгрузки геймплея</param>
	void UnloadingPlay(std::string nextScreen);
	// Отрисовка игрового поля
	void DrawPlay();

	void DrawGameplay();
	// Закрыть
	void CloseInventory();
	// Поставить объект по определенным коодинатам
	void PutObject(sf::Vector2f position);
	// Геймплей
	void Gameplay();
	// Какой инвентарь открыт
	void WhatInventory();

	void AllDraw();
	// Игра
	void Play();
	// Меню
	void Menu();
	// Следуюущий кадр
	void Next();
	// Событие мыши
	void Mouse(sf::Event& e, sf::RenderWindow& rw);
	// Прокручено колесико мыши
	void MouseWheelScrolled(int _mouseWheel);

};

