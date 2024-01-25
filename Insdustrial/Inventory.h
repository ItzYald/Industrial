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
#include "ObjectInventory.h"

class Inventory : public ObjectInventory
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
	Inventory(std::shared_ptr<sf::RenderWindow> _rw);
	// ������� ������
	void DeleteButtons();
	// ��������� ���������
	void Draw();
	// �������� ���������
	void Update();
	// ��������� � �������� ����������� ��������� (������ � ���� ���������, ������� ���� �� ��������)
	void DrawMiniWorkbench();
	// ��������� ������ ����� ��������� (�� ����� ��������)
	void DrawNear(int mouseWheel);
	

};

