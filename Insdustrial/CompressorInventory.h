#pragma once
#include "EnergyObjectInventory.h"
#include "TransferItemObjectInventory.h"
#include "ProgressInventory.h"

class CompressorInventory : public EnergyObjectInventory, public TransferItemObjectInventory
{
public:
	ProgressInventory progress;

	std::vector<CellInInventory> cells;

	CompressorInventory() { }
	CompressorInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, std::vector<sf::Texture*>& _textures);

	// ������
	void PlayUpdate() override;
	// ���������� ����������
	void Draw() override;
	// ����� ����� � ���������
	void WhileOpen(Inventory& playerInventory) override;
};

