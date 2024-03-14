#pragma once
#include "ObjectInventory.h"
#include "ProgressInventory.h"
#include "Inventory.h"
#include "TransferObject.h"

class CoalOvenInventory : public ObjectInventory, public TransferObject
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
	CoalOvenInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	void Burn();
	void PlayUpdate() override;
	void Draw() override;
	void WhileOpen(Inventory& playerInventory);

};

