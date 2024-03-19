#pragma once
#include "ITransferItemSimpleObject.h"

template<class T>
class TransferItemSimpleObject : public ITransferItemSimpleObject
{
public:
	T TypeInventory;

	TransferItemSimpleObject()
	{
	}
	/// <summary�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_fieldSizeOne">������ ����� ������</param>
	/// <param name="_texture">������ �� ��������</param>
	/// <param name="_position">�������</param>

	TransferItemSimpleObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture* _texture, std::vector<sf::Texture*>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _itemTextures);
		inventory = &TypeInventory;
	}

	TransferItemSimpleObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
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
	}
	/// <summary>���������</summary>
	/// <param name="cameraPosition">������� ������</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(sprite);
	}


};

