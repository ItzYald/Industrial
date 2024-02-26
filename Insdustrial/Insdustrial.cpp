#include <iostream>
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

	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	ShowWindow(GetConsoleWindow(), SW_SHOW);
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Industrial", 7U, settings);

	Game game = Game(window);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				game.Mouse(event, window);
			}
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				game.MouseWheelScrolled((int)event.mouseWheelScroll.delta);
			}

		}

		window.clear();

		game.Next();

		window.display();

	}
}

