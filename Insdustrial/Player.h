#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "Sprite.h"
#include "StaticSprites.h"
#include "Inventory.h"
#include "StaingObject.h"
// Инвентари
#include "CoalOvenInventory.h"
#include "ElectricOvenInventory.h"
#include "ChestInventory.h"
#include "WorbenchInventory.h"
#include "Wire.h"
#include "EnergySprite.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"

class Player : public Sprite
{
private:
	Functions functions;
	// Скорость ходьбы/бега
	float run;

public:
	// Инвентарь
	Inventory inventory;

	// Угол игрока
	int angle;
	bool isOpenInventory;
	int whatTypeInventoryOpen;
	int whatNumberInventoryOpen;

	Player(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_fieldSizeOne">Размер одной ячейки</param>
	/// <param name="imageFileName">Имя файла картинки</param>
	/// <param name="_position">Позиция</param>
	/// <param name="_colorsInventory">Базовые цвета инвентаря</param>
	/// <param name="_textures">Текстуры предметов</param>
	Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		std::string imageFileName, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);


	// Ходьба игрока
	void Move();
	//Каждый кадр
	void Update();
	// Проверить наличие объекта перед игроком
	bool PutObject(std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>& ovens,
		std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>& electricOvens,
		std::vector<std::shared_ptr<StaingObject<ChestInventory>>>& chests,
		std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>& workbenches,
		std::vector<std::shared_ptr<Wire>>& wires,
		std::vector<std::shared_ptr<EnergySprite<EnergyStorageInventory>>>& energyStorages,
		std::vector<std::shared_ptr<EnergySprite<EnergyHandGeneratorInventory>>>& energyHandGenerators,
		std::vector<std::shared_ptr<EnergySprite<EnergyCoalGeneratorInventory>>>& energyCoalGenerators);
	// Отрисовка
	void Draw(sf::Vector2f cameraPosition);
};

