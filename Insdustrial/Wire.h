#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Object.h"

class Wire : Object
{
public:
	// Кол-во соединений между проводами и механизмами
	bool connections[4] = { 0, 0, 0, 0 };

	// Список спрайтов, текстур и картинок
	// (может быть в разныз состояниях, может соединяться с несколькими разными проводами и механизмами)
	std::vector<sf::Image> images;
	std::vector<sf::Texture> textures;
	std::vector<sf::Sprite> sprites;

	Wire(){ }
	Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position);

	void NearPlayer(sf::Vector2f playerPosition, int playerAngle);
	void Update(sf::Vector2f playerPosition, int playerAngle);
};

