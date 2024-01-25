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
#include "ObjectInventory.h"

class Inventory : public ObjectInventory
{
private:
	std::vector<Checks> ch;

public:
	// Ячейки с предметами
	std::vector<std::vector<CellInInventory>> cells;
	// Ячейки с предметами маленького верстака
	std::vector<std::vector<CellInInventory>> cellsMiniWorkbench;

	// Предмет перетаскиваемый мышкой
	Item mouseItem;
	// Выбранная ячейка (колесиком мыши)
	int choseCell;	


	// Базовый конструктор
	Inventory(){ }
	// Конструктор
	Inventory(std::shared_ptr<sf::RenderWindow> _rw);
	// Удалить кнопки
	void DeleteButtons();
	// Отрисовка инвентаря
	void Draw();
	// Действия инвентаря
	void Update();
	// Отрисовка и действия внутреннего инвентаря (вместе с мини верстаком, который пока не работает)
	void DrawMiniWorkbench();
	// Отрисовка нижней части инвентаря (во время геймплея)
	void DrawNear(int mouseWheel);
	

};

