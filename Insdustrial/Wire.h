#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Sprite.h"

class Wire : public Sprite
{
public:
	// ���-�� ���������� ����� ��������� � �����������
	bool connections[4] = { 0, 0, 0, 0 };

	// ������ ��������
	sf::Sprite sprite;
	// ���������� �������
	int energy;

	// ����� ���������������� ������� (� ����������� �� ������)
	int numberSprite;
	// ������� (���� ��������� �����)
	int turn;

	Wire(){ }

	Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& texture, sf::Vector2f _position);

	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle);
	void CheckConnections(sf::Vector2f positionSeconObject);
	void Update(sf::Vector2f playerPosition, int playerAngle);
	void Draw(sf::Vector2f cameraPosition);
};

