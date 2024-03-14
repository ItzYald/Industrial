#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"
#include "Functions/Checks.h"

#include "IPlayUpdatable.h"

#include "StaticSprites.h"

#include "CellInInventory.h"

class AllInventory : public IPlayUpdatable
{
public:
	// Списко кнопок
	std::vector<OldButton> oldButtons;
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	// Функции
	Functions functions;
	// Позиция мыши
	sf::Vector2i mousePosition;
	/// Цвета для интерфейса
	// Список цветов
	std::vector<sf::Color> colorsInventory;

	StaticSprites itemsSprites;

	std::vector<Checks> ch;

	// Общая отрисовка ячеек в инвентаре (для всех у кого есть список клеток)
	// Для двумерных списков
	void DrawCommon(std::vector<std::vector<CellInInventory>> cells);
	// Для одномерных списков
	void DrawCommon(std::vector<CellInInventory> cells);
	// Отрисовка инвентаря
	virtual void Draw() = 0;
	// Всегда (даже когда инвентарь не открыт)
	virtual void PlayUpdate() = 0;

};

