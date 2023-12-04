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
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	// ������ ���� (���-�� ������)
	sf::Vector2i size;
	// ������ ����� ������
	int sizeOne;
	// ������ ����
	sf::Vector2u sizeW;

	Functions functions;

	Field(){ }
	Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW);

	void Draw(sf::Vector2f cameraPosition, int i, int j);
	sf::Vector2i WhatActive(sf::Vector2i mousePosition);


};

