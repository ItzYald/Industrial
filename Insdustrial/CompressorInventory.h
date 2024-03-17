#pragma once
#include "EnergyObjectInventory.h"
#include "ProgressInventory.h"
#include "TransferObject.h"
#include "AcceptItemObject.h"

class CompressorInventory : public EnergyObjectInventory, public TransferObject, public AcceptItemObject
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

