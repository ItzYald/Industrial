#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Object.h"
#include "Item.h"

#include "Player.h"

#include "Assets.h"
#include "IPlayUpdatable.h"

#include "NotTransferItemEnergyObject.h"
#include "NotTransferItemSimpleObject.h"
#include "TransferItemSimpleObject.h"
#include "TransferItemEnergyObject.h"
// ���������
#include "CoalOvenInventory.h"
#include "ChestInventory.h"
#include "WorkbenchInventory.h"
#include "MineInventory.h"

#include "TransferItemObjectInventory.h"

#include "ElectricOvenInventory.h"
#include "CrusherInventory.h"
#include "CompressorInventory.h"
#include "EnergyStorageInventory.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"
#include "PipeInventory.h"
#include "WireInventory.h"

class Field : public sf::Drawable, public IPlayUpdatable, public GamePlayUpdatable
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
	// ������ ��������� (�������������, ����, �����, ������...)
	Functions functions;

	Assets* assets;

	std::vector<std::vector<sf::Sprite>> sprites;

	Player* player;
	
	sf::Vector2f* cameraPosition;

	// ��������� �� ������ ���� ��������
	std::vector<Object*> objects;
	std::vector<std::vector<int>> energyObjectsNumbers;
	std::vector<std::vector<int>> transferEnergyObjectsNumbers;
	std::vector<std::vector<int>> transferItemObjectsNumbers;

	// ��� �� ���������
	std::vector<sf::Drawable*>* drawables;

	// ��� ������� �������
	std::vector<INotTransferItemSimpleObject*> simpleObjects;
	// ��� �������������� �������
	std::vector<INotTransferItemEnergyObject*> energyObjects;
	// ��� ������� ���������� �������
	std::vector<INotTransferItemEnergyObject*> transferEnergyObjects;

	std::vector<TransferItemObjectInventory*> transferItemObjectsInventories;
	std::vector<Object*> transferItemObjects;
	std::vector<ITransferItemSimpleObject*> transferItemSimpleObjects;
	std::vector<ITransferItemEnergyObject*> transferItemEnergyObjects;

	std::vector<IPlayUpdatable*> playUpdatables;

	Field(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_size">������ ���� (���-�� ������)</param>
	/// <param name="_sizeOne">������ ����� ������</param>
	/// <param name="_sizeW">������ ����</param>
	/// <param name="texture">��������� �����</param>
	Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition,
		sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW,
		Assets& _assets, Player& _player, std::vector<sf::Drawable*>& _drawables);

	void LoadingForDev(std::vector<sf::Color>& colorsInventory);

	void LoadingForPlay(std::vector<sf::Color>& colorsInventory);

	void LoadingPlay();

	void UnloadingPlay();
	/// <summary>��������� �����</summary>
	/// <param name="cameraPosition">������� ������</param>
	void Draw();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	/// <summary>
	/// ��������� ������
	/// </summary>
	/// <param name="position">������� �� ������ ���������</param>
	/// <param name="playerCell">����� ������ � ��������� ������</param>
	/// <param name="colorsInventory">����� ��������� (��� �������� � ����������)</param>
	void PutObject(sf::Vector2f position, Item& chooseItem, std::vector<sf::Color>& colorsInventory);

	void GamePlayUpdate() override;

	void TransEnergy(float& originalEnergy, int power, float& nextEnergy, int nextMaxEnergy);
	// ����� ������ ������� �� ������������ �����������, ����������� ��������
	void CheckNextEnergyObject(sf::Vector2i nextPosition, float& energy, int power);

	void WhatObjectTransEnergy();
	
	void TransItem(Item* transferItem, Item* acceptItem);
	// ����� ������ ������� �� ������������ ����������� � ����������� ��������
	void CheckNextItemObject(sf::Vector2i nextPosition, Item* transferItem);

	void WhatObjectTransItem();
	/// <summary>
	/// ���� �������� ������
	/// </summary>
	/// <param name="turn">������� ��������</param>
	/// <returns>�������� ���������</returns>
	sf::Vector2i CheckTurn(int turn);

	void PlayUpdate() override;

	bool ObjectHere(sf::Vector2i mousePositionGrid, Item& chooseItem);
	// � � ������ �� ����� ��� ���, ��� ��� �������� ����� �����
	sf::Vector2i WhatActive(sf::Vector2i mousePosition);
};

