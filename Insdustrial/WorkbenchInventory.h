#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"

#include "Inventory.h"
#include "ObjectInventory.h"
#include "TransferItemObjectInventory.h"

#include "StaticSprites.h"

class WorkbenchInventory : public ObjectInventory, public TransferItemObjectInventory
{
public:
	// Ячейки с предметами
	std::vector<std::vector<CellInInventory>> cells;
	// Результат (полученный предмет)
	CellInInventory madeItemCell;
	// Какие есть крафты
	std::vector<std::vector<std::vector<int>>> collectionCraft;
	std::vector<std::vector<int>> collectionResult;

	WorkbenchInventory(){}
	WorkbenchInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	// Добавить новый крафт (в начале программы для сокращения кода)
	void AddCraft(
		int craft1, int craft2, int craft3,
		int craft4, int craft5, int craft6,
		int craft7, int craft8, int craft9,
		int result, int quantity);
	// Добавить одиночный крафт (где только один предмет, но можно в каждую ячейку)
	void AddSingleCraft(int craft, int result, int quantity);
	// Добавить четверной крафт (где только 4 ОДИНАКОВЫХ предмета используется, но можно в 4 вариантах разложить)
	void AddQuadroSimpleCraft(int craft, int result, int quantity);
	// Добавить четверной крафт (где только 4 РАЗЛИЧНЫХ предмета используется, но можно в 4 вариантах разложить)
	void AddQuadroCraft(int craft1, int craft2, int craft3, int craft4, int result, int quantity);
	// Добавить крафт в виде вертикальной линии из трех
	void AddVerticalCraft(int craft1, int craft2, int craft3, int result, int quantity);
	// Добавить крафт в виде вертикальной линии из двух
	void AddVerticalDualCraft(int craft1, int craft2, int result, int quantity);
	// Добавить крафт в виде горизонтальной линии из двух
	void AddHorizontalDualCraft(int craft1, int craft2, int result, int quantity);
	// Добавление всех возможных крафтов с двумя предметами (например для молота)
	void AddAllDualCraft(int craft1, int craft2, int result, int quantity);
	// Проверка слотов крафта
	void Craft();
	void PlayUpdate(){ }
	// Отрисовка
	void Draw();
	// Работа интерфейса и мыши
	void WhileOpen(Inventory& playerInventory);

};

