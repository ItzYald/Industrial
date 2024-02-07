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

#include "EnergyStorageSprite.h"


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
	std::vector<std::shared_ptr<EnergyStorageSprite>> energyStorages;

	// ������ ��������
	std::vector<std::shared_ptr<Wire>> wires;
	
	// ������ ���� �������
	std::map<std::string, sf::Texture> textures;
	// ������ ������� ��������� (� ���������)
	std::vector<sf::Texture> itemTextures;


	// ����
	Field field;

public:
	Game(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	Game(sf::RenderWindow& _rw);
	// ������������ (�������) �������� ����������
	void LoadingApp1();
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
	// �������
	void CloseInventory();
	// ��������� ������ �� ������������ ����������
	void PutObject(sf::Vector2f position);
	// ��������
	void Drive();
	/// <summary>�������� �������</summary>
	/// <param name="nextPosition">������� �������, �������� �������� �������</param>
	/// <param name="energy">����� ������� ��������</param>
	/// <param name="power">������� �������� �������</param>
	void TransEnergy(sf::Vector2i nextPosition, int& energy, int power);
	/// <summary>����� ������� ����������</summary>
	/// <param name="originalPosition">������� ������� ����������, ������� �������� �������</param>
	/// <param name="nextPosition">������� ������� ����������, �������� �������� �������</param>
	/// <param name="typeObject">��� ����������, ������� �������� ������� (0 - ������, 1 - ���������)</param>
	void CheckTypeTrans(sf::Vector2i originalPosition, sf::Vector2i nextPosition, int typeObject);
	/// <summary>�������� �������� ��������� ��� �������, ���� ���������� �������</summary>
	/// <param name="turn">������� �������</param>
	sf::Vector2i CheckTurnEnergy(int turn);
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

	void EndProgramm(){}
};

