#include "StaticSprites.h"

StaticSprites::StaticSprites()
{
	textures = std::vector<sf::Texture*>();
	sprites = std::vector<sf::Sprite>();
	
	for (int i = 0; i < 7; i++)
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
	// Сундук
	textures[6]->loadFromFile("Images/IronBlock.png");

	for (int i = 0; i < 7; i++)
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
