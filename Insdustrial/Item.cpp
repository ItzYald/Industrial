#include "Item.h"

Item::Item(int _number, int _quantity)
{
	NumberUpdate(_number);
	quantity = _quantity;
}

void Item::NumberUpdate(int _number)
{
	number = (ItemEnum)_number;
	whatBurn = 0;
	whatFuel = 0;
	whatCrush = sf::Vector2i(0, 0);
	whatCompress = 0;
	isReusable = 0;
	switch (number)
	{
	case ItemEnum::empty:
		quantity = 0;
		break;
	case ItemEnum::ironOre:
		name = L"�������� ����";
		whatBurn = 4;
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
		whatCompress = 25;
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
		whatBurn = 3;
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
		whatCompress = 26;
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
		whatCompress = 27;
		break;
	case ItemEnum::tinWire:
		name = L"�������� ������";
		break;
	case ItemEnum::copperOre:
		name = L"������ ����";
		whatBurn = 14;
		break;
	case ItemEnum::tinOre:
		name = L"�������� ����";
		whatBurn = 19;
		break;
	case ItemEnum::crushedIronOre:
		name = L"������������ �������� ����";
		whatBurn = 4;
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
	}
}