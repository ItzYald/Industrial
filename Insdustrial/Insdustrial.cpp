﻿#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Game.h"
#include <Windows.h>


int main()
{
	std::setlocale(LC_ALL, "Russian");
	// ShowWindow(GetConsoleWindow(), SW_HIDE);
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	sf::RenderWindow rw(sf::VideoMode(1280, 720), "Industrial");

	Game game = Game(rw);
	rw.setFramerateLimit(60);

	while (rw.isOpen())
	{
		sf::Event event;


		while (rw.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				rw.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				game.Mouse(event, rw);
			}
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				game.MouseWheelScrolled((int)event.mouseWheelScroll.delta);
			}

		}

		rw.clear();

		game.Next();

		rw.display();

	}
}

