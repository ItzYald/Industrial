#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Object.h"
#include "Item.h"
#include "IStaingObject.h"
#include "IEnergyObject.h"

#include "Player.h"

#include "Assets.h"

#include "EnergyObject.h"
#include "StaingObject.h"
// ���������
#include "CoalOvenInventory.h"
#include "ChestInventory.h"
#include "WorkbenchInventory.h"
#include "MineInventory.h"

#include "ElectricOvenInventory.h"
#include "CrusherInventory.h"
#include "CompressorInventory.h"
#include "EnergyStorageInventory.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"
#include "WireInventory.h"

class Field : public sf::Drawable
{
public:
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	// ������ ���� (���-�� ������)
	sf::Vector2i size;
	// ������ �����
	sf::Sprite sprite;
	// ������ ����� ������
	int sizeOne;
	// ������ ����
	sf::Vector2u sizeW;

	Assets* assets;

	std::vector<std::vector<sf::Sprite>> sprites;
	
	sf::Vector2f* cameraPosition;

	// ��������� �� ������ ���� ��������
	std::vector<Object*> objects;
	std::vector<std::vector<int>> newEnergyObjectsNumbers;
	std::vector<std::vector<int>> transEnergyObjectsNumbers;

	// ��� ������� �������
	std::vector<IStaingObject*> simpleObjects;
	// ��� �������������� �������
	std::vector<IEnergyObject*> energyObjects;
	// ��� ������� ���������� �������
	std::vector<IEnergyObject*> transEnergyObjects;

	// ������ ��������� (�������������, ����, �����, ������...)
	Functions functions;

	Field(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_size">������ ���� (���-�� ������)</param>
	/// <param name="_sizeOne">������ ����� ������</param>
	/// <param name="_sizeW">������ ����</param>
	/// <param name="texture">��������� �����</param>
	Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition,
		sf::Vector2i _size, int _sizeOne,
		sf::Vector2u _sizeW, sf::Texture* _texture, Assets& _assets);

	void LoadingForDev(std::vector<sf::Color>& colorsInventory);

	void LoadingForPlay(std::vector<sf::Color>& colorsInventory);

	void LoadingPlay();

	void UnloadingPlay();
	/// <summary>��������� �����</summary>
	/// <param name="cameraPosition">������� ������</param>
	void Draw();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void GamePlay(Player& player);

	void Next();

	bool ObjectHere(sf::Vector2i mousePositionGrid, Item& chooseItem);
	// � � ������ �� ����� ��� ���, ��� ��� �������� ����� �����
	sf::Vector2i WhatActive(sf::Vector2i mousePosition);


};

