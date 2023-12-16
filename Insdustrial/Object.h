#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"

#include "Sprite.h"


class Object : public Sprite
{
protected:
	Functions functions;

public:

	bool isOpenInventory;

	Object(){ }
	Object(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position);

	virtual bool NearPlayer(sf::Vector2f playerCoords, int playerAngle) = 0;
	virtual void Update(sf::Vector2f playerCoords, int playerAngle) = 0;

};

