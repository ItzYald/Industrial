#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "StaticSprites.h"

#include <fstream>

struct ItemStruct
{
	int number;
	int quantity;
};

class ObjectInventory
{
protected:
	// Списко кнопок
	std::vector<Button> buttons;
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	// Функции
	Functions functions;
	StaticSprites itemsSprites;
	// Позиция мыши
	sf::Vector2i mousePosition;
	/// Цвета для интерфейса
	// Список уветов
	std::vector<sf::Color> colorsInventory;

public:
	void LoadColorInventoryFromFile();
	void DrawCommon(std::vector<std::vector<ItemStruct>> items);
	void DrawCommon(std::vector<ItemStruct> items);

};

