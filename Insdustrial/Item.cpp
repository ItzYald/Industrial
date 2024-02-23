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
		name = L"�������� ����";
		whatBurn = 4;
		whatCrush = sf::Vector2i(23, 2);
		break;
	case 2:
		name = L"�����";
		break;
	case 3:
		name = L"�����";
		whatFuel = 16;
		break;
	case 4:
		name = L"�������� ������";
		whatCrush = sf::Vector2i(23, 1);
		whatCompress = 25;
		break;
	case 5:
		name = L"������";
		break;
	case 6:
		name = L"�������� ����";
		break;
	case 7:
		name = L"���������";
		whatFuel = 4;
		whatBurn = 3;
		break;
	case 8:
		name = L"�������";
		break;
	case 9:
		name = L"�����";
		whatFuel = 2;
		break;
	case 10:
		name = L"�����������";
		break;
	case 11:
		name = L"����������";
		break;
	case 12:
		name = L"������ ������";
		break;
	case 13:
		name = L"���������������";
		break;
	case 14:
		name = L"������ ������";
		whatCompress = 26;
		break;
	case 15:
		name = L"�������� ������";
		break;
	case 16:
		name = L"������ ���������������";
		break;
	case 17:
		name = L"�������� ���������������";
		break;
	case 18:
		name = L"������ ���������";
		break;
	case 19:
		name = L"�������� ������";
		whatCompress = 27;
		break;
	case 20:
		name = L"�������� ������";
		break;
	case 21:
		name = L"������ ����";
		whatBurn = 14;
		break;
	case 22:
		name = L"�������� ����";
		whatBurn = 19;
		break;
	case 23:
		name = L"������������ �������� ����";
		whatBurn = 4;
		break;
	case 24:
		name = L"���������";
		break;
	case 25:
		name = L"�������� ��������";
		break;
	case 26:
		name = L"������ ��������";
		break;
	case 27:
		name = L"�������� ��������";
		break;
	case 28:
		name = L"����������";
		break;
	case 29:
		name = L"������������";
		break;
	case 30:
		name = L"�����";
		break;
	case 31:
		name = L"�����";
		isReusable = true;
		break;
	}
}
