#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Sprite.h"

class Wire : public Sprite
{
public:
	// ���-�� ���������� ����� ��������� � �����������
	bool connections[4] = { 0, 0, 0, 0 };

	// ������ ��������
	sf::Sprite sprite;
	sf::Sprite spriteOn;
	sf::Sprite spriteOff;
	// ���������� �������
	float energy;
	// ����������� �������� �������
	int maxEnergy;
	// ����, � ������� ����� ���������� ������� ������
	int power;

	// ����� ���������������� ������� (� ����������� �� ������)
	int numberSprite;
	// ������� (���� ��������� �����)
	int turn;

	Wire(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_fieldSizeOne">������ ����� ������</param>
	/// <param name="textureOn">�������� �� ���������� ��������</param>
	/// <param name="textureOff">�������� � ����������� ��������</param>
	/// <param name="_position">�������</param>
	/// <param name="type">��� (0 - ������, 1 - ��������)</param>
	Wire(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& textureOn, sf::Texture& textureOff, sf::Vector2f _position, int _type);
	/// <summary>���� �� ������ ����� �������</summary>
	/// <param name="playerPosition">������� ������</param>
	/// <param name="playerAngle">���� �������� ������</param>
	/// <returns>���� ��� ���</returns>
	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle);
	void CheckConnections(sf::Vector2f positionSeconObject);
	void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle);

	void Next() override{ }
	/// <summary>���������</summary>
	/// <param name="cameraPosition">�������� ������</param>
	void Draw() override;
};

