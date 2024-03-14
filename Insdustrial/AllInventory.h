#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"
#include "Functions/Checks.h"

#include "IPlayUpdatable.h"

#include "StaticSprites.h"

#include "CellInInventory.h"

class AllInventory : public IPlayUpdatable
{
public:
	// ������ ������
	std::vector<OldButton> oldButtons;
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

	std::vector<Checks> ch;

	// ����� ��������� ����� � ��������� (��� ���� � ���� ���� ������ ������)
	// ��� ��������� �������
	void DrawCommon(std::vector<std::vector<CellInInventory>> cells);
	// ��� ���������� �������
	void DrawCommon(std::vector<CellInInventory> cells);
	// ��������� ���������
	virtual void Draw() = 0;
	// ������ (���� ����� ��������� �� ������)
	virtual void PlayUpdate() = 0;

};

