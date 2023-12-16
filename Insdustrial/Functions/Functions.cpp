#include "Functions.h"

Functions::Functions(std::shared_ptr<sf::RenderWindow> _rw)
{
	font.loadFromFile("Font/Undertale-Font.ttf");
	rw = _rw;
	text = sf::Text("", font, 25);
}
// Нарисовать прямоугольник (старый)
void Functions::Rectangle(sf::RenderWindow* rw, sf::Vector2f pos, sf::Vector2f size, sf::Color col)
{
	sf::RectangleShape rect;
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(col);
	rw->draw(rect);
}
// Нарисовать прямоугольник с границей (старый)
void Functions::Rectangle(sf::RenderWindow* rw, sf::Vector2f pos, sf::Vector2f size, sf::Color col, sf::Color col2, float size2)
{
	sf::RectangleShape rect;
	rect = sf::RectangleShape();
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(col);
	rect.setOutlineColor(col2);
	rect.setOutlineThickness(size2);
	rw->draw(rect);
}
// Нарисовать прямоугольник
void Functions::DrawRectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color col)
{
	sf::RectangleShape rect;
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(col);
	rw->draw(rect);
}
// Нарисовать прямоугольник с границей
void Functions::DrawRectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color col, sf::Color col2, float size2)
{
	sf::RectangleShape rect;
	rect = sf::RectangleShape();
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(col);
	rect.setOutlineColor(col2);
	rect.setOutlineThickness(size2);
	rw->draw(rect);
}
// Нарисовать прямоугольник с градиентом
void Functions::DrawRectangleGradient(sf::Vector2f pos, sf::Vector2f size, sf::Color colorA, sf::Color colorB, bool gorizontal)
{
	// sf::Vertex rectangle[];
	if (gorizontal == 1)
	{
		sf::Vertex rectangle[] =
		{
			sf::Vertex(pos, colorA),
			sf::Vertex(sf::Vector2f(pos.x + size.x, pos.y), colorB),
			sf::Vertex(sf::Vector2f(pos.x + size.x, pos.y + size.y), colorB),
			sf::Vertex(sf::Vector2f(pos.x, pos.y + size.y), colorA)
		};
		rw->draw(rectangle, 4, sf::Quads);
	}
	else
	{
		sf::Vertex rectangle[] =
		{
			sf::Vertex(pos, colorA),
			sf::Vertex(sf::Vector2f(pos.x + size.x, pos.y), colorA),
			sf::Vertex(sf::Vector2f(pos.x + size.x, pos.y + size.y), colorB),
			sf::Vertex(sf::Vector2f(pos.x, pos.y + size.y), colorB)
		};
		rw->draw(rectangle, 4, sf::Quads);
	}

	// rw->draw(rectangle, 4, sf::Quads);
}
// Нарисовать спрайт
void Functions::DrawSprite(sf::RenderWindow* rw, sf::Sprite spr, sf::Vector2f pos, sf::Vector2f size)
{
	if (pos.y != 0)
		spr.setScale(size.x / spr.getTexture()->getSize().x, size.y / spr.getTexture()->getSize().y);
	else
	{
		spr.setScale(size.x / spr.getTexture()->getSize().x, size.x / spr.getTexture()->getSize().x);
	}


	if (size.x < 0)
	{
		spr.setPosition(pos.x - size.x, pos.y);
	}
	else
	{
		spr.setPosition(pos.x, pos.y);
	}
	rw->draw(spr);
}
// Отрисовка спрайта с прозрачностью
void Functions::DrawSprite(sf::RenderWindow* rw, sf::Sprite spr, sf::Vector2f pos, sf::Vector2f size, int transparent)
{
	spr.setScale(size.x / spr.getTexture()->getSize().x, size.y / spr.getTexture()->getSize().y);
	if (size.x < 0)
	{
		spr.setPosition(pos.x - size.x, pos.y);
	}
	else
	{
		spr.setPosition(pos.x, pos.y);
	}

	spr.setColor(sf::Color(255, 255, 255, transparent));

	rw->draw(spr);
}

void Functions::PrintText(sf::String mes, sf::Vector2f pos, int size, sf::Color col, int center)
{
	// text = sf::Text(mes, font, size);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setString(mes);
	if (center == 0)
	{
		text.setPosition(sf::Vector2f(pos.x - mes.getSize() * size / 2, pos.y));
	}
	else if (center == 1)
	{
		text.setPosition(sf::Vector2f(pos.x - mes.getSize() * size / 4, pos.y));
	}
	else
	{
		text.setPosition(pos);
	}
	text.setFillColor(col);
	rw->draw(text);
}

