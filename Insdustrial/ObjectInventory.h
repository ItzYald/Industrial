#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "Inventory.h"

#include "StaticSprites.h"


class ObjectInventory
{
protected:
	// ������ ������
	std::vector<Button> buttons;
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;
	// ������� ����
	sf::Vector2i mousePosition;

	virtual void Draw(Inventory& playerInventory) = 0;
};

