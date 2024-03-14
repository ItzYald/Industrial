#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "StaticSprites.h"

#include "Item.h"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"

class CellInInventory
{
private:
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;

protected:

public:
	// Можно ли класть в ячейку
	bool put;
	// Можно ли брать из ячейки
	bool take;

	//ItemStruct item;
	Item item;
	// Кнопка
	OldButton button;
	// Список цветов
	std::vector<sf::Color> colorsInventory;
	CellInInventory(){ }
	CellInInventory(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f position,
		bool _put, bool _take, std::vector<sf::Texture*>& _textures, std::vector<sf::Color> _colorsInventory);
	CellInInventory(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f position,
		bool _put, std::vector<sf::Texture*>& _textures, std::vector<sf::Color> _colorsInventory);

	// Отрисовать ячейку
	void DrawCell();

	void DrawName();
	// Взять из ячейки
	bool Take(Item& mouseItem);
	// Каждый кадр
	void WhileOpen(Item& mouseItem);

};

