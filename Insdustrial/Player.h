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
#include "CrusherInventory.h"
#include "CompressorInventory.h"
#include "ChestInventory.h"
#include "WorbenchInventory.h"
#include "Wire.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"

class Player : public Sprite
{
private:
	Functions functions;
	// �������� ������/����
	float run;

	sf::Sprite sprite1;
	sf::Sprite sprite2;

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
	/// <param name="_texture">��������</param>
	/// <param name="_position">�������</param>
	/// <param name="_colorsInventory">������� ����� ���������</param>
	/// <param name="_textures">�������� ���������</param>
	Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& _texture, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _itemTextures);

	// ������ ������
	void Move();
	//������ ����
	void Update();

	void Next() override{ }
	// ��������� ������� ������� ����� �������
	bool PutObject(sf::Vector2i mousePositionGrid, std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>>& ovens,
		std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>>& electricOvens,
		std::vector<std::shared_ptr<StaingObject<CrusherInventory>>>& crushers,
		std::vector<std::shared_ptr<StaingObject<CompressorInventory>>>& compressors,
		std::vector<std::shared_ptr<StaingObject<ChestInventory>>>& chests,
		std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>>& workbenches,
		std::vector<std::shared_ptr<Wire>>& wires,
		std::vector<std::shared_ptr<StaingObject<EnergyStorageInventory>>>& energyStorages,
		std::vector<std::shared_ptr<StaingObject<EnergyHandGeneratorInventory>>>& energyHandGenerators,
		std::vector<std::shared_ptr<StaingObject<EnergyCoalGeneratorInventory>>>& energyCoalGenerators);
	// ���������
	void Draw(sf::Vector2f cameraPosition) override;
};

