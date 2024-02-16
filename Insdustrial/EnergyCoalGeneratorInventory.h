#pragma once
#include "EnergyStorageInventory.h"

class EnergyCoalGeneratorInventory : public EnergyStorageInventory
{
public:
	// ����� ��� ����� (��� ������� ��������)
	CellInInventory coalCell;
	// ������� �������
	int burn;
	int maxBurn;

	EnergyCoalGeneratorInventory(){ }

	EnergyCoalGeneratorInventory(
		std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, int _power, std::vector<sf::Texture>& _textures);

	// ������
	void Next();
	// ���������� ����������
	void Draw();
	// ����� ����� � ���������
	void Update(Inventory& playerInventory);

};

