#include "WorkbenchInventory.h"

WorkbenchInventory::WorkbenchInventory(std::shared_ptr<sf::RenderWindow> _rw,
	std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures)
{
	// ����
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	// ������ ���������
	cells = std::vector< std::vector<CellInInventory>>();
	for (int i = 0; i < 3; i++)
	{
		// ��������� ������
		auto cellsI = std::vector<CellInInventory>();
		for (int j = 0; j < 3; j++)
		{
			cellsI.push_back(CellInInventory(
				rw, sf::Vector2f(350 + 8 + i * 66, 130 + 8 + j * 66), true, _textures, colorsInventory));
		}
		cells.push_back(cellsI);
	}

	// ��������� �������
	madeItemCell = CellInInventory(rw, sf::Vector2f(700, 130 + 8 + 1 * 66), false, _textures, colorsInventory);

	itemsSprites = StaticSprites(_textures);
	// ����� ���� ������
	collectionCraft = std::vector<std::vector<std::vector<int>>>();
	collectionResult = std::vector<std::vector<int>>();

	// �������� ����
	AddCraft(
		4, 4, 4,
		4, 4, 4,
		4, 4, 4,
		6, 1);
	// �����
	AddSingleCraft(7, 9, 4);
	// �������
	AddQuadroSimpleCraft(9, 8, 1);
	// ������
	AddCraft(
		9, 9, 9,
		9, 0, 9,
		9, 9, 9,
		5, 1);
	// ����������
	AddCraft(
		4, 4, 4,
		4, 2, 4,
		4, 4, 4,
		11, 1);
	// ������ ������
	AddVerticalCraft(14, 14, 14, 12, 3);
	// �������� ������
	AddVerticalCraft(4, 4, 4, 15, 3);
	// �������� ������
	AddVerticalCraft(19, 19, 19, 20, 3);
	// ������ ���������������
	AddCraft(
		0, 4, 0,
		9, 9, 9,
		9, 9, 9,
		16, 1);
	// ������ ���������
	AddCraft(
		25, 25, 25,
		25, 0, 25,
		25, 25, 25,
		18, 1);
	// �������� ���������������
	AddCraft(
		0, 0, 0,
		29, 11, 18,
		0, 0, 0,
		17, 1);
	// ������������
	AddCraft(
		12, 12, 12,
		25, 25, 25,
		12, 12, 12,
		29, 1);
	// �����������
	AddCraft(
		0, 14, 0,
		27, 12, 27,
		27, 12, 27,
		10, 1);
	// �����
	AddVerticalDualCraft(9, 9, 30, 2);
	// �����
	AddCraft(
		0, 4, 4,
		0, 30, 4,
		30, 0, 0,
		31, 1);
	// �������� ��������
	AddAllDualCraft(31, 4, 25, 1);
	// ������ ��������
	AddAllDualCraft(31, 14, 26, 1);
	// �������� ��������
	AddAllDualCraft(31, 19, 27, 1);
	// �����
	AddCraft(
		0, 4, 4,
		0, 30, 4,
		30, 0, 0,
		31, 1);
}

void WorkbenchInventory::AddCraft(
	int craft1, int craft2, int craft3,
	int craft4, int craft5, int craft6,
	int craft7, int craft8, int craft9,
	int result, int quantity)
{
	// ��������� ������
	std::vector<std::vector<int>> mas = std::vector<std::vector<int>>();
	for (int j = 0; j < 3; j++)
	{
		// ������ ��������� ������
		std::vector<int> mas2 = std::vector<int>();
		mas2.push_back(craft1);
		mas2.push_back(craft4);
		mas2.push_back(craft7);
		mas.push_back(mas2);
		mas2.clear();
		mas2.push_back(craft2);
		mas2.push_back(craft5);
		mas2.push_back(craft8);
		mas.push_back(mas2);
		mas2.clear();
		mas2.push_back(craft3);
		mas2.push_back(craft6);
		mas2.push_back(craft9);
		mas.push_back(mas2);
		mas2.clear();
	}

	collectionCraft.push_back(mas);
	std::vector<int> resAndQuant = std::vector<int>();
	resAndQuant.push_back(result);
	resAndQuant.push_back(quantity);
	collectionResult.push_back(resAndQuant);
}

void WorkbenchInventory::AddSingleCraft(int craft, int result, int quantity)
{
	AddCraft(craft, 0, 0, 0, 0, 0, 0, 0, 0, result, quantity);
	AddCraft(0, craft, 0, 0, 0, 0, 0, 0, 0, result, quantity);
	AddCraft(0, 0, craft, 0, 0, 0, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0, craft, 0, 0, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0, 0, craft, 0, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0, 0, 0, craft, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0, 0, 0, 0, craft, 0, 0, result, quantity);
	AddCraft(0, 0, 0, 0, 0, 0, 0, craft, 0, result, quantity);
	AddCraft(0, 0, 0, 0, 0, 0, 0, 0, craft, result, quantity);
}

void WorkbenchInventory::AddQuadroSimpleCraft(int craft, int result, int quantity)
{
	AddCraft(craft, craft, 0, craft, craft, 0, 0, 0, 0, result, quantity);
	AddCraft(0, craft, craft, 0, craft, craft, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0, craft, craft, 0, craft, craft, 0, result, quantity);
	AddCraft(0, 0, 0, 0, craft, craft, 0, craft, craft, result, quantity);
}

void WorkbenchInventory::AddQuadroCraft(int craft1, int craft2, int craft3, int craft4, int result, int quantity)
{
	AddCraft(craft1, craft2, 0, craft3, craft4, 0, 0, 0, 0, result, quantity);
	AddCraft(0, craft1, craft2, 0, craft3, craft4, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0, craft1, craft2, 0, craft3, craft4, 0, result, quantity);
	AddCraft(0, 0, 0, 0, craft1, craft2, 0, craft3, craft4, result, quantity);
}

void WorkbenchInventory::AddVerticalCraft(int craft1, int craft2, int craft3, int result, int quantity)
{
	AddCraft(0, craft1, 0, 0, craft2, 0, 0, craft3, 0, result, quantity);
	AddCraft(craft1, 0, 0, craft2, 0, 0, craft3, 0, 0, result, quantity);
	AddCraft(0, 0, craft1, 0, 0, craft2, 0, 0, craft3, result, quantity);
}

void WorkbenchInventory::AddVerticalDualCraft(int craft1, int craft2, int result, int quantity)
{
	AddCraft(craft1, 0, 0, craft2, 0, 0, 0, 0, 0, result, quantity);
	AddCraft(0, craft1, 0, 0, craft2, 0, 0, 0, 0, result, quantity);
	AddCraft(0, 0, craft1, 0, 0, craft2, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0, craft1, 0, 0, craft2, 0, 0, result, quantity);
	AddCraft(0, 0, 0, 0, craft1, 0, 0, craft2, 0, result, quantity);
	AddCraft(0, 0, 0, 0, 0, craft1, 0, 0, craft2, result, quantity);
	
}

void WorkbenchInventory::AddHorizontalDualCraft(int craft1, int craft2, int result, int quantity)
{
	AddCraft(craft1, craft2, 0, 0, 0, 0, 0, 0, 0, result, quantity);
	AddCraft(0, craft1, craft2, 0, 0, 0, 0, 0, 0, result, quantity);
	AddCraft(0, 0, 0,craft1, craft2, 0, 0, 0, 0,result, quantity);
	AddCraft(0, 0, 0, 0, craft1, craft2, 0, 0, 0,result, quantity);
	AddCraft(0, 0, 0, 0, 0, 0, craft1, craft2, 0, result, quantity);
	AddCraft(0, 0, 0, 0, 0, 0,0, craft1, craft2, result, quantity);
}

void WorkbenchInventory::AddAllDualCraft(int craft1, int craft2, int result, int quantity)
{
	AddHorizontalDualCraft(craft1, craft2, result, quantity);
	AddHorizontalDualCraft(craft2, craft1, result, quantity);
	AddVerticalDualCraft(craft1, craft2, result, quantity);
	AddVerticalDualCraft(craft2, craft1, result, quantity);
}

void WorkbenchInventory::Craft()
{
	// ���� ��� �� ������ ������, �� ������� ���������� ������
	bool isAllCraft = true;
	for (int i = 0; i < collectionCraft.size(); i++)
	{
		// ���� ����� ����� ���� 
		if (collectionResult[i][0] != 0)
		{
			// ������� ������ ������ �������, ���� 9 - ��������, ����� - ���
			int isCraft = 0;
			// �������� ������ ������ ������
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (collectionCraft[i][j][k] == cells[j][k].item.number)
					{
						isCraft += 1;
					}
					else
					{
						break;
					}
				}
			}
			// ���� ����� ������
			if (isCraft == 9)
			{
				isAllCraft = false;
				if (madeItemCell.item.number == ItemEnum::empty)
				{
					madeItemCell.item.NumberUpdate(collectionResult[i][0]);
					madeItemCell.item.quantity = collectionResult[i][1];
				}
			}
		}
		else
		{
			break;
		}
	}

	if (isAllCraft)
	{
		madeItemCell.item.NumberUpdate(ItemEnum::empty);
	}

	// ���� ��� ������ - ������� ����������� 0
	if (madeItemCell.item.number == ItemEnum::empty)
	{
		madeItemCell.item.quantity == 0;
	}
	// ���� ����������� 0 - ������� ��� ������
	if (madeItemCell.item.quantity == 0)
	{
		madeItemCell.item.NumberUpdate(ItemEnum::empty);
	}

}

void WorkbenchInventory::Draw()
{
	DrawCommon(cells);
	madeItemCell.DrawCell();
}

void WorkbenchInventory::WhileOpen(Inventory& playerInventory)
{
	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// ��� ����� �� ����������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].WhileOpen(playerInventory.mouseItem);
		}
	}

	if (madeItemCell.Take(playerInventory.mouseItem))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cells[i][j].item.number != ItemEnum::empty)
				{
					if (!cells[i][j].item.isReusable)
					{
						cells[i][j].item.quantity -= 1;
					}
				}
			}
		}
	}

	Craft();
	Draw();
	playerInventory.WhileOpen();
}
