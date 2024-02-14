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
		name = L"�������� ����";
		isBurn = 4;
		break;
	case 2:
		name = L"�����";
		break;
	case 3:
		name = L"�����";
		isFuel = 8;
		break;
	case 4:
		name = L"�������� ������";
		break;
	case 5:
		name = L"������";
		break;
	case 6:
		name = L"�������� ����";
		break;
	case 7:
		name = L"���������";
		isFuel = 2;
		isBurn = 3;
		break;
	case 8:
		name = L"�������";
		break;
	case 9:
		name = L"�����";
		isFuel = 1;
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
		break;
	case 20:
		name = L"�������� ������";
		break;
	}
}
