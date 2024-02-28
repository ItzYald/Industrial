#pragma once
#include "ObjectInventory.h"
#include "EnergyObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"

class WireInventory : public EnergyObjectInventory
{
public:
	// ������ ��������
	sf::Sprite spriteOn;
	sf::Sprite spriteOff;

	sf::Sprite* thisSprite;

	WireInventory(){ }

	WireInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture*>& _textures);

	// ��������� ���������
	void Draw() override;
	// ������
	void Next() override;
	/// <summary>������ ���������</summary>
	/// <param name="playerInventory">��������� ������</param>
	void Update(Inventory& playerInventory) override;

};

