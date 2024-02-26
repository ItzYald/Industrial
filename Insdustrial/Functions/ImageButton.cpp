#include "ImageButton.h"

ImageButton::ImageButton()
{
}

ImageButton::ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	sf::Texture& _baseSprite,
	int outlineSize)
{
	baseSprite = sf::Sprite();
	aimSprite = sf::Sprite();
	leftDownSprite = sf::Sprite();
	rightDownSprite = sf::Sprite();

	baseSprite.setTexture(_baseSprite);
	aimSprite.setTexture(_baseSprite);
	leftDownSprite.setTexture(_baseSprite);
	rightDownSprite.setTexture(_baseSprite);

	thisSprite = &baseSprite;

	Init(_mousePosition, _position, _size);
}

ImageButton::ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	sf::Texture& _baseSprite, sf::Texture& _aimSprite,
	int outlineSize)
	: ImageButton(_mousePosition, _position, _size, _baseSprite, outlineSize)

{
	aimSprite.setTexture(_aimSprite);
	leftDownSprite.setTexture(_aimSprite);
	rightDownSprite.setTexture(_aimSprite);
}

ImageButton::ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	sf::Texture& _baseSprite, sf::Texture& _aimSprite, sf::Texture& _leftDownSprite,
	int outlineSize)
	: ImageButton(_mousePosition, _position, _size, _baseSprite, outlineSize)

{
	aimSprite.setTexture(_aimSprite);
	leftDownSprite.setTexture(_leftDownSprite);
	rightDownSprite.setTexture(_leftDownSprite);
}

ImageButton::ImageButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	sf::Texture& _baseSprite, sf::Texture& _aimSprite, sf::Texture& _leftDownSprite, sf::Texture& _rightDownSprite,
	int outlineSize)
	: ImageButton(_mousePosition, _position, _size, _baseSprite, outlineSize)
{
	aimSprite.setTexture(_aimSprite);
	leftDownSprite.setTexture(_leftDownSprite);
	rightDownSprite.setTexture(_rightDownSprite);
}

void ImageButton::Update()
{
	leftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	rightClick = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	if (Aim())
	{
		if (leftClick)
		{
			thisSprite = &leftDownSprite;
		}
		else if (rightClick)
		{
			thisSprite = &rightDownSprite;
		}
		else
		{
			thisSprite = &aimSprite;
		}
	}
	else
	{
		thisSprite = &baseSprite;
	}
}

void ImageButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}

