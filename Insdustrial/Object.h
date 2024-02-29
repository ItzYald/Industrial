#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Checks.h"

#include "Sprite.h"

class Object : public Sprite
{
public:
	int turn;
	// Открыт ли инт
	bool isOpenInventory;

	virtual bool NearPlayer(sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void PlayUpdate() = 0;
	virtual void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

