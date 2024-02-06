#pragma once
#include "ObjectInventory.h"
#include "Functions/Checks.h"
#include "Inventory.h"

class EnergyStorageInventory : public ObjectInventory
{
private:
	std::shared_ptr<sf::RenderWindow> rw;
	// ������������ �������, ������� �������
	int maxEnergy;
	std::vector<Checks> ch;

public:
	int energy;
	// ������� �����������
	EnergyStorageInventory(){ }
	/// <summary>�����������</summary>
	/// <param name="_rw">����</param>
	EnergyStorageInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, int type, std::vector<sf::Texture>& _textures);
	// ��������� ���������
	void Draw();
	// ������
	void Next();
	/// <summary>������ ���������</summary>
	/// <param name="playerInventory">��������� ������</param>
	void Update(Inventory& playerInventory);

};

