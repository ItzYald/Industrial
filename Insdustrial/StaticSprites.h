#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class StaticSprites
{
public:
	// �����������
	StaticSprites();

	std::vector<sf::Texture*> textures;
	std::vector<sf::Sprite> sprites;

	sf::Sprite GetSprite(int numberItem);
	sf::Texture GetTexture(int numberItem);
	void DrawItemSprite(sf::RenderWindow* rw, int numberItem, sf::Vector2f position, sf::Vector2f scale);
	// ����� �������������� ��� �������
	int IsFuel(int nuberItem);
	// ����� ����������� / �����
	int IsBurn(int nuberItem);
	// �������� ��������
	sf::String GetName(int nuberItem);
	~StaticSprites()
	{
		for (int i = 0; i < textures.size(); i++)
		{
			textures[i] = NULL;
			delete textures[i];
		}
	}

};

