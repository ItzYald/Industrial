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
// ���������
#include "CoalOvenInventory.h"
#include "ElectricOvenInventory.h"
#include "ChestInventory.h"
#include "WorbenchInventory.h"
#include "Wire.h"
#include "EnergyStorageSprite.h"

class Player : public Sprite
{
private:
	Functions functions;

public:
	// ���������
	Inventory inventory;

	// ���� ������
	int angle;
	bool isOpenInventory;
	int whatTypeInventoryOpen;
	int whatNumberInventoryOpen;

	float run;

	Player(){ }
	Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		std::string imageFileName, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);

	std::vector<Button> buttons;


	// ������ ������
	void Move();
	//������ ����
	void Update();
	// ��������� ������� ������� ����� �������
	bool PutObject(std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>& ovens,
		std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>& electricOvens,
		std::vector<std::shared_ptr<StaingObject<ChestInventory>>>& chests,
		std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>& workbenches,
		std::vector<std::shared_ptr<Wire>>& wires,
		std::vector<std::shared_ptr<EnergyStorageSprite>>& energyStorages);
	// ���������
	void Draw(sf::Vector2f cameraPosition);
};

