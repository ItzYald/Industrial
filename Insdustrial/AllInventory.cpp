#include "AllInventory.h"

void AllInventory::DrawCommon(std::vector<std::vector<CellInInventory>> cells)
{
	// ��������� �������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].button.Draw(*rw);
			cells[i][j].DrawCell();
		}
	}

	// ��������� �������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].DrawName();
		}
	}

}

void AllInventory::DrawCommon(std::vector<CellInInventory> cells)
{
	// ��������� �������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].button.Draw(*rw);
		cells[i].DrawCell();
	}

}

