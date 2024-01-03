#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Functions
{
private:
	// �����
	sf::Text text;
	// �����
	sf::Font font;
	std::shared_ptr<sf::RenderWindow> rw;
public:

	Functions(){ }
	Functions(std::shared_ptr<sf::RenderWindow> _rw);
	// ���������� �������������
	void DrawRectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	// ���������� ������������� � ��������
	void DrawRectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color col, sf::Color col2, float size2);
	// ���������� ������������� � ����������
	void DrawRectangleGradient(sf::Vector2f pos, sf::Vector2f size, sf::Color colorA, sf::Color colorB, bool gorizontal = 1);
	// ���������� ������
	void DrawSprite(sf::Sprite spr, sf::Vector2f pos, sf::Vector2f size);
	// ���������� ������ � �������������
	void DrawSprite(sf::Sprite spr, sf::Vector2f pos, sf::Vector2f size, int transparent);
	// �������� �����
	void PrintText(sf::String mes, sf::Vector2f pos, int size, sf::Color col, int center = 55);

};

