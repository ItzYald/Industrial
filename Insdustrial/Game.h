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


class Game
{
private:
	//// ������������
	std::shared_ptr<sf::RenderWindow> rw;
	// ����
	sf::CircleShape circle;
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
	//
	std::vector<Checks> ch;
	// �������
	Functions functions;
	// ������ ������
	std::vector<Button> buttons;
	// ����
	sf::Clock clock;

	// ������� ������
	sf::Vector2f cameraPosition;

	// �����
	Player player;

	// ������ ���� ��������
	// std::vector<std::shared_ptr<StaingObject<OvenInventory>>> objects;
	// ������ �����
	std::vector<std::shared_ptr<StaingObject<CoalOvenInventory>>> coalOvens;
	// ������ ������������� �����
	std::vector<std::shared_ptr<StaingObject<ElectricOvenInventory>>> electricOvens;
	// ������ ��������
	std::vector<std::shared_ptr<StaingObject<ChestInventory>>> chests;
	// ������ ���������
	std::vector<std::shared_ptr<StaingObject<WorkbenchInventory>>> workbenches;
	// ������ ��������
	std::vector<std::shared_ptr<Wire>> wires;

	//std::vector<std::shared_ptr<Object>> objects;

	std::map<std::string, sf::Texture> textures;


	// ����
	Field field;

public:
	Game(){ }
	Game(sf::RenderWindow& _rw);
	// ������������ �������� ����������
	void LoadingApp1();
	// �������� ����������
	void LoadingApp();
	// ������������ �������� ��������
	void LoadingScreen(std::string nextScreen);
	// �������� ��������
	void LoadingPlay();
	// �������� ��������
	void UnloadingPlay(std::string nextScreen);
	// ��������� �������� ����
	void DrawPlay();
	// �������
	void CloseInventory();
	// ��������� �����
	void OvenInventoryFun();
	// ��������� ������������
	void ElectricOvenInventoryFun(){ }
	// ��������� �������
	void ChestInventoryFun();
	// ��������� ��������
	void WorkbenchInventoryFun();
	// ��������� ������ �� ������������ ����������
	void PutObject(sf::Vector2f position);
	// ��������
	void Drive();
	// ����
	void Play();
	// ����
	void Menu();
	// ���������� ����
	void Next();
	// ���������� ����
	void Circle(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	// ������� ����
	void Mouse(sf::Event& e, sf::RenderWindow& rw);
	// ���������� �������� ����
	void MouseWheelScrolled(int _mouseWheel);

	void EndProgramm(){}
};

