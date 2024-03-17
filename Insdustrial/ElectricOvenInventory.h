#pragma once
#include "ProgressInventory.h"
#include "EnergyTransferItemObjectInventory.h"

class ElectricOvenInventory : public EnergyTransferItemObjectInventory

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

