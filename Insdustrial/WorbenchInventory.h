#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "Inventory.h"
#include "ObjectInventory.h"

#include "StaticSprites.h"

class WorkbenchInventory : ObjectInventory
{
public:
	// �������� � ���� ��� ������
	std::vector<std::vector<ItemStruct>> items;
	// ��������� (���������� �������)
	ItemStruct madeItem;
	// ����� ���� ������
	std::vector<std::vector<std::vector<int>>> collectionCraft;
	std::vector<std::vector<int>> collectionResult;

	WorkbenchInventory(){}
	WorkbenchInventory(std::shared_ptr<sf::RenderWindow> _rw);

	// �������� ����� ����� (� ������ ��������� ��� ���������� ����)
	void AddCraft(
		int craft1, int craft2, int craft3, int craft4, int craft5, int craft6, int craft7, int craft8, int craft9,
		int result, int quantity);
	// �������� ��������� ����� (��� ������ ���� �������, �� ����� � ������ ������)
	void AddSingleCraft(int craft, int result, int quantity);
	// �������� ��������� ����� (��� ������ 4 ���������� �������� ������������, �� ����� � 4 ��������� ���������)
	void AddQuadroSimpleCraft(int craft, int result, int quantity);
	// �������� ��������� ����� (��� ������ 4 ��������� �������� ������������, �� ����� � 4 ��������� ���������)
	void AddQuadroCraft(int craft1, int craft2, int craft3, int craft4, int result, int quantity);
	// �������� ������ ������
	void Craft();
	// ���������
	void Draw();
	// ������ ���������� � ����
	void Update(Inventory& playerInventory);

};

