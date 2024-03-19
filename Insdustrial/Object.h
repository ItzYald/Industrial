#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Checks.h"

#include "Sprite.h"

class Object : public Sprite
{
public:
	int turn;
	// ������ �� ���������
	bool isOpenInventory;

	/// <summary>�������� ������ �����</summary>
	/// <param name="playerPosition">������� ������</param>
	/// <param name="playerAngle">���� �������� �����</param>
	/// <returns>������� ����� ������</returns>
	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle)
	{
		if (((int)playerPosition.x == position.x && (int)playerPosition.y == position.y + 1 && playerAngle == 0) ||
			((int)playerPosition.x == position.x && (int)playerPosition.y == position.y - 1 && playerAngle == 2) ||
			((int)playerPosition.x == position.x + 1 && (int)playerPosition.y == position.y && playerAngle == 3) ||
			((int)playerPosition.x == position.x - 1 && (int)playerPosition.y == position.y && playerAngle == 1))
		{
			return true;
		}
		return false;
	}
	virtual void PlayUpdate() = 0;
	/// ������ ����
	/// </summary>
	/// <param name="playerPosition">������� ������</param>
	/// <param name="playerAngle">���� �������� �����</param> = 0;
	void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			isOpenInventory = (position == (sf::Vector2f)mousePositionGrid);
		}
		if (ch[0].Check(sf::Keyboard::Key::R))
		{
			if ((position == (sf::Vector2f)mousePositionGrid))
			{
				if (turn < 3)
					turn += 1;
				else
					turn = 0;
			}
		}
	}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

