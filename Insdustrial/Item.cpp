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
		name = L"Железная руда";
		whatBurn = 4;
		whatCrush = sf::Vector2i(23, 2);
		break;
	case ItemEnum::oven:
		name = L"Печка";
		break;
	case ItemEnum::coal:
		name = L"Уголь";
		whatFuel = 16;
		break;
	case ItemEnum::ironIngot:
		name = L"Железный слиток";
		whatCrush = sf::Vector2i(23, 1);
		whatCompress = 25;
		break;
	case ItemEnum::chest:
		name = L"Сундук";
		break;
	case ItemEnum::ironBlock:
		name = L"Железный блок";
		break;
	case ItemEnum::wood:
		name = L"Древесина";
		whatFuel = 4;
		whatBurn = 3;
		break;
	case ItemEnum::workbench:
		name = L"Верстак";
		break;
	case ItemEnum::planks:
		name = L"Доски";
		whatFuel = 2;
		break;
	case ItemEnum::accumulator:
		name = L"Аккумулятор";
		break;
	case ItemEnum::energyOven:
		name = L"Электропеч";
		break;
	case ItemEnum::copperWire:
		name = L"Медный провод";
		break;
	case ItemEnum::energyStorage:
		name = L"Энергохранилище";
		break;
	case ItemEnum::copperIngot:
		name = L"Медный слиток";
		whatCompress = 26;
		break;
	case ItemEnum::ironWire:
		name = L"Железный провод";
		break;
	case ItemEnum::handEnergyGenerator:
		name = L"Ручной энергогенератор";
		break;
	case ItemEnum::coalEnergyGenerator:
		name = L"Угольный энергогенератор";
		break;
	case ItemEnum::mechanismBody:
		name = L"Корпус механизма";
		break;
	case ItemEnum::tinIngot:
		name = L"Оловяный слиток";
		whatCompress = 27;
		break;
	case ItemEnum::tinWire:
		name = L"Оловяный провод";
		break;
	case ItemEnum::copperOre:
		name = L"Медная руда";
		whatBurn = 14;
		break;
	case ItemEnum::tinOre:
		name = L"Оловяная руда";
		whatBurn = 19;
		break;
	case ItemEnum::crushedIronOre:
		name = L"Измельченная железная руда";
		whatBurn = 4;
		break;
	case ItemEnum::crusher:
		name = L"Дробитель";
		break;
	case ItemEnum::ironPlate:
		name = L"Железная пластина";
		break;
	case ItemEnum::copperPlate:
		name = L"Медная пластина";
		break;
	case ItemEnum::tinPlate:
		name = L"Оловяная пластина";
		break;
	case ItemEnum::compressor:
		name = L"Компрессор";
		break;
	case ItemEnum::chip:
		name = L"Электросхема";
		break;
	case ItemEnum::stick:
		name = L"Палка";
		break;
	case ItemEnum::hammer:
		name = L"Молот";
		isReusable = true;
		break;
	case ItemEnum::mine:
		name = L"Автошахта";
		break;
	}
}