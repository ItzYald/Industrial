#pragma once
#include "ObjectInventory.h"
#include "EnergyObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"


class EnergyStorageInventory : public EnergyObjectInventory
{
protected:

public:
	// ������� �����������
	EnergyStorageInventory(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	/// <param name="_colorsInventory">������� ����� ����������</param>
	/// <param name="_maxEnergy">����������� ��������� �������</param>
	/// <param name="_power">����������� ���������� ������</param>
	/// <param name="_textures">������ �������</param>
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture*>& _textures);
	// ��������� ���������
	void Draw() override;
	// ������
	void Next() override;
	/// <summary>������ ���������</summary>
	/// <param name="playerInventory">��������� ������</param>
	void Update(Inventory& playerInventory) override;

};

