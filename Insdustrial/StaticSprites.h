#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class StaticSprites
{
public:
	// Конструктор
	StaticSprites();

	std::vector<sf::Texture*> textures;
	std::vector<sf::Sprite> sprites;

	sf::Sprite GetSprite(int numberItem);
	sf::Texture GetTexture(int numberItem);
	void DrawItemSprite(sf::RenderWindow* rw, int numberItem, sf::Vector2f position, sf::Vector2f scale);
	// Может использоваться как топливо
	int IsFuel(int nuberItem);
	// Можно переплавить / сжечь
	int IsBurn(int nuberItem);

};

