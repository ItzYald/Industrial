#pragma once
#include "TransferItemObjectInventory.h"
#include "EnergyObjectInventory.h"

class EnergyCoalGeneratorInventory : public EnergyObjectInventory, public TransferItemObjectInventory
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
		int _maxEnergy, int _power, std::vector<sf::Texture*>& _textures);

	// ������
	void PlayUpdate() override;
	// ���������� ����������
	void Draw() override;
	// ����� ����� � ���������
	void WhileOpen(Inventory& playerInventory) override;

};

