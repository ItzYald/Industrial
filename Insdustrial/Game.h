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

#include "Wire.h"
#include "Field.h"
#include "Player.h"
#include "StaingObject.h"
// Инвентари
#include "CoalOvenInventory.h"
#include "ElectricOvenInventory.h"
#include "ChestInventory.h"
#include "WorbenchInventory.h"
#include "EnergyStorageInventory.h"

#include "EnergyStorageSprite.h"


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

	// Игрок
	Player player;

	// Стандартные цвета для приложения
	std::vector<sf::Color> colorsInventory;

	// Список печек
	std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>> coalOvens;
	// Список электрических печек
	std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>> electricOvens;
	// Список сундуков
	std::vector<std::shared_ptr<StaingObject<ChestInventory>>> chests;
	// Список верстаков
	std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>> workbenches;
	// Список хранилищ энергии
	std::vector<std::shared_ptr<EnergyStorageSprite>> energyStorages;

	// Список проводов
	std::vector<std::shared_ptr<Wire>> wires;
	
	// Список всех текстур
	std::map<std::string, sf::Texture> textures;
	// Список текстур предметов (в инвентаре)
	std::vector<sf::Texture> itemTextures;


	// Поле
	Field field;

public:
	Game(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	Game(sf::RenderWindow& _rw);
	// Прогрессбарр (надпись) загрузки приложения
	void LoadingApp1();
	// Загрузка приложения
	void LoadingApp();
	// Прогрессбарр (надпись) загрузки геймплея
	void LoadingScreen(std::string nextScreen);
	// Загрузка настроек цвета интерфейса из файла
	void LoadColorInventoryFromFile();
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
	// Закрыть
	void CloseInventory();
	// Поставить объект по определенным коодинатам
	void PutObject(sf::Vector2f position);
	// Геймплей
	void Drive();
	/// <summary>Передать энеригю</summary>
	/// <param name="nextPosition">Позиция объекта, которому передать энергию</param>
	/// <param name="energy">Какую энергию передать</param>
	/// <param name="power">Сколько передать энергии</param>
	void TransEnergy(sf::Vector2i nextPosition, int& energy, int power);
	/// <summary>Какую энергию передавать</summary>
	/// <param name="originalPosition">Позиция первого устройства, который передает энергию</param>
	/// <param name="nextPosition">Позиция второго устройства, которому передают энергию</param>
	/// <param name="typeObject">Тип устройства, которое передает энергию (0 - провод, 1 - хранилище)</param>
	void CheckTypeTrans(sf::Vector2i originalPosition, sf::Vector2i nextPosition, int typeObject);
	/// <summary>Проверка поворота устройста для понятия, куда отправлять энергию</summary>
	/// <param name="turn">Поворот объекта</param>
	sf::Vector2i CheckTurnEnergy(int turn);
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

	void EndProgramm(){}
};

