#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Object.h"

class Wire : public Sprite
{
public:
	// ���-�� ���������� ����� ��������� � �����������
	bool connections[4] = { 0, 0, 0, 0 };

	// ������ ��������
	// (����� ���� � ������ ����������, ����� ����������� � ����������� ������� ��������� � �����������)
	std::vector<sf::Sprite> sprites;
	// ����� ���������������� ������� (� ����������� �� ������)
	int numberSprite;

	Wire(){ }
	Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3, sf::Texture& texture4, sf::Texture& texture5,
		sf::Vector2f _position);

	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle);
	void Update(sf::Vector2f playerPosition, int playerAngle);
	void Draw(sf::Vector2f cameraPosition);
};

