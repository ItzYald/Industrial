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

	// Всегда
	void PlayUpdate() override;
	// Отроисовка отнвентаря
	void Draw() override;
	// Когда зашел в инвентарь
	void WhileOpen(Inventory& playerInventory) override;

};

