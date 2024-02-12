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
#include "EnergySprite.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"

class Player : public Sprite
{
private:
	Functions functions;
	// �������� ������/����
	float run;

public:
	// ���������
	Inventory inventory;

	// ���� ������
	int angle;
	bool isOpenInventory;
	int whatTypeInventoryOpen;
	int whatNumberInventoryOpen;

	Player(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_fieldSizeOne">������ ����� ������</param>
	/// <param name="imageFileName">��� ����� ��������</param>
	/// <param name="_position">�������</param>
	/// <param name="_colorsInventory">������� ����� ���������</param>
	/// <param name="_textures">�������� ���������</param>
	Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		std::string imageFileName, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);


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
		std::vector<std::shared_ptr<EnergySprite<EnergyStorageInventory>>>& energyStorages,
		std::vector<std::shared_ptr<EnergySprite<EnergyHandGeneratorInventory>>>& energyHandGenerators,
		std::vector<std::shared_ptr<EnergySprite<EnergyCoalGeneratorInventory>>>& energyCoalGenerators);
	// ���������
	void Draw(sf::Vector2f cameraPosition);
};

