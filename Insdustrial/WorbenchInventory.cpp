#include "WorbenchInventory.h"

WorkbenchInventory::WorkbenchInventory(std::shared_ptr<sf::RenderWindow> _rw)
{
	// Окно
	rw = _rw;
	functions = Functions(rw);

	// Предметы в поле для крафта
	items = std::vector<std::vector<ItemStruct>>();
	for (int i = 0; i < 3; i++)
	{
		items.push_back(std::vector<ItemStruct>());
		for (int j = 0; j < 3; j++)
		{
			items[i].push_back(ItemStruct());
		}
	}
	// Созданный предмет
	madeItem = ItemStruct();
	
	itemsSprites = StaticSprites();
	// Какие есть крафты
	collectionCraft = std::vector<std::vector<std::vector<int>>>();
	collectionResult = std::vector<int>();

	AddCraft(4, 4, 4, 4, 4, 4, 4, 4, 4, 6);

	AddSingleCraft(7, 9);

	AddQuadroSimpleCraft(9, 8);
}

void WorkbenchInventory::AddCraft(
	int craft1, int craft2, int craft3, int craft4, int craft5, int craft6, int craft7, int craft8, int craft9,
	int result)
{
	// Временный массив
	std::vector<std::vector<int>> mas = std::vector<std::vector<int>>();
	for (int j = 0; j < 3; j++)
	{
		// Другой временный массив
		std::vector<int> mas2 = std::vector<int>();
		mas2.push_back(craft1);
		mas2.push_back(craft2);
		mas2.push_back(craft3);
		mas.push_back(mas2);
		mas2.clear();
		mas2.push_back(craft4);
		mas2.push_back(craft5);
		mas2.push_back(craft6);
		mas.push_back(mas2);
		mas2.clear();
		mas2.push_back(craft7);
		mas2.push_back(craft8);
		mas2.push_back(craft9);
		mas.push_back(mas2);
		mas2.clear();
	}
	collectionCraft.push_back(mas);
	collectionResult.push_back(result);
}

void WorkbenchInventory::AddSingleCraft(int craft, int result)
{
	AddCraft(craft, 0, 0, 0, 0, 0, 0, 0, 0, result);
	AddCraft(0, craft, 0, 0, 0, 0, 0, 0, 0, result);
	AddCraft(0, 0, craft, 0, 0, 0, 0, 0, 0, result);
	AddCraft(0, 0, 0, craft, 0, 0, 0, 0, 0, result);
	AddCraft(0, 0, 0, 0, craft, 0, 0, 0, 0, result);
	AddCraft(0, 0, 0, 0, 0, craft, 0, 0, 0, result);
	AddCraft(0, 0, 0, 0, 0, 0, craft, 0, 0, result);
	AddCraft(0, 0, 0, 0, 0, 0, 0, craft, 0, result);
	AddCraft(0, 0, 0, 0, 0, 0, 0, 0, craft, result);
}

void WorkbenchInventory::AddQuadroSimpleCraft(int craft, int result)
{
	AddCraft(craft, craft, 0, craft, craft, 0, 0, 0, 0, result);
	AddCraft(0, craft, craft, 0, craft, craft, 0, 0, 0, result);
	AddCraft(0, 0, 0, craft, craft, 0, craft, craft, 0, result);
	AddCraft(0, 0, 0, 0, craft, craft, 0, craft, craft, result);
}

void WorkbenchInventory::AddQuadroCraft(int craft1, int craft2, int craft3, int craft4, int result)
{
	AddCraft(craft1, craft2, 0, craft3, craft4, 0, 0, 0, 0, result);
	AddCraft(0, craft1, craft2, 0, craft3, craft4, 0, 0, 0, result);
	AddCraft(0, 0, 0, craft1, craft2, 0, craft3, craft4, 0, result);
	AddCraft(0, 0, 0, 0, craft1, craft2, 0, craft3, craft4, result);
}

void WorkbenchInventory::Craft()
{
	// Если нет ни одного крафта, то сделать реузультат пустым
	bool isAllCraft = true;
	for (int i = 0; i < collectionCraft.size(); i++)
	{
		// Если такой крафт есть 
		if (collectionResult[i] != 0)
		{
			// Сколько частей крафта совпало, если 9 - крафтить, иначе - нет
			int isCraft = 0;
			// Проверка каждой ячейки крафта
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (collectionCraft[i][j][k] == items[j][k].number)
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
				if (madeItem.number == 0)
				{
					madeItem.number = collectionResult[i];
					madeItem.quantity = 1;
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
		madeItem.number = 0;
		madeItem.quantity = 0;
	}

	// Если тип пустой - сделать колличество 0
	if (madeItem.number == 0)
	{
		madeItem.quantity == 0;
	}
	// Если колличество 0 - сделать тип пустой
	if (madeItem.quantity == 0)
	{
		madeItem.number = 0;
	}

}

void WorkbenchInventory::Draw(Inventory& playerInventory)
{
	if (buttons.size() < 1)
	{
		for (int i = 0; i < items.size(); i++)
		{
			for (int j = 0; j < items[0].size(); j++)
			{
				buttons.push_back(Button(sf::Vector2f(350 + 8 + i * 66, 130 + 8 + j * 66), sf::Vector2f(64, 64), L"",
					sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(100, 100, 100), sf::Color::Transparent,
					sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
			}
		}
		buttons.push_back(Button(sf::Vector2f(700, 130 + 8 + 1 * 66), sf::Vector2f(64, 64), L"",
			sf::Color::Transparent, sf::Color(100, 100, 100, 100), sf::Color(100, 100, 100), sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25));
	}

	// Узнать координаты мыши
	mousePosition = sf::Mouse::getPosition(*rw);
	// Отрисовать окно интерфейса
	functions.Rectangle(rw.get(), sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// Два цикла по координатам поля для крафта
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < items[0].size(); j++)
		{

			int numberButton = i * items[0].size() + j;
			// Нажатие левой кнопки мыши
			if (buttons[numberButton].CheckLeft(*rw))
			{
				// Если и в мыши и в ячейке есть предмет
				if (items[i][j].number != 0 && playerInventory.mouseItem.number != 0)
				{
					// Если предметы одинаковые - сложить
					if (items[i][j].number == playerInventory.mouseItem.number)
					{
						items[i][j].quantity += playerInventory.mouseItem.quantity;
						playerInventory.mouseItem.number = 0;
						playerInventory.mouseItem.quantity = 0;
					}
					// Если разные - поменять
					else
					{
						ItemStruct intermediateItem = playerInventory.mouseItem;
						playerInventory.mouseItem = items[i][j];
						items[i][j] = intermediateItem;
					}
				}
				// Если в ячейке есть предмет, а в мыше нету
				else if (items[i][j].number != 0)
				{
					playerInventory.mouseItem = items[i][j];
					items[i][j].number = 0;
					items[i][j].quantity = 0;
				}
				// Если предмет есть в мыши, но нету в ячейке
				else if (playerInventory.mouseItem.number != 0)
				{

					items[i][j] = playerInventory.mouseItem;
					playerInventory.mouseItem.number = 0;
					playerInventory.mouseItem.quantity = 0;
				}
			}
			// Нажатие правой кнопки мыши
			if (buttons[numberButton].CheckRight(*rw))
			{
				// Если в мыши есть предмет, а в ячейке нету
				if (playerInventory.mouseItem.number != 0 && items[i][j].number == 0)
				{
					items[i][j].number = playerInventory.mouseItem.number;
					items[i][j].quantity = 1;
					playerInventory.mouseItem.quantity -= 1;
					if (playerInventory.mouseItem.quantity == 0)
					{
						playerInventory.mouseItem.number = 0;
					}
				}
				// Если в мыши нет предмета, а в ячейке есть
				if (playerInventory.mouseItem.number == 0 && items[i][j].number != 0)
				{
					playerInventory.mouseItem.number = items[i][j].number;
					if (items[i][j].quantity == 1)
					{
						playerInventory.mouseItem.quantity = 1;
						items[i][j].number = 0;
						items[i][j].quantity = 0;
					}
					else
					{
						playerInventory.mouseItem.quantity = items[i][j].quantity / 2;
						items[i][j].quantity = items[i][j].quantity - playerInventory.mouseItem.quantity;
					}
				}
			}

			// Отрисовка
			sf::Vector2f positionInventory = buttons[numberButton].coords;
			if (items[i][j].number != 0)
			{
				itemsSprites.DrawItemSprite(rw.get(), items[i][j].number, positionInventory, sf::Vector2f(4, 4));
				functions.PrintText(std::to_string(items[i][j].quantity), sf::Vector2f(positionInventory.x + 40, positionInventory.y + 40), 20, sf::Color(250, 250, 250));
			}

			buttons[numberButton].Draw(*rw);
		}
	}
	// Отрисовать созданный объект
	buttons[9].Draw(*rw);
	sf::Vector2f positionInventory = buttons[9].coords;
	itemsSprites.DrawItemSprite(rw.get(), madeItem.number, positionInventory, sf::Vector2f(4, 4));
	functions.PrintText(std::to_string(madeItem.quantity), sf::Vector2f(positionInventory.x + 40, positionInventory.y + 40), 20, sf::Color(250, 250, 250));

	Craft();

	// Забрать созданный объект
	if (buttons[9].CheckLeft(*rw) && madeItem.number != 0)
	{
		playerInventory.mouseItem = madeItem;
		madeItem.number = 0;
		madeItem.quantity = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				items[i][j].quantity -= 1;
				if (items[i][j].quantity == 0)
				{
					items[i][j].number = 0;
				}
			}
		}
	}
	playerInventory.Update();
}

