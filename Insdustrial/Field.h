#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Object.h"
#include "Item.h"

class Field : public sf::Drawable
{
public:
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	// ������ ���� (���-�� ������)
	sf::Vector2i size;
	// ������ �����
	sf::Sprite sprite;
	// ������ ����� ������
	int sizeOne;
	// ������ ����
	sf::Vector2u sizeW;
	
	sf::Vector2f* cameraPosition;

	// ��������� �� ������ ���� ��������
	std::vector<Object*>* objects;
	std::vector<std::vector<int>> newEnergyObjectsNumbers;
	std::vector<std::vector<int>> transEnergyObjectsNumbers;

	// ������ ��������� (�������������, ����, �����, ������...)
	Functions functions;

	Field(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_size">������ ���� (���-�� ������)</param>
	/// <param name="_sizeOne">������ ����� ������</param>
	/// <param name="_sizeW">������ ����</param>
	/// <param name="texture">��������� �����</param>
	Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, sf::Vector2i _size, int _sizeOne,
		sf::Vector2u _sizeW, sf::Texture& _texture, std::vector<Object*>& _objects);
	/// <summary>��������� �����</summary>
	/// <param name="cameraPosition">������� ������</param>
	void Draw();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void Next();

	bool PutObject(sf::Vector2i mousePositionGrid, std::vector<Object*> _objects, Item& chooseItem);
	// � � ������ �� ����� ��� ���, ��� ��� �������� ����� �����
	sf::Vector2i WhatActive(sf::Vector2i mousePosition);


};

