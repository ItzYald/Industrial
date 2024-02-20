#pragma once
#include "SFML/System.hpp"


class Item
{
public:
	// �������� ��������
	sf::String name;
	// ����� (id) ��������
	int number;
	// ����������
	int quantity;
	// ����� �� � � ����� ������� ������� (� ����� ��������������)
	int whatBurn;
	// ����� �� ���� �������� � ������� ���� �������
	int whatFuel;
	// ����� �� ���� ������ � �� ��� ��������
	int whatCompress;
	// ����� �� ��������� � �� ��� �������� (x - �� ��� ��������, y - ������� ���������)
	sf::Vector2i whatCrush;
	
	Item(){}
	Item(int _number, int _quantity);

	/// <summary>���������� id ��������</summary>
	/// <param name="_number">ID ��������</param>
	void NumberUpdate(int _number);

};

