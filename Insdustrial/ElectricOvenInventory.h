#pragma once
#include "ProgressInventory.h"
#include "EnergyObjectInventory.h"

class ElectricOvenInventory : public EnergyObjectInventory

{
	// ������ � ����������
	std::vector<CellInInventory> cells;

	ProgressInventory progress;
public:
	ElectricOvenInventory(){ }
	ElectricOvenInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);

	void Next(){}
	void Burn();
	void Draw();
	void Update(Inventory& playerInventory);

};

