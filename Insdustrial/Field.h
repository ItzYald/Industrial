#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Sprite.h"
#include "Item.h"

class Field
{
public:
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	// Размер поля (кол-во клеток)
	sf::Vector2i size;
	// Спрайт травы
	sf::Sprite sprite;
	// Размер одной клетки
	int sizeOne;
	// Размер окна
	sf::Vector2u sizeW;
	// Указатель на список всех объектов
	std::vector<Sprite*>* objects;
	// Список объектов передающих и принимающих электричество (x - какой объект, y - номер в массиве)
	std::vector<std::vector<sf::Vector2i>> energyObjectsNumbers;
	std::vector<std::vector<int>> transEnergyObjectsNumbers;

	// Фнкции отрисовки (прямоугольник, круг, текст, спрайт...)
	Functions functions;

	Field(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_size">Размер поля (кол-во клеток)</param>
	/// <param name="_sizeOne">Размер одной клетки</param>
	/// <param name="_sizeW">Размер окна</param>
	/// <param name="texture">Текстурка травы</param>
	Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2i _size, int _sizeOne,
		sf::Vector2u _sizeW, sf::Texture& _texture, std::vector<Sprite*>& _objects);
	/// <summary>Отрисовка травы</summary>
	/// <param name="cameraPosition">Позиция камеры</param>
	void Draw(sf::Vector2f cameraPosition);

	bool PutObject(sf::Vector2i mousePositionGrid, std::vector<Sprite*> _objects, Item& chooseItem);
	// А я кстати не помню что это, так что возможно скоро удалю
	sf::Vector2i WhatActive(sf::Vector2i mousePosition);


};

