#pragma once
#include <iostream>
#include <vector>

#include "CellInInventory.h"

class ProgressInventory
{
private:
	Functions functions;

public:
	int whatProgress;
	int previousItemProgress;


	ProgressInventory(){ }
	ProgressInventory(std::shared_ptr<sf::RenderWindow> _rw);

	bool Progress(float& energy, std::vector<CellInInventory>& cells, int whatProgress, int quantity);

	void DrawEnergy(int energy, int maxEnergy, sf::Color color);
	void Draw();
};

