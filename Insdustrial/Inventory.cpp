#include "Inventory.h"

Inventory::Inventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	// ������ ���������� ����
	mousePosition = sf::Vector2i();
	// ������� ��������������� ������
	mouseItem = ItemStruct();
	itemsSprites = StaticSprites();
	rw = _rw;
	functions = Functions(rw);
	// ��������� ������
	choseCell = 0;

	LoadColorInventoryFromFile();

	// ������ ���������
	cells = std::vector< std::vector<CellInInventory>>();
	for (int i = 0; i < 10; i++)
	{
		// ��������� ������
		auto cellsI = std::vector<CellInInventory>();
		for (int j = 0; j < 4; j++)
		{
			cellsI.push_back(CellInInventory(rw, sf::Vector2f(300 + 8 + i * 66, 400 + 8 + j * 66), true, true));
		}
		cells.push_back(cellsI);
	}
	// ������ ���� ��������
	for (int i = 0; i < 2; i++)
	{
		// ��������� ������
		auto cellsI = std::vector<CellInInventory>();
		for (int j = 0; j < 2; j++)
		{
			cellsI.push_back(CellInInventory(rw, sf::Vector2f(600 + 8 + i * 66, 130 + 8 + j * 66), true, true));
		}
		cellsMiniWorkbench.push_back(cellsI);
	}

	for (int i = 0; i < 30; i++)
		ch.push_back(Checks());

}

void Inventory::DeleteButtons()
{
	buttons.clear();
}

void Inventory::Draw()
{
	DrawCommon(cells);

	// ��������� �������� � �����
	if (mouseItem.number != 0)
	{
		itemsSprites.DrawItemSprite(rw.get(), mouseItem.number, sf::Vector2f(mousePosition.x, mousePosition.y), sf::Vector2f(4, 4));
		functions.PrintText(std::to_string(mouseItem.quantity), sf::Vector2f(mousePosition.x + 35, mousePosition.y + 35), 25, sf::Color(250, 250, 250));
	}
}

void Inventory::Update()
{
	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 400), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// ��� ����� �� ����������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].Update(mouseItem);
		}
	}

	Draw();
}

void Inventory::DrawMiniWorkbench()
{
	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	for (int i = 0; i < cellsMiniWorkbench.size(); i++)
	{
		for (int j = 0; j < cellsMiniWorkbench[0].size(); j++)
		{
			cellsMiniWorkbench[i][j].Update(mouseItem);
			DrawCommon(cellsMiniWorkbench);
		}
	}
}
// ��������� ������ ����� ��������� (�� ����� ��������)
void Inventory::DrawNear(int mouseWheel)
{
	functions.DrawRectangle(sf::Vector2f(302, 598), sf::Vector2f(676, 82), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);
	
	for (int i = 0; i < cells.size(); i++)
	{
		// ���� 0 - ������� ������
		if (cells[i][3].item.quantity == 0)
		{
			cells[i][3].item.number = 0;
		}

		// ���������
		functions.DrawRectangle(sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66), sf::Vector2f(64, 64), sf::Color(150, 150, 150), sf::Color(100, 100, 100), 2);
		sf::Vector2f positionInventory = sf::Vector2f(300 + 8 + i * 66, 400 + 8 + 3 * 66);
		if (cells[i][3].item.number != 0)
		{
			itemsSprites.DrawItemSprite(rw.get(), cells[i][3].item.number, positionInventory, sf::Vector2f(4, 4));
			// �����������
			functions.PrintText(std::to_string(cells[i][3].item.quantity), sf::Vector2f(positionInventory.x + 35, positionInventory.y + 35), 25, sf::Color(250, 250, 250));
		}

	}

	functions.DrawRectangle(sf::Vector2f(300 + 8 + choseCell * 66, 400 + 8 + 3 * 66), sf::Vector2f(64, 64), sf::Color::Transparent, sf::Color(100, 100, 100), 4);

	if (mouseWheel < 0)
	{
		if (choseCell < cells.size() - 1)
		{
			choseCell += 1;
		}
		else
		{
			choseCell = 0;
		}
	}
	else if (mouseWheel > 0)
	{
		if (choseCell > 0)
		{
			choseCell -= 1;
		}
		else
		{
			choseCell = cells.size() - 1;
		}
	}

}
