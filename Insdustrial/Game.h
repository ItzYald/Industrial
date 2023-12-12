#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Functions.h"
#include "Button.h"
#include "Checks.h"

//#include "Sprite.h"
#include "Wire.h"
#include "Field.h"
#include "Player.h"
#include "Inventory.h"
#include "Object.h"
#include "StaingObject.h"
// ���������
#include "OvenInventory.h"
#include "ChestInventory.h"


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
	std::vector<std::shared_ptr<StaingObject<OvenInventory>>> ovens;
	std::vector<std::shared_ptr<StaingObject<ChestInventory>>> chests;
	// ����
	Field field;

public:
	Game(sf::RenderWindow& _rw);
	void LoadingApp1();
	void LoadingImg();
	void LoadingApp();
	// ��������� �������� ����
	void DrawPlay();
	// ��������� �����
	void OvenInventoryFun();
	// ��������� �������
	void ChestInventoryFun();
	// ��������� ������ �� ������������ ����������
	void PutObject(sf::Vector2f position);
	// ��������
	void Drive();
	// ���������
	void Draw();
	// ����
	void Play();
	// ����
	void Menu();
	// ���������� ����
	void Next();
	// ���������� ����
	void Circle(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	// �����
	void Mouse(sf::Event& e, sf::RenderWindow& rw);

	void MouseWheelScrolled(int _mouseWheel);

	void EndProgramm(){}
};

