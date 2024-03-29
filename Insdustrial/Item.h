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
	mine,
	stone,
	flint,
	pipe
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
	ItemEnum whatBurn;
	// ����� �� ���� �������� � ������� ���� �������
	int whatFuel;
	// ����� �� ���� ������ � �� ��� ��������
	ItemEnum whatCompress;
	// ����� �� ��������� � �� ��� �������� (x - �� ��� ��������, y - ������� ���������)
	sf::Vector2i whatCrush;
	// ����������� �� ��� ������ 
	bool isReusable;
	
	Item(){}
	Item(int _number, int _quantity);

	/// <summary>���������� id ��������</summary>
	/// <param name="_number">id ��������</param>
	void NumberUpdate(int _number);

};

