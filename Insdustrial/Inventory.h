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
	std::vector<std::vector<CellInInventory>> cells;
	std::vector<std::vector<CellInInventory>> cellsMiniWorkBench;

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
	//void Draw();
	void Draw();
	// Действия инвентаря
	//void Update();

	void Update();
	// Отрисовка и действия внутреннего инвентаря (вместе с мини верстаком, который пока не работает)
	void DrawMiniWorkbench();
	void DrawMiniWorkbench2(){}
	// Отрисовка нижней части инвентаря (во время геймплея)
	void DrawNear(int mouseWheel);
	

};

