#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"
#include "Button.h"

#include "Sprite.h"
#include "StaticSprites.h"
#include "Inventory.h"
#include "Oven.h"
#include "StaingObject.h"

class Player : public Sprite
{
private:
	Functions functions;

public:
	// ���������
	Inventory inventory;

	// ���� ������
	int angle;
	bool isOpenInterface;
	int whatTypeInventoryOpen;
	int whatNumberInventoryOpen;

	float run;

	Player(){ }
	Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position);

	std::vector<Button> buttons;


	// ������ ������
	void Move();
	//������ ����
	void Update();
	// ��������� ������� ������� ����� �������
	bool PutObject(std::vector<std::shared_ptr<StaingObject<OvenInventory>>> objects);
	// ���������
	void Draw(sf::Vector2f cameraPosition);
};

