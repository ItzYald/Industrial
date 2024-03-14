#pragma once
#include "ProgressInventory.h"
#include "EnergyObjectInventory.h"
#include "TransferObject.h"

class ElectricOvenInventory : public EnergyObjectInventory, public TransferObject

{
	// ������ � ����������
	std::vector<CellInInventory> cells;

	ProgressInventory progress;
public:
	ElectricOvenInventory(){ }
	ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	void Burn();
	// ������ ���� (���� ���� ����� �� ������ ���� ���������)
	void PlayUpdate() override;
	// ���������
	void Draw() override;
	// ����� ��������� ������
	void WhileOpen(Inventory& playerInventory) override;

};

