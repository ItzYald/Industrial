#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "../Updatable.h"

class Button : public sf::Drawable, public Updatable
{
protected:
	sf::RectangleShape rectangle;
	sf::Vector2i* mousePosition;
	bool leftClick;
	bool leftPreviousClick;
	bool rightClick;
	bool rightPreviousClick;

public:
	Button(){ }

	void Init(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size, int outlineSize);

	bool Aim();

	bool LeftDown();

	bool RightDown();

	bool CheckLeft();

	bool CheckRight();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	virtual void Update() = 0;

};

