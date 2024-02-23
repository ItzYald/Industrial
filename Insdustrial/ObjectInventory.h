#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "StaticSprites.h"

#include "CellInInventory.h"

class ObjectInventory
{
public:
	// ������ ������
	std::vector<Button> buttons;
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	// �������
	Functions functions;
	// ������� ����
	sf::Vector2i mousePosition;
	/// ����� ��� ����������
	// ������ ������
	std::vector<sf::Color> colorsInventory;

	StaticSprites itemsSprites;

	// �������� �������� ����� ���������� �� �����
	void LoadColorInventoryFromFile();
	// ����� ��������� ����� � ��������� (��� ���� � ���� ���� ������ ������)
	// ��� ��������� �������
	void DrawCommon(std::vector<std::vector<CellInInventory>> cells);
	// ��� ���������� �������
	void DrawCommon(std::vector<CellInInventory> cells);
	// ��������� ���������
	virtual void Draw() = 0;
	// ������ (���� ����� ��������� �� ������)
	virtual void Next() = 0;
	/// <summary>���� ��������� ������</summary>
	/// <param name="playerInventory">��������� ������</param>
	//virtual void Update(Inventory& playerInventory) = 0;

};

