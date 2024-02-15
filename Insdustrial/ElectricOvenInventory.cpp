#include "ElectricOvenInventory.h"

ElectricOvenInventory::ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures)
{
	rw = _rw;
	functions = Functions(rw);
	colorsInventory = _colorsInventory;

	// 3 ������ � ���������
	cells = std::vector<CellInInventory>();
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 130), true, _textures));
	cells.push_back(CellInInventory(rw, sf::Vector2f(460, 306), true, _textures));
	cells.push_back(CellInInventory(rw, sf::Vector2f(670, 218), false, _textures));

	fuel = 0;
	whatBurn = 120;
	maxFuel = 3600;

	itemsSprites = StaticSprites(_textures);
}

void ElectricOvenInventory::Burn()
{
	// ������ ��� ��������, �� ��� ������ ���
	//if (cells[1].item.number == 10 && fuel < maxFuel)
	//{
	//	fuel += 10;
	//	cells[1].item.quantity -= 1;
	//	if (fuel > maxFuel)
	//	{
	//		fuel = maxFuel;
	//	}
	//}

	AllBurn();
	if (cells[0].item.whatBurn && fuel > 0)
	{
		fuel -= 1;
	}

	if (fuel > maxFuel)
	{
		fuel = maxFuel;
	}

}

void ElectricOvenInventory::Draw()
{
	AllDraw();
	// ������� �����
	functions.DrawRectangle(sf::Vector2f(400, 180), sf::Vector2f(30, 140), sf::Color::Transparent, sf::Color(100, 100, 100), 2);
	if (maxFuel != 0)
	{
		functions.DrawRectangleGradient(sf::Vector2f(400, 320), sf::Vector2f(30, ((fuel / (float)maxFuel)) * -140), sf::Color::Red, sf::Color(255, 200, 0));
	}

}

void ElectricOvenInventory::Update(Inventory& playerInventory)
{
	// ������ ���������� ����
	mousePosition = sf::Mouse::getPosition(*rw);
	// ���������� ���� ����������
	functions.DrawRectangle(sf::Vector2f(302, 110), sf::Vector2f(676, 280), sf::Color(250, 250, 250), sf::Color(100, 100, 100), 3);

	// ���� �� ����������� ���������
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].Update(playerInventory.mouseItem);
	}

	Draw();
	playerInventory.Update();
}
