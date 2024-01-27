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

	// Список всех объектов
	// std::vector<std::shared_ptr<StaingObject<OvenInventory>>> objects;
	// Список печек
	std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>> coalOvens;
	// Список электрических печек
	std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>> electricOvens;
	// Список сундуков
	std::vector<std::shared_ptr<StaingObject<ChestInventory>>> chests;
	// Список верстаков
	std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>> workbenches;
	// Список проводов
	std::vector<std::shared_ptr<Wire>> wires;

	//std::vector<std::shared_ptr<Object>> objects;

	std::map<std::string, sf::Texture> textures;


	// Поле
	Field field;

public:
	Game(){ }
	Game(sf::RenderWindow& _rw);
	// Прогрессбарр загрузки приложения
	void LoadingApp1();
	// Загрузка приложения
	void LoadingApp();
	// Прогрессбарр загрузки геймплея
	void LoadingScreen(std::string nextScreen);
	// Загрузка геймплея
	void LoadingPlay();
	// Выгрузка геймплея
	void UnloadingPlay(std::string nextScreen);
	// Отрисовка игрового поля
	void DrawPlay();
	// Закрыть
	void CloseInventory();
	// Интерфейс Печки
	void OvenInventoryFun();
	// Интерфейс ЭлектроПечки
	void ElectricOvenInventoryFun(){ }
	// Инвентарь сундука
	void ChestInventoryFun();
	// Инвентарь верстака
	void WorkbenchInventoryFun();
	// Поставить объект по определенным коодинатам
	void PutObject(sf::Vector2f position);
	// Геймплей
	void Drive();
	// Игра
	void Play();
	// Меню
	void Menu();
	// Следуюущий кадр
	void Next();
	// Нарисовать круг
	void Circle(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	// Событие мыши
	void Mouse(sf::Event& e, sf::RenderWindow& rw);
	// Прокручено колесико мыши
	void MouseWheelScrolled(int _mouseWheel);

	void EndProgramm(){}
};

