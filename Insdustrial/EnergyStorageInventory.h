#pragma once
#include "ObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"

class EnergyStorageInventory : public ObjectInventory
{
private:
	std::shared_ptr<sf::RenderWindow> rw;
	int maxEnergy;
	std::vector<Checks> ch;

public:
	int energy;
	// ������� �����������
	EnergyStorageInventory(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory);
	// ��������� ���������
	void Draw();
	// ������
	void Next();
	// ������ ���������
	void Update(Inventory& playerInventory);

};

