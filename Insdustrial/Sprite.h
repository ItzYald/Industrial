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

public:
	sf::Vector2f position;
	sf::Texture* texture;
	sf::Sprite sprite;
	int fieldSizeOne;
	std::vector<Checks> ch;
	
	Sprite(){ }
	Sprite(std::shared_ptr<sf::RenderWindow> _rw, int _sizeWorld, std::string imageFileName, sf::Vector2f _position){ }
	~Sprite()
	{
		texture = NULL;
		delete texture;
	}

	virtual void Draw(sf::Vector2f cameraPosition) = 0;

};

