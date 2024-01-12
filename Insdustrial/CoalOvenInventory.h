#pragma once
#include "OvenInventory.h"

class CoalOvenInventory : public OvenInventory
{
private:
	// ������������ ������� (��� ��������� ������� �������� �������)
	int maxFuel;

public:
	CoalOvenInventory(){}
	CoalOvenInventory(std::shared_ptr<sf::RenderWindow> _rw);

	void Burn();
	void Draw();
	void Update(Inventory& playerInventory);

};

