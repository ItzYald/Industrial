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
protected:
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

public:
	void LoadColorInventoryFromFile();
	void DrawCommon(std::vector<std::vector<CellInInventory>> cells);
	void DrawCommon(std::vector<CellInInventory> cells);

};

