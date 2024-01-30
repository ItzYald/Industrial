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
	// Кол-во соединений между проводами и механизмами
	bool connections[4] = { 0, 0, 0, 0 };

	// Список спрайтов
	// (может быть в разных состояниях, может соединяться с несколькими разными проводами и механизмами)
	std::vector<sf::Sprite> sprites;

	sf::Sprite newSprite;

	// Номер оотрисовываемого спрайта (в зависимости от связей)
	int numberSprite;

	int turn;

	Wire(){ }
	Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3, sf::Texture& texture4, sf::Texture& texture5,
		sf::Vector2f _position);

	Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& texture, sf::Vector2f _position);

	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle);
	void CheckConnections(sf::Vector2f positionSeconObject);
	void Update(sf::Vector2f playerPosition, int playerAngle);
	void Draw(sf::Vector2f cameraPosition);
};

