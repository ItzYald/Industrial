#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <vector>

class Checks
{
public:

	bool checkB = false;
	bool checkB2 = true;

	Checks()
	{
		checkB = false;
		checkB2 = true;
	}

	// Проверка на отжатие клавивиши
	bool Check(sf::Keyboard::Key what);
	// Проверка на единоразовое нажатие клавиши
	bool Check2(sf::Keyboard::Key what);

};

