#pragma once
#include "EnergyObjectInventory.h"
#include "ProgressInventory.h"

class CrusherInventory : public EnergyObjectInventory
{
public:
	ProgressInventory progress;

	std::vector<CellInInventory> cells;

	CrusherInventory(){ }
	CrusherInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory,
		int _maxEnergy, std::vector<sf::Texture*>& _textures);

	// ������
	void PlayUpdate() override;
	// ���������� ����������
	void Draw() override;
	// ����� ����� � ���������
	void WhileOpen(Inventory& playerInventory) override;
};

