#pragma once
#include "Button.h"

class ImageButton : public Button
{
	sf::Sprite* thisSprite;

	sf::Sprite baseSprite;
	sf::Sprite aimSprite;
	sf::Sprite leftDownSprite;
	sf::Sprite rightDownSprite;


	ImageButton();

	ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::Texture& _baseSprite,
		int outlineSize = 0);

	ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::Texture& _baseSprite, sf::Texture& _aimSprite,
		int outlineSize = 0);

	ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::Texture& _baseSprite, sf::Texture& _aimSprite, sf::Texture& _leftDownSprite,
		int outlineSize = 0);

	ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::Texture& _baseSprite, sf::Texture& _aimSprite, sf::Texture& _leftDownSprite, sf::Texture& _rightDownSprite,
		int outlineSize = 0);

	void Update() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

