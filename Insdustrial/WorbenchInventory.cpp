#include "WorbenchInventory.h"

WorkbenchInventory::WorkbenchInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures)
{
	// Окно
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	// Ячейки инвентаря
	cells = std::vector< std::vector<CellInInventory>>();
	for (int i = 0; i < 3; i++)
	{
		// Временный массив
		auto cellsI = std::vector<CellInInventory>();
		for (int j = 0; j < 3; j++)
		{
			cellsI.push_back(CellInInventory(rw, sf::Vector2f(350 + 8 + i * 66, 130 + 8 + j * 66), true, _textures));
		}
		cells.push_back(cellsI);
	}

	// Созданный предмет
	madeItemCell = CellInInventory(rw, sf::Vector2f(700, 130 + 8 + 1 * 66), false, _textures);

	itemsSprites = StaticSprites(_textures);
	// Какие есть крафты
	collectionCraft = std::vector<std::vector<std::vector<int>>>();
	collectionResult = std::vector<std::vector<int>>();

	// Железный блок
	AddCraft(
		4, 4, 4,
		4, 4, 4,
		4, 4, 4,
		6, 1);
	// Доски
	AddSingleCraft(7, 9, 4);
	// Верстак
	AddQuadroSimpleCraft(9, 8, 1);
	// Сундук
	AddCraft(
		9, 9, 9,
		9, 0, 9,
		9, 9, 9,
		5, 1);
	// Электропеч
	AddCraft(
		4, 4, 4,
		4, 2, 4,
		4, 4, 4,
		11, 1);
	// Медный провод
	AddCraft(
		0, 14, 0,
		0, 14, 0,
		0, 14, 0,
		12, 3);
	// Железный провод
	AddCraft(
		0, 4, 0,
		0, 4, 0,
		0, 4, 0,
		15, 3);
	// Железный провод
	AddCraft(
		0, 4, 0,
		9, 9, 9,
		9, 9, 9,
		16, 1);
	// Корпус механизма
	AddCraft(
		4, 4, 4,
		4, 0, 4,
		4, 4, 4,
		18, 1);
	// Угольный энергогенератор
	AddCraft(
		0, 0, 0,
		0, 18, 0,
		0, 0, 0,
		17, 1);
}

void WorkbenchInventory::AddCraft(
	int craft1, int craft2, int craft3, int craft4, int craft5, int craft6, int craft7, int craft8, int craft9,
	int result, int quantity)
{
	// Временный массив
	std::vector<std::vector<int>> mas = std::vector<std::vector<int>>();
	for (int j = 0; j < 3; j++)
	{
		// Другой временный массив
		//std::vector<int> mas2 = std::vector<int>();
		//mas2.push_back(craft1);
		//mas2.push_back(craft2);
		//mas2.push_back(craft3);
		//mas.push_back(mas2);
		//mas2.clear();
		//mas2.push_back(craft4);
		//mas2.push_back(craft5);
		//mas2.push_back(craft6);
		//mas.push_back(mas2);
		//mas2.clear();
		//mas2.push_back(craft7);
		//mas2.push_back(craft8);
		//mas2.push_back(craft9);
		//mas.push_back(mas2);
		//mas2.clear();

		// Другой временный массив
		std::vector<int> mas2 = std::vector<int>();
		mas2.push_back(craft3);
		mas2.push_back(craft6);
		mas2.push_back(craft9);
		mas.push_back(mas2);
		mas2.clear();
		mas2.push_back(craft2);
		mas2.push_back(craft5);
		mas2.push_back(craft8);
		mas.push_back(mas2);
		mas2.clear();
		mas2.push_back(craft1);
		mas2.push_back(craft4);
		mas2.push_back(craft7);
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

void WorkbenchInventory::Craft()
{
	// Если нет ни одного крафта, то сделать реузультат пустым
	bool isAllCraft = true;
	for (int i = 0; i < collectionCraft.size(); i++)
	{
		// Если такой крафт есть 
		if (collectionResult[i][0] != 0)
		{
			// Сколько частей крафта совпало, если 9 - крафтить, иначе - нет
			int isCraft = 0;
			// Проверка каждой ячейки крафта
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
			// Если крафт совпал
			if (isCraft == 9)
			{
				isAllCraft = false;
				if (madeItemCell.item.number == 0)
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
		madeItemCell.item.NumberUpdate(0);
	}

	// Если тип пустой - сделать колличество 0
	if (madeItemCell.item.number == 0)
	{
		madeItemCell.item.quantity == 0;
	}
	// Если колличество 0 - сделать тип пустой
	if (madeItemCell.item.quantity == 0)
	{
		madeItemCell.item.NumberUpdate(0);
	}

}

void WorkbenchInventory::Draw()
{
	DrawCommon(cells);
	madeItemCell.DrawCell();
}

void WorkbenchInventory::Update(Inventory& playerInventory)
{
	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Два цикла по координатам инвентаря
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[0].size(); j++)
		{
			cells[i][j].Update(playerInventory.mouseItem);
		}
	}

	if (madeItemCell.Take(playerInventory.mouseItem))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cells[i][j].item.number != 0)
				{
					cells[i][j].item.quantity -= 1;
					if (cells[i][j].item.quantity == 0)
					{
						cells[i][j].item.NumberUpdate(0);
					}
				}
			}
		}
	}

	Craft();
	Draw();
	playerInventory.Update();
}
