#pragma once
#include "SFML/System.hpp"

enum ItemEnum
{
	empty = 0,
	ironOre,
	oven,
	coal,
	ironIngot,
	chest,
	ironBlock,
	wood,
	workbench,
	planks,
	accumulator,
	energyOven,
	copperWire,
	energyStorage,
	copperIngot,
	ironWire,
	handEnergyGenerator,
	coalEnergyGenerator,
	mechanismBody,
	tinIngot,
	tinWire,
	copperOre,
	tinOre,
	crushedIronOre,
	crusher,
	ironPlate,
	copperPlate,
	tinPlate,
	compressor,
	chip,
	stick,
	hammer,
	mine
};

class Item
{
public:
	// �������� ��������
	sf::String name;
	// ����� (id) ��������
	ItemEnum number;
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
	// ����������� �� ��� ������ 
	bool isReusable;
	
	Item(){}
	Item(int _number, int _quantity);

	/// <summary>���������� id ��������</summary>
	/// <param name="_number">ID ��������</param>
	void NumberUpdate(int _number);

};

