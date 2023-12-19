#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"
#include "Functions/Checks.h"

#include "StaticSprites.h"

struct ItemStruct
{
	int number;
	int quantity;
};

class Inventory
{
private:
	// Список кнопок
	std::vector<Button> buttons;
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;
	std::vector<Checks> ch;

public:

	// Позиция мыши
	sf::Vector2i mousePosition;

	// Предметы в интерфейсе
	std::vector<std::vector<ItemStruct>> items;
	// Предметы в мини 
	std::vector<std::vector<ItemStruct>> itemsMiniWorkbench;
	// Предмет перетаскиваемый мышкой
	ItemStruct mouseItem;

	int choseCell;	

	// Не используется
	Inventory(){ }
	// Конструктор
	Inventory(std::shared_ptr<sf::RenderWindow> _rw);

	// Удалить кнопки
	void DeleteButtons();
	// Добавить кнопки
	void AddButtons(bool miniWorkbench);
	// Отрисовка инвентаря
	void Draw();
	// Действия инвентаря
	void Update();
	// Отрисовка внутреннего инвентаря (вместе с мини верстаком)
	void DrawMiniWorkbench();
	// Отрисовка нижней части инвентаря (во время геймплея)
	void DrawNear(int mouseWheel);
	

};

