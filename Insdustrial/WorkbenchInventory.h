#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"

#include "Inventory.h"
#include "ObjectInventory.h"
#include "TransferItemObjectInventory.h"

#include "StaticSprites.h"

class WorkbenchInventory : public ObjectInventory, public TransferItemObjectInventory
{
public:
	// ������ � ����������
	std::vector<std::vector<CellInInventory>> cells;
	// ��������� (���������� �������)
	CellInInventory madeItemCell;
	// ����� ���� ������
	std::vector<std::vector<std::vector<int>>> collectionCraft;
	std::vector<std::vector<int>> collectionResult;

	WorkbenchInventory(){}
	WorkbenchInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	// �������� ����� ����� (� ������ ��������� ��� ���������� ����)
	void AddCraft(
		int craft1, int craft2, int craft3,
		int craft4, int craft5, int craft6,
		int craft7, int craft8, int craft9,
		int result, int quantity);
	// �������� ��������� ����� (��� ������ ���� �������, �� ����� � ������ ������)
	void AddSingleCraft(int craft, int result, int quantity);
	// �������� ��������� ����� (��� ������ 4 ���������� �������� ������������, �� ����� � 4 ��������� ���������)
	void AddQuadroSimpleCraft(int craft, int result, int quantity);
	// �������� ��������� ����� (��� ������ 4 ��������� �������� ������������, �� ����� � 4 ��������� ���������)
	void AddQuadroCraft(int craft1, int craft2, int craft3, int craft4, int result, int quantity);
	// �������� ����� � ���� ������������ ����� �� ����
	void AddVerticalCraft(int craft1, int craft2, int craft3, int result, int quantity);
	// �������� ����� � ���� ������������ ����� �� ����
	void AddVerticalDualCraft(int craft1, int craft2, int result, int quantity);
	// �������� ����� � ���� �������������� ����� �� ����
	void AddHorizontalDualCraft(int craft1, int craft2, int result, int quantity);
	// ���������� ���� ��������� ������� � ����� ���������� (�������� ��� ������)
	void AddAllDualCraft(int craft1, int craft2, int result, int quantity);
	// �������� ������ ������
	void Craft();
	void PlayUpdate(){ }
	// ���������
	void Draw();
	// ������ ���������� � ����
	void WhileOpen(Inventory& playerInventory);

};

