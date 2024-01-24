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
	int isBurn;
	// ����� �� ���� �������� � ������� ���� �������
	int isFuel;
	
	Item(int _number, int _quantity);

	/// <summary>���������� id ��������</summary>
	/// <param name="_number">ID ��������</param>
	void NumberUpdate(int _number);

};

