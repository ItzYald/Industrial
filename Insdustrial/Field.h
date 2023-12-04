#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"

class Field
{
public:
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	// Размер поля (кол-во клеток)
	sf::Vector2i size;
	// Размер одной клетки
	int sizeOne;
	// Размер окна
	sf::Vector2u sizeW;

	Functions functions;

	Field(){ }
	Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW);

	void Draw(sf::Vector2f cameraPosition, int i, int j);
	sf::Vector2i WhatActive(sf::Vector2i mousePosition);


};

