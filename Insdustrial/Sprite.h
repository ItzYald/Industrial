#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Checks.h"
#include "Functions/Functions.h"

class Sprite
{
protected:
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	sf::Vector2f* cameraPosition;

public:
	sf::Vector2f position;
	sf::Texture* texture;
	sf::Sprite sprite;
	int fieldSizeOne;
	std::vector<Checks> ch;

	virtual void Next() = 0;
	virtual void Draw() = 0;

};

