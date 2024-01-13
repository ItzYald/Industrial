#include "StaticSprites.h"

StaticSprites::StaticSprites()
{
	textures = std::vector<sf::Texture*>();
	sprites = std::vector<sf::Sprite>();
	
	for (int i = 0; i < 12; i++)
	{
		textures.push_back(new sf::Texture());
		sprites.push_back(sf::Sprite());
	}

	// ������ ����
	textures[0]->loadFromFile("Images/Empty.png");
	// �������� ����
	textures[1]->loadFromFile("Images/IronOre.png");
	// �����
	textures[2]->loadFromFile("Images/Objects/Oven.png");
	// �����
	textures[3]->loadFromFile("Images/Coal.png");
	// �������� ������
	textures[4]->loadFromFile("Images/IronIngot.png");
	// ������
	textures[5]->loadFromFile("Images/Objects/Chest.png");
	// �������� ����
	textures[6]->loadFromFile("Images/IronBlock.png");
	// ���������
	textures[7]->loadFromFile("Images/Wood.png");
	// �������
	textures[8]->loadFromFile("Images/Objects/WorkBench.png");
	// �����
	textures[9]->loadFromFile("Images/Planks.png");
	// ��������
	textures[10]->loadFromFile("Images/Redstone.png");
	// ����������
	textures[11]->loadFromFile("Images/Objects/ElectricOven.png");

	for (int i = 0; i < 12; i++)
	{
		sprites[i].setTexture(*textures[i]);
	}

}

sf::Sprite StaticSprites::GetSprite(int numberItem)
{
	return sprites[numberItem];
}

sf::Texture StaticSprites::GetTexture(int numberItem)
{
	return *textures[numberItem];
}

void StaticSprites::DrawItemSprite(sf::RenderWindow* rw, int numberItem, sf::Vector2f position, sf::Vector2f scale)
{

	sprites[numberItem].setPosition(position);
	sprites[numberItem].setScale(scale);
	rw->draw(sprites[numberItem]);
	rw = NULL;
	delete rw;
}
// ����� �������������� ��� �������
int StaticSprites::IsFuel(int nuberItem)
{
	int res = 0;
	switch (nuberItem)
	{
	// �����
	case 3:
		res = 8;
		break;
	case 7:
		res = 2;
		break;
	case 9:
		res = 1;
		break;
	default:
		break;
	}
	return res;
}
// ����� ����������� / �����
int StaticSprites::IsBurn(int nuberItem)
{
	int res = 0;
	switch (nuberItem)
	{
	// �������� ���� �������������� � �������� ������
	case 1:
		res = 4;
		break;
	// ��������� � �����
	case 7:
		res = 3;
		break;
	default:
		break;
	}
	return res;
}

sf::String StaticSprites::GetName(int numberItem)
{
	switch (numberItem)
	{
	case 1:
		return L"�������� ����";
		break;
	case 2:
		return L"�����";
		break;
	case 3:
		return L"�����";
		break;
	case 4:
		return L"�������� ������";
		break;
	case 5:
		return L"C�����";
		break;
	case 6:
		return L"�������� ������";
		break;
	case 7:
		return L"���������";
		break;
	case 8:
		return L"�������";
		break;
	case 9:
		return L"�����";
		break;
	case 10:
		return L"��������";
		break;
	case 11:
		return L"����������";
		break;
	default:
		return L"";
		break;
	}

}
