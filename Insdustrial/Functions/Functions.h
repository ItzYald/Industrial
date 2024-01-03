#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Functions
{
private:
	// Текст
	sf::Text text;
	// Шрифт
	sf::Font font;
	std::shared_ptr<sf::RenderWindow> rw;
public:

	Functions(){ }
	Functions(std::shared_ptr<sf::RenderWindow> _rw);
	// Нарисовать прямоугольник
	void DrawRectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	// Нарисовать прямоугольник с границей
	void DrawRectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color col, sf::Color col2, float size2);
	// Нарисовать прямоугольник с градиентом
	void DrawRectangleGradient(sf::Vector2f pos, sf::Vector2f size, sf::Color colorA, sf::Color colorB, bool gorizontal = 1);
	// Нарисовать спрайт
	void DrawSprite(sf::Sprite spr, sf::Vector2f pos, sf::Vector2f size);
	// Нарисовать спрайт с прозрачностью
	void DrawSprite(sf::Sprite spr, sf::Vector2f pos, sf::Vector2f size, int transparent);
	// Написать текст
	void PrintText(sf::String mes, sf::Vector2f pos, int size, sf::Color col, int center = 55);

};

