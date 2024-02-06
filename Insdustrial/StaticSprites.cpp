#include "StaticSprites.h"

StaticSprites::StaticSprites(std::vector<sf::Texture>& _textures)
{
	for (int i = 0; i < _textures.size(); i++)
	{
		sprites.push_back(sf::Sprite());
		sprites[i].setTexture(_textures[i]);
	}
}

sf::Sprite StaticSprites::GetSprite(int numberItem)
{
	return sprites[numberItem];
}

void StaticSprites::DrawItemSprite(sf::RenderWindow* rw, int numberItem, sf::Vector2f position, sf::Vector2f scale)
{
	sprites[numberItem].setPosition(position);
	sprites[numberItem].setScale(scale);
	rw->draw(sprites[numberItem]);
	//rw = NULL;
	//delete rw;
}