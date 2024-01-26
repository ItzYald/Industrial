#include "StaticSprites.h"

StaticSprites::StaticSprites()
{
	textures = std::vector<sf::Texture*>();
	sprites = std::vector<sf::Sprite>();
	
	for (int i = 0; i < 13; i++)
	{
		textures.push_back(new sf::Texture());
		sprites.push_back(sf::Sprite());
	}

	// Пустой слот
	textures[0]->loadFromFile("Images/Empty.png");
	// Железная руда
	textures[1]->loadFromFile("Images/IronOre.png");
	// Печка
	textures[2]->loadFromFile("Images/Objects/Oven.png");
	// Уголь
	textures[3]->loadFromFile("Images/Coal.png");
	// Железный слиток
	textures[4]->loadFromFile("Images/IronIngot.png");
	// Сундук
	textures[5]->loadFromFile("Images/Objects/Chest.png");
	// Железный блок
	textures[6]->loadFromFile("Images/IronBlock.png");
	// Древесина
	textures[7]->loadFromFile("Images/Wood.png");
	// Верстак
	textures[8]->loadFromFile("Images/Objects/WorkBench.png");
	// Доски
	textures[9]->loadFromFile("Images/Planks.png");
	// Редстоун
	textures[10]->loadFromFile("Images/Redstone.png");
	// Электропеч
	textures[11]->loadFromFile("Images/Objects/ElectricOven.png");
	// Медный провод
	textures[12]->loadFromFile("Images/Wires/CooperWire1.png");

	for (int i = 0; i < 13; i++)
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
	//rw = NULL;
	//delete rw;
}