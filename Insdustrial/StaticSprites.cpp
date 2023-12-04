#include "StaticSprites.h"

StaticSprites::StaticSprites()
{
	textures = std::vector<sf::Texture*>();
	sprites = std::vector<sf::Sprite>();
	
	for (int i = 0; i < 4; i++)
	{
		textures.push_back(new sf::Texture());
		sprites.push_back(sf::Sprite());
	}

	textures[0]->loadFromFile("Images/Empty.png");
	textures[1]->loadFromFile("Images/Wood.png");
	textures[2]->loadFromFile("Images/Oven.png");
	textures[3]->loadFromFile("Images/Coal.png");

	for (int i = 0; i < 4; i++)
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
	if (nuberItem == 1)
		res = 4;
	if (nuberItem == 3)
		res = 8;
	return res;
}
// Можно переплавить / сжечь
int StaticSprites::IsBurn(int nuberItem)
{
	int res = 0;
	if (nuberItem == 1)
		res = 3;
	return res;
}
