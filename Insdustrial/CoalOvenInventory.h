#pragma once
#include "ObjectInventory.h"
#include "ProgressInventory.h"
#include "Inventory.h"

class CoalOvenInventory : public ObjectInventory
{
private:
	// ������ � ����������
	std::vector<CellInInventory> cells;

	ProgressInventory progress;
	// ������������ ������� (��� ��������� ������� �������� �������)
	int maxEnergy;
	// �������
	float energy;
public:
	CoalOvenInventory(){}
	CoalOvenInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _textures);

	void Burn();
	void Next() override;
	void Draw() override;
	void Update(Inventory& playerInventory);

};

