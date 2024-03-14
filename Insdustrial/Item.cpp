#include "Item.h"

Item::Item(int _number, int _quantity)
{
	NumberUpdate(_number);
	quantity = _quantity;
}

void Item::NumberUpdate(int _number)
{
	number = (ItemEnum)_number;
	whatBurn = ItemEnum::empty;
	whatFuel = ItemEnum::empty;
	whatCrush = sf::Vector2i(0, 0);
	whatCompress = ItemEnum::empty;
	isReusable = 0;
	switch (number)
	{
	case ItemEnum::empty:
		quantity = 0;
		break;
	case ItemEnum::ironOre:
		name = L"�������� ����";
		whatBurn = ItemEnum::ironIngot;
		whatCrush = sf::Vector2i(23, 2);
		break;
	case ItemEnum::oven:
		name = L"�����";
		break;
	case ItemEnum::coal:
		name = L"�����";
		whatFuel = 16;
		break;
	case ItemEnum::ironIngot:
		name = L"�������� ������";
		whatCrush = sf::Vector2i(23, 1);
		whatCompress = ItemEnum::ironPlate;
		break;
	case ItemEnum::chest:
		name = L"������";
		break;
	case ItemEnum::ironBlock:
		name = L"�������� ����";
		break;
	case ItemEnum::wood:
		name = L"���������";
		whatFuel = 4;
		whatBurn = ItemEnum::coal;
		break;
	case ItemEnum::workbench:
		name = L"�������";
		break;
	case ItemEnum::planks:
		name = L"�����";
		whatFuel = 2;
		break;
	case ItemEnum::accumulator:
		name = L"�����������";
		break;
	case ItemEnum::energyOven:
		name = L"����������";
		break;
	case ItemEnum::copperWire:
		name = L"������ ������";
		break;
	case ItemEnum::energyStorage:
		name = L"���������������";
		break;
	case ItemEnum::copperIngot:
		name = L"������ ������";
		whatCompress = ItemEnum::copperPlate;
		break;
	case ItemEnum::ironWire:
		name = L"�������� ������";
		break;
	case ItemEnum::handEnergyGenerator:
		name = L"������ ���������������";
		break;
	case ItemEnum::coalEnergyGenerator:
		name = L"�������� ���������������";
		break;
	case ItemEnum::mechanismBody:
		name = L"������ ���������";
		break;
	case ItemEnum::tinIngot:
		name = L"�������� ������";
		whatCompress = ItemEnum::tinPlate;
		break;
	case ItemEnum::tinWire:
		name = L"�������� ������";
		break;
	case ItemEnum::copperOre:
		name = L"������ ����";
		whatBurn = ItemEnum::copperIngot;
		break;
	case ItemEnum::tinOre:
		name = L"�������� ����";
		whatBurn = ItemEnum::tinIngot;
		break;
	case ItemEnum::crushedIronOre:
		name = L"������������ �������� ����";
		whatBurn = ItemEnum::ironIngot;
		break;
	case ItemEnum::crusher:
		name = L"���������";
		break;
	case ItemEnum::ironPlate:
		name = L"�������� ��������";
		break;
	case ItemEnum::copperPlate:
		name = L"������ ��������";
		break;
	case ItemEnum::tinPlate:
		name = L"�������� ��������";
		break;
	case ItemEnum::compressor:
		name = L"����������";
		break;
	case ItemEnum::chip:
		name = L"������������";
		break;
	case ItemEnum::stick:
		name = L"�����";
		break;
	case ItemEnum::hammer:
		name = L"�����";
		isReusable = true;
		break;
	case ItemEnum::mine:
		name = L"���������";
		break;
	case ItemEnum::stone:
		name = L"������";
		whatCrush = sf::Vector2i(ItemEnum::flint, 1);
		break;
	case ItemEnum::flint:
		name = L"�������";
		break;
	}
}