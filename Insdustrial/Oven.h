#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"

#include "Object.h"
#include "Checks.h"

#include "OvenInventory.h"


class Oven : public Object
{
public:

	OvenInventory inventory;

	Oven(){ }
	Oven(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position);

	bool NearPlayer(sf::Vector2f playerCoords, int playerAngle) override;
	void Update(sf::Vector2f playerCoords, int playerAngle) override;


};

