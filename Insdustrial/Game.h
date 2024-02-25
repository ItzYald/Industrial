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
#include "Functions/Button.h"
#include "Functions/Checks.h"

#include "Field.h"
#include "Player.h"
#include "StaingObject.h"
#include "EnergyObject.h"
// Инвентари
#include "CoalOvenInventory.h"
#include "ElectricOvenInventory.h"
#include "CrusherInventory.h"
#include "CompressorInventory.h"
#include "ChestInventory.h"
#include "WorbenchInventory.h"
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
	// Текст
	sf::Text text;
	// Шрифт
	sf::Font font;
	// Позиция мыши
	sf::Vector2i mousePosition;
	// Колесико мыши
	int mouseWheel;
	
	std::vector<Checks> ch;
	// Функции
	Functions functions;
	// Список кнопок
	std::vector<Button> buttons;
	// Часы
	sf::Clock clock;

	// Позиция камеры
	sf::Vector2f cameraPosition;
	// Позиция мышки по сетке
	sf::Vector2i mousePositionGrid;
	const float maxMouseDistance = 4.2f;

	// Игрок
	Player player;

	// Стандартные цвета для приложения
	std::vector<sf::Color> colorsInventory;

	// Все объекты
	std::vector<Object*> objects;
	// Все объекты передающие энергию
	std::vector<IEnergyObject*> objectsTransEnergy;
	// Все энергетические объекты
	std::vector<IEnergyObject*> energyObjects;
	// Все обычные объекты
	std::vector<IStaingObject*> simpleObjects;
	
	// Список всех текстур
	std::map<std::string, sf::Texture> textures;
	// Список текстур предметов (в инвентаре)
	std::vector<sf::Texture> itemTextures;
	// Список текстур иконок в инвентаре
	std::map<std::string, sf::Texture> texturesInInventory;


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
	void LoadingImagesPlay();
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
	/// <summary>Процесс передачи энергии</summary>
	/// <param name="originalEnergy">Ссылка на энергию объекта,которй передает</param>
	/// <param name="power">Скорость передвчи энергии</param>
	/// <param name="nextEnergy">Ссылка на энергию того, которому передают</param>
	/// <param name="nextMaxEnergy">Максимальная энегрия объекта, которому передают</param>
	void TransEnergy(float &originalEnergy, int power, float& nextEnergy, int nextMaxEnergy);
	/// <summary>Какому объекту передать энергию</summary>
	/// <param name="nextPosition">Позиция объекта, которому передать энергию</param>
	/// <param name="energy">Какую энергию передать</param>
	/// <param name="power">Сколько передать энергии</param>
	void CheckNextEnergyObject(sf::Vector2i nextPosition, float& energy, int power);
	/// <summary>Проверка поворота устройста для понятия, куда отправлять энергию</summary>
	/// <param name="turn">Поворот объекта</param>
	sf::Vector2i CheckTurnEnergy(int turn);
	/// Какой объект находится по координатам (будет передавать энергию)
	void WhatObjectTransEnergy();
	// Какой инвентарь открыт
	void WhatInventory();
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

