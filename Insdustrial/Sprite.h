#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Checks.h"
#include "Functions/Functions.h"

#include "PlayUpdatable.h"

class Sprite : public sf::Drawable, public PlayUpdatable
{
protected:
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	sf::Vector2f* cameraPosition;

public:
	sf::Vector2f position;
	sf::Sprite sprite;
	int fieldSizeOne;
	std::vector<Checks> ch;

	virtual void PlayUpdate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

