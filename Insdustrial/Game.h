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
#include "Functions/OldButton.h"
#include "Functions/Checks.h"

#include "Assets.h"

#include "Field.h"
#include "Player.h"
#include "StaingObject.h"
#include "EnergyObject.h"
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


class Game
{
private:
	//// ������������
	std::shared_ptr<sf::RenderWindow> rw;
	// ����� �����
	sf::String screen;
	// ������ �������
	sf::Vector2u sizeW;
	// ����
	sf::Clock clock;
	// ������� ����
	sf::Vector2i mousePosition;
	// �������� ����
	int mouseWheel;
	// ����� � �������
	sf::Time fps;
	// ��������� 10 ��������� ������ � �������
	std::vector<int> lastFpsS = std::vector<int>();
	// ������� Fps
	float avarageFps = 0;
	// ����� ������ Fps �� ����� (�� 0, �� ������� FpsS
	int whatNumberFps;

	Assets assets;
	
	std::vector<Checks> ch;
	// �������
	Functions functions;
	// ������ ������
	std::vector<OldButton> oldButtons;

	// ������� ������
	sf::Vector2f cameraPosition;
	// ������� ����� �� �����
	sf::Vector2i mousePositionGrid;
	const float maxMouseDistance = 4.2f;

	// �����
	Player player;

	// ����������� ����� ��� ����������
	std::vector<sf::Color> colorsInventory;

	// ��� �� ���������
	std::vector<sf::Drawable*> drawables;

	std::vector<IPlayUpdatable*> playUpdatables;

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
	// �������� ���� ��� ����������
	void LoadingForDev();
	// �������� ���� ��� ����
	void LoadingForPlay();
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
	// ��������
	void Gameplay();
	// ����� ��������� ������
	void WhatInventory();

	void AllDraw();
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

