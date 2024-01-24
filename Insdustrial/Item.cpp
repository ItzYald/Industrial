#include "Item.h"

Item::Item(int _number, int _quantity)
{
	NumberUpdate(_number);
	quantity = _quantity;
}

void Item::NumberUpdate(int _number)
{
	number = _number;
	isBurn = 0;
	isFuel = 0;
	switch (number)
	{
	case 1:
		name = L"Железная руда";
		isBurn = 4;
		break;
	case 2:
		name = L"Печка";
		break;
	case 3:
		name = L"Уголь";
		isFuel = 8;
		break;
	case 4:
		name = L"Железный слиток";
		break;
	case 5:
		name = L"Сундук";
		break;
	case 6:
		name = L"Железный блок";
		break;
	case 7:
		name = L"Древесина";
		isFuel = 2;
		isBurn = 3;
		break;
	case 8:
		name = L"Верстак";
		break;
	case 9:
		name = L"Доски";
		isFuel = 1;
		break;
	case 10:
		name = L"Редстоун";
		break;
	case 11:
		name = L"Электропеч";
		break;
	default:
		break;
	}
}
