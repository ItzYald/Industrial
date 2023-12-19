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

struct ItemStruct
{
	int number;
	int quantity;
};

class Inventory
{
private:
	// ������ ������
	std::vector<Button> buttons;
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;
	std::vector<Checks> ch;

public:

	// ������� ����
	sf::Vector2i mousePosition;

	// �������� � ����������
	std::vector<std::vector<ItemStruct>> items;
	// �������� � ���� 
	std::vector<std::vector<ItemStruct>> itemsMiniWorkbench;
	// ������� ��������������� ������
	ItemStruct mouseItem;

	int choseCell;	

	// �� ������������
	Inventory(){ }
	// �����������
	Inventory(std::shared_ptr<sf::RenderWindow> _rw);

	// ������� ������
	void DeleteButtons();
	// �������� ������
	void AddButtons(bool miniWorkbench);
	// ��������� ���������
	void Draw();
	// �������� ���������
	void Update();
	// ��������� ����������� ��������� (������ � ���� ���������)
	void DrawMiniWorkbench();
	// ��������� ������ ����� ��������� (�� ����� ��������)
	void DrawNear(int mouseWheel);
	

};

