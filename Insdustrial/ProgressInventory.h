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
	/// <summary>
	/// ������� ������ (������, ������, ���������...)
	/// </summary>
	/// <param name="energy">������ �� �������</param>
	/// <param name="cells">������</param>
	/// <param name="whatNext">�� ��� ������������</param>
	/// <param name="quantity">����������� ����, �� ��� ������������</param>
	/// <returns></returns>
	bool Progress(float& energy, std::vector<CellInInventory>& cells, int whatNext, int quantity);

	void DrawEnergy(int energy, int maxEnergy, sf::Color color);
	void Draw();
};

