#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "Inventory.h"
#include "ObjectInventory.h"

#include "StaticSprites.h"

#define coal 10

class WorbenchInventory : ObjectInventory
{
public:
	// Предметы в поле для крафта
	std::vector<std::vector<ItemStruct>> items;
	// Результат (полученный предмет)
	ItemStruct madeItem;
	// Какие есть крафты
	std::vector<std::vector<std::vector<int>>> collectionCraft;
	std::vector<int> collectionResult;

	WorbenchInventory(){}
	WorbenchInventory(std::shared_ptr<sf::RenderWindow> _rw);

	// Добавить новый крафт (в начале программы для сокращения кода)
	void AddCraft(int number,
		int craft1, int craft2, int craft3, int craft4, int craft5, int craft6, int craft7, int craft8, int craft9,
		int result);
	// Проверка слотов крафта
	void Craft();
	// Отрисовка и работа с мышью
	void Draw(Inventory& playerInventory);

};

