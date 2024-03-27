#pragma once
#include "TransferItemObjectInventory.h"
#include "ObjectInventory.h"

class PipeInventory : public ObjectInventory, public TransferItemObjectInventory
{
	CellInInventory transferCell;

public:
	PipeInventory(){}
	PipeInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	// ������
	void PlayUpdate() override;
	// ���������� ����������
	void Draw() override;
	// ����� ����� � ���������
	void WhileOpen(Inventory& playerInventory) override;

};

