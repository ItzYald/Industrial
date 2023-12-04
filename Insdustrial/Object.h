#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"

#include "Sprite.h"


class Object : public Sprite
{

public:
	Object(){ }
	Object(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position);

	virtual void NearPlayer(sf::Vector2f playerCoords, int playerAngle);
	virtual void Update(sf::Vector2f playerCoords, int playerAngle);

};

