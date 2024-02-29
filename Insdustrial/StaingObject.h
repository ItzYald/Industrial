#pragma once
#include "IStaingObject.h"

template<class T>
class StaingObject : public IStaingObject
{
public:

	T TypeInventory;

	StaingObject(){}
	/// <summary�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_fieldSizeOne">������ ����� ������</param>
	/// <param name="_texture">������ �� ��������</param>
	/// <param name="_position">�������</param>

	StaingObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture* _texture, std::vector<sf::Texture*>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _itemTextures);
		inventory = &TypeInventory;
	}

	StaingObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture* _texture, std::vector<sf::Texture*>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory, 
		std::map<std::string, sf::Texture>& _texturesInInventory)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _itemTextures, _texturesInInventory);
		inventory = &TypeInventory;
	}

	void Init(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture* _texture, std::vector<sf::Texture*>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory)
	{
		sprite = sf::Sprite();
		rw = _rw;
		fieldSizeOne = _fieldSizeOne;
		sprite.setTexture(*_texture);
		position = _position;

		cameraPosition = &_cameraPosition;

		functions = Functions(rw);

		isOpenInventory = false;

		turn = 0;
		sprite.setScale(fieldSizeOne / (float)sprite.getTexture()->getSize().x, fieldSizeOne / (float)sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			ch.push_back(Checks());
		}
	}

	/// <summary>�������� ������ �����</summary>
	/// <param name="playerPosition">������� ������</param>
	/// <param name="playerAngle">���� �������� �����</param>
	/// <returns>������� ����� ������</returns>
	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle) override
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
	// ���������� ���������
	void PlayUpdate() override
	{
		inventory->PlayUpdate();
		// ���� �������� �����
		if (turn == 0)
		{
			sprite.setRotation(0);
		}
		// ���� �������� ������
		if (turn == 1)
		{
			sprite.setRotation(90);
		}
		// ���� �������� ����
		if (turn == 2)
		{
			sprite.setRotation(180);
		}
		// ���� �������� �����
		if (turn == 3)
		{
			sprite.setRotation(270);
		}

		// ������ �������
		sprite.setPosition(
			fieldSizeOne * (position.x - (*cameraPosition).x),
			fieldSizeOne * (position.y - (*cameraPosition).y));

		// ����� ��� ����������� ��������
		if (sprite.getRotation() == 90)
		{
			sprite.setPosition(
				sprite.getPosition().x + fieldSizeOne,
				sprite.getPosition().y);
		}
		else if (sprite.getRotation() == 180)
		{
			sprite.setPosition(
				sprite.getPosition().x + fieldSizeOne,
				sprite.getPosition().y + fieldSizeOne);
		}
		else if (sprite.getRotation() == 270)
		{
			sprite.setPosition(
				sprite.getPosition().x,
				sprite.getPosition().y + fieldSizeOne);
		}

		//rw->draw(sprite);
		//sf::Vector2f realPosition = sf::Vector2f(
		//	fieldSizeOne * (position.x - (*cameraPosition).x),
		//	fieldSizeOne * (position.y - (*cameraPosition).y));
	}
	/// <summary>
	/// ������ ����
	/// </summary>
	/// <param name="playerPosition">������� ������</param>
	/// <param name="playerAngle">���� �������� �����</param>
	void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle) override
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
	/// <summary>���������</summary>
	/// <param name="cameraPosition">������� ������</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(sprite);
	}


};

