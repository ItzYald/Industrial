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

// struct ItemStruct
// {
// 	int number;
// 	int quantity;
// };

class Player : public Sprite
{
private:
	Functions functions;
	// ������� ����
	//sf::Vector2i mousePosition;

public:

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

	bool CheckObject(std::vector<Object*> objects);
	// ��������� ������� ������� ����� �������
	bool PutObject(std::vector<Object*> objects);
	// ���������
	void Draw(sf::Vector2f cameraPosition);
};

