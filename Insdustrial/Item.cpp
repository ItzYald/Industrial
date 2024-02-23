#include "Item.h"

Item::Item(int _number, int _quantity)
{
	NumberUpdate(_number);
	quantity = _quantity;
}

void Item::NumberUpdate(int _number)
{
	number = _number;
	whatBurn = 0;
	whatFuel = 0;
	whatCrush = sf::Vector2i(0, 0);
	whatCompress = 0;
	isReusable = 0;
	switch (number)
	{
	case 0:
		quantity = 0;
		break;
	case 1:
		name = L"Железная руда";
		whatBurn = 4;
		whatCrush = sf::Vector2i(23, 2);
		break;
	case 2:
		name = L"Печка";
		break;
	case 3:
		name = L"Уголь";
		whatFuel = 16;
		break;
	case 4:
		name = L"Железный слиток";
		whatCrush = sf::Vector2i(23, 1);
		whatCompress = 25;
		break;
	case 5:
		name = L"Сундук";
		break;
	case 6:
		name = L"Железный блок";
		break;
	case 7:
		name = L"Древесина";
		whatFuel = 4;
		whatBurn = 3;
		break;
	case 8:
		name = L"Верстак";
		break;
	case 9:
		name = L"Доски";
		whatFuel = 2;
		break;
	case 10:
		name = L"Аккумулятор";
		break;
	case 11:
		name = L"Электропеч";
		break;
	case 12:
		name = L"Медный провод";
		break;
	case 13:
		name = L"Энергохранилище";
		break;
	case 14:
		name = L"Медный слиток";
		whatCompress = 26;
		break;
	case 15:
		name = L"Железный провод";
		break;
	case 16:
		name = L"Ручной энергогенератор";
		break;
	case 17:
		name = L"Угольный энергогенератор";
		break;
	case 18:
		name = L"Корпус механизма";
		break;
	case 19:
		name = L"Оловяный слиток";
		whatCompress = 27;
		break;
	case 20:
		name = L"Оловяный провод";
		break;
	case 21:
		name = L"Медная руда";
		whatBurn = 14;
		break;
	case 22:
		name = L"Оловяная руда";
		whatBurn = 19;
		break;
	case 23:
		name = L"Измельченная железная руда";
		whatBurn = 4;
		break;
	case 24:
		name = L"Дробитель";
		break;
	case 25:
		name = L"Железная пластина";
		break;
	case 26:
		name = L"Медная пластина";
		break;
	case 27:
		name = L"Оловяная пластина";
		break;
	case 28:
		name = L"Компрессор";
		break;
	case 29:
		name = L"Электросхема";
		break;
	case 30:
		name = L"Палка";
		break;
	case 31:
		name = L"Молот";
		isReusable = true;
		break;
	}
}
