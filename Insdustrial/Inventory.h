#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"
#include "Functions/Checks.h"

#include "StaticSprites.h"

#include "AllInventory.h"

class Inventory : public AllInventory
{
private:
	std::vector<Checks> ch;

public:
	// ������ � ����������
	std::vector<std::vector<CellInInventory>> cells;
	// ������ � ���������� ���������� ��������
	std::vector<std::vector<CellInInventory>> cellsMiniWorkbench;
	// ������� ��������������� ������
	Item mouseItem;
	// ��������� ������ (��������� ����)
	int choseCell;	


	// ������� �����������
	Inventory(){ }
	// �����������
	Inventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);
	// ��������� ���������
	void Draw() override;
	// � ������ ������ �� ������������
	void Next() override{ }
	// �������� ���������
	void Update();
	// ��������� � �������� ����������� ��������� (������ � ���� ���������, ������� ���� �� ��������)
	void DrawMiniWorkbench();
	// ��������� ������ ����� ��������� (�� ����� ��������)
	void DrawNear(int mouseWheel);
	

};

