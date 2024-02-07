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
	StaticSprites(){}
	StaticSprites(std::vector<sf::Texture>& _textures);

	std::vector<sf::Sprite> sprites;

	sf::Sprite GetSprite(int numberItem);
	void DrawItemSprite(sf::RenderWindow* rw, int numberItem, sf::Vector2f position, sf::Vector2f scale);
	void DrawItemSprite(sf::RenderWindow* rw, int numberItem, sf::Vector2f position, int sizeOne);

};

