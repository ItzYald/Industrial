#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"
#include "Functions/Checks.h"

#include "Wire.h"
#include "Field.h"
#include "Player.h"
#include "StaingObject.h"
// ���������
#include "CoalOvenInventory.h"
#include "ElectricOvenInventory.h"
#include "ChestInventory.h"
#include "WorbenchInventory.h"
#include "EnergyStorageInventory.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"

#include "EnergySprite.h"


class Game
{
private:
	//// ������������
	std::shared_ptr<sf::RenderWindow> rw;
	// ����� �����
	sf::String screen;
	// ������ �������
	sf::Vector2u sizeW;
	// �����
	sf::Text text;
	// �����
	sf::Font font;
	// ������� ����
	sf::Vector2i mousePosition;
	// �������� ����
	int mouseWheel;
	
	std::vector<Checks> ch;
	// �������
	Functions functions;
	// ������ ������
	std::vector<Button> buttons;
	// ����
	sf::Clock clock;

	// ������� ������
	sf::Vector2f cameraPosition;
	// ������� ����� �� �����
	sf::Vector2i mousePositionGrid;
	const float maxMouseDistance = 4.2f;

	// �����
	Player player;

	// ����������� ����� ��� ����������
	std::vector<sf::Color> colorsInventory;

	// ������ �����
	std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>> coalOvens;
	// ������ ������������� �����
	std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>> electricOvens;
	// ������ ��������
	std::vector<std::shared_ptr<StaingObject<ChestInventory>>> chests;
	// ������ ���������
	std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>> workbenches;
	// ������ �������� �������
	std::vector<std::shared_ptr<StaingObject<EnergyStorageInventory>>> energyStorages;
	// ������ ������ �����������������
	std::vector<std::shared_ptr<EnergySprite<EnergyHandGeneratorInventory>>> energyHandGenerators;
	// ������ ������ �����������������
	std::vector<std::shared_ptr<EnergySprite<EnergyCoalGeneratorInventory>>> energyCoalGenerators;

	// ������ ��������
	std::vector<std::shared_ptr<Wire>> wires;
	
	// ������ ���� �������
	std::map<std::string, sf::Texture> textures;
	// ������ ������� ��������� (� ���������)
	std::vector<sf::Texture> itemTextures;
	// ������ ������� ������ � ���������
	std::map<std::string, sf::Texture> texturesInInventory;


	// ����
	Field field;

public:
	Game(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	Game(sf::RenderWindow& _rw);
	// �������� ����������
	void LoadingApp();
	// ������������ (�������) �������� ��������
	void LoadingScreen(std::string nextScreen);
	// �������� �������� ����� ���������� �� �����
	void LoadColorInventoryFromFile();
	// �������� ��������
	void LoadingPlay();
	/// <summary>
	/// �������� �������� �� ������
	/// (������� �������� � ��������� ��������)
	/// </summary>
	/// <param name="nextScreen">����� � ������� ��������� ����� �������� ��������</param>
	void UnloadingPlay(std::string nextScreen);
	// ��������� �������� ����
	void DrawPlay();

	void DrawDrive();
	// �������
	void CloseInventory();
	// ��������� ������ �� ������������ ����������
	void PutObject(sf::Vector2f position);
	// ��������
	void Drive();
	/// <summary>������� �������� �������</summary>
	/// <param name="originalEnergy">������ �� ������� �������,������ ��������</param>
	/// <param name="power">�������� �������� �������</param>
	/// <param name="nextEnergy">������ �� ������� ����, �������� ��������</param>
	/// <param name="nextMaxEnergy">������������ ������� �������, �������� ��������</param>
	void TransEnergy(float &originalEnergy, int power, float& nextEnergy, int nextMaxEnergy);
	/// <summary>������ ������� �������� �������</summary>
	/// <param name="nextPosition">������� �������, �������� �������� �������</param>
	/// <param name="energy">����� ������� ��������</param>
	/// <param name="power">������� �������� �������</param>
	void CheckNextEnergyObject(sf::Vector2i nextPosition, float& energy, int power);
	/// <summary>����� ������� ����������</summary>
	/// <param name="originalPosition">������� ������� ����������, ������� �������� �������</param>
	/// <param name="nextPosition">������� ������� ����������, �������� �������� �������</param>
	/// <param name="typeObject">��� ����������, ������� �������� ������� (0 - ������, 1 - ���������)</param>
	void CheckTypeTrans(sf::Vector2i originalPosition, sf::Vector2i nextPosition, int typeObject);
	/// <summary>�������� �������� ��������� ��� �������, ���� ���������� �������</summary>
	/// <param name="turn">������� �������</param>
	sf::Vector2i CheckTurnEnergy(int turn);
	/// ����� ������ ��������� �� ����������� (����� ���������� �������)
	void WhatObjectTransEnergy();
	// ����
	void Play();
	// ����
	void Menu();
	// ���������� ����
	void Next();
	// ������� ����
	void Mouse(sf::Event& e, sf::RenderWindow& rw);
	// ���������� �������� ����
	void MouseWheelScrolled(int _mouseWheel);
};

