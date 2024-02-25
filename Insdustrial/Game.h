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

#include "Field.h"
#include "Player.h"
#include "StaingObject.h"
#include "EnergyObject.h"
// ���������
#include "CoalOvenInventory.h"
#include "ElectricOvenInventory.h"
#include "CrusherInventory.h"
#include "CompressorInventory.h"
#include "ChestInventory.h"
#include "WorbenchInventory.h"
#include "EnergyStorageInventory.h"
#include "EnergyHandGeneratorInventory.h"
#include "EnergyCoalGeneratorInventory.h"
#include "WireInventory.h"


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

	// ��� �������
	std::vector<Object*> objects;
	// ��� ������� ���������� �������
	std::vector<IEnergyObject*> objectsTransEnergy;
	// ��� �������������� �������
	std::vector<IEnergyObject*> energyObjects;
	// ��� ������� �������
	std::vector<IStaingObject*> simpleObjects;
	
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
	void LoadingImagesPlay();
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

	void DrawGameplay();
	// �������
	void CloseInventory();
	// ��������� ������ �� ������������ ����������
	void PutObject(sf::Vector2f position);
	// ��������
	void Gameplay();
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
	/// <summary>�������� �������� ��������� ��� �������, ���� ���������� �������</summary>
	/// <param name="turn">������� �������</param>
	sf::Vector2i CheckTurnEnergy(int turn);
	/// ����� ������ ��������� �� ����������� (����� ���������� �������)
	void WhatObjectTransEnergy();
	// ����� ��������� ������
	void WhatInventory();
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

