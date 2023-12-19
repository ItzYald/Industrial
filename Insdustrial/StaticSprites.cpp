#include "StaticSprites.h"

StaticSprites::StaticSprites()
{
	textures = std::vector<sf::Texture*>();
	sprites = std::vector<sf::Sprite>();
	
	for (int i = 0; i < 10; i++)
	{
		textures.push_back(new sf::Texture());
		sprites.push_back(sf::Sprite());
	}

	// Пустой слот
	textures[0]->loadFromFile("Images/Empty.png");
	// Железная руда
	textures[1]->loadFromFile("Images/IronOre.png");
	// Печка
	textures[2]->loadFromFile("Images/Oven.png");
	// Уголь
	textures[3]->loadFromFile("Images/Coal.png");
	// Железный слиток
	textures[4]->loadFromFile("Images/IronIngot.png");
	// Сундук
	textures[5]->loadFromFile("Images/Chest.png");
	// Железный блок
	textures[6]->loadFromFile("Images/IronBlock.png");
	// Древесина
	textures[7]->loadFromFile("Images/Wood.png");
	// Верстак
	textures[8]->loadFromFile("Images/WorkBench.png");
	// Доски
	textures[9]->loadFromFile("Images/Planks.png");

	for (int i = 0; i < 10; i++)
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

}
// Может использоваться как топливо
int StaticSprites::IsFuel(int nuberItem)
{
	int res = 0;
	switch (nuberItem)
	{
	// Уголь
	case 3:
		res = 8;
		break;
	default:
		break;
	}
	return res;
}
// Можно переплавить / сжечь
int StaticSprites::IsBurn(int nuberItem)
{
	int res = 0;
	switch (nuberItem)
	{
	// Железная руда переплавляется в железный слиток
	case 1:
		res = 4;
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
		return L"Железная руда";
		break;
	case 2:
		return L"Печка";
		break;
	case 3:
		return L"Уголь";
		break;
	case 4:
		return L"Железный слиток";
		break;
	case 5:
		return L"Cундук";
		break;
	case 6:
		return L"Железный слиток";
		break;
	case 7:
		return L"Древесина";
		break;
	case 8:
		return L"Верстак";
		break;
	case 9:
		return L"Доски";
		break;
	default:
		return L"";
		break;
	}

}
